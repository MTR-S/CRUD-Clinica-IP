#ifndef PACIENTES_H
#define PACIENTES_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "util.h"


int menu_pacientes() {
    printf("\n-----------------------------MENU PACIENTES-----------------------------\n");
    printf("Selecione a funcionalidade que desejar: \n");
    printf("\n[1] Inserir um Novo Paciente\n[2] Alterar um Paciente Existente");
    printf("\n[3] Excluir um Paciente\n[4] Exibir os Dados de um Paciente pelo seu Código");
    printf("\n[5] Exibir os Dados de Pacientes que Apresentam o Mesmo Tipo Sanguíneo");
    printf("\n[6] Exibir os Dados de Pacientes pelo Dia de Consulta\n[7] Exibir Todos os Pacientes");
    printf("\n[8]Exibir Todos os Pacientes em Ordem Alfabética\n[9]Voltar para o Menu Anterior");
    printf("\n------------------------------------------------------------------------\n");

    printf("\n\nDigite o Número Correlacionado a Funcionalidade Desejada: ");
    fflush(stdin);
    int interacao_menu_pacientes;
    scanf("%d", &interacao_menu_pacientes);

    return interacao_menu_pacientes;
}


int pacientes_funcionalidades(int funcionalidade_selecionada) {
    switch (funcionalidade_selecionada) {
        case 1:
            printf("\nOpcção -> [1], \"Inserir um Novo Paciente\" Selecionada...\n\n");
            return 1;
        case 2:
            printf("\nOpcção -> [2], \"Alterar um Paciente Existente\" Selecionada...\n\n");
            return 2;
        case 3:
            printf("\nOpcção -> [3], \"Excluir um Paciente\" Selecionada...\n\n");
            return 3;
        case 4:
            printf("\nOpcção -> [4], \"Exibir os Dados de um Paciente pelo seu "
                   "Código\" Selecionada...\n\n");
            return 4;
        case 5:
            printf("\nOpcção -> [5], \"Exibir os Dados de Pacientes que Apresentam o Mesmo"
                   " Tipo Sanguíneo\" Selecionada...\n\n");
            return 5;
        case 6:
            printf("\nOpcção -> [6], \"Exibir os Dados de Pacientes pelo Dia de "
                   "Consulta\" Selecionada...\n\n");
            return 6;
        case 7:
            printf("\nOpcção -> [7], \"Exibir Todos os Pacientes\" Selecionada...\n\n");
            return 7;
        case 8:
            printf("\nOpcção -> [8], \"Exibir Todos os Pacientes em Ordem"
                   " Alfabética\" Selecionada...\n\n");
            return 8;
        case 9:
            printf("\nOpcção -> [9], \"Voltar para o Menu Anterior\" Selecionada...\n\n");
            return 9;
        default:
            printf("\nSelecione alguma das opções anteriores!\n");
            return 10;
    }
}


#endif