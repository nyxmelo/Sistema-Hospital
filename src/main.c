#include<stdio.h>
#include<stdlib.h>
#include "../include/lista.h"
#include "../include/paciente.h"

void menu_paciente(){
    int opcao;
    int id;

    static Paciente *lista = NULL;

    do{
        printf("~~~~~~~~~~//~~~~~~~~~~\n");
        printf("Digite a opção desejada \n");
        printf("1. Cadastrar paciente\n");
        printf("2. Pesquisar paciente\n");
        printf("3. Listar todos os pacientes\n");
        printf("4. Remover um paciente\n");
        printf("0. SAIR\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            if (lista == NULL) {
                    lista = listapaciente_cria(lista);
                }
            lista = inserir_paciente(lista);
            break;
        case 2:
            printf("Digite o id do paciente: ");
            scanf("%d", &id);
            pesquisar_paciente(lista, id);
            break;
        case 3:
            listar_todospacientes(lista);
            break;
        case 4:
            lista = remover_paciente(lista);
            break;
        default:
            break;
        }
    } while(opcao != 0);
}

void menu_principal(){
    int opcao;
    do{
        printf("~~~~~~~~~~//~~~~~~~~~~\n");
        printf("Digite a opção desejada \n");
        printf("1. Menu dos pacientes\n");
        printf("0. SAIR\n");
        scanf("%d", &opcao);
        if(opcao == 1){
            menu_paciente();
        }
    } while(opcao != 0);
}

int main(int argc, char const *argv[]) {
    
    menu_principal();

    // Paciente *lista = listapaciente_cria();

    // lista = inserir_paciente(lista);
    // listar_todospacientes(lista);

    return 0;
}
