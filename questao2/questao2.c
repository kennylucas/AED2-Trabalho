#include <stdlib.h>
#include <stdio.h>
#include "questao1.h"
#include "questao2.h"
#define TAMANHO 1000000

void imprimirNum(int num){

	printf("%d ", num);

}

int main(void){

	Lista* lista = criarLista();
	tipoVetor *tp = criaVetor();//o vetor que será usado esta criado e prenchido assim como a lista. 
	preencherVetorAleatoriamente(tp, TAMANHO);
	//agora, preciso fazer uma copia desse vetor para a lista. como a lista é preenchida ao contrario, colocarei o novo
	//elemento sempre no final da lista.

	for(int i=0; i<TAMANHO; i++){
		inserirFinalLista(lista, tp->vet[i]);
	}//aqui, o vetor é copiado para a lista. 

	percorrerLista(lista, imprimirNum); printf("\n");


	



	/*
	inserirFinalLista(lista, 1);
	inserirFinalLista(lista, 2);
	inserirFinalLista(lista, 3);

	percorrerLista(lista, imprimirNum); printf("\n");

	removerInicioLista(lista);
	removerFinalLista(lista);

	percorrerLista(lista, imprimirNum); printf("\n");
	*/
	return 0;
	
}