void criarLista(tipoNo **p) {
  	*p = NULL;
}

void destroiLista(tipoLista *l) {
  tipoNo *auxPrim,*aux;
  auxPrim = l->prim;
  l->prim = NULL;
  while(auxPrim) {
    aux = auxPrim;
    auxPrim = auxPrim->prox;
    free(aux);
  }
}

void inserirElementoLista(tipoNo **prim, tipoDado d) {
  	tipoNo *aux;

  	aux = (tipoNo *) malloc (sizeof(tipoNo));
  	if(!aux) {
    	exit(1); // ALGO DEU MUITO ERRADO!
  	}
  	aux->d = d;   // ou ainda (*aux).d = d;
  	aux->prox = *prim;
  	*prim = aux;

}

void removeElementoLista(tipoLista *l, char chave[]) {
  tipoNo *ant,*atual;

  ant = l->prim;

  if(ant) {   // Se há elementos na lista
    if( strcmp(chave,ant->d.nomeCurso)== 0)  {//se quero apagar 1o
      l->prim =  ant->prox;
      free(ant);
    } else { // se nao era o 1o, busca no resto da lista
      while(ant->prox != NULL) {   // while(ant->prox) {
	if( strcmp(chave,ant->prox->d.nomeCurso)== 0)  {
	  // entra aqui se achou alguem pra apagar
	  atual = ant->prox;
	  ant->prox = atual->prox;
	  free(atual);
	  return;
	}
	ant = ant->prox;
      } 
    }
  }
}

void mostrarLista(tipoNo *p) {

  	while(p != NULL) {   // while(p) {
    	printf("id: %d\n",p->d.id);
    	p = p->prox;
	} 
}

