
#include "tipoVet.h"

typedef struct tipoArv tipoArv;

tipoArv* Cria_Arvore(tipoArv *arv, int n);

int Insere_Elemento(tipoArv *arv,int n);

void Imprime_Arvore_Pre(tipoArv *arv);

void Imprime_Arvore_Central(tipoArv *arv);

void Imprime_Arvore_Pos(tipoArv *arv);

void Vet_To_Tree(tipo_vet vet,int tam, tipoArv **arv);

void Preenche_Arvore_Rnd(tipoArv **arv,int tam);