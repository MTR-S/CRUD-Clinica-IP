#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include <stdio.h>

int menu_atendimento() {
    printf("\n-----------------------------"BLUE"MENU ATENDIMENTO"RESET"-----------------------------\n");
    printf("Selecione a funcionalidade que desejar: \n");
    printf(BLUE"\n[1]"RESET" Inserir um Novo Atendimento\n"BLUE"[2]"RESET" Alterar um Atendimento Existente");
    printf(BLUE"\n[3]"RESET" Excluir Atendimento\n"BLUE"[4]"RESET" Exibir Atendimento(Código)");
    printf(BLUE"\n[5]"RESET" Exibir Atendimentos de um Paciente(Código do Paciente)");
    printf(BLUE"\n[6]"RESET" Exibir Atendimentos de um Paciente(Nome do Paciente)\n"BLUE"[7]"RESET" Exibir Todos Atendimentos(Ordenado pela data)");
    printf(BLUE"\n[8]"RESET" Voltar para o Menu Anterior");
    printf("\n---------------------------------------------------------------------------\n");

    printf("\nDigite a Funcionalidade Desejada: ");
    fflush(stdin);
    int opcao;
    scanf("%d", &opcao);

    return opcao;
}
void exibir_dados_atendimento(char codigo[][8],char paciente[][255],char codigo_paciente[][8],int indice_paciente,char data[][255],char tipo[][255],float preco[],char status[][255],int indice_atendimento){
    printf("Código--------Paciente------Código do Paciente-----Data-----------Tipo----------Preço---------Status--------\n");
    printf("%s   |   %s   |  %s   |   %s   |   %s   |   R$%.2f   |   %s  \n   ",codigo[indice_atendimento],paciente[indice_paciente],codigo_paciente[indice_paciente],data[indice_atendimento],tipo[indice_atendimento],preco[indice_atendimento],status[indice_atendimento]);
}
void receber_status_atendimento(char vetor_status_atendimentos[][255],int indice_do_atendimento){
    int opcao;
    printf("Status da consulta:\n");
    printf("[0]Agendado [1]Esperando [2]Em atendimento [3]Atendido\n");
    scanf("%d",&opcao);
    switch(opcao){
        case 0:strcpy(vetor_status_atendimentos[indice_do_atendimento],"Agendado");break;
        case 1:strcpy(vetor_status_atendimentos[indice_do_atendimento],"Esperando");break;
        case 2:strcpy(vetor_status_atendimentos[indice_do_atendimento],"Em atendimento");break;
        case 3:strcpy(vetor_status_atendimentos[indice_do_atendimento],"Atendido");break;
    }
}

#endif