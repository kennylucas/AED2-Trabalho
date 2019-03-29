#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "questao1.h"
#include "questao2.h"
#define TAMANHO 1000000
//#define NULL ((void *)0)

/*
void imprimirNum(int num){
	printf("%d ", num);

}*/

int main(void){

	srand(time(NULL));//necessario pra gerar um valor aleatório diferente em cada execução. 
	//isso altera a semente de aleatoriedade da funcao rand();

	clock_t inicio, final;
	int chave = 0;
	double clockTime; 
	double mediaBuscaVetor, mediaBuscaLista;
	mediaBuscaLista = mediaBuscaVetor = 0;

	Lista* lista = criarLista();
	tipoVetor *tp = criaVetor();//o vetor que será usado esta criado e prenchido assim como a lista. 
	preencherVetorAleatoriamente(tp, TAMANHO);
	
	for(int i=0; i<TAMANHO; i++){
		inserirFinalLista(lista, retornaValorVetor(tp,i));
	}//aqui, o vetor é copiado para a lista. 

	//percorrerLista(lista, imprimirNum); printf("\n");
	for(int i =0;i<30;i++){

		chave = rand()%10000000;
		printf("chave:%d\n", chave);
		inicio = clock();
		buscaSequencialLista(lista, chave);
		//printf("%d\n",buscaSequencialLista(lista, chave));
		final = clock();
		clockTime = ((double) (final - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução da Busca Sequencial na Lista %d: %.4lfms\n", i+1, clockTime*100);
		mediaBuscaLista += clockTime;

		inicio = clock();
		buscaSequencial(tp, TAMANHO, chave);
        //printf("%d\n",buscaSequencial(tp, TAMANHO, chave));
        final = clock();
        clockTime = ((double) (final - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução da Busca Sequencial no Vetor %d: %.4lfms\n\n\n", i+1, clockTime*100);
        mediaBuscaVetor += clockTime;
		
	}

	mediaBuscaLista = mediaBuscaLista/30;
    mediaBuscaVetor = mediaBuscaVetor/30;

	printf("Media da busca sequencial na Lista: %lfms\n",mediaBuscaLista*100);
	printf("Media da busca sequencial no Vetor: %lfms\n",mediaBuscaVetor*100);

	//percorrerLista(lista, imprimirNum); printf("\n");
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