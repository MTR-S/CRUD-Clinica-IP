#ifndef UTIL_H
#define UTIL_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


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

    system("cls");

    return interacao_menu_pacientes;
}


int preenche_vetor_ativos(int vetor_ativos[], int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; i++)
        vetor_ativos[i] = 0;
}


int preenche_matriz_bidimensional(char vetor_ativos[][255], int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; i++)
        strcpy(vetor_ativos[i], "VOID");}


int procura_espaco_livre(int vetor_ativos[], int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; i++) {

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

int ja_existe(char string[],char vetor[][255],int tamanho,int indice){
    for(int i = 0; i < tamanho; i++){
        if(i == indice)
            continue;
        if(strcmp(string,vetor[i]) == 0){
            return 1;
        }
    }return 0;
}
int procura_string(char string[],char vetor[][255],int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(strcmp(string,vetor[i]) == 0){
            return i;
        }
    }return -1;
}
int procura_codigo(char codigo[],char vetor[][8],int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(strcmp(vetor[i],codigo) == 0){
            return i;
        }
    }return -1;
}
void receber_data(char vetor[][255],int indice_livre){
    int dia, mes, ano;
    while(1){
        printf("Digite o dia: ");
        scanf("%d", &dia);

        printf("Digite o mês: ");
        scanf("%d", &mes);

        printf("Digite o ano (ex. 2023): ");
        scanf("%d", &ano);
        
        if (!(dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0)){
        printf("Data inválida!\n");
        continue;
        }
        sprintf(vetor[indice_livre],"%d/%d/%d",dia,mes,ano);
        break;
    }

}

void imprimir_vetor(char vetor[][255],int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("%d - %s\n",i,vetor[i]);
    }
}


int gera_codigo() {  // 5 Digitos
    srand(time(NULL));

    int num_aleatorio = rand() + rand();

    return num_aleatorio;
}
void cria_codigo(char vetor[][8],int indice_livre){
    char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";//36 caracteres

    srand(time(NULL));

    for (int i = 0; i < 8; i++) {
        int indice_aleatorio = rand() % 36;
        vetor[indice_livre][i] = caracteres[indice_aleatorio];
    }
}
void armazena_codigo_aleatorio(int codigo_unico, int matriz_codigos[], int espaco_livre) {
    matriz_codigos[espaco_livre] = codigo_unico;
}

#endif