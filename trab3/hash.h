#define N 9997
//Struct Utilizada na Hash
typedef struct Aluno_h
{
    int matricula;
    int deslocamento;
    struct Aluno_h *prox;
} Aluno_h;

//Definição da tabela
typedef Aluno_h *Hash[N];
//------------------FUNÇÕES-------------------//

//Função Hash
int hash(int matricula);

//inserção sem repetição
Aluno_h *inserir_Hash(Hash tabela, int matricula, int deslocamento);

//buscar um elemento
int busca_hash(Hash tabela, int matricula, FILE *arq);

//quantidade de colisões
int colisoes(Hash tabela);

//printar a matricula da tabela inteira
void mostrar_hash(Hash tabela);