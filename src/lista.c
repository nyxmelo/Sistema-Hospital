#include<stdio.h>
#include<stdlib.h>
#include "../include/lista.h"


Paciente* listapaciente_cria(){
    return NULL;
};

Paciente* inserir_paciente(Paciente* p){
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));

    int id;
    char* nome;
    printf("Digite o id do paciente: \n");
    scanf("%d", &id);
    printf("Digite o nome do paciente: \n");
    scanf("%s", &nome);

    if (novo == NULL){
        printf("Erro de memoria\n");
        return p;
    }

    novo->id = id;

    novo->nome = (char*) malloc(sizeof(nome) + 1);
    if (novo->nome == NULL){
        printf("Erro de memoria\n");
        free(novo);
        return p;
    }

    strcpy(novo->nome, nome);
    novo->prox = p;
    if(p != NULL){
       p->ant = novo; 
    }
    return novo;
}

Paciente* pesquisar_paciente(Paciente* p, int id){
    Paciente* q;
    if (p == NULL) {
        printf("Nenhum paciente registrado");
    } else{
    while(q->id != id){
        q = q->prox;
    }
}
    if(q != NULL){
        printf("Paciente encontrado ");
    }
    return q;
}