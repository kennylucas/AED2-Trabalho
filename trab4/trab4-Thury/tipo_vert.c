#include <stdio.h>
#include <stdlib.h>
#include "tipoFila.h"
#include "tipoPilha.h"
#include "tipo_vert.h"

struct tipo_vert{
	int cor;              //0 == branco; 1 == cinza; 2==preto;
	int distancia;
	int posicao;
};



void conta_zero(size_t TAM,int grafo[TAM][TAM]){
	int cont0 = 0;
	int cont1 = 0;
	for (int i = 0; i < TAM; ++i){
		for (int j = 0; j < TAM; ++j){
			if (grafo[i][j] == 0){
				cont0++;
			}else{
				cont1++;
			}
		}
	}
	printf("cont0: %d\n", cont0);
	printf("cont1: %d\n", cont1);
}

void inicializaVetor(tipo_vert *vet[], int TAM){
	for (int i = 0; i < TAM; ++i){
		vet[i] = (tipo_vert*) malloc(sizeof(tipo_vert));
	}
}


void inicia_grafo(size_t TAM, int grafo[TAM][TAM]){
	for (int i = 0; i < TAM; i++){
		for (int j = 0; j < TAM; j++){
			grafo[i][j] = 0;
		}
	}
}

void geraRnd(size_t TAM, int grafo[TAM][TAM]){
	int aleatorio = rand()%TAM;
	for (int i = 0; i < TAM; ++i){
		for (int j = i; j < TAM; ++j){
			if(!((i==aleatorio)||(j==aleatorio))){
				grafo[i][j] = rand()%2;	
				grafo[j][i] = grafo[i][j];
			}
		}
	}
}

int gera_Conexo(size_t TAM,int grafo[TAM][TAM], int modo){
	//conectividade base: n-1/((n^2)/2)
	//n = n^2/2 * porcentagem
	//porcentagem = n/(n^2/2)

	//n e o numero de elementos que devem ser inseridos para alcancar a porcentagem
	float n = 0;
	int i = 0;
	int j = 0;
	int existe;
	//30%
	if(modo == 0){
		//n = (TAM*TAM/2) * (3/10); da erro de precisao
		n = (TAM*TAM*3)/10;
	}
	//50%
	else if(modo == 1){
		n =  (TAM*TAM*5/10);
	}
	//70%
	else if(modo == 2){
		n = (TAM*TAM*7/10);
	}
	//100%
	else if(modo == 3){
		for (i = 0; i < TAM; ++i){
			for (j = i+2; j < TAM; ++j){
				grafo[i][j] = 1;
				grafo[j][i] = 1;
			}
		}
	}
	//1s ja existentes
	n -= 2*(TAM-1);
	int cont = 0;

	//consertar
	for (int i = 0; i < TAM; ++i){
		grafo[i][i+1] = 1;
		grafo[i+1][i] = 1;
	}

	while(cont < n){
		for (i = 0; i < TAM; ++i){
			for (j = i+2; j < TAM; ++j){
				grafo[i][j] = rand()%2;
				grafo[j][i] = grafo[i][j];
				if (existe){
					cont += 2;
				}
				if (cont >= n){
					j = TAM;
					i = TAM;
				}
			}
		}
		if (cont < n){
			for (int i = 0; i < TAM; ++i){
				for (int j = i+2; i < TAM; ++j){
					if(grafo[i][j] == 0){
						grafo[i][j] = 1;
						grafo[j][i] = 1;
						cont+=2;
						if (cont ==n){
							return 0;
						}
					}
				}
			}
		}
	}
}

