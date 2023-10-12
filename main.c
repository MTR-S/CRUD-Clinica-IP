#include <stdio.h>

#include "pacientes.h"
#include "util.h"
//oi

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
                                puts(nomes_pacientes[espaco_livre]);
                                break;
                            };      
                            
                            formata_string_maisculo(nomes_pacientes[espaco_livre]);
                            
                            printf("Paciente %s cadastrado!",nomes_pacientes[espaco_livre]);
                            pacientes_ativos[espaco_livre]=1;
                            
                            break;
                        case 2:
                            system("cls");
                            printf("\nOpção -> [2], \"Alterar um Paciente Existente\" Selecionada...\n\n");

                    }continue;
                }
                break;
            case 2:
                printf("\nMenu \"Atendimento\" Selecionado...\n");
                break;
            case 3:
                printf("\nSaída do Sistema Confirmada!\n");
                return 0;
            default:
                printf("Selecione alguma das opções anteriores!\n");
                break;
        }break;
    }

    return 0;
}
