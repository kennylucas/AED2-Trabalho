#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "questao1.h"
#include "questao2.h"

#define TAMANHO 1000000

int main(){

    clock_t inicio, final;
    int chave;
    double clockTime;
    double mediaSequencial, mediaBinaria;
    mediaSequencial = mediaBinaria = 0;
    tipoVetor *tp = criaVetor();
    preencherVetorAleatoriamente(tp, TAMANHO);
    printf("----------Questão 1----------\n\n");

    for(int i=0;i<30;i++){
        chave = rand()%10000000;

        //Execução busca binaria
        inicio = clock();
        buscaSequencial(tp, TAMANHO, chave);
        final = clock();
        clockTime = ((double) (final - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução da Busca Sequencial %d: %.4lfms\n", i+1, clockTime*100);
        mediaSequencial += clockTime;

        //execucao busca sequencial
        inicio = clock();
        buscaBinaria(tp, TAMANHO, chave);
        final = clock();
        clockTime = ((double) (final - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução da Busca Binaria %d: %.4lfms\n\n\n", i+1, clockTime*100);
        mediaBinaria += clockTime;

    }
    mediaBinaria = mediaBinaria/30;
    mediaSequencial = mediaSequencial/30;

    printf("Media da busca sequencial: %lfms\n",mediaSequencial*100);
	printf("Media da busca binaria: %lfms\n",mediaBinaria*100);

    printf("----------Questão 2----------\n\n");	
	
    Lista* lista = criarLista();
	for(int i=0; i<TAMANHO; i++){
		inserirFinalLista(lista, retornaValorVetor(tp,i));
	}//aqui, o vetor é copiado para a lista. 

    inicio = final = 0;
    double mediaBuscaLista, mediaBuscaVetor;
    mediaBuscaVetor = mediaBuscaLista = 0;

	//percorrerLista(lista, imprimirNum); printf("\n");
	for(int i=0;i<30;i++){

		chave = rand()%10000000;
		//printf("chave:%d\n", chave);
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


    /*for(int i =0; i<100;i++){
        printf("%d\n", tp->vet[i]);
    }*/
}