/*vetor c/ 1milhão de elementos ordenados
 - executar a busca sequencial e binária 30 vezes cada, para cada busca, um vetor diferente.
 - mostrar o tempo de execução para cada busca e a média para cada tipo algoritmo. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor.h"
//#include "lista.h"

struct tipoVetor{
    int vet[1000000];
};


tipoVetor* criaVetor(){
    tipoVetor *tp = (tipoVetor *) malloc(sizeof(tipoVetor));
    return tp;
}

int retornaValorVetor(tipoVetor *p1, int indice){
    return p1->vet[indice];
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
    tp->vet[0] = 0;
    for(int i=1; i<tamanho; i++){
        tp->vet[i] =  tp->vet[i-1] + (rand()%5);
        //tp -> vet[tamanho] = 
    }
}
/*
0 3 9 16 21 24 29 35 37 46 47 49 56 56 65 68 74 74 80 82 88 89 97 104 113 115 115 117 120 127 132 141 143 145 153 162 169 172 178 179 181 190 193 194 203 207 214 222 226 231 231 234 240 241 241 247 250 252 252 258 259 264 269 273 280 286 291 297 306 309 316 320 325 327 332 336 343 347 351 354 354 361 369 375 383 391 395 398 399 403 412 414 414 420 428 437 439 445 451 455 
*/
