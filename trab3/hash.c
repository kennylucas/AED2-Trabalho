#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hash.h"
#include "arquivo.h"

int hash(int matricula)
{
	return (matricula % N);
}

Aluno_h *inserir_Hash(Hash tabela, int matricula, int deslocamento)
{
	int n = hash(matricula);
	Aluno_h *aux = NULL;
	Aluno_h *bux = tabela[n];
	while (bux != NULL)
	{
		if (bux->matricula == matricula)
		{
			printf("Este aluno já está na Hash\n");
			return NULL;
		}
		aux = bux;
		bux = bux->prox;
	}

	if (bux == NULL)
	{
		bux = (Aluno_h *)malloc(sizeof(Aluno_h));
		bux->matricula = matricula;
		bux->prox = NULL;
		if (aux == NULL)
		{
			tabela[n] = bux;
		}
		else
		{
			aux->prox = bux;
		}
	}
	bux->deslocamento = deslocamento;
	return bux;
}

int busca_hash(Hash tabela, int matricula, FILE *arq)
{
	int h = hash(matricula);
	Aluno_h *aux = tabela[h];
	while (aux != NULL)
	{
		if (aux->matricula == matricula)
		{
			Aluno b;
			fseek(arq, aux->deslocamento * sizeof(Aluno), SEEK_SET);
			fread(&b, sizeof(Aluno), 1, arq);
			printf("Forma de ingresso: %d\n", b.ingresso);
			printf("Nota             : %0.2f\n", b.nota);
			printf("Nome             : %s\n", b.nome);
			printf("Idade            : %d\n", b.idade);
			printf("matricula        : %d\n", b.matricula);
			printf("posição no arquivo:%d\n", b.deslocamento);

			return 1;
		}
		aux = aux->prox;
	}
	return 0;
}

int colisoes(Hash tabela)
{
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		Aluno_h *aux = tabela[i];
		if (aux->prox != NULL)
		{
			while (aux->prox != NULL)
			{
				aux = aux->prox;
				total++;
			}
		}
	}
	return total;
}

void mostrar_hash(Hash tabela)
{
	for (int i = 0; i < N; i++)
	{
		Aluno_h *aux = tabela[i];
		while (aux != NULL)
		{
			printf("Matrícula do aluno:%d\n", aux->matricula);
			aux = aux->prox;
		}
		printf("saindo da linha: %d\n", i);
	}
}
