/*vetor c/ 1milhão de elementos ordenados
 - executar a busca sequencial e binária 30 vezes cada, para cada busca, um vetor diferente.
 - mostrar o tempo de execução para cada busca e a média para cada tipo algoritmo. 

 */
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "questao1.h"

int main(){

    tipoVetor *tp = criaVetor();

    preencherVetorAleatoriamente(tp, 100);

    for(int i =0; i<100;i++){
        printf("%d\n", tp->vet[i]);
    }
}
