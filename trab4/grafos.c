#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

typedef struct TipoGrafo{
    int V;
    int A;
    int **MatrizAdj;
}TipoGrafo;

void Cria_Grafo(TipoGrafo *G, int vertices){

	G->V = vertices;
	G->A = 0;
	G->MatrizAdj = GeraMatriz(vertices,vertices,0);

}

int InserirA(TipoGrafo *G, int V1, int V2){
	if ((V1 < G->V) && (V2<G->V) && (G->MatrizAdj[V1][V2] == 0)){ // Verifica se o valor está no intervalo e se eles não estão conectados
		G->MatrizAdj[V1][V2]=1;
		G->MatrizAdj[V2][V1]=1;
		G->A++;
		vet_AV[V1]++;
		vet_AV[V2]++;
		// printf("\nAresta inserida com sucesso! \n" );
		// getchar();
		return 1;
	}
	return 0;
	// printf("\nOperacao nao realizada! \n" );
	// getchar();

}


int RemoverA(TipoGrafo *G, int V1, int V2){
	if ((V1 < G->V) && (V2<G->V) &&(G->MatrizAdj[V1][V2] == 1)){ // Faz as mesmas coisas que a inserir, mas verifica de eles já estão conectados
		G->MatrizAdj[V1][V2]=0;
		G->MatrizAdj[V2][V1]=0;
		G->A--; 
		// printf("\nAresta removida com sucesso! \n" );
		// getchar();
		return 1;
	}
	return 0;
	// printf("\nOperacao nao realizada! \n" );
	// getchar();

}

void Insere_Percentual(TipoGrafo *G, int QtdeArestas){
	int i,j;
	int x,aux,armazena;
	for (i=0; i<G->V;i++){
		armazena = QtdeArestas - vet_AV[i];
		for(j=0;j<armazena;j++){
			x= (int)rand() % (G->V);
			
			aux=InserirA(G,i,x);

			if(aux != 1){
				j--;
			}
		}
	}	
}

int Verifica_Conexao(TipoGrafo *G){
	int i;
	for(i=0;i<G->V;i++){ //Todos os elemenos do vetor visitado ficam 0, afim de iniciar o algoritmo
		visitado[i]=0;
	}
	Verifica_ConexaoInterno(G,0); //Retorna o vetor visitado indicando quais vértices o Vertice 0 está relacionado

	for (i=0;i<G->V;i++){

		if (visitado[i]!=1){ // 

			return 0;
		}
	} 
	return 1;	
}

void Gera_Grafo(TipoGrafo *G, int qtde_arestas,char optA){
	int x,y; // Para gerar os valores aleatorios
	int i,j,aux;

	for(i=0;i<(G->V)-1;i++){
			InserirA(G,i,i+1);
	} 

	if(optA == '0'){

		for(i=0;i<(qtde_arestas - G->V-1)+1;i++){
			x= (int)rand() % (G->V);
			//printf("\nx: %d \n",x);
			y= (int)rand() % (G->V);
			//printf("\ny: %d \n",y);
			aux=InserirA(G,x,y);
				if(aux != 1){
					i--;
				}
		}
	}

	else{
		Insere_Percentual(G,((G->V) * qtde_arestas)/100);
	}


}

int verifica_lista(int g){

	for (int i=0;i<cnt;i++){
		if(g==vet_profundidade[i])
			return 1; 	
	}
	return 0;
}


void Todos_caminhos(TipoGrafo *G,int c){
	vet_profundidade[cnt]=c; 
	cnt++;
	
	for(int j=0;j<G->V;j++){ 
		if (G->MatrizAdj[c][j]	== 1){
			if(j==d){ 
				for (int i=0;i<cnt;i++)
					printf("%d ",vet_profundidade[i]);
				printf("%d",d);	
				printf("\n"); 
			}
			else if	(verifica_lista(j)==0) 
				Todos_caminhos(G,j);			
			
		}
	}
	cnt--;
	return;
}


