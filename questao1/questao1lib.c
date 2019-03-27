/*vetor c/ 1milhão de elementos ordenados
 - executar a busca sequencial e binária 30 vezes cada, para cada busca, um vetor diferente.
 - mostrar o tempo de execução para cada busca e a média para cada tipo algoritmo. 

*/

#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

struct tipoVetor{
    int vet[1000000];
};

#include "questao1.h"




tipoVetor* criaVetor(){
    tipoVetor *tp = (tipoVetor *) malloc(sizeof(tipoVetor));
    return tp;
}

int buscaSequencial(tipoVetor *tp, int tamanho, int numero)
{
    for(int i=0; i<tamanho; i++){
        if(tp->vet[i] ==  numero){//como o vetor está passado como ponteiro, utiliza tp->vet pra acessar o indice.
            return 1; //caso ele encontro o número.
        }
    }
    return 0;//caso não encontre o número.
}

int buscaBinaria(tipoVetor *tp, int tamanho, int numero)
{
    int inicio, meio, fim;
    inicio = 0;//vetor começa em 0
    fim = tamanho - 1;//o final do vetor é o tamanho menos um. já que os indices começam em 0 e o tamanho em 1.
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        if(tp->vet[meio] == numero){
            return 1;
        }
        if(tp->vet[meio] < numero){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
        return -1;
    }
}

//para preencher de forma aleatoria, ahcei um vidoe no yt falando sobe a função rand()
//vet[i]=rand()%n; a função cria numeros aleatoriamente de 1 até n. 
void preencherVetorAleatoriamente(tipoVetor *tp, int tamanho)
{
    tp->vet[0] = rand()%1;
    for(int i=1; i<tamanho; i++){
        tp->vet[i] =  tp->vet[i-1] + (rand()%10);
    }
}