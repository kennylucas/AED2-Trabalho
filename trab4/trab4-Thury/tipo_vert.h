#include <stdio.h>
#include <stdlib.h>
#include "tipoFila.h"
#include "tipoPilha.h"

typedef struct tipo_vert tipo_vert;

void inicia_grafo(size_t TAM,int grafo[TAM][TAM]);

int gera_Conexo(size_t TAM,int grafo[TAM][TAM], int modo);

void insere_aresta(size_t TAM,int grafo[TAM][TAM], int a, int b);

void imprimir_matriz_adj(size_t TAM,int grafo[TAM][TAM]);

void bfs(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[], int vert_i, tipoFila *p);

void dfs_visita(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[], int vert_i);

void dfs(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[], int vert_i);

int conexo(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[]);


void imprime_dfs_visita(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[], int vert_i);

void imprime_dfs(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[], int vert_i);

void todos_dfs_visita(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[], int vert_i, tipoPilha *p);

void todos_dfs(size_t TAM,int grafo[TAM][TAM], tipo_vert *vert[], int inicio ,tipoPilha *p);

void inicializaVetor(tipo_vert *vert[], int TAM);

void geraRnd(size_t TAM, int grafo[TAM][TAM]);

void bfs_imprime(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[], int vert_i, tipoFila *p);

int gera_Conexo2(size_t TAM,int grafo[TAM][TAM], int modo);

void conta_zero(size_t TAM,int grafo[TAM][TAM]);