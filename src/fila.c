#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/fila.h"

Fila* criar_fila(){

    Fila* f = (Fila*) malloc(sizeof(Fila));

    if(f == NULL){
        printf("Erro de memoria.\n");
        return NULL;
    }

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

void enfileirar(Fila* f, Paciente* p){

    if(p == NULL){
        printf("Paciente invalido.\n");
        return;
    }

    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));

    if(novo == NULL){
        printf("Erro de memoria.\n");
        return;
    }

    novo->id = p->id;

    novo->nome = (char*) malloc(strlen(p->nome) + 1);

    strcpy(novo->nome, p->nome);

    novo->prox = NULL;
    novo->ant = NULL;

    if(f->inicio == NULL){

        f->inicio = novo;
        f->fim = novo;

    } else {

        f->fim->prox = novo;
        novo->ant = f->fim;
        f->fim = novo;
    }

    printf("Paciente adicionado na fila.\n");
}

Paciente* desenfileirar(Fila* f){

    if(f->inicio == NULL){
        printf("Fila vazia.\n");
        return NULL;
    }

    Paciente* removido = f->inicio;

    f->inicio = removido->prox;

    if(f->inicio != NULL){
        f->inicio->ant = NULL;
    } else {
        f->fim = NULL;
    }

    printf("\nPaciente atendido:\n");
    printf("ID: %d\n", removido->id);
    printf("Nome: %s\n", removido->nome);

    return removido;
}

void mostrar_fila(Fila* f){

    if(f->inicio == NULL){

        printf("Fila vazia.\n");
        return;
    }

    Paciente* atual = f->inicio;

    printf("\n===== FILA DE ATENDIMENTO =====\n");

    while(atual != NULL){

        printf("ID: %d | Nome: %s\n", atual->id, atual->nome);

        atual = atual->prox;
    }
}

void liberar_fila(Fila* f){

    Paciente* atual = f->inicio;

    while(atual != NULL){

        Paciente* temp = atual;

        atual = atual->prox;

        free(temp->nome);
        free(temp);
    }

    free(f);

    printf("Fila apagada.\n");
}