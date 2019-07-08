
typedef struct TipoGrafo TipoGrafo; //Struct para o tipo grafo contendo a quantidade de vértices, arestas e a matriz de adjacência

void Cria_Grafo(TipoGrafo *G, int vertices); 
//Dado o grafo e a quantidade de vértices, cria o grafo e chama a função para criar uma matriz de adjacência
int InserirA(TipoGrafo *G, int V1, int V2);
//Dados dois vértices, cria uma aresta que liga os dois
int RemoverA(TipoGrafo *G, int V1, int V2);
//Dados dois vértices, remove a aresta que liga os dois
void Insere_Percentual(TipoGrafo *G, int QtdeArestas);
void Gera_Grafo(TipoGrafo *G, int qtde_arestas,char optA);
int Verifica_Conexao(TipoGrafo *G);
//Verifica se o grafo é conexo
void Verifica_ConexaoInterno(TipoGrafo *G, int VA);
//Chamada interna para chamada do Verifica_conexão
void Mostrar_Busca(TipoGrafo *G, int* vetor);
//Dado o grafo e o vetor, irá verificar a ordem inicial do vetor e irá exibir em ordem de acessos
void Busca_Profundidade(TipoGrafo *G, int VB);
//Algoritmo de busca em profundidade
void Busca_ProfundidadeInterno(TipoGrafo *G, int VB);
//Chamada interna da função Busca_Profundidade para realizar as chamadas recursivas (empilhar)
void Busca_Largura(TipoGrafo *G, int VB);
//Algoritmo de busca em largura
void Preenche_AV(TipoGrafo *G);
//Preenche o vetor AV com a quantidade de arestas por vertice
void Todos_caminhos(TipoGrafo *G,int c);
int verifica_lista(int g);
