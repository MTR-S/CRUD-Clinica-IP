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


int preenche_vetor_ativos(int vetor_ativos[], int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; ++i)
        vetor_ativos[i] = 0;
}


int procura_espaco_livre(int vetor_ativos[], int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; ++i) {

        if(!vetor_ativos[i]) {
            return i;
        }
    }
    return -1;
}


void ler_string(char string[]) {
    fflush(stdin);
    gets(string);
    fflush(stdin);
    gets(string);
}

int checar_string(char string[]){
    if (string == NULL || string[0] =='\0'){
        return 1;
    }
    for(int i = 0;string[i] != '\0';i++){
        if(string[i] == ' '){
            continue;
        }
        if(isdigit(string[i])||!isalnum(string[i])){
          return 1;  
        }
    }return 0;
}

void formata_string_maisculo(char string[]) {
    int string_tamanho = strlen(string);

    for (int i = 0; i < string_tamanho; ++i)
        string[i] = toupper(string[i]);
}

int ja_existe(char string[], char vetor[],  int tamanho){
    for(int i =0; i<tamanho;i++){
        if(!strcmp(vetor[i],string)){
            return 1;
        }
    }return 0;
}

#endif