#include<string.h>
#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct paciente {
    int id;
    char *nome;
    struct paciente *prox;
    struct paciente *ant;
} Paciente;

#endif