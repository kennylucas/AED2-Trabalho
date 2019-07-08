#include <stdio.h>
#include <stdlib.h>



typedef struct tipoNo tipoNo;

typedef struct tipoPilha tipoPilha;

void criaPilha(tipoPilha **p);

void inserePilha(tipoPilha *p, int vert);

void removePilha(tipoPilha *p);

void imprimePilhaAx(tipoNo *p);

void imprimePilha(tipoPilha *p);