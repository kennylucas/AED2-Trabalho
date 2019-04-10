/*vetor c/ 1milhão de elementos ordenados
 - executar a busca sequencial e binária 30 vezes cada, para cada busca, um vetor diferente.
 - mostrar o tempo de execução para cada busca e a média para cada tipo algoritmo. 

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"

#define TAMANHO 1000000

int main(){

    srand(clock());//necessario pra gerar um valor aleatório diferente em cada execução. 
	//isso altera a semente de aleatoriedade da funcao rand();

    clock_t inicio, final;
    int chave, lixo;
    double clockTime;
    double mediaSequencial, mediaBinaria;
    mediaSequencial = mediaBinaria = 0;
    printf("Vetor não criado, digite 0 para continuar.\n");
    scanf("%d", &lixo);
    tipoVetor *tp = criaVetor();
    printf("Vetor vazio, digite 0 para continuar.\n");
    scanf("%d", &lixo);
    preencherVetorAleatoriamente(tp, TAMANHO);
    printf("Vetor preenchido, digite 0 para continuar.\n");
    scanf("%d", &lixo);

    for(int i=0;i<30;i++){
        chave = rand()%10000000000;

        //Execução busca binaria
        inicio = clock();
        buscaSequencial(tp, TAMANHO, chave);
        final = clock();
        clockTime = ((double) (final - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução da Busca Sequencial %d: %.4lfms\n", i+1, clockTime*1000);
        mediaSequencial += clockTime;

        //execucao busca sequencial
        inicio = clock();
        buscaBinaria(tp, TAMANHO, chave);
        final = clock();
        clockTime = ((double) (final - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução da Busca Binaria %d: %.4lfms\n\n\n", i+1, clockTime*1000);
        mediaBinaria += clockTime;

    }
    mediaBinaria = mediaBinaria/30;
    mediaSequencial = mediaSequencial/30;

    printf("Media da busca sequencial: %lfms\n",mediaSequencial*1000);
	printf("Media da busca binaria: %lfms\n",mediaBinaria*1000);

    /*for(int i =0; i<100;i++){
        printf("%d\n", tp->vet[i]);
    }*/
}
