#include <stdio.h>
#include "pacientes.h"
#include "atendimento.h"
#include "util.h"

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
char RG_pacientes[QNTD_PACIENTES][12]; 
char CPF_pacientes[QNTD_PACIENTES][12];
char tipo_sanguineo_pacientes[QNTD_PACIENTES][3];
char fator_RH_pacientes[QNTD_PACIENTES][9];  
char endereco_pacientes[QNTD_PACIENTES][255];
char datas_nascimento_pacientes[QNTD_PACIENTES][255];


int atendimentos_ativos[QNTD_ATENDIMENTOS];

int paciente_do_atendimento[QNTD_ATENDIMENTOS];//guarda o indice do paciente para cada atendimento
char codigo_atendimentos[QNTD_ATENDIMENTOS][8];
char tipo_atendimentos[QNTD_ATENDIMENTOS][255];  
char data_atendimentos[QNTD_ATENDIMENTOS][255];
char status_atendimentos[QNTD_ATENDIMENTOS][255];  
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
                    char opcao_selecionada;
                    int ja_cadastrado;
                    int informacao_nao_obrigatoria;
                    int formatacao_incorreta;


                    switch (interacao_menu_pacientes) {
                        case 1:
                            system("clear");
                            printf("\nOpção -> [1], \"Inserir um Novo Paciente\" Selecionada...\n\n");
                            while (1) {

                                espaco_livre = procura_espaco_livre(pacientes_ativos, QNTD_PACIENTES);
                                if(espaco_livre < 0) {
                                    printf("\nCadastro Impossível, Quantidade de Pacientes Cadastrados Cheia!\n");
                                    break;
                                }
                                
                                if(cadastra_nome_paciente(nomes_pacientes, espaco_livre, QNTD_PACIENTES)) {
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

                                cadastra_documento("RG", RG_pacientes[espaco_livre], espaco_livre);
                                if(procura_documento(RG_pacientes[espaco_livre], RG_pacientes, 12, espaco_livre)) { 
                                    printf("RG já cadastrado --> Impossível Inserir este Paciente!\n");
                                    
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


                                cadastra_documento("CPF", CPF_pacientes[espaco_livre], espaco_livre);
                                if(procura_documento(CPF_pacientes[espaco_livre], CPF_pacientes, 12, espaco_livre)) { 
                                    printf("CPF já cadastrado --> Impossível Inserir este Paciente!\n");
                                    
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

                                while (1) {
                                    printf("Digite o seu Tipo Sanguíneo (Sem o Fator RH) ou ENTER para pular:\n");
                                    printf("[1] A     [2] B     [3] AB     [4] O\n");  // dando erro porque a string e maior e eu to querendo colocar uma menor eu acho
                                    ler_str(tipo_sanguineo_pacientes[espaco_livre]);

                                    informacao_nao_obrigatoria = cadastro_informacao_nao_obrigatorio(tipo_sanguineo_pacientes[espaco_livre]);
                                    if(informacao_nao_obrigatoria) {
                                        break;
                                    }
                                    
                                    formatacao_incorreta = valida_tipo_sanguineo(tipo_sanguineo_pacientes[espaco_livre]);
                                    if(formatacao_incorreta) {
                                        printf("Tipo Sanguíneo Inválido, Digite Novamente!\n");
                                        continue;
                                    }
                                    break;
                                }

                                while(1) {
                                    printf("Digite o Fator RH do Paciente (Positivo ou Negativo) ou ENTER para pular:\n");
                                    printf("[1] Positivo     [2] Negativo\n");
                                    ler_str(fator_RH_pacientes[espaco_livre]);

                                    informacao_nao_obrigatoria = cadastro_informacao_nao_obrigatorio(fator_RH_pacientes[espaco_livre]);
                                    if(informacao_nao_obrigatoria) {
                                        break;
                                    }
                                        
                                    formatacao_incorreta = valida_fato_rh(fator_RH_pacientes[espaco_livre]);
                                    if(formatacao_incorreta) {
                                        printf("Fator RH Inválido, Digite Novamente!\n");
                                        continue;
                                    }
                                        break;
                                }

                                printf("Digite seu Endereço ou ENTER para pular:\n");
                                ler_str(endereco_pacientes[espaco_livre]);
                                informacao_nao_obrigatoria = cadastro_informacao_nao_obrigatorio(endereco_pacientes[espaco_livre]);

                                printf("Digite a Data de Nascimento do Paciente:\n");
                                receber_data(datas_nascimento_pacientes[espaco_livre], espaco_livre);

                                exibe_informacoes_paciente(nomes_pacientes, codigo_pacientes, RG_pacientes, CPF_pacientes, tipo_sanguineo_pacientes, fator_RH_pacientes, endereco_pacientes, datas_nascimento_pacientes, espaco_livre);

                                //nome dando erro ao errar uma vez

                                pacientes_ativos[espaco_livre] = 1;
                                
                                printf("\n[1] Incluir novo paciente   [2] Voltar ao Menu Pacientes\n");

                                opcao_selecionada = interacao_pos_erro();
                                
                                if(opcao_selecionada == '1') {
                                    printf("\nOpção -> [1], \"Incluir novo paciente\" Selecionada...\n\n"); 
                                    continue;
                                }
                                else {
                                    printf("\nOpção -> [2], \"Voltar ao Menu Pacientes\" Selecionada...\n\n"); 
                                    break;
                                }
                                
                            }
                            break;
                        case 2:
                            system("clear");
                            printf("\nOpção -> [2], \"Alterar um Paciente Existente\" Selecionada...\n\n");
                            //colocar um laço q percorra o vetor de ativos e se so tiver 0 falar q n tem ngm cadastrado

                            printf("Digite o Código do Paciente que Deseja Alterar: \n");

                            printf("-> Código: ");
                            char alterar_paciente_codigo[9];
                            scanf("%s", &alterar_paciente_codigo);

                            int index_paciente = procura_codigo(alterar_paciente_codigo,codigo_pacientes,QNTD_ATENDIMENTOS);

                            if(index_paciente >= 0) {
                                printf("Paciente de Código %s Encontrado\n", alterar_paciente_codigo);

                                printf("\nQual Informação Você deseja alterar?\n");
                                printf("[1] Nome     [2] RG     [3] CPF     [4] Tipo Sanguíneo     [5] Fator RH     [6] Endereço     [7] Data de Nascimento\n");
                                int alteracao_desejada;
                                scanf("%d", &alteracao_desejada);

                                switch (alteracao_desejada) {
                                    case 1:
                                        printf("\nOpção -> [1], \"Alterar Nome\" Selecionada...\n\n");

                                        char nome_antigo[255];
                                        strcpy(nome_antigo ,nomes_pacientes[index_paciente]);                               

                                        if(cadastra_nome_paciente(nomes_pacientes, index_paciente, QNTD_PACIENTES)) {
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
                                        printf("\nNome Alterado com Sucesso!\n");
                                        printf("De: %s ---> Para: %s", nome_antigo, nomes_pacientes[index_paciente]);

                                        break;
                                    case 2:
                                        printf("\nOpção -> [2], \"Alterar RG\" Selecionada...\n\n");
                                        
                                        char RG_antigo[12];
                                        strcpy(RG_antigo ,nomes_pacientes[index_paciente]); 

                                        cadastra_documento("RG", RG_pacientes[espaco_livre], espaco_livre);
                                        if(procura_documento(RG_pacientes[espaco_livre], RG_pacientes, 12, espaco_livre)) { 
                                            printf("RG já cadastrado --> Impossível Inserir este Paciente!\n");
                                            
                                            printf("\n[1] Inserir outro paciente [2] Ir para o Menu Pacientes\n");

                                            opcao_selecionada = interacao_pos_erro();
                                        }
                                        printf("RG Alterado com Sucesso!\n");
                                        printf("De: %s ---> Para: %s", RG_antigo, RG_pacientes[index_paciente]);

                                        break;
                                    case 3:
                                        printf("\nOpção -> [2], \"Alterar CPF\" Selecionada...\n\n");

                                        char CPF_antigo[12];
                                        strcpy(CPF_antigo ,CPF_pacientes[index_paciente]);

                                        cadastra_documento("CPF", CPF_pacientes[espaco_livre], espaco_livre);
                                        if(procura_documento(CPF_pacientes[espaco_livre], CPF_pacientes, 12, espaco_livre)) { 
                                            printf("CPF já cadastrado --> Impossível Inserir este Paciente!\n");
                                            
                                            printf("\n[1] Inserir outro paciente [2] Ir para o Menu Pacientes\n");

                                            opcao_selecionada = interacao_pos_erro();
                                        }
                                        printf("CPF Alterado com Sucesso!\n");
                                        printf("De: %s ---> Para: %s", CPF_antigo, CPF_antigo[index_paciente]);

                                        break;
                                    case 4:
                                        printf("\nOpção -> [2], \"Alterar Tipo Sanguíneo\" Selecionada...\n\n");
                                        break;

                                    default:
                                        break;
                                }  
                            }
                            else {
                                printf("Paciente de Código %s NÃO Encontrado Verifique o Código Inserido!", alterar_paciente_codigo);
                                // colocar opcao de inserri de volta ou voltar para o menu de pacientes
                            }
                            
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
                            printf("\n-----------------"BLUE"Inserir um Novo Atendimento"RESET"------------------\n");
                            while (1){
                                espaco_livre = procura_espaco_livre(atendimentos_ativos, QNTD_ATENDIMENTOS);
                                
                                int indice_paciente=procura_paciente(nomes_pacientes,QNTD_PACIENTES);
                                if( indice_paciente == -1)break;//saida da operacao
                                
                                paciente_do_atendimento[espaco_livre]=indice_paciente;
                                
                                receber_data(data_atendimentos,espaco_livre);
                                
                                int data_ja_cadastrada=atendimento_ja_cadastrado(data_atendimentos,paciente_do_atendimento,espaco_livre,QNTD_ATENDIMENTOS);
                                if(data_ja_cadastrada)continue;
                                
                                receber_tipo_atendimento(tipo_atendimentos,espaco_livre);

                                printf("Digite o preço da consulta:\n");
                                scanf("%f",&preco_atendimentos[espaco_livre]);//criar funcao ler preco.

                                receber_status_atendimento(status_atendimentos,espaco_livre);
                                
                                atendimentos_ativos[espaco_livre]=1;
                                cria_codigo(codigo_atendimentos,espaco_livre); 
                                
                                system("clear");
                                printf(GREEN"Atendimento Cadastrado com sucesso!\n"RESET);
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,espaco_livre);
                                
                                if(coletar_opcao("Voltar","Inserir outro Atendimento"))continue;
                                else break;
                            }
                            imprimir_vetor(data_atendimentos,QNTD_ATENDIMENTOS);
                            break;
                        case 2:
                            system("clear");
                            printf("\n----------------"BLUE"Alterar um Atendimento Existente"RESET"---------------\n");
                            int indice_do_paciente;
                            while(1){
                                printf("Digite o código do atendimento que deseja alterar:\n");
                                int indice_do_atendimento = procura_atendimento(codigo_atendimentos,QNTD_ATENDIMENTOS,atendimentos_ativos);
                                if(indice_do_atendimento == -1)continue;
                                
                                indice_do_paciente = paciente_do_atendimento[indice_do_atendimento];
                                
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,espaco_livre); 
                                int opcao;
                                
                                printf("Qual dado deseja alterar?\n");
                                printf(BLUE"[1]"RESET"Paciente "BLUE"[2] "RESET"Data "BLUE"[3] "RESET"Tipo "BLUE"[4]"RESET" Preço "BLUE"[5]"RESET"Status\n");
                                scanf("%d",&opcao);

                                switch(opcao){
                                    case 1: 
                                        printf("Paciente anterior : %s \n",nomes_pacientes[indice_do_paciente]);
                                        int indice_novo_paciente = procura_paciente(nomes_pacientes,QNTD_PACIENTES);

                                        paciente_do_atendimento[indice_do_atendimento]=indice_novo_paciente;
                                        printf(GREEN"Paciente alterado!\n"RESET);
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
                            printf("---------------------"BLUE"Excluir um Atendimento"RESET"-----------------------\n");
                            while(1){
                                printf("Digite o código do atendimento que deseja excluir:\n");
                                int indice_do_atendimento =procura_atendimento(codigo_atendimentos,QNTD_ATENDIMENTOS,atendimentos_ativos);
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
                            system("clear");
                            printf("---------------------"BLUE"Exibir Atendimento(Código)"RESET"-------------------\n");
                            while(1){
                                printf("Digite o código do atendimento que deseja consultar:\n");
                                int indice_do_atendimento=procura_atendimento(codigo_atendimentos,QNTD_ATENDIMENTOS,atendimentos_ativos);
                                indice_do_paciente = paciente_do_atendimento[indice_do_atendimento];
                                exibir_dados_atendimento(codigo_atendimentos,nomes_pacientes,codigo_pacientes,indice_do_paciente,data_atendimentos,tipo_atendimentos,preco_atendimentos,status_atendimentos,indice_do_atendimento);
                                
                                if(coletar_opcao("Voltar","Exibir outro Atendimento"))continue;
                                else break; 
                            }break;
                        case 5:
                            system("clear");
                            printf("----------------------"BLUE"Exibir Atendimento (Código do Paciente)"RESET"-----------------\n");
                            char codigo_paciente[8];
                            while(1){
                                
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
                            system("clear");
                            printf("-----------------------"BLUE"Exibir atendimento do paciente (Nome do Paciente)"RESET"------------------------\n");
                            char nome_paciente[255];
                            while(1){
                                printf("Digite o nome do Paciente que deseja exibir:\n");
                                int indice_do_paciente = procura_paciente(nomes_pacientes,QNTD_PACIENTES);
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