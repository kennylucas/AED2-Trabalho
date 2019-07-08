#include<stdio.h>
typedef struct arv {
	float nota;
	int matricula;
	int deslocamento;
	struct arv* esq;
	struct arv* dir;
}Arv;

int altura (Arv* a);

Arv* abp_inicializar(void);

Arv* abp_criar(int m,float n,int d);

int abp_vazia(Arv* a);

void abp_mostrar_central(Arv* a);

void abp_mostrar_pre(Arv* a);

void abp_mostrar_pos(Arv* a);

void menorQueArvore(Arv *raiz, int k, FILE *pf);

int abp_busca_binaria(Arv*a , int d, FILE * pf);

Arv* abp_inserir_matricula(Arv* a, int m,float n, int d);

Arv *abp_inserir_nota(Arv *a, int m,float n, int d);

/*void abp_encher(Arv* a, int tamanho);*/