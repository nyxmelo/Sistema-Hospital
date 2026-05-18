#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "paciente.h"
#include "medico.h"

void salvar_pacientes(Paciente* lista);

Paciente* carregar_pacientes();

void salvar_medicos(Medico* raiz);

Medico* carregar_medicos();

#endif