#ifndef GRAFOSM_H
#define GRAFOSM_H

#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"


typedef struct TipoGrafo{
	int V;
	int A;
	int **MatrizAdj;
}TipoGrafo; //Struct para o tipo grafo contendo a qtde de vértices, arestas e a matriz de adjacência

int* visitado; // Vetor para saber quais vertices já foram visitados - função Verifica_Caminho
int* vet_profundidade; // Vetor para determinar a ordem que os vértices foram acessados na busca em profundidade
int  cont_profundidade; // Guarda quantos vértices foram acessados na busca em profundidade
int* fila_largura; //Vetor para representar a ordem em que os vértices devem ser acessados na busca em largura
int* vet_largura; // Vetor para determinar a ordem que os vértices foram acessados na busca em largura
int  inicio_largura; //inicio da fila na busca em largura
int  fim_largura; //fim da fila na busca em largura
int* vet_AV; // Qunatidade de arestas por vertice
int cnt;
int d;

void Cria_Grafo(TipoGrafo *G, int vertices);

// Dado o grafo e a quantidade de vertices, cria o grafo e chama a função para criar uma matriz de adjacência

int InserirA(TipoGrafo *G, int V1, int V2);

// Dados dois vértices, cria uma aresta que liga os dois

int RemoverA(TipoGrafo *G, int V1, int V2);

// Dados dois vértices, remove a aresta que liga os dois

void Insere_Percentual(TipoGrafo *G, int QtdeArestas);


int Verifica_Caminho(TipoGrafo *G, int VI, int VF);

// Verifica se os dois vértices estão conectados (se de alguma forma V1 chega à V2)

void Verifica_ConexaoInterno(TipoGrafo *G, int VA);

//Chamada interna para chamada recursiva do Verifica_Caminho

int Verifica_Conexao(TipoGrafo *G);

//Verifica se o grafo é conexo

void Gera_Grafo(TipoGrafo *G, int qtde_arestas, char optA);


void Mostrar_Busca(TipoGrafo *G, int* vetor);

//Dado o grafo e o vetor, irá verificar a ordem inicial do vetor e irá exibir em ordem de acessos

void Busca_Profundidade(TipoGrafo *G, int VB);

//Algoritmo de busca em profundidade


void Busca_ProfundidadeInterno(TipoGrafo *G, int VB);

//Chamada interna da função Busca_Profundidade para realizar as chamadas recursivas (empilhar)

void Busca_Largura(TipoGrafo *G, int VB);

//Algoritmo de busca em largura - pão-gésimo XD

void Preenche_AV(TipoGrafo *G);

//Preenche o vetor AV com a quantidade de arestas por vertice

int verifica_lista(int g);

void Todos_caminhos(TipoGrafo *G, int c);

#endif