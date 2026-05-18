#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/arquivo.h"

void salvar_pacientes(Paciente* lista){

    FILE* arquivo = fopen("pacientes.txt", "w");

    if(arquivo == NULL){

        printf("Erro ao abrir arquivo.\n");
        return;
    }

    Paciente* atual = lista;

    while(atual != NULL){

        fprintf(arquivo, "%d;%s\n",
                atual->id,
                atual->nome);

        atual = atual->prox;
    }

    fclose(arquivo);

    printf("Pacientes salvos.\n");
}

Paciente* carregar_pacientes(){

    FILE* arquivo = fopen("pacientes.txt", "r");

    if(arquivo == NULL){

        return NULL;
    }

    Paciente* lista = NULL;

    int id;

    char nome[100];

    while(fscanf(arquivo, "%d;%99[^\n]\n",
                 &id,
                 nome) == 2){

        Paciente* novo =
        (Paciente*) malloc(sizeof(Paciente));

        novo->id = id;

        novo->nome =
        (char*) malloc(strlen(nome) + 1);

        strcpy(novo->nome, nome);

        novo->prox = lista;
        novo->ant = NULL;

        if(lista != NULL){

            lista->ant = novo;
        }

        lista = novo;
    }

    fclose(arquivo);

    printf("Pacientes carregados.\n");

    return lista;
}

void salvar_medicos_recursivo(FILE* arquivo,
                              Medico* raiz){

    if(raiz != NULL){

        salvar_medicos_recursivo(arquivo,
                                 raiz->esq);

        fprintf(arquivo,
                "%d;%s;%s\n",
                raiz->id,
                raiz->nome,
                raiz->especialidade);

        salvar_medicos_recursivo(arquivo,
                                 raiz->dir);
    }
}

void salvar_medicos(Medico* raiz){

    FILE* arquivo = fopen("medicos.txt", "w");

    if(arquivo == NULL){

        printf("Erro ao abrir arquivo.\n");
        return;
    }

    salvar_medicos_recursivo(arquivo,
                             raiz);

    fclose(arquivo);

    printf("Medicos salvos.\n");
}

Medico* inserir_medico_arquivo(Medico* raiz,
                               int id,
                               char nome[],
                               char especialidade[]){

    if(raiz == NULL){

        Medico* novo =
        (Medico*) malloc(sizeof(Medico));

        novo->id = id;

        novo->nome =
        (char*) malloc(strlen(nome) + 1);

        novo->especialidade =
        (char*) malloc(strlen(especialidade) + 1);

        strcpy(novo->nome, nome);

        strcpy(novo->especialidade,
               especialidade);

        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if(id < raiz->id){

        raiz->esq =
        inserir_medico_arquivo(
            raiz->esq,
            id,
            nome,
            especialidade
        );

    } else {

        raiz->dir =
        inserir_medico_arquivo(
            raiz->dir,
            id,
            nome,
            especialidade
        );
    }

    return raiz;
}

Medico* carregar_medicos(){

    FILE* arquivo = fopen("medicos.txt", "r");

    if(arquivo == NULL){

        return NULL;
    }

    Medico* raiz = NULL;

    int id;

    char nome[100];
    char especialidade[100];

    while(fscanf(arquivo,
                 "%d;%99[^;];%99[^\n]\n",
                 &id,
                 nome,
                 especialidade) == 3){

        raiz =
        inserir_medico_arquivo(
            raiz,
            id,
            nome,
            especialidade
        );
    }

    fclose(arquivo);

    printf("Medicos carregados.\n");

    return raiz;
}