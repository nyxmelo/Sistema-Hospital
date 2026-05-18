#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arvore.h"

Medico* inserir_medico(Medico* raiz){

    if(raiz == NULL){

        Medico* novo = (Medico*) malloc(sizeof(Medico));

        if(novo == NULL){
            printf("Erro de memoria.\n");
            return NULL;
        }

        char buffer_nome[100];
        char buffer_esp[100];

        printf("Digite o ID do medico: ");
        scanf("%d", &novo->id);

        printf("Digite o nome do medico: ");
        scanf(" %[^\n]", buffer_nome);

        printf("Digite a especialidade: ");
        scanf(" %[^\n]", buffer_esp);

        novo->nome = (char*) malloc(strlen(buffer_nome) + 1);
        novo->especialidade = (char*) malloc(strlen(buffer_esp) + 1);

        strcpy(novo->nome, buffer_nome);
        strcpy(novo->especialidade, buffer_esp);

        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if(raiz != NULL){

        int id;

        printf("Digite o ID do medico: ");
        scanf("%d", &id);

        if(id < raiz->id){

            Medico* temp = raiz->esq;

            if(temp == NULL){

                Medico* novo = (Medico*) malloc(sizeof(Medico));

                char buffer_nome[100];
                char buffer_esp[100];

                novo->id = id;

                printf("Digite o nome do medico: ");
                scanf(" %[^\n]", buffer_nome);

                printf("Digite a especialidade: ");
                scanf(" %[^\n]", buffer_esp);

                novo->nome = (char*) malloc(strlen(buffer_nome) + 1);
                novo->especialidade = (char*) malloc(strlen(buffer_esp) + 1);

                strcpy(novo->nome, buffer_nome);
                strcpy(novo->especialidade, buffer_esp);

                novo->esq = NULL;
                novo->dir = NULL;

                raiz->esq = novo;

            } else {

                Medico* atual = temp;

                while(1){

                    if(id < atual->id){

                        if(atual->esq == NULL){

                            Medico* novo = (Medico*) malloc(sizeof(Medico));

                            char buffer_nome[100];
                            char buffer_esp[100];

                            novo->id = id;

                            printf("Digite o nome do medico: ");
                            scanf(" %[^\n]", buffer_nome);

                            printf("Digite a especialidade: ");
                            scanf(" %[^\n]", buffer_esp);

                            novo->nome = (char*) malloc(strlen(buffer_nome) + 1);
                            novo->especialidade = (char*) malloc(strlen(buffer_esp) + 1);

                            strcpy(novo->nome, buffer_nome);
                            strcpy(novo->especialidade, buffer_esp);

                            novo->esq = NULL;
                            novo->dir = NULL;

                            atual->esq = novo;
                            break;
                        }

                        atual = atual->esq;

                    } else {

                        if(atual->dir == NULL){

                            Medico* novo = (Medico*) malloc(sizeof(Medico));

                            char buffer_nome[100];
                            char buffer_esp[100];

                            novo->id = id;

                            printf("Digite o nome do medico: ");
                            scanf(" %[^\n]", buffer_nome);

                            printf("Digite a especialidade: ");
                            scanf(" %[^\n]", buffer_esp);

                            novo->nome = (char*) malloc(strlen(buffer_nome) + 1);
                            novo->especialidade = (char*) malloc(strlen(buffer_esp) + 1);

                            strcpy(novo->nome, buffer_nome);
                            strcpy(novo->especialidade, buffer_esp);

                            novo->esq = NULL;
                            novo->dir = NULL;

                            atual->dir = novo;
                            break;
                        }

                        atual = atual->dir;
                    }
                }
            }

        } else {

            Medico* novo = (Medico*) malloc(sizeof(Medico));

            char buffer_nome[100];
            char buffer_esp[100];

            novo->id = id;

            printf("Digite o nome do medico: ");
            scanf(" %[^\n]", buffer_nome);

            printf("Digite a especialidade: ");
            scanf(" %[^\n]", buffer_esp);

            novo->nome = (char*) malloc(strlen(buffer_nome) + 1);
            novo->especialidade = (char*) malloc(strlen(buffer_esp) + 1);

            strcpy(novo->nome, buffer_nome);
            strcpy(novo->especialidade, buffer_esp);

            novo->esq = NULL;
            novo->dir = NULL;

            raiz->dir = novo;
        }
    }

    return raiz;
}

Medico* buscar_medico(Medico* raiz, int id){

    if(raiz == NULL){
        return NULL;
    }

    if(id == raiz->id){
        return raiz;
    }

    if(id < raiz->id){
        return buscar_medico(raiz->esq, id);
    }

    return buscar_medico(raiz->dir, id);
}

void listar_medicos(Medico* raiz){

    if(raiz != NULL){

        listar_medicos(raiz->esq);

        printf("\nID: %d\n", raiz->id);
        printf("Nome: %s\n", raiz->nome);
        printf("Especialidade: %s\n", raiz->especialidade);

        listar_medicos(raiz->dir);
    }
}

Medico* remover_medico(Medico* raiz, int id){

    if(raiz == NULL){
        return NULL;
    }

    if(id < raiz->id){
        raiz->esq = remover_medico(raiz->esq, id);
    }

    else if(id > raiz->id){
        raiz->dir = remover_medico(raiz->dir, id);
    }

    else {

        if(raiz->esq == NULL && raiz->dir == NULL){

            free(raiz->nome);
            free(raiz->especialidade);
            free(raiz);

            return NULL;
        }

        else if(raiz->esq == NULL){

            Medico* temp = raiz->dir;

            free(raiz->nome);
            free(raiz->especialidade);
            free(raiz);

            return temp;
        }

        else if(raiz->dir == NULL){

            Medico* temp = raiz->esq;

            free(raiz->nome);
            free(raiz->especialidade);
            free(raiz);

            return temp;
        }

        Medico* temp = raiz->dir;

        while(temp->esq != NULL){
            temp = temp->esq;
        }

        raiz->id = temp->id;

        free(raiz->nome);
        free(raiz->especialidade);

        raiz->nome = (char*) malloc(strlen(temp->nome) + 1);
        raiz->especialidade = (char*) malloc(strlen(temp->especialidade) + 1);

        strcpy(raiz->nome, temp->nome);
        strcpy(raiz->especialidade, temp->especialidade);

        raiz->dir = remover_medico(raiz->dir, temp->id);
    }

    return raiz;
}

Medico* liberar_arvore(Medico* raiz){

    if(raiz != NULL){

        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);

        free(raiz->nome);
        free(raiz->especialidade);
        free(raiz);
    }

    return NULL;
}