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
    int opcao;
    scanf("%d", &opcao);

    return opcao;
}
void exibir_dados_atendimento(char codigo[][8],char paciente[][255],int indice_paciente,char data[][255],char tipo[][255],float preco[],char status[][255],int indice_atendimento){
    printf("Código--------Paciente--------Data---------Tipo---------Preço--------Status--------\n");
    printf("%s   |   %s   |   %s   |   %s   |   R$%.2f   |   %s\n   ",codigo[indice_atendimento],paciente[indice_paciente],data[indice_atendimento],tipo[indice_atendimento],preco[indice_atendimento],status[indice_atendimento]);
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