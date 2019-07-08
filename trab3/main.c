#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivo.h"
#include "abp.h"
#include "hash.h"

#define K 10000

Hash tabela;

void embaralhar_vetor(int vet[], int vetSize)
{
    for (int i = 0; i < vetSize; i++)
    {
        int r = rand() % vetSize;

        int temp = vet[i];
        vet[i] = vet[r];
        vet[r] = temp;
    }
}

int main()
{
    double tempo, tempo_hash = 0, tempo_abp = 0, tempo_disco = 0;
    srand(time(NULL));
    clock_t inicio, fim;

    //-----------Preparando vetor de matrículas-----------//
    int vet[K], chave, result;
    float vet2[K], nota;

    for (int i = 0; i < K; i++)
    {
        vet[i] = i;
        vet2[i] = ((float)rand() / (float)(RAND_MAX)) * 10;
    }

    embaralhar_vetor(vet, K);

    //-----------Preparando arquivo-----------//
    FILE *arq = NULL;
    arq = fopen("registro.bin", "wb");

    //Disco
    preenche_arquivo(arq, vet, vet2, K); //Preenche o disco com os dados

    //Árvore
    Arv *raiz = abp_criar(vet[0], vet2[0], 0);  //Obter raiz
    Arv *raiz2 = abp_criar(vet[0], vet2[0], 0); //Obter raiz

    for (int i = 1; i < K; ++i)
    {
        abp_inserir_matricula(raiz, vet[i], vet2[i], i); //Preencher Árvore de matriculas
        abp_inserir_nota(raiz, vet[i], vet2[i], i);      //Preencher Árvore de notas
    }

    //Hash
    for (int i = 0; i < K; ++i)
    {
        inserir_Hash(tabela, vet[i], i); //Preencher Hash
    }

    //Número total de colisões na Hash
    printf("Número total de colisões na Hash: %d \n\n", colisoes(tabela));

    fclose(arq);

    //---------------------------------------------------------------QUESTOES---------------------------------------------------------------//
    arq = fopen("registro.bin", "rb");

    printf("Resultados das Buscas por matrícula:\n\n");
    for (int i = 0; i < 30; ++i)
    {
        chave = rand() % K * 2;
        printf("\n------------------------------------------\n");
        printf("\nDado buscado: %d\n", chave);

        //---------------------------------------------------ABP---------------------------------------------------//
        printf("\nABP:\n");
        inicio = clock();
        result = abp_busca_binaria(raiz, chave, arq);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%d\n", result);
        printf("%f\n", tempo);

        tempo_abp = tempo_abp + tempo;

        //---------------------------------------------------DISCO---------------------------------------------------//
        printf("\n\nDisco:\n");
        inicio = clock();
        result = busca_sequencial(arq, chave);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%d\n", result);
        printf("%f\n", tempo);

        tempo_disco = tempo_disco + tempo;

        //---------------------------------------------------HASH---------------------------------------------------//
        printf("\n\nHash:\n");
        inicio = clock();
        result = busca_hash(tabela, chave, arq);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("%d\n", result);
        printf("%08lf\n", tempo);

        tempo_hash = tempo_hash + tempo;
    }

    //---------------------------- MÉDIAS DO TEMPO ----------------------------//
    printf("\n\n---------------------------- MÉDIAS DO TEMPO ----------------------------\n\n");
    printf("Média do tempo em DISCO: %08lf\nMédia do tempo da ABP: %08lf\nMédia do tempo da HASH: %08lf\n", tempo_disco / 30, tempo_abp / 30, tempo_hash / 30);

    //---------------------------- BUSCAS POR INTERVALO ----------------------------//
    double tempo_disco_menor = 0, tempo_disco_maior = 0;
    double tempo_abp_menor = 0, tempo_abp_maior = 0;

    for (int i = 0; i < 30; i++)
    {
        printf("-----------------------------------------------------");

        nota = ((float)rand() / (float)(RAND_MAX)) * 10;
        printf("Item a ser buscado: %f\n\n", nota);

        printf("\nDISCO MENOR QUE:\n");
        inicio = clock();
        result = busca_sequencial_intervalo(arq, nota);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Quantidades: %d\n", result);
        printf("%f\n", tempo);

        tempo_disco_menor = tempo_disco_menor + tempo;

        //------------------------------------------------------------//

        printf("\nABP MENOR QUE:\n");
        inicio = clock();
        menorQueArvore(raiz2, nota, arq);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("%f\n", tempo);

        tempo_abp_menor = tempo_abp_menor + tempo;

    }

    //---------------------------- MÉDIAS DO TEMPO ----------------------------//
    printf("\n\n---------------------------- MÉDIAS DO TEMPO ----------------------------\n\n");
    printf("Média do tempo em DISCO MENOR QUE: %08lf\nMédia do tempo da ABP MENOR: %08lf\n", tempo_disco_menor / 30, tempo_abp_menor / 30);

    fclose(arq);
}