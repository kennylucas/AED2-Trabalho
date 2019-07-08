#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tipoPilha.h"




struct tipoNo{
	int vertice;
	struct tipoNo *prox;
};

struct tipoPilha{
	tipoNo *prim;
};

void criaPilha(tipoPilha **p){
	(*p) = (tipoPilha*) malloc(sizeof(tipoPilha));
	(*p)->prim = NULL;
}


void inserePilha(tipoPilha *p, int vert){
	tipoNo *aux;
	aux = (tipoNo*) malloc(sizeof(tipoNo));
	aux->vertice = vert;
	aux->prox = p->prim;
	p->prim = aux;
}

void removePilha(tipoPilha *p){
	tipoNo *aux;
	int vert;
	aux = p->prim;
	p->prim = aux->prox;
	vert = aux->vertice;
	free(aux);
	//return(vert);
}

void imprimePilhaAx(tipoNo *p){
	if(p){
		if(p->prox){
			imprimePilhaAx(p->prox);
		}
		printf("-> %d ",p->vertice);
	}
}

void imprimePilha(tipoPilha *p){
	imprimePilhaAx(p->prim);
}