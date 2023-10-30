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

    system("cls");

    return interacao_menu_pacientes;
}


int opcoes_pacientes(int funcionalidade_selecionada) {
    switch (funcionalidade_selecionada) {
        case 1:
            printf("\nOpção -> [1], \"Inserir um Novo Paciente\" Selecionada...\n\n");
            return 1;
        case 2:
            printf("\nOpção -> [2], \"Alterar um Paciente Existente\" Selecionada...\n\n");
            return 2;
        case 3:
            printf("\nOpção -> [3], \"Excluir um Paciente\" Selecionada...\n\n");
            return 3;
        case 4:
            printf("\nOpção -> [4], \"Exibir os Dados de um Paciente pelo seu "
                   "Código\" Selecionada...\n\n");
            return 4;
        case 5:
            printf("\nOpção -> [5], \"Exibir os Dados de Pacientes que Apresentam o Mesmo"
                   " Tipo Sanguíneo\" Selecionada...\n\n");
            return 5;
        case 6:
            printf("\nOpção -> [6], \"Exibir os Dados de Pacientes pelo Dia de "
                   "Consulta\" Selecionada...\n\n");
            return 6;
        case 7:
            printf("\nOpção -> [7], \"Exibir Todos os Pacientes\" Selecionada...\n\n");
            return 7;
        case 8:
            printf("\nOpção -> [8], \"Exibir Todos os Pacientes em Ordem"
                   " Alfabética\" Selecionada...\n\n");
            return 8;
        case 9:
            printf("\nOpção -> [9], \"Voltar para o Menu Anterior\" Selecionada...\n\n");
            return 9;
        default:
            printf("\nSelecione alguma das opções anteriores!\n");
            return 10;
    }
}


int valida_tipo_sanguineo(char tipo_sanguineo[]) {
    int tipo_sanguineo_convertido = atoi(tipo_sanguineo);

    if(tipo_sanguineo_convertido < 1 || tipo_sanguineo_convertido > 4) {
        return 1;
    }
    else {
        switch (tipo_sanguineo_convertido) {
            case 1:
                strcpy(tipo_sanguineo, "A");
                break;
            
            case 2:
                strcpy(tipo_sanguineo, "B");
                break;

            case 3: 
                strcpy(tipo_sanguineo, "AB");
                break;
            default:
                strcpy(tipo_sanguineo, "O");
                break;
        }
        return 0;
    }
}


int valida_fato_rh(char fator_rh[]) {
    int fator_rh_convertido = atoi(fator_rh);

    if(fator_rh_convertido < 1 || fator_rh_convertido > 2) {
        return 1;
    }
    else {
        switch (fator_rh_convertido) {
            case 1:
                strcpy(fator_rh, "Positivo");
                break;
            default:
                strcpy(fator_rh, "Negativo");
        }

        return 0;
    }

}

int valida_documento(char documento[]) {
    int tamanho_documento = strlen(documento);

    if(tamanho_documento < 11 || tamanho_documento > 11) {
        return 1;
    }

    int eh_alfanumerico;
    for(int i  = 0; i < tamanho_documento; i++) {
        eh_alfanumerico = isdigit(documento[i]);
        if(!(eh_alfanumerico)) {
            return 1;
        }
        
    }

    return 0;
}


int cadastra_documento(char tipo_documento[], char str_documento[], int espaco_livre) {
    while(1) {
        printf("Digite o %s do Paciente", tipo_documento);

        int documento_nao_obrigatorio = !(strcmp(tipo_documento, "RG"));
        if(documento_nao_obrigatorio) {
            printf(" ou ENTER para pular:\n");
        }
        else {
            printf(":\n");
        }

        ler_str(str_documento);

        int enter_pressionado = cadastro_informacao_nao_obrigatorio(str_documento);
        if(documento_nao_obrigatorio && enter_pressionado) {
            return 1;
        }
    
        int documento_invalido = valida_documento(str_documento);
        if(documento_invalido) {
            printf("\n%s Inválido!\n", tipo_documento);
            continue;
        }

        break;
    }
}


int cadastro_informacao_nao_obrigatorio(char str_documento[]) {
        int documento_nao_obrigatorio_vazio = str_documento[0] == '\0';
        if(documento_nao_obrigatorio_vazio) {
            strcpy(str_documento, "Não Informado");
            return 1;
        }
}


int procura_documento(char documento_paciente[], char matriz_documento[][12], int tamanho_matriz, int indice_matriz) {  // igual a funcao "ja existe" mas com unm parametro diferente
        for(int i = 0; i < tamanho_matriz; i++){
            if(i == indice_matriz)
                continue;
            if(!(strcmp(documento_paciente, matriz_documento[i]))){
                return 1;
            }
    }
    
    return 0;
}

#endif