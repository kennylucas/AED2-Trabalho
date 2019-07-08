#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../arvore/abp.h"
#define N 50
#define MAX 1001

int main(void){

	No* arvore = criarArvore();

	preencherArvoreAleatorio(&arvore, N, MAX);

	printf("=== Questão 1 ===\n\n");
	printf("- Impressão com caminhamento pré-fixado: \n");
	impressaoPrefixado(arvore); printf("\n");
	printf("\n- Impressão com caminhamento central: \n");
	impressaoCentral(arvore); printf("\n");
	printf("\n- Impressão com caminhamento pós-fixado: \n");
	impressaoPosfixado(arvore); printf("\n");

	return 0;

}