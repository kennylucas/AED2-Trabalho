#include <stdio.h>
#include <stdlib.h>
 
typedef struct tipoVetor{
    int vet[100];
}tipoVetor;

tipoVetor* criaVetor(){
    tipoVetor *tp = (tipoVetor *) malloc(sizeof(tipoVetor));
    return tp;
}

void preencherVetorAleatoriamente(tipoVetor *tp, int tamanho){
    tp->vet[0] = rand()%1;
    for(int i=1; i<tamanho; i++){
        tp->vet[i] =  tp->vet[i-1] + (rand()%10);
    }

}

int main(){
    
    tipoVetor *tp = criaVetor();

    preencherVetorAleatoriamente(tp, 100);

    for(int i =0; i<100;i++){
        printf("%d\n", tp->vet[i]);
    }
}