#include<string.h>
#ifndef ARVORE_H
#define ARVORE_H
#include "medico.h"

Medico* inserir_medico(Medico* raiz);
Medico* buscar_medico(Medico* raiz, int id);
void listar_medicos(Medico* raiz);
Medico* liberar_arvore(Medico* raiz);
Medico* remover_medico(Medico* raiz, int id);

#endif