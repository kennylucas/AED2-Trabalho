#include <stdio.h>
#include <stdlib.h>
#include "tipoArv.h"

 struct tipoArv{ //Nó das arvores
	int id;
	struct tipoArv *esq; //Aponta para a folha/sub-arvore esquerda
	struct tipoArv *dir; //Aponta para a folha/sub-arvore direita
};


tipoArv* Cria_Arvore( tipoArv *arv, int n){ //Recebe ponteiro para ponteiro (ou  endereço para ponteiro) e o header
	arv = (tipoArv *) malloc(sizeof(tipoArv)); //Faz o ponteiro apontado pelo ponteiro receber o endereco do header
	(*arv).id = n;
	(arv)->esq = NULL;
	(arv)->dir = NULL;
	return arv;
}

//Insere que faz a arvore crescer apenas para a direita ou esquerda!
//assume que o raiz ja ta inicializado
int Insere_Elemento(tipoArv *arv,int n){ //Recebe o pontiero p/ ponrtiero e o elemento que vai ser inserido
	if(arv->esq == NULL){ //Verifica se existe elemento na folha esquerda
		if(arv->id >= n){
			tipoArv *temp = Cria_Arvore((arv)->esq,n);
			arv->esq = temp;	
			return 1;
		}				
	}
	else if (arv->id >= n){ //para evitar a criacao de nos duplicados e evitar segfault
		Insere_Elemento((arv)->esq,n);
	}

	if(arv->dir == NULL){//Verifica se existe elemento na folha direita
		if(arv->id < n){
			tipoArv *temp = Cria_Arvore((arv)->dir,n);
			arv->dir = temp;	
			return 1;
		}
	}
	else if (arv->id < n){
		Insere_Elemento((arv)->dir,n);
	}
}

void Imprime_Arvore_Pre(tipoArv *arv){ //Imprime toda a arvore dando prioridad para elementos da esquerda(ou seja nesse caso elementos impares)
	if(arv != NULL){ //verifica se a arvore acabou!
		printf("%d\n",(arv)->id);
		Imprime_Arvore_Pre(arv->esq); //Chama recursivamente para imprimir a folha/sub-arvore da esquerda
		Imprime_Arvore_Pre(arv->dir); //Chama recursivamente para imprimir a folha/sub-arvore da direita
	}
}

void Imprime_Arvore_Central(tipoArv *arv){ //Imprime toda a arvore dando prioridad para elementos da esquerda(ou seja nesse caso elementos impares)
	if(arv != NULL){ //verifica se a arvore acabou!
		Imprime_Arvore_Central(arv->esq); //Chama recursivamente para imprimir a folha/sub-arvore da esquerda
		printf("%d\n",(arv)->id);
		Imprime_Arvore_Central(arv->dir); //Chama recursivamente para imprimir a folha/sub-arvore da direita
	}
}

void Imprime_Arvore_Pos(tipoArv *arv){ //Imprime toda a arvore dando prioridad para elementos da esquerda(ou seja nesse caso elementos impares)
	if(arv != NULL){ //verifica se a arvore acabou!
		Imprime_Arvore_Pos(arv->esq); //Chama recursivamente para imprimir a folha/sub-arvore da esquerda
		Imprime_Arvore_Pos(arv->dir); //Chama recursivamente para imprimir a folha/sub-arvore da direita
		printf("%d\n",(arv)->id);
	}
}

void Vet_To_Tree(tipo_vet vet,int tam, tipoArv **arv){
	int i;
	*(arv) = Cria_Arvore((*arv),vet[0]);
	for (i = 1; i<tam; i++){
		Insere_Elemento((*arv),vet[i]);
	}
}

void Preenche_Arvore_Rnd(tipoArv **arv,int tam){
	int i;
	*(arv) = Cria_Arvore((*arv),rand()%51);
	for (i = 1; i<tam; i++){
		Insere_Elemento((*arv),rand()%51);
	}
}

/*
int main(){
	tipoArvore *arvore;

	arvore = Cria_Arvore(arvore,0);
	Insere_Elemento(arvore,1);
	Insere_Elemento(arvore,4);
	Insere_Elemento(arvore,3);
	Insere_Elemento(arvore,2);
	Insere_Elemento(arvore,5);
	Insere_Elemento(arvore,8);
	Insere_Elemento(arvore,-1);
	Insere_Elemento(arvore,-2);
	Insere_Elemento(arvore,-3);

	Imprime_Arvore_Pre(arvore);
	printf("---------------\n");
	Imprime_Arvore_Central(arvore);
	printf("---------------\n");
	Imprime_Arvore_Pos(arvore);
	printf("---------------\n");



	return 0;
}
*/