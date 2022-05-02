/******************************************************************************
//     listaSequencial.c
// Este programa gerencia listas lineares sequenciais.
// As listas gerenciadas podem ter MAX elementos (posicoes de 0 a MAX-1 no
//   arranjo A). Alocamos MAX+1 posicoes no arranjo para possibilitar a 
//   criacao de um elemento sentinela.
******************************************************************************/
#include <stdio.h>
#define MAX 50
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
  REGISTRO A[MAX+1];
  int nroElem;
} LISTA;


void ordenar(LISTA* l, int tam){

int ult, i, aux;
  for (ult = tam-1; ult>0; ult--)
    for (i=0; i<ult; i++)
      if (l->A[i].chave > l->A[i+1].chave) {
        aux = l->A[i].chave;
        l->A[i].chave = l->A[i+1].chave;
        l->A[i+1].chave = aux;
      }
}


/* Inicializa��o da lista sequencial (a lista j� est� criada e � apontada 
pelo endere�o em l) */
void inicializarLista(LISTA* l){
  l->nroElem = 0;
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
  return sizeof(LISTA);
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
   arranjo A vao de 0 a MAX-1  */
TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} /* enesimoElem */

/* Reinicializar a estrutura */
void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
} /* reinicializarLista */

/* Inser��o "direta" na i�sima posi��o (posicao i do arranjo A).
   Funciona da mesma maneira de um insertionSort: deve-se deslocar todos os
   elementos a partir da iesima posicao e entao se insere o novo elemento. */
bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
  int j;
  if ((l->nroElem >= MAX) || (i < 0) || (i > l->nroElem)) 
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


/* Exclus�o do elemento cuja chave seja igual a ch */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos == ERRO) return false; // n�o existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemLista */


/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posi��es) */
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave != ch) i++;
  if (i > l->nroElem -1) return ERRO; // n�o achou
  else return i;
} /* buscaSentinela */



int main(){
  LISTA lista;
  inicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  REGISTRO reg;
  reg.chave = 9;
  inserirElemLista(&lista,reg,0);
  exibirLista(&lista);
  reg.chave=3;
  inserirElemLista(&lista,reg,1);
  reg.chave=4;
  inserirElemLista(&lista,reg,2);
  reg.chave=1;
  inserirElemLista(&lista,reg,3);
  reg.chave=12;
  inserirElemLista(&lista,reg,2);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  int tamanhoLista = tamanho(&lista);
  ordenar(&lista, tamanhoLista);
  exibirLista(&lista);
  return 0;
}
    
/* SAIDA DO PROGRAMA:
Lista: " "
Numero de elementos na lista: 0.
Tamanho da lista (em bytes): 208.
Lista: " 9 "
Lista: " 9 3 12 4 1 "
Numero de elementos na lista: 5.
Tamanho da lista (em bytes): 208.
Lista: " 1 3 4 9 12 "
*/
