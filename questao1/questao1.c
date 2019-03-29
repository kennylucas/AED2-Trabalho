/*vetor c/ 1milhão de elementos ordenados
 - executar a busca sequencial e binária 30 vezes cada, para cada busca, um vetor diferente.
 - mostrar o tempo de execução para cada busca e a média para cada tipo algoritmo. 

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "questao1.h"

#define TAMANHO 1000000

int main(){

    clock_t inicio, final;
    int chave;
    double clockTime;
    double mediaSequencial, mediaBinaria;
    mediaSequencial = mediaBinaria = 0;
    tipoVetor *tp = criaVetor();
    preencherVetorAleatoriamente(tp, TAMANHO);

    for(int i=0;i<30;i++){
        chave = rand()%10000000000;

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

    /*for(int i =0; i<100;i++){
        printf("%d\n", tp->vet[i]);
    }*/
}
