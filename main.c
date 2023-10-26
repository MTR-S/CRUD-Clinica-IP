#include <stdio.h>
//alterado no github
#include "pacientes.h"
#include "atendimento.h"
#include "util.h"

#define QNTD_PACIENTES 100
#define QNTD_ATENDIMENTOS 100

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"


int pacientes_ativos[QNTD_PACIENTES];

char codigo_pacientes[QNTD_PACIENTES][8];  
char nomes_pacientes[QNTD_PACIENTES][255];
char RG_pacientes[QNTD_PACIENTES][10]; 
char CPF_pacientes[QNTD_PACIENTES][12];
char tipo_sanguineo_pacientes[QNTD_PACIENTES][3];
char fator_RH_pacientes[QNTD_PACIENTES][25];  
char endereco_pacientes[QNTD_PACIENTES][255];
int datas_nascimento_pacientes[QNTD_PACIENTES];


int atendimentos_ativos[QNTD_ATENDIMENTOS];

int paciente_atendimento[QNTD_ATENDIMENTOS];//guarda o indice do paciente para cada atendimento
char codigo_atendimentos[QNTD_ATENDIMENTOS][8];
char tipo_atendimentos[QNTD_ATENDIMENTOS][255];  // int?
char data_atendimentos[QNTD_ATENDIMENTOS][255];
char status_atendimentos[QNTD_ATENDIMENTOS][255];  //int?
float preco_atendimentos[QNTD_ATENDIMENTOS];

