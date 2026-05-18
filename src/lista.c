#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "../include/lista.h"


Paciente* inserir_paciente(Paciente* p){
    Paciente* q = p;
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));
    if (novo == NULL){
        printf("Erro de memoria\n");
        return p;
    }

    int id;
    char buffer_nome[100];

    
    printf("Digite o id do paciente: \n");
    scanf("%d", &id);
    
    while(q != NULL) {
        if(q->id == id) {
            printf("Erro: ID %d ja cadastrado!\n", id);
            free(novo); 
            return p;
        }
        q = q->prox;
    }
    printf("Digite o nome do paciente: \n");
    scanf(" %[^\n]", buffer_nome); 

    novo->id = id;
    
    novo->nome = (char*) malloc(strlen(buffer_nome) + 1);
    
    if (novo->nome == NULL){
        printf("Erro de memoria\n");
        free(novo);
        return p;
    }

    strcpy(novo->nome, buffer_nome);
    
    
    novo->prox = p;
    novo->ant = NULL; 

    if(p != NULL){
       p->ant = novo; 
    }
    
    return novo;
}

Paciente* pesquisar_paciente(Paciente* p, int id){
    Paciente* q = p;

    if (q == NULL) {
        printf("Nenhum paciente registrado\n");
        return NULL;
    } 

    while(q != NULL){
        if(q->id == id){
            printf("Paciente encontrado: %s\n", q->nome);
            return q;
        }
        q = q->prox;
    }

    printf("Paciente com ID %d nao encontrado.\n", id);
    return NULL;
}

void listar_todospacientes(Paciente* p) {
    Paciente* q = p;
    
    if (q == NULL) {
        printf("\n--- Lista Vazia ---\n");
        return;
    }

    printf("\n--- Lista de Pacientes ---\n");
    while (q != NULL) {
        printf("ID: %d | Nome: %s\n", q->id, q->nome);
        q = q->prox;
    }
    printf("--------------------------\n");
}

Paciente* remover_paciente(Paciente* p){

    if(p == NULL){
        listapaciente_vazia(p);
        return NULL;
    }

    int id;
    printf("Digite o id do paciente a ser removido: ");
    scanf("%d", &id);
    Paciente* q = p;
    

    while(q != NULL && q->id != id){
        q = q->prox;
    }
    if(q == NULL){
        printf("Paciente não encontrado.");
        return p;
    }
    if(q->ant != NULL){
        q->ant->prox = q->prox;
    } else{
        p = q->prox;
    }
    if(q->prox != NULL){
        q->prox->ant = q->ant;
    }

        printf("Paciente '%s' foi removido.", q->nome);
        free(q->nome);
        free(q);
        return p;
    }


void listapaciente_vazia(Paciente* lista){
    if(lista == NULL){
        printf("Lista vazia!!!");
    }
}

Paciente* liberar_lista(Paciente* p){
    Paciente* q = p;
    while (q != NULL) {
        p = q;
        q = q->prox;
        free(p);
        free(p->nome);
    }
    return NULL;
    
}