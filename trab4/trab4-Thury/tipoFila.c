#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tipoFila.h"
#include "tipoPilha.h"

struct tipoFila{
	tipoNoF *prim;
	tipoNoF *ult;
};

struct tipoNoF{
	int vertice;
	struct tipoNoF *prox;
};

int isEmpty(tipoFila *f){
	if(f->prim){
		return 1;
	}else{
		return 0;
	}
}

void criaFila(tipoFila **p){
	(*p) = (tipoFila*) malloc(sizeof(tipoFila));
	(*p)->prim = NULL;
	(*p)->ult = NULL;
}

void insereFila(tipoFila *p, int vert){
	tipoNoF *aux;
	aux = (tipoNoF*) malloc(sizeof(tipoNoF));
	aux->vertice = vert;
	aux->prox = NULL;
	if (!(p->prim)){
		p->prim = aux;
		p->ult = aux;
	}
	else{
		p->ult->prox = aux;
		p->ult = aux;
	}
}

int removeFila(tipoFila *p){
	tipoNoF *aux;
	int vert;
	aux = p->prim;
	vert = aux->vertice;
	if(aux->prox){
		p->prim = aux->prox;
	}
	else{
		p->prim = NULL;
	}
	free(aux);
	return vert;
}