int main(void) {
    preenche_matriz_bidimensional(nomes_pacientes,QNTD_PACIENTES); 
    preenche_matriz_bidimensional(data_atendimentos,QNTD_ATENDIMENTOS); 
    preenche_vetor_ativos(pacientes_ativos, QNTD_PACIENTES);
    preenche_vetor_ativos(atendimentos_ativos, QNTD_ATENDIMENTOS);


    while(1) {
        system("clear");
        
        int interacao_menu_principal = menu_principal();

        switch (interacao_menu_principal) {
            case 1:
                system("clear");
                printf("\nMenu \"Paciente\" Selecionado...\n");
                while(1) {
                    int interacao_menu_pacientes = menu_pacientes();
                    int espaco_livre;

                    switch (interacao_menu_pacientes) {
                        case 1:
                            while (1){
                                system("clear");
                                printf("\nOpção -> [1], \"Inserir um Novo Paciente\" Selecionada...\n\n");

                                espaco_livre = procura_espaco_livre(pacientes_ativos, QNTD_PACIENTES);

                                if(espaco_livre < 0) {
                                    printf("\nCadastro Impossível, Quantidade de Pacientes Cadastrados Cheia!\n");
                                    break;//vss dps
                                }

                                printf("Digite o Nome do Paciente:\n");
                                ler_string(nomes_pacientes[espaco_livre]);
                                

                                if(checar_string(nomes_pacientes[espaco_livre])){
                                    printf("Digite o nome corretamente!\n");
                                    continue;
                                }

                                formata_string_maisculo(nomes_pacientes[espaco_livre]);
                                int ja_cadastrado=ja_existe(nomes_pacientes[espaco_livre],nomes_pacientes,QNTD_PACIENTES,espaco_livre);
                                if(ja_cadastrado){ 
                                    printf("Paciente já cadastrado!");
                                    continue;
                                }
                                
                                cria_codigo(codigo_pacientes,espaco_livre);

                                printf("-> Paciente cadastrado!\n");
                                printf("Nome: %s\n", nomes_pacientes[espaco_livre]);
                                printf("Código do Paciente: %s\n", codigo_pacientes[espaco_livre]);

                                pacientes_ativos[espaco_livre] = 1;
                                
                                int opcao;
                                printf("[0] Voltar   [1]Incluir novo paciente\n");
                                scanf("%d", &opcao);
                                if(opcao)
                                    continue;                            
                                
                                break;
                            }break;
                        case 2:
                            //system("cls");
                            printf("\nOpção -> [2], \"Alterar um Paciente Existente\" Selecionada...\n\n");
                        case 3:
                            printf("\nOpção -> [3], \"Excluir um Paciente\" Selecionada...\n\n");
                        case 4:
                            printf("\nOpção -> [4], \"Exibir os Dados de um Paciente pelo seu ""Código\" Selecionada...\n\n");
                        case 5:
                            printf("\nOpção -> [5], \"Exibir os Dados de Pacientes que Apresentam o Mesmo"
                                " Tipo Sanguíneo\" Selecionada...\n\n");
                        case 6:
                            printf("\nOpção -> [6], \"Exibir os Dados de Pacientes pelo Dia de "
                                "Consulta\" Selecionada...\n\n");
                        case 7:
                            printf("\nOpção -> [7], \"Exibir Todos os Pacientes\" Selecionada...\n\n");
                        case 8:
                            printf("\nOpção -> [8], \"Exibir Todos os Pacientes em Ordem"
                                " Alfabética\" Selecionada...\n\n");
                        case 9:
                            printf("\nOpção -> [9], \"Voltar para o Menu Anterior\" Selecionada...\n\n");
                            break;
                        default:
                            printf("\nSelecione alguma das opções anteriores!\n");
                            break;
                    }
                    if(interacao_menu_pacientes==9)break;
                    continue;
                }continue;
            case 2:
                system("clear");
                printf(BLUE"\nMenu \"Atendimento\" Selecionado...\n"RESET);
                while(1) {
                    int interacao_menu_atendimentos = menu_atendimento();
                    int espaco_livre;

                    switch (interacao_menu_atendimentos) {
                        case 1:
                            system("clear");
                            printf("\nOpção -> [1], \"Inserir um Novo Atendimento\" Selecionada...\n\n");
                            while (1){
                                espaco_livre = procura_espaco_livre(atendimentos_ativos, QNTD_ATENDIMENTOS);
                                
                                char nome[255];
                                printf("Digite o Nome do Paciente: \n");
                                ler_string(nome);
                                formata_string_maisculo(nome);
                            
                                int indice_paciente=procura_string(nome,nomes_pacientes,QNTD_PACIENTES);
                                if(indice_paciente < 0){
                                    printf(RED"Paciente não cadastrado\n"RESET);
                                    continue;
                                }
                                
                                receber_data(data_atendimentos,espaco_livre);
                                
                                int atendimento_ja_cadastrado=0;
                                for(int i=0;i<QNTD_ATENDIMENTOS;i++){
                                    if(i==espaco_livre) continue;
                                    if(paciente_atendimento[i]== indice_paciente){
                                        if(!(strcmp(data_atendimentos[i],data_atendimentos[espaco_livre]))){
                                            printf(RED"Paciente ja tem atendimento nesta data!\n"RESET);
                                            atendimento_ja_cadastrado=1;
                                            break;
                                        }
                                    }

                                }
                                if(atendimento_ja_cadastrado){
                                    
                                    continue;
                                }
                                paciente_atendimento[espaco_livre]=indice_paciente;
                                
                                int opcao;
                                printf("Tipo de Atendimento:\n");
                                printf(BLUE"[0]"RESET"Consulta "BLUE"[1]"RESET"Retorno\n");
                                scanf("%d",&opcao);//criar funcao ler inteiro
                                if(opcao) strcpy(tipo_atendimentos[espaco_livre],"Retorno");
                                else strcpy(tipo_atendimentos[espaco_livre],"Consulta");

                                printf("Digite o preço da consulta:\n");
                                scanf("%f",&preco_atendimentos[espaco_livre]);//criar funcao ler preco.

                                receber_status_atendimento(status_atendimentos,espaco_livre);
                                
                                atendimentos_ativos[espaco_livre]=1;
                                cria_codigo(codigo_atendimentos,espaco_livre); 
                                
                                system("clear");
                                printf(GREEN"Atendimento Cadastrado com sucesso!\n"RESET);
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,espaco_livre);
                                opcao=0;
                                printf("[0] Voltar   [1]Incluir novo atendimento\n");
                                scanf("%d", &opcao);
                                if(opcao)
                                    continue;                            
                                
                                break;
                            }
                            imprimir_vetor(data_atendimentos,QNTD_ATENDIMENTOS);
                            break;
                        case 2:
                            system("clear");
                            printf("\nOpção -> [2], \"Alterar um Atendimento Existente\" Selecionada...\n\n");
                            char codigo_atendimento[8];
                            char novo_nome[255];
                            while(1){
                                printf("Digite o código do atendimento que deseja alterar:\n");
                                ler_string(codigo_atendimento);
                                
                                int indice_do_atendimento = procura_codigo(codigo_atendimento,codigo_atendimentos,QNTD_ATENDIMENTOS);
                                int indice_do_paciente = paciente_atendimento[indice_do_atendimento];
                                if(indice_do_atendimento == -1){
                                    printf(RED"Atendimento não cadastrado\n"RESET);
                                    continue;
                                }
                                if(atendimentos_ativos[indice_do_atendimento]== 0){
                                    printf(RED"Atendimento não cadastrado ou Excluido recentemente\n"RESET);
                                    continue;
                                }
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,espaco_livre);                                 
                                int opcao;
                                printf("Qual dado deseja alterar?\n");
                                printf("[1]Paciente [2]Data [3]Tipo [4]Preço [5]Status\n");
                                scanf("%d",&opcao);

                                switch(opcao){
                                    case 1: 
                                        printf("Paciente anterior : %s \n",nomes_pacientes[indice_do_paciente]);
                                        printf("Digite o novo nome: ");
                                        ler_string(novo_nome);
                                        formata_string_maisculo(novo_nome);
                                        
                                        int indice_novo_paciente = procura_string(novo_nome,nomes_pacientes,QNTD_PACIENTES);
                                        if(indice_novo_paciente == -1){
                                            printf(RED"Paciente não cadastrado\n"RESET);
                                            continue;
                                        }
                                        
                                        paciente_atendimento[indice_do_atendimento]=indice_novo_paciente;
                                        printf(GREEN"Nome alterado!\n"RESET);
                                        break;

                                    case 2:
                                        printf("Digite a nova data:\n");
                                        receber_data(data_atendimentos,indice_do_atendimento);
                                        printf(GREEN"Nova data cadastrada: %s\n"RESET,data_atendimentos[indice_do_atendimento]);
                                        break;
                                    case 3:
                                        opcao=0;
                                        printf("Novo Tipo de Atendimento:\n");
                                        printf("[0]Consulta [1]Retorno\n");
                                        scanf("%d",&opcao);
                                        if(opcao) strcpy(tipo_atendimentos[indice_do_atendimento],"Retorno");
                                        else strcpy(tipo_atendimentos[indice_do_atendimento],"Consulta");
                                        printf(GREEN"Novo tipo cadastrado"RESET);
                                        break;
                                    case 4:
                                        printf("Digite o novo preço da consulta:\n");
                                        scanf("%f",&preco_atendimentos[indice_do_atendimento]);
                                        printf(GREEN"Novo preço cadastrado"RESET);
                                        break;
                                    case 5:
                                        printf("status atual: %s\n",status_atendimentos[indice_do_atendimento]);
                                        receber_status_atendimento(status_atendimentos,indice_do_atendimento);
                                        printf(GREEN"Status alterado\n"RESET);
                                        break;

                                }
                                opcao=0;
                                printf("[0] Voltar   [1]Alterar outro atendimento\n");
                                scanf("%d", &opcao);
                                if(opcao)
                                    continue;                            
                                
                                break;  
                            }break;                    
                        case 3:
                            printf("\nOpção -> [3], \"Excluir um Atendimento\" Selecionada...\n\n");
                            strcpy(codigo_atendimento,"void");
                            while(1){
                                printf("Digite o código do atendimento que deseja excluir:\n");
                                ler_string(codigo_atendimento);
                                
                                int indice_do_atendimento = procura_codigo(codigo_atendimento,codigo_atendimentos,QNTD_ATENDIMENTOS);
                                int indice_do_paciente = paciente_atendimento[indice_do_atendimento];
                                if(indice_do_atendimento == -1){
                                    printf(RED"Atendimento não cadastrado\n"RESET);
                                    continue;
                                }
                                if(atendimentos_ativos[indice_do_atendimento] == 0){
                                    printf(RED"Atendimento não cadastrado ou Excluido recentemente\n"RESET);
                                    continue;
                                }
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                
                                int opcao;
                                printf("Qual dado deseja alterar?\n");
                                printf("[1]Excluir [2]Cancelar Operação\n");
                                scanf("%d",&opcao);
                                if(opcao == 1) {
                                    atendimentos_ativos[indice_do_atendimento]=0;
                                    printf(GREEN"atendimento excluido\n"RESET);
                                    break;
                                }
                                printf(GREEN"operacao cancelada!"RESET);
                            }break;
                        case 4:
                            printf("\nOpção -> [4], \"Exibir Atendimento pelo seu ""Código\" Selecionada...\n\n");
                            strcpy(codigo_atendimento,"void");
                            while(1){
                                printf("Digite o código do atendimento que deseja consultar:\n");
                                ler_string(codigo_atendimento);
                                
                                int indice_do_atendimento = procura_codigo(codigo_atendimento,codigo_atendimentos,QNTD_ATENDIMENTOS);
                                int indice_do_paciente = paciente_atendimento[indice_do_atendimento];
                                if(indice_do_atendimento == -1){
                                    printf(RED"Atendimento não cadastrado\n"RESET);
                                    continue;
                                }
                                if(atendimentos_ativos[indice_do_atendimento]== 0){
                                    printf(RED"Atendimento não cadastrado ou Excluido recentemente\n"RESET);
                                    continue;
                                }
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                
                                int opcao=0;
                                printf("[0] Voltar   [1]Exibir outro atendimento\n");
                                scanf("%d", &opcao);
                                if(opcao)
                                    continue;                            
                                
                                break;  
                            }break;
                        case 5:
                            printf("\nOpção -> [5], \"Exibir atendimento do paciente (Código)\" Selecionada...\n\n");
                            char codigo_paciente[8];
                            while(1){
                                printf("Digite o código do Paciente que deseja exibir:\n");
                                ler_string(codigo_paciente);
                                
                                int indice_do_paciente = procura_codigo(codigo_paciente,codigo_pacientes,QNTD_PACIENTES);
                                if(indice_do_paciente == -1){
                                    printf(RED"paciente não cadastrado\n"RESET);
                                    continue;
                                }
                               for(int i = 0;i < QNTD_ATENDIMENTOS;i++){
                                    if(paciente_atendimento[i] == indice_do_paciente){
                                        if(atendimentos_ativos[i]==0) continue;
                                        int indice_do_atendimento=i;
                                        exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                    }
                                }
                                int opcao=0;
                                printf("[0] Voltar   [1]Exibir atendimentos de outro paciente\n");
                                scanf("%d", &opcao);
                                if(opcao)
                                    continue;                            
                                
                                break; 
                            }break;    
                        case 6:
                            printf("\nOpção -> [6], \"Exibir atendimento do paciente (Nome do Paciente)\" Selecionada...\n\n");
                            char nome_paciente[255];
                            while(1){
                                printf("Digite o nome do Paciente que deseja exibir:\n");
                                ler_string(nome_paciente);
                                if(checar_string(nome_paciente)){
                                    printf(RED"Digite o nome corretamente!\n"RESET);
                                    continue;
                                }
                                
                                formata_string_maisculo(nome_paciente);
                                
                                int indice_do_paciente = procura_string(nome_paciente,nomes_pacientes,QNTD_PACIENTES);
                                if(indice_do_paciente == -1){
                                    printf("Paciente não cadastrado\n");
                                    continue;
                                }
                               
                               for(int i = 0;i < QNTD_ATENDIMENTOS;i++){
                                    if(atendimentos_ativos[i]==0) continue;
                                    if(paciente_atendimento[i] == indice_do_paciente){  
                                        int indice_do_atendimento=i;
                                        exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                    }
                                }
                                int opcao=0;
                                printf("[0] Voltar   [1]Exibir atendimentos de outro paciente\n");
                                scanf("%d", &opcao);
                                if(opcao)
                                    continue;                            
                                
                                break; 
                            }break;   
                        case 7:
                            printf("\nOpção -> [7], \"Exibir Todos os Atendimentos(Data mais próxima)\" Selecionada...\n\n");
                        case 8:
                            printf("\nOpção -> [9], \"Voltar para o Menu Anterior\" Selecionada...\n\n");
                            break;
                        default:
                            printf("\nSelecione alguma das opções anteriores!\n");
                            break;
                    }
                    if(interacao_menu_atendimentos==8)break;
                    continue;
                }continue;
            case 3:
                printf(RED"\nSaída do Sistema Confirmada!\n"RESET);
                return 0;
            default:
                printf("Selecione alguma das opções anteriores!\n");
                break;
        }break;
    }

    return 0;
}