int gera_Conexo2(size_t TAM,int grafo[TAM][TAM], int modo){
	//conectividade base: n-1/((n^2)/2)
	//n = n^2/2 * porcentagem
	//porcentagem = n/(n^2/2)

	//n e o numero de elementos que devem ser inseridos para alcancar a porcentagem
	float n = 0;
	int i = 0;
	int j = 0;

	int cont = 0;
	//30%
	if(modo == 0){
		//n = (TAM*TAM/2) * (3/10); da erro de precisao
		n = (TAM*TAM*3)/10;
	}
	//50%
	else if(modo == 1){
		n =  (TAM*TAM*5/10);
	}
	//70%
	else if(modo == 2){
		n = (TAM*TAM*7/10);
	}
	//100%
	else if(modo == 3){
		for (i = 0; i < TAM; ++i){
			for (j = i+2; j < TAM; ++j){
				grafo[i][j] = 1;
				grafo[j][i] = 1;
			}
		}
	}
	//1s ja existentes

	n -= 2*(TAM-1);


	//cgaranto ele ser conexo
	
	for (int i = 0; i < TAM; ++i){
		grafo[i][i+1] = 1;
		grafo[i+1][i] = 1;
	}
	int rand1,rand2;
	int cont2 = 0;
	i = 0;
	j = 0;

	int t = 0;
	cont = 0;
	while(cont < n){
		//printf("cont : %d\n", n,cont);
		//tenta botar 3 vezes, se nao conseguir joga sequencial
		
		cont2 = 0;
		while(cont2 <8 && cont < n){
			rand2 = rand()%(TAM);
			rand1 = rand()%(TAM);
			if(grafo[rand1][rand2] == 0 && rand2 != rand1){
				grafo[rand1][rand2] = 1;
				grafo[rand2][rand1] = 1;
				cont += 2;
				cont2 = 0;
			}else{
				cont2++;
			}
		}
		if(cont >= n){
			return 0;
		}
		for (i = 0; i < TAM; ++i){
			for (j = i+2; j < TAM; ++j){
				if(grafo[i][j] == 0){
					grafo[i][j] = 1;
					grafo[j][i] = 1;
					cont+= 2;
					i = TAM+1;
					j = TAM+1;
				}
			}
		}
	}
}

void insere_aresta(size_t TAM, int grafo[TAM][TAM], int a, int b){
	grafo[a][b] = 1;
	grafo[b][a] = 1;
}

void imprimir_matriz_adj(size_t TAM, int grafo[TAM][TAM]){
 	for (int i = 0; i < TAM; i++){
		for (int j = 0; j < TAM; j++){
			printf("%d ", grafo[i][j]);
		}
		printf("\n");
	}
}


//**vet == *vet[]
void bfs(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[], int vert_i, tipoFila *p){
	//printf("bfs \n");
	//printf("fim");
	int tmp;
	for (int i = 0; i < TAM; ++i){
			vert[i]->cor = 0;   //branco
			vert[i]->distancia = 0;
			vert[i]->posicao = i;
			//vert[i].numero = i; //qual vertice estamos visitando
	}
	vert[vert_i]->cor = 1; //cinza
	vert[vert_i]->distancia = 0; //distancia == 0
	vert[vert_i]->posicao = vert_i;
	insereFila(p, vert_i);
	//printf("vertice: %d foi inserido na fila \n", vert_i);
	while(isEmpty(p)){
		tmp = removeFila(p);
		for (int i = 0; i < TAM; ++i){
			if(grafo[tmp][i]){        //verificando se a aresta existe
				if(vert[i]->cor == 0){ //if branco
					vert[i]->cor = 1;
					vert[i]->distancia = vert[tmp]->distancia +1;
					insereFila(p, i);
					//printf("vertice: %d foi inserido na fila \n", i);
					
				}
			}
		}
		vert[tmp]->cor = 2;
	}
	//printf("todos estao pretos \n");
}

void dfs_visita(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[], int vert_i){
	vert[vert_i]->cor = 1;
	int i = 0;
	for (i = 0; i < TAM; ++i){
		if(grafo[vert_i][i]){     //verificando se aresta existe
			if(vert[i]->cor == 0){ //verificando se e branco
				//printf("%d\n", i);
				dfs_visita(TAM, grafo, vert, i);
			}
		}
	}
	vert[vert_i]->cor = 2;
}

