#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tipo_vert.h"
#include "tipoFila.h"
#include "tipoPilha.h"


#define TAM_300 300
#define TAM_600 600
#define TAM_900 900


#define TAM_TODOS 8

int grafo_300[TAM_300][TAM_300];
int grafo_600[TAM_600][TAM_600];
int grafo_900[TAM_900][TAM_900];



int main(){
	srand(time(NULL));

	double tempo;

	clock_t t_inicial, t_final;
	double t_usado_cpu;

	


	tipo_vert *vet_300[TAM_300];
	tipo_vert *vet_600[TAM_600];
	tipo_vert *vet_900[TAM_900];

	inicializaVetor(vet_300, TAM_300);
	inicializaVetor(vet_600, TAM_600);
	inicializaVetor(vet_900, TAM_900);


	tipoFila *p;
	tipoPilha *l;
	int a, b;
	criaFila(&p);



	printf("\n");

	int val[4] = {30,50,70,100};


	for (int i = 0; i < 4; ++i){
	
		inicia_grafo(TAM_300, grafo_300);
		inicia_grafo(TAM_600, grafo_600);
		inicia_grafo(TAM_900, grafo_900);

		gera_Conexo2(TAM_300,grafo_300,i);
		gera_Conexo2(TAM_600,grafo_600,i);
		gera_Conexo2(TAM_900,grafo_900,i);

		t_usado_cpu = 0;
		t_inicial = clock();
		bfs(TAM_300, grafo_300, vet_300, 0, p);
		t_final = clock();
		t_usado_cpu = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;
		printf("Tempo para o BFS no grafo de tamanho 300 com %d por cento de conectividade %lf\n",val[i], t_usado_cpu);

		t_usado_cpu = 0;
		t_inicial = clock();
		bfs(TAM_600, grafo_600, vet_600, 0, p);
		t_final = clock();
		t_usado_cpu = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;
		printf("Tempo para o BFS no grafo de tamanho 600 com %d por cento de conectividade %lf\n",val[i], t_usado_cpu);

		t_usado_cpu = 0;
		t_inicial = clock();
		bfs(TAM_900, grafo_900, vet_900, 0, p);
		t_final = clock();
		t_usado_cpu = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;
		printf("Tempo para o BFS no grafo de tamanho 900 com %d por cento de conectividade %lf\n",val[i], t_usado_cpu);

		printf("-----------------------------------------------------------\n");


		t_usado_cpu = 0;
		t_inicial = clock();
		dfs(TAM_300, grafo_300, vet_300,0);
		t_final = clock();
		t_usado_cpu = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;
		printf("Tempo para o DFS no grafo de tamanho 300 com %d por cento de conectividade %lf\n",val[i], t_usado_cpu);

		t_usado_cpu = 0;
		t_inicial = clock();
		dfs(TAM_600, grafo_600, vet_600,0);
		t_final = clock();
		t_usado_cpu = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;
		printf("Tempo para o DFS no grafo de tamanho 600 com %d por cento de conectividade %lf\n",val[i], t_usado_cpu);

		t_usado_cpu = 0;
		t_inicial = clock();
		dfs(TAM_900, grafo_900, vet_900,0);
		t_final = clock();
		t_usado_cpu = ((double) (t_final - t_inicial)) / CLOCKS_PER_SEC;
		printf("Tempo para o DFS no grafo de tamanho 900 com %d por cento de conectividade %lf\n",val[i], t_usado_cpu);

		printf("-----------------------------------------------------------\n");
	}

	printf("\nArvore de caminhamento da busca em Largura: \n");

	int grafo_Cam[15][15];
	tipo_vert *vert_Cam[15];
	inicializaVetor(vert_Cam,15);
	//tava bugando com o val
	int val2[4] = {30,50,70,100};

	for (int i = 0; i < 4; ++i){
	
		inicia_grafo(15, grafo_Cam);

		gera_Conexo2(15,grafo_Cam,i);


		printf("\nCom %d por cento de conectividade: \n",val2[i]);
		bfs(15, grafo_Cam, vert_Cam, 0, p);
		bfs_imprime(15,grafo_Cam,vert_Cam,0,p);
		printf("------------------------------------------\n");
	}


	printf("\nSequencia de vertices visitados da busca em profundidade: \n");

	for (int i = 0; i < 4; ++i){
	
		inicia_grafo(15, grafo_Cam);

		gera_Conexo2(15,grafo_Cam,i);

		printf("\nCom %d por cento de conectividade: \n",val2[i]);
		dfs(15, grafo_Cam, vert_Cam, 5);
		imprime_dfs(15,grafo_Cam,vert_Cam, 5);
		printf("\n------------------------------------------\n");
	}


	printf("\n\nMatriz de adjacencia do grafo em que todos os caminhos serao encontrados: \n");
	tipo_vert *vet2[TAM_TODOS];
	inicializaVetor(vet2,TAM_TODOS);

	int grafo_Todos[TAM_TODOS+1][TAM_TODOS+1];
	inicia_grafo(TAM_TODOS, grafo_Todos);
	gera_Conexo(TAM_TODOS,grafo_Todos,2);

	imprimir_matriz_adj(TAM_TODOS,grafo_Todos);
	
	printf("\nTodos os caminhos usando busca em profundidade: \n\n");


	tipoPilha *pilha;
	criaPilha(&pilha);
	todos_dfs(TAM_TODOS,grafo_Todos, vet2,0,pilha);


	printf("\n\nTeste de conexidade: \n");

	printf("Matriz de adjacencia de um grafo aleatorio e provavelmente nao conexo: \n");

	tipo_vert *vet3[15];
	inicializaVetor(vet3,15);

	int grafo_Rnd[15][15];
	inicia_grafo(15,grafo_Rnd);
	geraRnd(15,grafo_Rnd);
	imprimir_matriz_adj(15,grafo_Rnd);

	printf("Teste de conexidade: \n");

	if(conexo(15,grafo_Rnd,vet3)){
		printf("E conexo\n");
	}else{
		printf("Nao e conexo\n");
	}

	printf("Teste de conexidade em um grafo garantidamente conexo: \n");

	if(conexo(TAM_TODOS,grafo_Todos,vet2)){
		printf("E conexo\n");
	}else{
		printf("Nao e conexo\n");
	}	

	return 0;
}