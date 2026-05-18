#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pilha.h"

Pilha* push(Pilha* topo, Paciente* p){

    if(p == NULL){
        return topo;
    }

    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));

    if(novo == NULL){
        printf("Erro de memoria.\n");
        return topo;
    }

    Paciente* copia = (Paciente*) malloc(sizeof(Paciente));

    if(copia == NULL){
        free(novo);
        return topo;
    }

    copia->id = p->id;

    copia->nome = (char*) malloc(strlen(p->nome) + 1);

    strcpy(copia->nome, p->nome);

    copia->prox = NULL;
    copia->ant = NULL;

    novo->paciente = copia;

    novo->prox = topo;

    topo = novo;

    printf("Paciente salvo no historico.\n");

    return topo;
}

Pilha* pop(Pilha* topo){

    if(topo == NULL){

        printf("Pilha vazia.\n");
        return NULL;
    }

    Pilha* temp = topo;

    printf("\nUltimo atendimento removido:\n");

    printf("ID: %d\n", temp->paciente->id);
    printf("Nome: %s\n", temp->paciente->nome);

    topo = topo->prox;

    free(temp->paciente->nome);
    free(temp->paciente);
    free(temp);

    return topo;
}

void mostrar_pilha(Pilha* topo){

    if(topo == NULL){

        printf("Historico vazio.\n");
        return;
    }

    Pilha* atual = topo;

    printf("\n======= HISTORICO =======\n");

    while(atual != NULL){

        printf("ID: %d | Nome: %s\n",
               atual->paciente->id,
               atual->paciente->nome);

        atual = atual->prox;
    }
}

Pilha* liberar_pilha(Pilha* topo){

    while(topo != NULL){

        Pilha* temp = topo;

        topo = topo->prox;

        free(temp->paciente->nome);
        free(temp->paciente);
        free(temp);
    }

    printf("Historico apagado.\n");

    return NULL;
}