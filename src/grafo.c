#include <stdio.h>
#include <stdlib.h>
#include "../include/grafo.h"

void dfs_recursivo(Grafo* g, int vertice, int visitado[]){

    visitado[vertice] = 1;

    printf("%d ", vertice);

    for(int i = 0; i < g->num_vertices; i++){

        if(g->matriz[vertice][i] == 1 && !visitado[i]){

            dfs_recursivo(g, i, visitado);
        }
    }
}

Grafo* criar_grafo(int vertices){

    Grafo* g = (Grafo*) malloc(sizeof(Grafo));

    if(g == NULL){

        printf("Erro de memoria.\n");
        return NULL;
    }

    g->num_vertices = vertices;

    for(int i = 0; i < MAX; i++){

        for(int j = 0; j < MAX; j++){

            g->matriz[i][j] = 0;
        }
    }

    return g;
}

void adicionar_aresta(Grafo* g, int origem, int destino){

    if(origem >= g->num_vertices || destino >= g->num_vertices){

        printf("Vertice invalido.\n");
        return;
    }

    g->matriz[origem][destino] = 1;
    g->matriz[destino][origem] = 1;

    printf("Ligacao criada.\n");
}

void mostrar_grafo(Grafo* g){

    printf("\n======= GRAFO =======\n");

    for(int i = 0; i < g->num_vertices; i++){

        printf("%d -> ", i);

        for(int j = 0; j < g->num_vertices; j++){

            if(g->matriz[i][j] == 1){

                printf("%d ", j);
            }
        }

        printf("\n");
    }
}

void bfs(Grafo* g, int inicio){

    int visitado[MAX] = {0};

    int fila[MAX];

    int inicio_fila = 0;
    int fim_fila = 0;

    visitado[inicio] = 1;

    fila[fim_fila++] = inicio;

    printf("\nBFS: ");

    while(inicio_fila < fim_fila){

        int atual = fila[inicio_fila++];

        printf("%d ", atual);

        for(int i = 0; i < g->num_vertices; i++){

            if(g->matriz[atual][i] == 1 && !visitado[i]){

                visitado[i] = 1;

                fila[fim_fila++] = i;
            }
        }
    }

    printf("\n");
}

void dfs(Grafo* g, int inicio){

    int visitado[MAX] = {0};

    printf("\nDFS: ");

    dfs_recursivo(g, inicio, visitado);

    printf("\n");
}

void liberar_grafo(Grafo* g){

    free(g);

    printf("Grafo apagado.\n");
}