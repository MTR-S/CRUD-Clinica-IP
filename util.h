#ifndef UTIL_H
#define UTIL_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int menu_principal() {
    printf("\n******************************************\n");
    printf("\n*Seja Muito Bem vindo(a) a Clinica Fatima*\n");
    printf("\n******************************************\n");

    printf("\nSelecione como você deseja acessar nosso sistema: \n");
    printf("--> [1] Paciente");
    printf(" \t--> [2] Atendimento\t");
    printf("\t--> [3] Encerrar\n");

    fflush(stdin);
    int interacao_menu_pacientes;
    scanf("%d", &interacao_menu_pacientes);

    //adicionar o  "system("cls")"

    return interacao_menu_pacientes;
}


int preenche_vetor_atividade(int vetor_atividade[], int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; ++i)
        vetor_atividade[i] = 0;
}


int procura_espaco_livre(int vetor_atividade[], int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; ++i) {

        if(!vetor_atividade[i]) {
            return i;
        }
    }
    return -1;
}


void leitura_string(char string[]) {
    fflush(stdin);
    gets(string);
}


void formata_string_maisculo(char string[]) {
    int string_tamanho = strlen(string);

    for (int i = 0; i < string_tamanho; ++i)
        string[i] = toupper(string[i]);
}


#endif