#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivo.h"

size_t gravar_registro(FILE *pf, int ingresso, float nota, char *nome, int idade, int mat, int des)
{
    Aluno a;
    a.ingresso = ingresso;
    a.nota = nota;
    strcpy(a.nome, nome);
    a.idade = idade;
    a.matricula = mat;
    a.deslocamento = des;
    return fwrite(&a, sizeof(Aluno), 1, pf);
}

void preenche_arquivo(FILE *pf, int vet[], float vet2[], int n)
{
    srand(time(NULL));
    fseek(pf, 0, SEEK_SET);
    int age, ti;
    float nota;
    int matricula, deslocamento;

    for (int j = 0; j < n; j++)
    {
        age = 17 + rand() % 20;
        ti = 1 + rand() % 3;
        nota = vet2[j];
        matricula = vet[j];
        deslocamento = j;
        gravar_registro(pf, ti, nota, "Fulano", age, matricula, deslocamento);
    }
}

void ler_registro(FILE *pf)
{
    Aluno a;
    fseek(pf, 0, SEEK_SET);
    while (fread(&a, sizeof(Aluno), 1, pf))
    {
        printf("Nota             : %0.2f\n", a.nota);
        printf("\n");
    }
}

int busca_sequencial(FILE *pf, int chave)
{
    Aluno a;
    fseek(pf, 0, SEEK_SET);
    while (fread(&a, sizeof(Aluno), 1, pf))
    {
        if (a.matricula == chave)
        {
            printf("Forma de ingresso: %d\n", a.ingresso);
            printf("Nota             : %0.2f\n", a.nota);
            printf("Nome             : %s\n", a.nome);
            printf("Idade            : %d\n", a.idade);
            printf("matricula        : %d\n", a.matricula);
            printf("posição no arquivo: %d\n", a.deslocamento);
            return 1;
        }
    }
    return 0;
}

int busca_sequencial_intervalo(FILE *pf, float nota)
{
    Aluno a;
    int cont = 0;
    fseek(pf, 0, SEEK_SET);
    
    printf("Buscando MENOR QUE\n");
    while (fread(&a, sizeof(Aluno), 1, pf))
    {
        if (a.nota < nota)
        {
            cont++;
        }
    }
    return cont;
    
    
}