void Verifica_ConexaoInterno(TipoGrafo *G, int VA){
	int i;
	visitado[VA]=1; //Faz com que o vertice atual (VA) seja marcado como visitado
	for(i=0;i<G->V;i++){ //percorrer cada coluna da matriz 
		if(G->MatrizAdj[VA][i] == 1 && visitado[i] == 0){ // Se houver conexão entre os vert. VA e i e ele ainda não tiver sido visitado
			Verifica_ConexaoInterno(G,i); 
			/* Irá realizar uma chamada recursiva com o vértice i, 
			para realizar o mesmo procedimento com os vert. conectados à ele, até que todos tenham sido visitados
			*/
		}
	}

}

void Mostrar_Busca(TipoGrafo *G, int* vetor){
	int cont=0;
	int i,j;

	printf("\nOrdem de acesso: \n");

	// //Mostra vetor com as ordens de cada
	// for (i=0;i<G->V;i++){
	// 	printf("%d --> ", vet_profundidade[i]);
	// }
	// printf("END\n");

	for (i=0;i<G->V;i++){ // Mostra a ordem de acesso
		for(j=0;j<G->V && vetor[j] != cont;j++){} // laço para chegar no item correspondente à ordem de acesso
		if (!(j>G->V-1)){ //Imprime apenas se o valor foi encontrado
			cont++;
			printf("%d --> ", j);
		}
		else{
			i=G->V; //Para sair do laço principal, pois se não entrou no if anterior, não há motivo para continuar a execução
		}

	}
	printf("END\n");
}



void Busca_Profundidade(TipoGrafo *G, int VB){
	int i;
	int j=0;
	cont_profundidade=0;
	

	Busca_ProfundidadeInterno(G,VB);
	
	
}



void Busca_ProfundidadeInterno(TipoGrafo *G, int VB){ //VB = VÉRTICE BASE
	int i;
	
	vet_profundidade[VB] = cont_profundidade; //Faz com que o campo destinado à ordem de acesso do veŕtice atual seja preenchido 
	cont_profundidade++; // incrementa um para que na proxima chamada, o o proximo vertice fique na ordem correta de acesso
	for(i=0;i<G->V;i++){
		if(G->MatrizAdj[VB][i] == 1 && vet_profundidade[i] == -1 ){ //Se houver relação e o vértice i ainda não tenha sido acessado
			Busca_ProfundidadeInterno(G,i);
		}

	}
	
}


void Busca_Largura(TipoGrafo *G, int VB){
	int i,j,aux=0;
	for(i=0;i<G->V;i++){
		vet_largura[i]=-1; //Zera o vetor da ordem de acessos
	}

	
	inicio_largura = 0; //inicio da fila
	fim_largura = 0; //fim da fila

	vet_largura[VB] = aux++; //Faz com que a posição do vértice base seja colocada como primeira no vetor de acesso
	fila_largura[fim_largura++] = VB; // Vertice base no inicio da fila

	while(inicio_largura != fim_largura){ //Repete enquanto a fila não tiver acabado
		i=fila_largura[inicio_largura++]; // pega o primeiro da fila

		for(j=0;j<G->V;j++){

			if(vet_largura[j] == -1 && G->MatrizAdj[i][j] == 1){
				vet_largura[j] = aux++; //Faz com que a ordem de acesso de cada vertice relacionado com o j mude
				fila_largura[fim_largura++] = j; //coloca, em ordem, os vizinhos do vértice j na fila
			}

		}
	}

}

void Preenche_AV(TipoGrafo *G){
	int i,j,contA=0;

	for(i=0;i<G->V;i++){
		for(j=0;j<G->V;j++){
			if(G->MatrizAdj[i][j] == 1){
				contA++;
			}
		}
		vet_AV[i] = contA;
		contA=0;
	}
}











