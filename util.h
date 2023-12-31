#ifndef UTIL_H
#define UTIL_H

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CIANO   "\x1b[36m"
#define RESET   "\x1b[0m"


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "atendimentos.h"
#include "pacientes.h"


int menu_principal();
int coletar_opcao(char opcao1[],char opcao2[]);
int preenche_vetor_ativos(int vetor_ativos[], int tamanho_vetor);
int preenche_matriz_bidimensional(char vetor_ativos[][40], int tamanho_vetor);
void ler_str(char string[]);
int checar_string(char string[]);
void formata_string_maisculo(char string[]);
int ja_existe(char string[],char vetor[][40],int tamanho,int indice);
int procura_string(char string[],char vetor[][40],int tamanho);
int procura_codigo(char codigo_unico_paciente[],char matriz_codigos_pacientes[][8],int tamanho_matriz);
int procura_espaco_livre(int vetor_ativos[], int tamanho_vetor);
void receber_data(char vetor[][40],int indice_livre);

void imprimir_vetor(char vetor[][40],int tamanho);
void cria_codigo(char vetor[][8],int indice_livre);
float soma_consultas_pagas_pacientes(char nome_paciente_desejado[], char matriz_nomes_paciente[][40], float vetor_preco_atendimentos[], int tamanho_vetores, int vetor_paciente_atendimento_indice[]);
void copia_matriz(char matriz1[][40], char matriz2[][40], int tamanho);
int varrer_datas(char data[][40], char matriz_datas_atendimentos_copia[][40], int tam_matriz_datas_atendimentos);
#endif
