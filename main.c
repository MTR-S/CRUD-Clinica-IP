#include <stdio.h>

#include "pacientes.h"
#include "util.h"


#define QNTD_PACIENTES 100
#define QNTD_ATENDIMENTOS 100


int atividade_pacientes[QNTD_PACIENTES];

int codigo_pacientes[QNTD_PACIENTES];
char nomes_pacientes[QNTD_PACIENTES][255];
int RG_pacientes[QNTD_PACIENTES];
int CPF_pacientes[QNTD_PACIENTES];
char tipo_sanguineo_pacientes[QNTD_PACIENTES];
char fator_RH_pacientes[QNTD_PACIENTES];
char endereco_pacientes[QNTD_PACIENTES];
char datas_nascimento_pacientes[QNTD_PACIENTES];


int atividade_atendimentos[QNTD_ATENDIMENTOS];

int codigo_atendimentos[QNTD_ATENDIMENTOS];
char tipo_atendimentos[QNTD_ATENDIMENTOS];
char data_atendimentos[QNTD_ATENDIMENTOS];
char status_atendimentos[QNTD_ATENDIMENTOS];
int preco_atendimentos[QNTD_ATENDIMENTOS];

int main(void) {

    preenche_vetor_atividade(atividade_pacientes, QNTD_PACIENTES);
    preenche_vetor_atividade(atividade_atendimentos, QNTD_ATENDIMENTOS);

    while(1) {
        int interacao_menu_principal = menu_principal();

        switch (interacao_menu_principal) {
            case 1:
                printf("\nMenu \"Paciente\" Selecionado...\n");

                while(1) {
                    int interacao_menu_pacientes = menu_pacientes();
                    int interacao_pacientes_funcionalidades = pacientes_funcionalidades(interacao_menu_pacientes);
                    int retorno_procura_espaco_livre;

                    switch (interacao_pacientes_funcionalidades) {
                        case 1:
                            retorno_procura_espaco_livre = procura_espaco_livre(atividade_pacientes, QNTD_PACIENTES);

                            if(retorno_procura_espaco_livre >= 0) {

                                printf("Digite o Nome do Paciente:\n");
                                leitura_string(nomes_pacientes[retorno_procura_espaco_livre]);

                                formata_string_maisculo(nomes_pacientes[retorno_procura_espaco_livre]);

                                puts(nomes_pacientes[retorno_procura_espaco_livre]);
                                return 1;

                            }
                            else {
                                printf("\nCadastro Impossível, Quantidade de Pacientes Cadastrados Cheia!\n");
                                break;
                            }
                    }
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
        }
    }

    return 0;
}