void dfs(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[], int vert_i){
	int conexo = 0;
	for (int i = 0; i < TAM; ++i){
		vert[i]->cor = 0;   //branco
	}
	for (int i = 0; i < TAM; ++i){
		if(vert[i]->cor == 0){
			dfs_visita(TAM, grafo, vert, i);
			conexo++;
		}
	}
}

int conexo(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[]){
	int conexo = 0;
	for (int i = 0; i < TAM; ++i){
		vert[i]->cor = 0;   //branco
	}
	for (int i = 0; i < TAM; ++i){
		if(vert[i]->cor == 0){
			dfs_visita(TAM, grafo, vert, i);
			conexo++;
		}
		if (conexo > 1){
			return 0;    // retorna 0 pois o grafo não é conexo
		}
	}
	return 1;
}



void imprime_dfs_visita(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[], int vert_i){
	
	vert[vert_i]->cor = 1;
	for (int i = 0; i < TAM; ++i){
		if(grafo[vert_i][i]){     //verificando se aresta existe
			if(vert[i]->cor == 0){ //verificando se e branco
				printf("-> %d ", i);
				imprime_dfs_visita(TAM, grafo, vert, i);
			}
		}
	}
	vert[vert_i]->cor = 2;
	
}


void imprime_dfs(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[], int vert_i){
	for (int i = 0; i < TAM; ++i){
		vert[i]->cor = 0;   //branco
	}
	imprime_dfs_visita(TAM, grafo, vert, vert_i);
	for (int i = 0; i < TAM; ++i){
		if(vert[i]->cor == 0){
			printf("%d ", i);
			imprime_dfs_visita(TAM, grafo, vert, i);
		}
	}
}


void todos_dfs_visita(size_t tam, int grafo[tam][tam], tipo_vert *vert[], int vert_i, tipoPilha *p){
	int imprimir = 0;
	vert[vert_i]->cor = 1;
	inserePilha(p, vert_i);
	for (int i = 0; i < tam; ++i){
		if(grafo[vert_i][i]){     //verificando se aresta existe
			if(vert[i]->cor == 0){ //verificando se e branco
				imprimir++;
				//printf("-> %d ", i);
				todos_dfs_visita(tam, grafo, vert, i, p);
				vert[i]->cor = 0;
				removePilha(p);
			}
		}
	}
	vert[vert_i]->cor = 2;
	if(!imprimir){
		imprimePilha(p);
		printf("\n");
	}
}

void todos_dfs(size_t tam, int grafo[tam][tam], tipo_vert *vert[], int inicio ,tipoPilha *p){
	for (int i = 0; i < tam; ++i){
		vert[i]->cor = 0;   //branco
	}
	todos_dfs_visita(tam, grafo, vert, inicio, p);
	removePilha(p);
}



void bfs_imprime(size_t TAM, int grafo[TAM][TAM], tipo_vert *vert[], int vert_i, tipoFila *p){
	int tmp;
	for (int i = 0; i < TAM; ++i){
		if(i != vert_i){
			vert[i]->cor = 0;   //branco
			vert[i]->posicao = i; //qual vertice estamos visitando
		}
	}
	vert[vert_i]->cor = 1; //cinza
	vert[vert_i]->distancia = 0; //distancia == 0
	vert[vert_i]->posicao = vert_i;
	insereFila(p, vert_i);
	while(isEmpty(p)){
		tmp = removeFila(p);
		printf("filhos de %d :", tmp);
		for (int i = 0; i < TAM; ++i){
			if(grafo[tmp][i]){        //verificando se a aresta existe
				if(vert[i]->cor == 0){ //if branco
					vert[i]->cor = 1;
					vert[i]->distancia = vert[tmp]->distancia +1;
					insereFila(p, i);
					printf(" %d", i);
					//jeremias(vert, TAM);
				}
			}
		}
		printf("\n");
		vert[tmp]->cor = 2;
	}
}