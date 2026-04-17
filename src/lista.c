#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "../include/lista.h"

Paciente* listapaciente_cria(Paciente* lista){
    if(lista != NULL){
        return lista;
    }
        return NULL;
}

Paciente* inserir_paciente(Paciente* p){
    Paciente* q = p;
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));
    if (novo == NULL){
        printf("Erro de memoria\n");
        return p;
    }

    int id;
    char buffer_nome[100]; // Espaço temporário para ler o teclado

    
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
    scanf("%s", buffer_nome); // Lê o nome para o buffer

    novo->id = id;
    // Aloca exatamente o tamanho do nome digitado
    novo->nome = (char*) malloc(strlen(buffer_nome) + 1);
    
    if (novo->nome == NULL){
        printf("Erro de memoria\n");
        free(novo);
        return p;
    }

    strcpy(novo->nome, buffer_nome);
    
    // Ajuste da Lista Duplamente Encadeada
    novo->prox = p;
    novo->ant = NULL; // Novo nó sempre será o primeiro, então 'ant' é NULL

    if(p != NULL){
       p->ant = novo; 
    }
    
    return novo;
}

Paciente* pesquisar_paciente(Paciente* p, int id){
    Paciente* q = p; // COMEÇA do início da lista

    if (q == NULL) {
        printf("Nenhum paciente registrado\n");
        return NULL;
    } 

    while(q != NULL){ // Percorre até o fim da lista
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
        free(q);
        free(q->nome);
        return p;
    }


void listapaciente_vazia(Paciente* lista){
    if(lista == NULL){
        printf("Lista vazia!!!");
    }
}