
typedef struct TipoGrafo TipoGrafo;

int **GeraMatriz(int L, int C, int key);
void DesalocaMatriz(TipoGrafo *G, int L);
void ZeraMatriz(TipoGrafo *G);
void MostraMatriz(TipoGrafo *G);
