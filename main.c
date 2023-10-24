#include <stdio.h>

#include "pacientes.h"
#include "atendimento.h"
#include "util.h"

#define QNTD_PACIENTES 100
#define QNTD_ATENDIMENTOS 100


int pacientes_ativos[QNTD_PACIENTES];

int codigo_pacientes[QNTD_PACIENTES];  
char nomes_pacientes[QNTD_PACIENTES][255];
char RG_pacientes[QNTD_PACIENTES][10]; 
char CPF_pacientes[QNTD_PACIENTES][12];
char tipo_sanguineo_pacientes[QNTD_PACIENTES][3];
char fator_RH_pacientes[QNTD_PACIENTES][25];  
char endereco_pacientes[QNTD_PACIENTES][255];
int datas_nascimento_pacientes[QNTD_PACIENTES];


int atendimentos_ativos[QNTD_ATENDIMENTOS];

int codigo_atendimentos[QNTD_ATENDIMENTOS];
char tipo_atendimentos[QNTD_ATENDIMENTOS][255];  // int?
char data_atendimentos[QNTD_ATENDIMENTOS][9];
char status_atendimentos[QNTD_ATENDIMENTOS][255];  //int?
int preco_atendimentos[QNTD_ATENDIMENTOS];

int main(void) {
    preenche_matriz_bidimensional(nomes_pacientes,QNTD_PACIENTES); 
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
                                //system("clear");
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
                                
                                int codigo_paciente = gera_codigo();
                                armazena_codigo_aleatorio(codigo_paciente, codigo_pacientes, espaco_livre);

                                printf("-> Paciente cadastrado!\n");
                                printf("Nome: %s\n", nomes_pacientes[espaco_livre]);
                                printf("Código do Paciente: %d\n", codigo_pacientes[espaco_livre]);

                                pacientes_ativos[espaco_livre] = 1;
                            
                                int opcao;
                                printf("[0] Voltar   [1]Incluir novo paciente\n");
                                scanf("%d", &opcao);
                                if(opcao)
                                    continue;                            
                                
                                break;
                            }
                        case 2:
                            system("cls");
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
                        default:
                            printf("\nSelecione alguma das opções anteriores!\n");
                    }   
                }continue;
            case 2:
                system("clear");
                printf("\nMenu \"Atendimento\" Selecionado...\n");
                while(1) {
                    int interacao_menu_atendimentos = menu_atendimento();
                    int espaco_livre;

                    switch (interacao_menu_atendimentos) {
                        case 1:
                            system("clear");
                            printf("\nOpção -> [1], \"Inserir um Novo Paciente\" Selecionada...\n\n"); 
                        case 2:
                            system("cls");
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
                            continue;
                    }
                }continue;
            case 3:
                printf("\nSaída do Sistema Confirmada!\n");
                return 0;
            default:
                printf("Selecione alguma das opções anteriores!\n");
                continue;;
        }break;
    }

    return 0;
}
