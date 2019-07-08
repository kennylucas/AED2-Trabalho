typedef struct no No;

No* criarArvore(void);
void inserirArvore(No** no, int info);
void impressaoPrefixado(No* no);
void impressaoCentral(No* no);
void impressaoPosfixado(No* no);
void preencherArvoreAleatorio(No** arvore,int N, int MAX);
void preencherArvoreVetor(int* vet, int tam, No** arvore);
No* buscaArvore(No* arvore, int chave);
//No* buscaABP(No* arvore, int chave);