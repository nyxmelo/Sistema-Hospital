#ifndef LISTA_H
#define LISTA_H
#include "paciente.h"



Paciente* inserir_paciente(Paciente* p);
Paciente* pesquisar_paciente(Paciente* p, int id);
void listar_todospacientes(Paciente* p);
Paciente* listapaciente_cria();

#endif