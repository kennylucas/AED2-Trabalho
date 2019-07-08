#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../arvore/abp.h"
#include "../vetor/vetor.h"
#define N 100



int main(){
    
    int vet[N];
    No* arvore = criarArvore();
    No* noChave;

    srand(clock());
    preencherVetorAleatoriamente(vet, N);

    quickSort(vet, 0, (N/2));
    printf("Pacotes Enviados:");
    printf("\n");
    imprimirVetor(vet, N);
    preencherArvoreVetor(vet, N, &arvore);
    printf("\n\n");
    printf("Pacotes recebidos e organizados:");
    printf("\n");
    impressaoCentral(arvore);
    printf("\n\n");
    //quickSort(vet,0,N);
    //imprimirVetor(vet, N);
}