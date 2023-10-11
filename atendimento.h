#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include <stdio.h>

int menu_atendimento() {
    printf("\n-----------------------------MENU ATENDIMENTO-----------------------------\n");
    printf("Selecione a funcionalidade que desejar: \n");
    printf("\n[1] Inserir um Novo Atendimento\n[2] Alterar um Paciente Existente");
    printf("\n[3] Excluir um Paciente\n[4] Exibir os Dados de um Paciente pelo seu Código");
    printf("\n[5] Exibir os Dados de Pacientes que Apresentam o Mesmo Tipo Sanguíneo");
    printf("\n[6] Exibir os Dados de Pacientes pelo Dia de Consulta\n[7] Exibir Todos os Pacientes");
    printf("\n[8]Exibir Todos os Pacientes em Ordem Alfabética\n[9]Voltar para o Menu Anterior");
    printf("\n---------------------------------------------------------------------------\n");

    printf("\n\nDigite o Número Correlacionado a Funcionalidade Desejada: ");
    fflush(stdin);
    int interacao_menu_pacientes;
    scanf("%d", &interacao_menu_pacientes);

    return interacao_menu_pacientes;
}


#endif