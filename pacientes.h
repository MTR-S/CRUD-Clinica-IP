#ifndef PACIENTES_H
#define PACIENTES_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "util.h"


int menu_pacientes() {
    printf("\n-----------------------------"BLUE"MENU PACIENTES"RESET"-----------------------------\n");
    printf(YELLOW"Selecione a funcionalidade que desejar: \n"RESET);
    printf("\n"BLUE"[1]"RESET" Inserir um Novo Paciente\n"BLUE"[2]"RESET" Alterar um Paciente Existente");
    printf("\n"BLUE"[3]"RESET" Excluir um Paciente\n"BLUE"[4]"RESET" Exibir os Dados de um Paciente pelo seu Código");
    printf("\n"BLUE"[5]"RESET" Exibir os Dados de Pacientes que Apresentam o Mesmo Tipo Sanguíneo");
    printf("\n"BLUE"[6]"RESET" Exibir os Dados de Pacientes pelo Dia de Consulta\n"BLUE"[7]"RESET" Exibir Todos os Pacientes");
    printf("\n"BLUE"[8]"RESET"Exibir Todos os Pacientes em Ordem Alfabética\n"BLUE"[9]"RESET"Voltar para o Menu Anterior");
    printf("\n------------------------------------------------------------------------\n");

    printf(YELLOW"\n\nDigite o Número Correlacionado a Funcionalidade Desejada: "RESET);
    fflush(stdin);
    int interacao_menu_pacientes;
    scanf("%d", &interacao_menu_pacientes);

    system("clear");

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


void exibe_informacoes_paciente(char nomes_pacientes[][255], char codigo_pacientes[][8], char RG_pacientes[][12], char CPF_pacientes[][12], char tipo_sanguineo_pacientes[][3], char fator_RH_pacientes[][9], char endereco_pacientes[][255], char datas_nascimento_pacientes[][255], int espaco_livre) {
    printf("\n-----------"GREEN"Paciente"RESET"-----------\n");
    printf("-> "BLUE"Nome:"RESET" "GREEN"%s\n"RESET, &nomes_pacientes[espaco_livre]);
    printf("-> "BLUE"Código do Paciente:"RESET" "GREEN"%s\n"RESET, &codigo_pacientes[espaco_livre]);
    printf("-> "BLUE"RG do Paciente:"RESET" "GREEN"%s\n"RESET, &RG_pacientes[espaco_livre]);
    printf("-> "BLUE"CPF do Paciente:"RESET" "GREEN"%s\n"RESET, &CPF_pacientes[espaco_livre]);
    printf("-> "BLUE"Tipo Sanguíneo do Paciente:"RESET" "GREEN"%s\n"RESET, &tipo_sanguineo_pacientes[espaco_livre]);
    printf("-> "BLUE"Fator RH  do Paciente:"RESET" "GREEN"%s\n"RESET, &fator_RH_pacientes[espaco_livre]);
    printf("-> "BLUE"Endereço do Paciente:"RESET" "GREEN"%s\n"RESET, &endereco_pacientes[espaco_livre]);
    printf("-> "BLUE"Data de Nascimento do Paciente:"RESET GREEN"%s\n"RESET, &datas_nascimento_pacientes[espaco_livre]);
    printf("--------------------------------------------\n");

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
            printf(" ou ENTER para Não Informar:\n");
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
    
    return 0;
}


int cadastro_informacao_nao_obrigatorio(char str_documento[]) {
        int documento_nao_obrigatorio_vazio = str_documento[0] == '\0';
        if(documento_nao_obrigatorio_vazio) {
            strcpy(str_documento, "Não Informado");
            return 1;
        }
}


int procura_informacao(char informacao_paciente[], char matriz_informacao_paciente[][12], int tamanho_matriz, int indice_matriz) {  
        for(int i = 0; i < tamanho_matriz; i++){
            if(i == indice_matriz)
                continue;
            if(!(strcmp(informacao_paciente, matriz_informacao_paciente[i]))){
                return 1;
            }
    }
    
    return 0;
}


int cadastra_nome_paciente(char matriz_nomes_pacientes[][255],int espaco_livre, int QNTD_PACIENTES) {
    while(1) {
        printf("Digite o Nome do Paciente:\n");
        ler_str(matriz_nomes_pacientes[espaco_livre]);
        
        int nome_incorreto = checar_string(matriz_nomes_pacientes[espaco_livre]);
        if(nome_incorreto) {
            printf("Digite o nome corretamente!\n");
            continue;
        }

        formata_string_maisculo(matriz_nomes_pacientes[espaco_livre]);
        
        int ja_cadastrado = ja_existe(matriz_nomes_pacientes[espaco_livre], matriz_nomes_pacientes,QNTD_PACIENTES,espaco_livre);
        if(ja_cadastrado) { 
            printf("Paciente já cadastrado!\n");
            return 1;
        }

        break;
    }

    return 0;
}


void exibe_tipo_sanguineo_pacientes(char tipo_sanguineo[], char matriz_tipo_sanguineo[][3], char matriz_fator_RH[][9], int tam_matriz_tp_sanguineo,char matriz_pacientes[][255]) {

    printf("Tipo Selecionado %s:\n", tipo_sanguineo);

    printf("\n--------------------------Grupo %s-----------------------\n", tipo_sanguineo);
    printf("---> %s Positivo\n", tipo_sanguineo);
    busca_tipo_sanguineo(tam_matriz_tp_sanguineo, tipo_sanguineo, matriz_tipo_sanguineo, matriz_fator_RH, "Positivo", matriz_pacientes);
    printf("\n---------------------------------------------------------");
    printf("\n---> %s Negativo\n", tipo_sanguineo);
    busca_tipo_sanguineo(tam_matriz_tp_sanguineo, tipo_sanguineo, matriz_tipo_sanguineo, matriz_fator_RH, "Negativo", matriz_pacientes);
}


void busca_tipo_sanguineo(int tam_matriz_tp_sanguineo, char tipo_sanguineo[], char matriz_tipo_sanguineo[][3], char matriz_fator_RH[][9], char fator_rh_escolhido[] ,char matriz_pacientes[][255]) {
        int contador = 0;

        for(int i = 0; i < tam_matriz_tp_sanguineo; i++) {
            if(!(strcmp(tipo_sanguineo, matriz_tipo_sanguineo[i])) && !strcmp(fator_rh_escolhido, matriz_fator_RH[i])) {
                printf("-> Paciente: %s\n", matriz_pacientes[i]);
                contador++;
            }
        }

        if(!contador) {
            printf("Sem Pacientes!\n");
        }
}


//sonambulo
#endif