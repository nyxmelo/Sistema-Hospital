#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/ordenacao.h"

Paciente* ordenar_pacientes_id(Paciente* lista){

    if(lista == NULL){

        printf("Lista vazia.\n");
        return lista;
    }

    int trocou;

    Paciente* atual;

    Paciente* ultimo = NULL;

    do{

        trocou = 0;

        atual = lista;

        while(atual->prox != ultimo){

            if(atual->id > atual->prox->id){

                int temp_id = atual->id;

                char* temp_nome = atual->nome;

                atual->id = atual->prox->id;

                atual->nome = atual->prox->nome;

                atual->prox->id = temp_id;

                atual->prox->nome = temp_nome;

                trocou = 1;
            }

            atual = atual->prox;
        }

        ultimo = atual;

    } while(trocou);

    printf("Pacientes ordenados por ID.\n");

    return lista;
}