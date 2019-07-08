#include <stdio.h>
typedef struct aluno
{
    int ingresso;
    float nota;
    char nome[50];
    int idade;
    int matricula;
    int deslocamento;
} Aluno;

int busca_sequencial(FILE *pf, int chave);

void ler_registro(FILE *pf);

int busca_sequencial_intervalo(FILE *pf, float nota);

void preenche_arquivo(FILE *pf, int vet[], float vet2[], int n);

size_t gravar_registro(FILE *pf, int ingresso, float nota, char *nome, int idade, int mat, int des);