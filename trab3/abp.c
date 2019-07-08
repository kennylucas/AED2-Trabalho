#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"
#include "arquivo.h"

int altura(Arv *a)
{
	if (a == NULL)
		return 0;
	else
	{

		int altura_e = altura(a->esq);
		int altura_d = altura(a->dir);

		if (altura_e > altura_d)
			return (altura_e + 1);
		else
			return (altura_d + 1);
	}
}

Arv *abp_inicializar(void)
{
	return NULL;
}

Arv *abp_criar(int m, float n, int d)
{
	Arv *raiz = (Arv *)malloc(sizeof(Arv));
	raiz->nota = n;
	raiz->matricula = m;
	raiz->deslocamento = d;
	raiz->esq = abp_inicializar();
	raiz->dir = abp_inicializar();
	printf("%f\n", raiz->nota);

	return raiz;
}

int abp_vazia(Arv *a)
{
	return a == NULL;
}

/*void abp_mostrar_central(Arv *a)
{
	if (!abp_vazia(a))
	{
		abp_mostrar_central(a->esq);
		printf("\n");
		printf("nota:%f\n", a->nota);
		printf("\nmatricula:%d ", a->matricula);
		printf("\nposição:%d ", a->deslocamento);
		abp_mostrar_central(a->dir);
	}
}*/

void abp_mostrar_pre(Arv *a)
{
	if (!abp_vazia(a))
	{
		printf("\n");
		printf("matricula: %d\n", a->matricula);
		printf("nota:%f\n", a->nota);
		printf("posição:%d\n ", a->deslocamento);
		abp_mostrar_pre(a->esq);
		abp_mostrar_pre(a->dir);
	}
}

/*void abp_mostrar_pos(Arv* a){
	if (!abp_vazia(a))
	{
		abp_mostrar_pos(a->esq);
		abp_mostrar_pos(a->dir);
		printf("%d ", a->dado);
	}
}*/

int abp_busca_binaria(Arv *a, int d, FILE *pf)
{
	if (!abp_vazia(a))
	{
		if (a->matricula == d)
		{
			Aluno b;

			fseek(pf, a->deslocamento * sizeof(Aluno), SEEK_SET);
			fread(&b, sizeof(Aluno), 1, pf);
			printf("Forma de ingresso: %d\n", b.ingresso);
			printf("Nota             : %0.2f\n", b.nota);
			printf("Nome             : %s\n", b.nome);
			printf("Idade            : %d\n", b.idade);
			printf("matricula        : %d\n", b.matricula);
			printf("posição no arquivo:%d\n", b.deslocamento);

			return 1;
		}

		if (a->matricula > d)
			return abp_busca_binaria(a->esq, d, pf);

		else
			return abp_busca_binaria(a->dir, d, pf);
	}
	return 0;
}

/*Arv* abp_inserir_nota(Arv_n* a, int n, int d){
	if(a==NULL){
		a = (Arv*)malloc(sizeof(Arv));
		a->nota = n;
		a->deslocamento = d;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if(a->dado >= n){
		a->esq = abp_inserir_com(a->esq, n);
	}
	else{
		a->dir = abp_inserir_com(a->dir, n);
	}
	return a;
}*/

Arv *abp_inserir_nota(Arv *a, int m, float n, int d)
{
	if (a == NULL)
	{
		a = (Arv *)malloc(sizeof(Arv));
		a->matricula = m;
		a->deslocamento = d;
		a->nota = n;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if (a->nota >= n)
	{
		a->esq = abp_inserir_nota(a->esq, m, n, d);
	}
	else
	{
		a->dir = abp_inserir_nota(a->dir, m, n, d);
	}
	return a;
}

Arv *abp_inserir_matricula(Arv *a, int m, float n, int d)
{
	if (a == NULL)
	{
		a = (Arv *)malloc(sizeof(Arv));
		a->matricula = m;
		a->deslocamento = d;
		a->nota = n;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if (a->matricula >= m)
	{
		a->esq = abp_inserir_matricula(a->esq, m, n, d);
	}
	else
	{
		a->dir = abp_inserir_matricula(a->dir, m, n, d);
	}
	return a;
}

void menorQueArvore(Arv *raiz, int k, FILE *pf){
	if (NULL == raiz){
		return;
	}

	menorQueArvore(raiz->esq, k, pf);
	if(raiz->nota > k){
		Aluno b;
		fseek(pf, raiz->deslocamento * sizeof(Aluno), SEEK_SET);
		fread(&b, sizeof(Aluno), 1, pf);
	}
	menorQueArvore(raiz->dir, k, pf);
}
