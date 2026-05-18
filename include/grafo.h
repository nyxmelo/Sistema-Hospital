#ifndef GRAFO_H
#define GRAFO_H

#define MAX 10

typedef struct grafo {

    int matriz[MAX][MAX];
    int num_vertices;

} Grafo;

Grafo* criar_grafo(int vertices);

void adicionar_aresta(Grafo* g, int origem, int destino);

void mostrar_grafo(Grafo* g);

void bfs(Grafo* g, int inicio);

void dfs(Grafo* g, int inicio);

void liberar_grafo(Grafo* g);

#endif