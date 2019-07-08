#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int **GeraMatriz(int L, int C, int key){
	int i,j;
	int **m;

	m = (int**) malloc(L*sizeof(int*)); //Cria um vetor de vetores de ponteiros com a qtde de linhas

	for (i=0;i<L;i++){
		m[i] = (int*) malloc(C*sizeof(int)); //Para cada vetor de ponteiros, irá criar um vetor de inteiros com a qtde de colunas

		for (j=0;j<C;j++){
			m[i][j]=key;
		}
	}

	return m;
}

void DesalocaMatriz(TipoGrafo *G, int L){
	int i,j;

	for(i=0;i<L;i++){
		free(G->MatrizAdj[i]);
	}
	free(G->MatrizAdj);
	G->MatrizAdj=NULL;

}

void ZeraMatriz(TipoGrafo *G){
	int i,j;

	for (i=0;i<G->V;i++){
		for (j=0;j<G->V;j++){
			G->MatrizAdj[i][j]=0;
		}
	}

}

void MostraMatriz(TipoGrafo *G){
	int i,j,cont1;
	int cont2=0;
	if (G->V < 11){
		printf("     ");
		for(cont1=0;cont1 < G->V; cont1++){
			printf("%d     ",cont1);
		}

		for(i=0;i<G->V;i++){
			printf("\n\n");
			for(j=0;j<G->V;j++){
				if (j==0){
					printf("%d    ",cont2);
					cont2++;
				}
				printf("%d     ",G->MatrizAdj[i][j]);
			}
		}
	}
	else{

		for (i=0;i<G->V;i++){
			printf("-----------------------------------------------------------------------\n\n");
			for(j=0;j<G->V;j++){
				printf("[%d] --> [%d] = %d\n",i,j,G->MatrizAdj[i][j]);
			}
		}

	}
	printf("\n");
	getchar();
	
}