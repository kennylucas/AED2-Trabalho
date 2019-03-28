/* aqui é colocado todos os cabeçalhos das funções usadas na lib.c
 assim como a definição do que for ser usado. por exemplo, será usado um vetor de 1 milhao de elementos. 
 uma estrutura tão grande não deve ser passada como parametro, então, é criado uma struct, alocado um espaço na memoria 
 e utiliza-se de um ponteiro para passar o vetor às funções.
*/

/*
struct tipoVetor{
    int vet[1000000];
};*/

typedef struct tipoVetor tipoVetor;

int buscaSequencial(tipoVetor *tp, int tamanho, int numero);

int buscaBinaria(tipoVetor *tp, int tamanho, int numero);

void preencherVetorAleatoriamente(tipoVetor *tp, int tamanho);

tipoVetor* criaVetor();
