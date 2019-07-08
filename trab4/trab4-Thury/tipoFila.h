#include <stdio.h>
#include <stdlib.h>
#include "tipoPilha.h"

typedef struct tipoFila tipoFila;

typedef struct tipoNoF tipoNoF;

int isEmpty(tipoFila *f);

void criaFila(tipoFila **p);

void insereFila(tipoFila *p, int vert);

int removeFila(tipoFila *p);