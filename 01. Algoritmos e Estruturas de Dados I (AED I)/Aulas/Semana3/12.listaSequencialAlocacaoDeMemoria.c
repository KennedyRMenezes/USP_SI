/******************************************************************************
//     listaSequencialAlocacaoDeMemoria.c
//  Neste programa o tamanho da lista sequencial eh definido pelo usuario
//  durante a inicializacao (alocacao dinamica de memoria).
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define ERRO -1
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO* A;
  int nroElem;
  int maxElem;
} LISTA;

/* Inicializa��o da lista sequencial (a lista j� est� criada e � apontada 
pelo endere�o em l) */
void inicializarLista(LISTA* l, int tamanhoMaximo){
  l->nroElem = 0;
  l->maxElem = tamanhoMaximo;
  l->A = (REGISTRO*) malloc(sizeof(REGISTRO)*(tamanhoMaximo+1));
} /* inicializarLista */

/* Exibi��o da lista sequencial */
void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave); // s� lembrando TIPOCHAVE = int
  printf("\"\n");
} /* exibirLista */ 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  return l->nroElem;
} /* tamanho */

/* Retornar o tamanho em bytes da lista. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados, pois a alocacao de memoria eh estatica.
   A priori, nao precisariamos do ponteiro para a lista, vamos utiliza-lo apenas
   porque teremos as mesmas funcoes para listas ligadas.   
*/
int tamanhoEmBytes(LISTA* l) {
  return sizeof(LISTA) + sizeof(REGISTRO)*(l->maxElem);
} /* tamanhoEmBytes */

/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE primeiroElem(LISTA* l){
  if(l->nroElem > 0) return l->A[0].chave;
  else return ERRO; // lista vazia
} /* primeiroElem */

/* Retornar a chave do ultimo elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE ultimoElem(LISTA* l) {
  if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
  else return ERRO; // lista vazia
} /* ultimoElem */

/* Retornar a chave do elemento que est� na posi��o n da LISTA. Lembre-se que as posicoes do
   arranjo A vao de 0 a l->maxElem-1  */
TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} /* enesimoElem */

/* Reinicializar a estrutura */
void reinicializarLista(LISTA* l, int tamanhoMaximo){
  if (l->A) free(l->A);
  l->nroElem = 0;
  l->maxElem = tamanhoMaximo;
  l->A = (REGISTRO*) malloc(sizeof(REGISTRO)*(tamanhoMaximo+1));

} /* reinicializarLista */

/* Inser��o "direta" na i�sima posi��o (posicao i do arranjo A).
   Funciona da mesma maneira de um insertionSort: deve-se deslocar todos os
   elementos a partir da iesima posicao e entao se insere o novo elemento. */
bool inserirElemLista(REGISTRO reg, int i, LISTA* l){
  int j;
  if ((l->nroElem >= l->maxElem) || (i < 0) || (i > l->nroElem)) 
     return(false); // lista cheia ou �ndice inv�lido
  for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];
  l->A[i] = reg;
  l->nroElem++;
  return true;
} /* inserirElemLista */

/* Busca sequencial em lista ordenada ou n�o SEM SENTINELA */
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroElem){
    if(ch == l->A[i].chave) return i; // achou
    else i++;
  }
  return ERRO; // n�o achou
} /* buscaSequencial */


/* Busca binaria em lista ordenada */
int buscaBinaria(LISTA* l, TIPOCHAVE ch){
  int esq, dir, meio;
  esq = 0;
  dir = l->nroElem-1;
  while(esq <= dir) {
    meio = ((esq + dir) / 2);
    if(l->A[meio].chave == ch) return meio; // achou
    else {
      if(l->A[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return ERRO;
} /* buscaBinaria */

/* Exclus�o do elemento cuja chave seja igual a ch */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos == ERRO) return false; // n�o existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemLista */


/* Exclus�o do elemento cuja chave seja igual a ch em lista ordenada*/
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaBinaria(l,ch);
  if(pos == ERRO) return false; // n�o existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemListaOrd */



/* Busca sequencial em lista COM SENTINELA (vetor criado com l->maxElem+1 posi��es) */
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave != ch) i++;
  if (i > l->nroElem -1) return ERRO; // n�o achou
  else return i;
} /* buscaSentinela */



/* Inser��o em lista ordenada usando busca bin�ria sem duplica��o */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= l->maxElem) return false; // lista cheia
  int pos;
  pos = buscaBinaria(l,reg.chave);
  if(pos != ERRO) return false; // elemento j� existe
  pos = l->nroElem-1;
  while(pos>=0 && l->A[pos].chave > reg.chave) {
    l->A[pos+1] = l->A[pos];
    pos--;
  }
  l->A[pos+1] = reg;
  l->nroElem++;
} /* inserirElemListaOrd */


/* Inser��o em lista ordenada COM SENTINELA sem duplica��o */
bool inserirElemListaOrd2(LISTA* l, REGISTRO reg) {
  int i = 0;
  TIPOCHAVE ch = reg.chave;
  if(l->nroElem >= l->maxElem) return false; // lista cheia
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave < ch) i++;
  if((l->A[i].chave == ch) && (i < l->nroElem)) return false;
  else return inserirElemLista(reg, i+1, l); // i = posicao no arranjo, i+1 significa o iesimo elemento
} /* inserirElemListaOrd */



int main(){
  LISTA lista;
  inicializarLista(&lista,4);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  REGISTRO reg;
  reg.chave = 9;
  inserirElemListaOrd(&lista,reg);
  exibirLista(&lista);
  reg.chave=3;
  inserirElemListaOrd(&lista,reg);
  reg.chave=4;
  inserirElemListaOrd(&lista,reg);
  reg.chave=1;
  inserirElemListaOrd(&lista,reg);
  reg.chave=12;
  inserirElemListaOrd(&lista,reg);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSequencial(&lista,4));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaBinaria(&lista,4));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSentinela(&lista,4));
  if (excluirElemLista(&lista,4)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista,8)) printf("Exclusao bem sucedida: 8.\n");
  if (excluirElemLista(&lista,9)) printf("Exclusao bem sucedida: 9.\n");
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  reinicializarLista(&lista,20);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  return 0;
}
    
/* SAIDA DO PROGRAMA:
Lista: " "
Numero de elementos na lista: 0.
Tamanho da lista (em bytes): 32.
Lista: " 9 "
Lista: " 1 3 4 9 "
Numero de elementos na lista: 4.
Tamanho da lista (em bytes): 32.
Chave 4 encontrada na posicao: 2 do arranjo A.
Chave 4 encontrada na posicao: 2 do arranjo A.
Chave 4 encontrada na posicao: 2 do arranjo A.
Exclusao bem sucedida: 4.
Exclusao bem sucedida: 9.
Lista: " 1 3 "
Numero de elementos na lista: 2.
Tamanho da lista (em bytes): 32.
Lista: " "
Numero de elementos na lista: 0.
Tamanho da lista (em bytes): 96.
*/
