// ========================= pilha.h =========================

#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"

typedef struct pilha {

    Paciente* paciente;
    struct pilha* prox;

} Pilha;

Pilha* push(Pilha* topo, Paciente* p);

Pilha* pop(Pilha* topo);

void mostrar_pilha(Pilha* topo);

Pilha* liberar_pilha(Pilha* topo);

#endif