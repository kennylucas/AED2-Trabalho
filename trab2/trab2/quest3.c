#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../arvore/abp.h"
#include "../vetor/vetor.h"
#define N 1000000
#define MAX 5000000
#define CLOCKS_PER_MSEC 1000.0
#define RODADAS 30

int main(void){

	int vet[N], chave, indiceChave;
	No* arvore = criarArvore();
	No* noChave;
	clock_t inicio, fim;
	double tempo, tempoVetor = 0.0, tempoArvore = 0.0;

	preencherVetorAleatoriamenteSemRepeticao(vet, N, 2);

	preencherArvoreVetor(vet, N, &arvore);
	quickSort(vet, 0, N);

	//preencherEstruturas(vet, &arvore);

	for(int cont = 0; cont < RODADAS; cont++){

		chave = rand() % N*2;

		printf("====== Rodada %02d ======\n\n", cont + 1);
		printf("Chave de busca: %d\n\n", chave);

		inicio = clock();
		indiceChave = buscaBinaria(vet, N, chave);
		fim = clock();
		tempoVetor += tempo = (fim - inicio)/CLOCKS_PER_MSEC;
		printf("Vetor: %lf ms    | Índice: %d\n", tempo, indiceChave);

		inicio = clock();
		noChave = buscaArvore(arvore, chave);
		fim = clock();
		tempoArvore += tempo = (fim - inicio)/CLOCKS_PER_MSEC;
		printf("Árvore: %lf ms   | Ponteiro: %p\n\n", tempo, noChave);

	}

	printf("#######################\n\n");
	printf("Tempo médio de execução dos algoritmos de busca em cada estrutura:\n\n");
	printf("Vetor: %lf ms\n", tempoVetor/RODADAS);
	printf("Árvore: %lf ms\n", tempoArvore/RODADAS);

	return 0;

}