#include <stdio.h>
#include "pacientes.h"
#include "atendimento.h"
#include "util.h"
//vinhas
#define QNTD_PACIENTES 100
#define QNTD_ATENDIMENTOS 100

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CIANO   "\x1b[36m"
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

int paciente_do_atendimento[QNTD_ATENDIMENTOS];//guarda o indice do paciente para cada atendimento
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
                                    break;
                                }

                                printf("Digite o Nome do Paciente:\n");
                                ler_string(nomes_pacientes[espaco_livre]);
                                
                                int nome_incorreto = checar_string(nomes_pacientes[espaco_livre]);
                                if(nome_incorreto){
                                    printf("Digite o nome corretamente!\n");
                                    continue;
                                }

                                formata_string_maisculo(nomes_pacientes[espaco_livre]);
                                
                                char opcao_selecionada;

                                int ja_cadastrado = ja_existe(nomes_pacientes[espaco_livre],nomes_pacientes,QNTD_PACIENTES,espaco_livre);
                                if(ja_cadastrado) { 
                                    printf("Paciente já cadastrado!");
                                    
                                    printf("\n[1] Inserir outro paciente [2] Ir para o Menu Pacientes\n");

                                    opcao_selecionada = interacao_pos_erro();
                                
                                    if(opcao_selecionada == '1') {
                                        printf("\nOpção -> [1], \"Inserir outro paciente\" Selecionada...\n\n"); 
                                        continue;
                                    }
                                    else {
                                        printf("\nOpção -> [2], \"Ir para o Menu Pacientes\" Selecionada...\n\n"); 
                                        break;
                                    }
                                }
                                
                                cria_codigo(codigo_pacientes,espaco_livre);

                                printf("\n-> Paciente cadastrado!\n");
                                printf("Nome: %s\n", nomes_pacientes[espaco_livre]);
                                printf("Código do Paciente: %s\n", codigo_pacientes[espaco_livre]);

                                pacientes_ativos[espaco_livre] = 1;
                                
                                printf("[1] Incluir novo paciente   [2] Voltar ao Menu Pacientes\n");

                                opcao_selecionada = interacao_pos_erro();
                                
                                if(opcao_selecionada == '1') {
                                    printf("\nOpção -> [1], \"Voltar ao Menu Pacientes\" Selecionada...\n\n"); 
                                    continue;
                                }
                                else {
                                    printf("\nOpção -> [2], \"Incluir novo paciente\" Selecionada...\n\n"); 
                                    break;
                                }
                                
                            }
                            break;
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
                    int indice_do_paciente;

                    switch (interacao_menu_atendimentos) {
                        case 1:
                            system("clear");
                            while (1){
                                printf("\n-----------------"BLUE"Inserir um Novo Atendimento"RESET"------------------\n");
                                
                                espaco_livre = procura_espaco_livre(atendimentos_ativos, QNTD_ATENDIMENTOS);
                                
                                int indice_paciente=procura_paciente(nomes_pacientes,QNTD_PACIENTES);
                                if( indice_paciente == -1)break;//saida da operacao
                                
                                paciente_do_atendimento[espaco_livre]=indice_paciente;
                                
                                system("clear");
                                printf("Paciente "GREEN" %s"RESET"  Selecionado...\n",nomes_pacientes[indice_paciente]);
                                
                                printf(BLUE"Dados da consulta:\n"RESET);
                                receber_data(data_atendimentos,espaco_livre);
                                
                                int data_ja_cadastrada=atendimento_ja_cadastrado(data_atendimentos,paciente_do_atendimento,espaco_livre,QNTD_ATENDIMENTOS);
                                if(data_ja_cadastrada)continue;
                                
                                receber_tipo_atendimento(tipo_atendimentos,espaco_livre);

                                preco_atendimentos[espaco_livre]=receber_preco();

                                receber_status_atendimento(status_atendimentos,espaco_livre);
                                
                                atendimentos_ativos[espaco_livre]=1;
                                cria_codigo(codigo_atendimentos,espaco_livre); 
                                
                                system("clear");
                                printf(GREEN"Atendimento Cadastrado com sucesso!\n"RESET);
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,espaco_livre);
                                
                                if(coletar_opcao("Voltar","Inserir outro Atendimento"))continue;
                                else break;
                            }break;
                        case 2:
                            system("clear");
                            while(1){
                                printf("\n----------------"BLUE"Alterar um Atendimento Existente"RESET"---------------\n");
                                
                                printf("Digite o código do atendimento que deseja alterar:\n");
                                int indice_do_atendimento = procura_atendimento(codigo_atendimentos,QNTD_ATENDIMENTOS,atendimentos_ativos);
                                if(indice_do_atendimento == -1)continue;
                                if(indice_do_atendimento == -2)break;
                                
                                indice_do_paciente = paciente_do_atendimento[indice_do_atendimento];
                                
                                system("clear");
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,espaco_livre); 
                                int opcao;
                                
                                printf("Qual dado deseja alterar?\n");
                                printf(BLUE"[1]"RESET"Paciente "BLUE"[2] "RESET"Data "BLUE"[3] "RESET"Tipo "BLUE"[4]"RESET" Preço "BLUE"[5]"RESET"Status\n");
                                scanf("%d",&opcao);

                                switch(opcao){
                                    case 1: 
                                        printf("Paciente anterior : %s \n",nomes_pacientes[indice_do_paciente]);
                                        int indice_novo_paciente = procura_paciente(nomes_pacientes,QNTD_PACIENTES);

                                        int data_ja_cadastrada=atendimento_ja_cadastrado(data_atendimentos,indice_novo_paciente,espaco_livre,QNTD_ATENDIMENTOS);
                                        if(data_ja_cadastrada)continue;
                                        
                                        paciente_do_atendimento[indice_do_atendimento]=indice_novo_paciente;
                                        printf(GREEN"Paciente do atendimento %s alterado!\n"RESET,codigo_atendimentos[indice_do_atendimento]);
                                        
                                        break;
                                    case 2:
                                        printf("Digite a nova data:\n");
                                        receber_data(data_atendimentos,indice_do_atendimento);
                                        printf(GREEN"Nova data cadastrada: %s\n"RESET,data_atendimentos[indice_do_atendimento]);
                                        break;
                                    case 3:
                                        receber_tipo_atendimento(tipo_atendimentos,indice_do_atendimento);
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
                                    default:
                                        printf("digite apenas 1,2,3,4 ou 5");
                                        break;
                                }break;
                                if(coletar_opcao("Voltar","Alterar outro Atendimento"))continue;
                                else break;
                            }break;          
                        case 3:
                            system("clear");
                            while(1){
                                printf("---------------------"BLUE"Excluir um Atendimento"RESET"-----------------------\n");
                                
                                printf("Digite o código do atendimento que deseja excluir:\n");
                                int indice_do_atendimento =procura_atendimento(codigo_atendimentos,QNTD_ATENDIMENTOS,atendimentos_ativos);
                                
                                if(indice_do_atendimento == -1)continue;
                                indice_do_paciente = paciente_do_atendimento[indice_do_atendimento];
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                
                                printf("Tem certeza?\n");
                                if(coletar_opcao("Excluir","Cancelar Operação")) {
                                    atendimentos_ativos[indice_do_atendimento]=0;
                                    printf(GREEN"Atendimento Excluído\n"RESET);
                                    break;
                                }
                                printf(GREEN"Operacão Cancelada!"RESET);
                            }break;
                        case 4:
                            while(1){
                                system("clear");
                                printf("---------------------"BLUE"Exibir Atendimento(Código)"RESET"-------------------\n");
                                
                                printf("Digite o código do atendimento que deseja consultar:\n");
                                int indice_do_atendimento=procura_atendimento(codigo_atendimentos,QNTD_ATENDIMENTOS,atendimentos_ativos);
                                indice_do_paciente = paciente_do_atendimento[indice_do_atendimento];
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                
                                if(coletar_opcao("Voltar","Exibir outro Atendimento"))continue;
                                else break; 
                            }break;
                        case 5:
                            while(1){
                                char codigo_paciente[8];
                                system("clear");
                                printf("----------------------"BLUE"Exibir Atendimento (Código do Paciente)"RESET"-----------------\n");
                                
                                int indice_do_paciente = procura_paciente_codigo(codigo_pacientes,QNTD_PACIENTES,pacientes_ativos);
                               
                                for(int i = 0;i < QNTD_ATENDIMENTOS;i++){
                                    if(paciente_do_atendimento[i] == indice_do_paciente){
                                        if(atendimentos_ativos[i]==0) continue;
                                        int indice_do_atendimento=i;
                                        exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                    }
                                }
                                
                                if(coletar_opcao("Voltar","Exibir Atendimentos de outro paciente"))continue;
                                else break; 
                            }break;    
                        case 6:
                           
                            while(1){
                                system("clear");
                                printf("-----------------------"BLUE"Exibir atendimento do paciente (Nome do Paciente)"RESET"------------------------\n");
                                
                                char nome_paciente[255];
                                //printf("Digite o nome do Paciente que deseja exibir:\n");
                                int indice_do_paciente = procura_paciente(nomes_pacientes,QNTD_PACIENTES);
                                
                                system("clear");
                                printf("Atendimentos do Paciente "BLUE"%s"RESET":\n",nomes_pacientes[indice_do_paciente]);
                                for(int i = 0;i < QNTD_ATENDIMENTOS;i++){
                                    if(atendimentos_ativos[i]==0) continue;
                                    if(paciente_do_atendimento[i] == indice_do_paciente){  
                                        int indice_do_atendimento=i;
                                        exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                    }
                                }
                                if(coletar_opcao("Voltar","Exibir Atendimentos de outro paciente"))continue;
                                else break;
                            }break;   
                        case 7:
                            
                            while(1){
                                system("clear");
                                printf("-------------------"BLUE"Exibir Todos os Atendimentos do Dia"RESET"--------------------\n");
                                
                                char atendimentos_do_dia[1][255];
                                float soma;
                                printf("Digite a data que deseja buscar atendimentos:\n");
                                receber_data(atendimentos_do_dia,1);
                                
                                for(int i = 0; i< QNTD_ATENDIMENTOS;i++){
                                    if(atendimentos_ativos[i]==0) continue;
                                    if(strcmp(atendimentos_do_dia[1],data_atendimentos[i]) == 0){
                                        int indice_do_atendimento=i;
                                        exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                        soma+=preco_atendimentos[i];
                                    }
                                }
                                printf("Total de Consultas Pagas no Dia[ %s ] = R$%.2f\n",atendimentos_do_dia[1],soma);
                                
                                if(coletar_opcao("Sair","Exibir Atendimentos de Outro Dia"))continue;
                                else break;
                            }break;
                        case 8:
                            while(1){
                                system("clear");
                                printf("-------------------"BLUE"Exibir Todos os Atendimentos(Data mais próxima)"RESET"--------------------\n");
                                
                                int ordem_datas[100];
                                ordenar_datas(data_atendimentos,ordem_datas,QNTD_ATENDIMENTOS,atendimentos_ativos);
                                int qnd_atend_ativos=0;
                                for(int i=0;i<QNTD_ATENDIMENTOS-1;i++){
                                    if(atendimentos_ativos[i]==1)qnd_atend_ativos++;
                                }
                                for(int i=0;i < qnd_atend_ativos;i++){
                                int atendimento=ordem_datas[i];
                                int paciente = paciente_do_atendimento[i];
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,atendimento);
                                }
                                if(coletar_opcao("Sair","Exibir Atendimentos Novamente"))continue;
                                else break;
                            }break;
                        case 9:
                            printf("\nOpção -> [9], \"Voltar para o Menu Anterior\" Selecionada...\n\n");
                            break;
                        default:
                            printf("\nSelecione alguma das opções anteriores!\n");
                            break;
                    }
                    if(interacao_menu_atendimentos==9)break;
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
