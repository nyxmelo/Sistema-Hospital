#include<string.h>
#include "paciente.h"
#ifndef FILA_H
#define FILA_H

typedef struct fila {
    Paciente* inicio;
    Paciente* fim;
} Fila;

Fila* criar_fila();

void enfileirar(Fila* f, Paciente* p);

Paciente* desenfileirar(Fila* f);

void mostrar_fila(Fila* f);

void liberar_fila(Fila* f);

#endif