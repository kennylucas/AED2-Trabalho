#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "grafosM.h"


int main(){
	cnt=0;
	char opt;
	char optA;
	TipoGrafo G;

	clock_t inicioBP, fimBP;
	double tempoBP;
	clock_t inicioBL, fimBL;
	double tempoBL;
	clock_t inicioBT, fimBT;
	double tempoBT;


	int qtdeV,qtdeA,V1,V2,i,j;
	printf("---------------Criando o grafo---------------- \n");
	printf("Informe a quantidade de vertices: \n");
	scanf("%d",&qtdeV);
	Cria_Grafo(&G,qtdeV);

	int maximo= (qtdeV + (qtdeV+((qtdeV*(qtdeV-1))/2)));
	int minimo = (100/qtdeV) +1;
	
	do{
		printf("\n\n---------------Menu Interativo - Quantidade de arestas---------\n");
		printf("| 0 - Inserir quantidade de arestas manualmente;                |\n");
		printf("| 1 - Inserir Grau de conectividade do grafo                    |\n");
		printf("|_______________________________________________________________|\n");
		printf("\nEscolha sua opcao: ");
		scanf("%c", &optA);
		switch(optA){
			case '0':
				
				do{
					printf("\nOBS: Deve haver no minimo %d arestas e no maximo %d \n",qtdeV-1,maximo);
					printf("\nInforme a quantidade de arestas: \n");
					scanf("%d",&qtdeA);
				}while(qtdeA<qtdeV -1 || qtdeA> maximo); //Vai ficar pedindo a qtde de arestas enquanto ela não estiver dentro do intervalo possível
				break;
			case '1':
				do{
					printf("\nOBS: Deve haver no minimo %d .. de conectividade e no maximo 100\n", minimo);
					printf("\nInforme o percentual de conectividade: \n");
					scanf("%d",&qtdeA);
				}while(qtdeA>100 || qtdeA<minimo);
				break;
		}
		printf("\e[H\e[2J");
	}while(optA != '0' && optA != '1');

	visitado = (int*) malloc(qtdeV*sizeof(int));
	vet_profundidade = (int*) malloc(qtdeV*sizeof(int));
	vet_largura = (int*) malloc(qtdeV*sizeof(int));
	fila_largura = (int*) malloc(qtdeV*sizeof(int)); //Aloca uma fila em forma de vetor para armazenar a em ordem, os vertices de mesmo nivel
	vet_AV = (int*) malloc(qtdeV*sizeof(int)); // Vetor para armazenar a qtde de arestas por vértice


	
	Gera_Grafo(&G,qtdeA,optA);
	Preenche_AV(&G); // vai preencher o vetor com a quantidade de arestas por vertice



	do{
		printf("\n\n--------------------------Menu Interativo------------------------\n");
		printf("| 1 - Inserir Aresta;                                           |\n");
		printf("| 2 - Remover Aresta;                                           |\n");
		printf("| 3 - Mostrar Matriz de Adjacencias;                            |\n");
		printf("| 4 - Realizar Busca em Largura                                 |\n");
		printf("| 5 - Realizar Busca em Profundidade                            |\n");
		printf("| 6 - Mostrar todos os caminhos possiveis                       |\n");
		printf("| 7 - Comparar tempo da Busca em Profundidade e Largura         |\n");
		printf("| 8 - Alterar grau de conectividade do grafo                    |\n");
		printf("| 9 - Sair (Parar a execucao do programa)                       |\n");
		printf("|_______________________________________________________________|\n");
		printf("\nEscolha sua opcao: ");
		scanf("%c", &opt);


		switch(opt){
		case '1': 
			printf("\nEscolha o primeiro vertice: ");
			scanf("%d", &V1);
			printf("\nEscolha o segundo vertice: ");
			scanf("%d", &V2);
			InserirA(&G,V1,V2);
			getchar();
			break;

		case '2':
			printf("\nEscolha o primeiro vertice: ");
			scanf("%d", &V1);
			printf("\nEscolha o segundo vertice: ");
			scanf("%d", &V2);
			RemoverA(&G,V1,V2);
			getchar(); 
			break;

		case '3':
			MostraMatriz(&G);
			getchar();
			break;

		case '4':
			printf("\nEscolha o vertice de origem: ");
			scanf("%d", &V1);
			Busca_Largura(&G,V1);
			Mostrar_Busca(&G,vet_largura);
			getchar();
			getchar();
			break;

		case '5':
			printf("\nEscolha o vertice de origem: ");
			scanf("%d", &V1);
			for (i=0;i<qtdeV;i++){
				vet_profundidade[i]=-1; //Deixa o vetor de acesso =-1 em todos os campos
			}
			Busca_Profundidade(&G,V1);
			Mostrar_Busca(&G,vet_profundidade);
			getchar();
			getchar();
			break;

		case '6':
			printf("Caminhos possiveis:\n");
			inicioBT = clock();
			for(i = 0; i < qtdeV; i++){
				printf("---------------------------------------------------------------------------\n");
				printf("\nVertice: %d\n\n", i );
				for(j = 0; j < qtdeV; j++){
					if(i == j)
						continue;
					d=j;
					Todos_caminhos(&G,i);
				}
				printf("\n");
			}
			fimBT = clock();
			tempoBT = (double)(fimBT-inicioBT) / CLOCKS_PER_SEC;

			printf("\n\nTempo para determinar todos os caminhos possiveis: %lf s\n", tempoBT);

			// Busca_ProfundidadeTotal(&G);
			getchar();
			getchar();
			break;

		case '7':
			printf("\nEscolha o vertice de origem: ");
			scanf("%d", &V1);

			for (i=0;i<qtdeV;i++){
				vet_profundidade[i]=-1; //Deixa o vetor de acesso =-1 em todos os campos
			}

			inicioBP = clock();
			Busca_Profundidade(&G,V1);
			fimBP = clock();
			tempoBP = (double)(fimBP-inicioBP) / CLOCKS_PER_SEC;

			inicioBL = clock();
			Busca_Largura(&G,V1);
			fimBL = clock();
			tempoBL = (double)(fimBL-inicioBL) / CLOCKS_PER_SEC;

			printf("Tempo da Busca em Profundidade: %lf s\n", tempoBP);
			printf("Tempo da Busca em Largura: %lf s\n", tempoBL);

			getchar();
			getchar();
			break;

		case '8':

			do{
				printf("\nOBS: Deve haver no minimo %d .. de conectividade e no maximo 100\n", minimo);
				printf("\nInforme o percentual de conectividade: \n");
				scanf("%d",&V1);
			}while(V1>100 || V1<minimo);

			Insere_Percentual(&G,(qtdeV * V1)/100);

			break;



		// default:
		// 	printf("\nOpcao invalida \n");
		// 	getchar();
		// 	break;

	}
	printf("\e[H\e[2J");

	}while(opt!='9');

	DesalocaMatriz(&G,qtdeV);
	free(visitado);
	free(vet_largura);
	free(vet_profundidade);

	
	return 0;

}
