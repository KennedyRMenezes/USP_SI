/******************************************************************************
     matrizTriangularInferior.c
  Este programa gerencia matrizes triangulares inferiores, onde numero
  de ordem=numero de colunas 
  (implementacao em arranjo unidimensional, declarado dinamicamente).
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;

typedef struct {
  int ordem;
  int* A;
} MTI;

typedef MTI* PontMTI;

/* Inicialização da matriz triangluar (aloca memoria para o arranjo, apontado 
   por A, preenche todos os valores do arranjo com zero e atribui valor na 
   variavel ordem)                                                         */
void inicializarMatriz(int lin, MTI* matriz){
   int numeroDeElementos = (lin*lin+lin)/2;
   matriz->ordem = lin;
   matriz->A = (int*)malloc(sizeof(int)*numeroDeElementos);
   int i;
   for (i=0;i<numeroDeElementos;i++) matriz->A[i]=0;
} /* inicializarMatriz */

/* Retornar o tamanho da matriz (numero de elementos validos)                 */
int tamanho(MTI* mat) {
  int n = mat->ordem;
  return (n*n+n)/2;
} /* tamanho */

/* Retornar o tamanho total em bytes ocupado pela matriz */
int tamanhoEmBytes(MTI* mat) {
  int n = mat->ordem;
  return (n*n+n)/2*sizeof(int) + sizeof(MTI);
} /* tamanhoEmBytes */

/* Libera a memoria de todos os elementos da matriz (memoria do arranjo A) e
   zera a variavel ordem                                                    */
void liberarMatriz(MTI* mat) {
     int i;
     int tam = tamanho(mat);
     free(mat->A);
     mat->A = NULL;
     mat->ordem=0;
     return;
} /* liberarMatriz */

/* Dados indices validos (lin, col) de uma matriz diagonal retorna a posicao no
   arranjo que esse elemento deve ocupar                                       */
int retornaPosicao(int lin, int col){
  return (lin*lin-lin)/2+col-1;
} /* retornaPosicao */

/* Inserção na matriz => funcionara como substituir caso o valor jah exista */
bool AtribuiMatriz(int lin, int col, int val, MTI* mat) {
  if ((lin<1) || (lin>mat->ordem) || (col<1) || (col>mat->ordem) ||(lin<col)) return false;
  int posicao = retornaPosicao(lin,col);
  mat->A[posicao]=val;
  return true;
} /* AtribuiMatriz */

/* ValorMatriz - retorna o valor do elemento de posicao lin, col 
   e -1 caso elemento nao exista (posicao invalida)   */
int ValorMatriz(int lin, int col, MTI* mat){
  if ((lin<1) || (lin>mat->ordem) || (col<1) || (col>mat->ordem))
     return -1;
  if (lin<col) return 0;
  return mat->A[retornaPosicao(lin,col)];
} /* ValorMatriz */


/* OrdemMatriz - coloca nos enderecos m e n a ordem da matriz */
void OrdemMatriz(MTI* mat, int* m, int* n){
     *m = mat->ordem;
     *n = mat->ordem;
     return;
} /* OrdemMatriz */

MTI* SomaMatriz(MTI* a, MTI* b) {
  int n = a->ordem;
  if (b->ordem != a->ordem) return NULL;      
  MTI* c = (MTI*) malloc(sizeof(MTI));
  inicializarMatriz(n,c);
  int x;
  int tam = tamanho(a);
  for (x=0;x<tam;x++)
    c->A[x] = a->A[x] + b->A[x];
  return c;
}

/* Calcula a eficiência da representação matriz diagonal 
   comparação com a usual, em percentagem                                 */
float eficiencia(MTI a) {
  int m = a.ordem;
  if (m!=0)
    return 100.0*((tamanho(&a))*sizeof(int))/(m*m*sizeof(int));
  else
    return 0;
}


/* Exibição bidimensional da matriz                                         */
void exibirMatriz(MTI* matriz){
  int n = matriz->ordem;
  int i, j;
  int zero = 0;
  for (i=1;i<=n;i++){
      for (j=1;j<=n;j++) printf("%3d ",ValorMatriz(i,j,matriz));
      printf("\n");
  }
return;
} /* exibirMatriz */ 

void exibirArranjo(MTI* matriz){
  int tam = tamanho(matriz);
  int i;
  for (i=0;i<tam;i++){
    printf("%3d ",matriz->A[i]);
  }
  return;
}
