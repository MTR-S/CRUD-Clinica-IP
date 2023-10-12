#include <stdio.h>

#include "pacientes.h"
#include "atendimento.h"
#include "util.h"

#define QNTD_PACIENTES 100
#define QNTD_ATENDIMENTOS 100


int pacientes_ativos[QNTD_PACIENTES];

int codigo_pacientes[QNTD_PACIENTES];
char nomes_pacientes[QNTD_PACIENTES][255];
int RG_pacientes[QNTD_PACIENTES];
int CPF_pacientes[QNTD_PACIENTES];
char tipo_sanguineo_pacientes[QNTD_PACIENTES];
char fator_RH_pacientes[QNTD_PACIENTES];
char endereco_pacientes[QNTD_PACIENTES];
char datas_nascimento_pacientes[QNTD_PACIENTES];


int atendimentos_ativos[QNTD_ATENDIMENTOS];

int codigo_atendimentos[QNTD_ATENDIMENTOS];
char tipo_atendimentos[QNTD_ATENDIMENTOS];
char data_atendimentos[QNTD_ATENDIMENTOS];
char status_atendimentos[QNTD_ATENDIMENTOS];
int preco_atendimentos[QNTD_ATENDIMENTOS];

int main(void) {

    preenche_vetor_ativos(pacientes_ativos, QNTD_PACIENTES);
    preenche_vetor_ativos(atendimentos_ativos, QNTD_ATENDIMENTOS);
    fflush(stdin);
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
                            system("clear");
                            printf("\nOpção -> [1], \"Inserir um Novo Paciente\" Selecionada...\n\n");
                            espaco_livre = procura_espaco_livre(pacientes_ativos, QNTD_PACIENTES);

                            if(espaco_livre < 0) {
                                printf("\nCadastro Impossível, Quantidade de Pacientes Cadastrados Cheia!\n");
                                continue;//vss dps
                            }
                            while (1){
                                printf("Digite o Nome do Paciente:\n");
                                ler_string(nomes_pacientes[espaco_livre]);
                                
                                if(checar_string(nomes_pacientes[espaco_livre])){
                                    printf("Digite o nome corretamente!\n");
                                    continue;
                                }
                                formata_string_maisculo(nomes_pacientes[espaco_livre]);
                                int novopaciente[255];

                                if(ja_existe(novopaciente,nomes_pacientes[],QNTD_PACIENTES)) 
                                printf("Paciente já cadastrado!");
                                continue;
                                break;
                            };      
                            
                            
                            
                            printf("Paciente %s cadastrado!",nomes_pacientes[espaco_livre]);
                            pacientes_ativos[espaco_livre]=1;
                            break;

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
                    int interacao_menu_atendimentos = menu_atendimentos();
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
