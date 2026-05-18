#include<stdio.h>
#include<stdlib.h>

#include "../include/lista.h"
#include "../include/arvore.h"
#include "../include/fila.h"
#include "../include/pilha.h"
#include "../include/grafo.h"
#include "../include/arquivo.h"
#include "../include/ordenacao.h"

static Paciente *lista = NULL;
static Medico *raiz = NULL;
static Fila *fila = NULL;
static Pilha *historico = NULL;
static Grafo *hospital = NULL;

void menu_paciente(){

    int opcao;
    int id;

    do{

        printf("\n======== MENU PACIENTES ========\n");

        printf("1. Cadastrar paciente\n");
        printf("2. Pesquisar paciente\n");
        printf("3. Listar pacientes\n");
        printf("4. Remover paciente\n");
        printf("5. Apagar lista\n");
        printf("6. Adicionar paciente na fila\n");
        printf("7. Ordenar pacientes por ID\n");
        printf("0. SAIR\n");

        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                lista = inserir_paciente(lista);

                break;

            case 2:

                printf("Digite o ID: ");
                scanf("%d", &id);

                pesquisar_paciente(lista, id);

                break;

            case 3:

                listar_todospacientes(lista);

                break;

            case 4:

                lista = remover_paciente(lista);

                break;

            case 5:

                lista = liberar_lista(lista);

                break;

            case 6: {

                printf("Digite o ID do paciente: ");
                scanf("%d", &id);

                Paciente* encontrado = pesquisar_paciente(lista, id);

                if(encontrado != NULL){

                    enfileirar(fila, encontrado);

                } else {

                    printf("Paciente nao encontrado.\n");
                }

                break;
            }

            case 7:

                lista = ordenar_pacientes_id(lista);

                 break;

            case 0:
                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);
}

void menu_medico(){

    int opcao;
    int id;

    do{

        printf("\n======== MENU MEDICOS ========\n");

        printf("1. Cadastrar medico\n");
        printf("2. Buscar medico\n");
        printf("3. Listar medicos\n");
        printf("4. Remover medico\n");
        printf("5. Apagar lista\n");
        printf("0. SAIR\n");

        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                raiz = inserir_medico(raiz);

                break;

            case 2: {

                printf("Digite o ID do medico: ");
                scanf("%d", &id);

                Medico* encontrado = buscar_medico(raiz, id);

                if(encontrado != NULL){

                    printf("\nMedico encontrado!\n");

                    printf("ID: %d\n", encontrado->id);
                    printf("Nome: %s\n", encontrado->nome);
                    printf("Especialidade: %s\n", encontrado->especialidade);

                } else {

                    printf("Medico nao encontrado.\n");
                }

                break;
            }

            case 3:

                listar_medicos(raiz);

                break;

            case 4:

                printf("Digite o ID do medico: ");
                scanf("%d", &id);

                raiz = remover_medico(raiz, id);

                break;

            case 5:

                raiz = liberar_arvore(raiz);

                break;

            case 0:
                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);
}

void menu_fila(){

    int opcao;

    do{

        printf("\n======== MENU FILA ========\n");

        printf("1. Mostrar fila\n");
        printf("2. Atender paciente\n");
        printf("3. Apagar fila\n");
        printf("0. SAIR\n");

        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                mostrar_fila(fila);

                break;

            case 2: {

                Paciente* atendido = desenfileirar(fila);

                if(atendido != NULL){

                    historico = push(historico, atendido);

                    free(atendido->nome);
                    free(atendido);
                }

                break;
            }

            case 3:

                liberar_fila(fila);

                fila = criar_fila();

                break;

            case 0:
                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);
}

void menu_historico(){

    int opcao;

    do{

        printf("\n======== MENU HISTORICO ========\n");

        printf("1. Mostrar historico\n");
        printf("2. Remover ultimo atendimento\n");
        printf("3. Apagar historico\n");
        printf("0. SAIR\n");

        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                mostrar_pilha(historico);

                break;

            case 2:

                historico = pop(historico);

                break;

            case 3:

                historico = liberar_pilha(historico);

                break;

            case 0:
                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);
}

void menu_grafo(){

    int opcao;

    int origem;
    int destino;

    int inicio;

    do{

        printf("\n======== MENU GRAFO ========\n");

        printf("0 -> Recepcao\n");
        printf("1 -> Triagem\n");
        printf("2 -> Consultorio\n");
        printf("3 -> Exames\n");
        printf("4 -> UTI\n");
        printf("5 -> Farmacia\n");

        printf("\n1. Mostrar setores\n");
        printf("2. Conectar setores\n");
        printf("3. BFS\n");
        printf("4. DFS\n");
        printf("0. SAIR\n");

        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                mostrar_grafo(hospital);

                break;

            case 2:

                printf("Origem: ");
                scanf("%d", &origem);

                printf("Destino: ");
                scanf("%d", &destino);

                adicionar_aresta(hospital, origem, destino);

                break;

            case 3:

                printf("Vertice inicial: ");
                scanf("%d", &inicio);

                bfs(hospital, inicio);

                break;

            case 4:

                printf("Vertice inicial: ");
                scanf("%d", &inicio);

                dfs(hospital, inicio);

                break;

            case 0:
                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);
}

void menu_principal(){

    int opcao;

    do{

        printf("\n======== SISTEMA HOSPITAL ========\n");

        printf("1. Menu pacientes\n");
        printf("2. Menu medicos\n");
        printf("3. Menu fila\n");
        printf("4. Menu historico\n");
        printf("5. Menu grafo\n");
        printf("0. SAIR\n");

        scanf("%d", &opcao);

        switch(opcao){

            case 1:

                menu_paciente();

                break;

            case 2:

                menu_medico();

                break;

            case 3:

                menu_fila();

                break;

            case 4:

                menu_historico();

                break;

            case 5:

                menu_grafo();

                break;

            case 0:
                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);
}

int main(){

    fila = criar_fila();

    hospital = criar_grafo(6);

    lista = carregar_pacientes();

    raiz = carregar_medicos();

    menu_principal();

    salvar_pacientes(lista);

    salvar_medicos(raiz);

    liberar_lista(lista);

    liberar_arvore(raiz);

    liberar_fila(fila);

    liberar_pilha(historico);

    liberar_grafo(hospital);

    return 0;
}