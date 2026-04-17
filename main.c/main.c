#include<stdio.h>
#include<stdlib.h>
#include "../include/lista.h"
#include "../include/paciente.h"
#include "../src/lista.c"

int main(int argc, char const *argv[]) {
    
    Paciente *lista = listapaciente_cria();

    lista = inserir_paciente(lista);
    listar_todospacientes(lista);

    return 0;
}
