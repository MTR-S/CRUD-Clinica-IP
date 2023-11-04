#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include <stdio.h>

int menu_atendimento() {
    printf("\n-----------------------------"BLUE"MENU ATENDIMENTO"RESET"-----------------------------\n");
    printf("Selecione a funcionalidade que desejar: \n");
    printf(BLUE"\n[1]"RESET" Inserir um Novo Atendimento\n"BLUE"[2]"RESET" Alterar um Atendimento Existente");
    printf(BLUE"\n[3]"RESET" Excluir Atendimento\n"BLUE"[4]"RESET" Exibir Atendimento(Código)");
    printf(BLUE"\n[5]"RESET" Exibir Atendimentos de um Paciente(Código do Paciente)");
    printf(BLUE"\n[6]"RESET" Exibir Atendimentos de um Paciente(Nome do Paciente)\n"BLUE"[7]"RESET" Exibir Todos Atendimentos do Dia");
    printf(BLUE"\n[8]"RESET" Exibir Todos Atendimentos do Dia\n"BLUE"[8]"RESET" Voltar para o Menu Anterior\n");
    printf("\n---------------------------------------------------------------------------\n");

    printf("\nDigite a Funcionalidade Desejada: ");
    fflush(stdin);
    int opcao;
    scanf("%d", &opcao);

    return opcao;
}
void exibir_dados_atendimento(char codigo[][8],char paciente[][255],char codigo_paciente[][8],int indice_paciente,char data[][255],char tipo[][255],float preco[],char status[][255],int indice_atendimento){
    printf("Código------Paciente-----Código do Paciente-----Data-----------Tipo----------Preço---------Status--------\n");
    printf("%s   |   %s   |  %s   |   %s   |   %s   |   R$%.2f   |   %s  \n   ",codigo[indice_atendimento],paciente[indice_paciente],codigo_paciente[indice_paciente],data[indice_atendimento],tipo[indice_atendimento],preco[indice_atendimento],status[indice_atendimento]);
}
void receber_status_atendimento(char vetor_status_atendimentos[][255],int indice_do_atendimento){
    char opcao;
    printf("Status da consulta:\n");
    printf(BLUE"[1]"RESET"Agendado "BLUE"[2]"RESET"Esperando "BLUE"[3]"RESET"Em atendimento "BLUE"[4]"RESET"Atendido\n");
    __fpurge(stdin);  
    opcao=getchar();
    switch(opcao){
        case  '1':strcpy(vetor_status_atendimentos[indice_do_atendimento],"Agendado");break;
        case  '2':strcpy(vetor_status_atendimentos[indice_do_atendimento],"Esperando");break;
        case  '3':strcpy(vetor_status_atendimentos[indice_do_atendimento],"Em atendimento");break;
        case  '4':strcpy(vetor_status_atendimentos[indice_do_atendimento],"Atendido");break;
        case  '\0': strcpy(vetor_status_atendimentos[indice_do_atendimento],"Não Informado");break;
    }
}
int procura_paciente(char nomes_pacientes[][255],int tamanho){
    char nome[255];
    int indice_paciente;
    while(1){
        printf("Digite o Nome do Paciente: \n");
        ler_string(nome);
        formata_string_maisculo(nome);

        indice_paciente=procura_string(nome,nomes_pacientes,tamanho);
 
        if(nome == "SAIR")return -1;
        if(indice_paciente < 0){
            printf(RED"Paciente não cadastrado!\n"RESET);
            continue;
        }
        break;
    }
    return indice_paciente;
}
int procura_paciente_codigo(char codigo_pacientes[][8],int QNTD_PACIENTES,int pacientes_ativos[]){
    char codigo_paciente[8];
    ler_string(codigo_paciente);                            
    
    int indice_do_paciente = procura_codigo(codigo_paciente,codigo_pacientes,QNTD_PACIENTES);
    if(indice_do_paciente == -1){
        printf(RED"Paciente não cadastrado\n"RESET);
        return -1;
    }
    if(pacientes_ativos[indice_do_paciente]== 0){
        printf(RED"Paciente não cadastrado ou Excluido recentemente\n"RESET);
        return -1;
    }
    return indice_do_paciente;
}
int procura_atendimento(char codigo_atendimentos[][8],int QNTD_ATENDIMENTOS,int atendimentos_ativos[]){
    char codigo_atendimento[8];
    ler_string(codigo_atendimento);                            
    
    int indice_do_atendimento = procura_codigo(codigo_atendimento,codigo_atendimentos,QNTD_ATENDIMENTOS);
    if(indice_do_atendimento == -1){
        printf(RED"Atendimento não cadastrado\n"RESET);
        return -1;
    }
    if(atendimentos_ativos[indice_do_atendimento]== 0){
        printf(RED"Atendimento não cadastrado ou Excluido recentemente\n"RESET);
        return -1;
    }
    return indice_do_atendimento;
}

int atendimento_ja_cadastrado(char data_atendimentos[][255],int paciente_do_atendimento[],int atendimento_atual,int tamanho){
    int atendimento_ja_cadastrado=0;
    for(int i=0;i<tamanho;i++){
        if(i==atendimento_atual) continue;
        if(paciente_do_atendimento[i] == paciente_do_atendimento[atendimento_atual]){
            int data_paciente_igual= !(strcmp(data_atendimentos[i],data_atendimentos[atendimento_atual]));
            if(data_paciente_igual){
                printf(RED"Paciente ja tem atendimento nesta data!\n"RESET);
                atendimento_ja_cadastrado=1;
            }
        }

    }return atendimento_ja_cadastrado;
}
void receber_tipo_atendimento(char tipo_atendimentos[][255],int espaco_livre){
    
    printf("Tipo de Atendimento:\n");
    int opcao=coletar_opcao("Consulta","Retorno");
    
    if(opcao) strcpy(tipo_atendimentos[espaco_livre],"Retorno") ;
    else strcpy(tipo_atendimentos[espaco_livre],"Consulta");
}
float receber_preco(){
    float preco;
    while(1){
        printf("Digite o preço da consulta:\n");
        scanf("%f",&preco);
        if(preco<0){
            printf("Digite o preço Corretamente!");
            continue;
        }
        break;
    }return preco;
}
int compara_data(char data1[],char data2[]) {
    
    int dia1, mes1, ano1, dia2, mes2, ano2;

    sscanf(data1, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(data2, "%d/%d/%d", &dia2, &mes2, &ano2);

    if (ano1 > ano2) {
        return 1;
    } else if (ano1 < ano2) {
        return 0;
    } else {
        if (mes1 > mes2) {
            return 1;
        } else if (mes1 < mes2) {
            return 0;
        } else {
            if (dia1 > dia2) {
                return 1;
            } else if (dia1 < dia2) {
                return 0;
            } else {
                return 0; // As datas são iguais
            }
        }
    }
}
void ordenar_datas(char datas[][255],int ordem_datas[],int tamanho,int atendimentos_ativos[]){
    for (int i = 0; i < tamanho; i++) {
        ordem_datas[i] = i;
    }
    for (int i = 0; i < tamanho - 1; i++) {
        if(atendimentos_ativos[i]==0) continue;
        for (int j = i + 1; j < tamanho; j++) {
            if(atendimentos_ativos[j]==0) continue;
            if (compara_data(datas[ordem_datas[j]], datas[ordem_datas[i]])) {
                int aux = ordem_datas[i];
                ordem_datas[i] = ordem_datas[j];
                ordem_datas[j] = aux;
            }
        }
    }
}
#endif