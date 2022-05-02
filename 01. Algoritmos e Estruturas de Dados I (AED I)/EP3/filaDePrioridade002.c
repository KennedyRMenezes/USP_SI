/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"
#define MAX 5
#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

PFILA criarFila(){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->referencias = (PONT*) malloc(sizeof(PONT)*MAX);/*ponteiro para um arranjo de ponteiros para elem*/
  res->heap = (PONT*) malloc(sizeof(PONT)*MAX); /*ponteiro para um arranjo de ponteiros para elem*/
  int i;
  for (i=0;i<MAX;i++) {
    res->referencias[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0; /*qtd de elem efetivamente no heap*/
  return res;
}


bool exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

/*
void heapify (PFILA f, int tam, int indice){
  int maior = indice; 
  int filhoEsquerda = 2 * indice;
  int filhoDireita = 2 * indice + 1;

  if(filhoEsquerda < tam && f->heap[filhoEsquerda] > f->heap[maior]) maior = filhoEsquerda;

  if(filhoDireita < tam && f->heap[filhoDireita] > f->heap[maior]) maior = filhoDireita;

  if(maior != tam){

    PONT temp = f->heap[tam];
    f->heap[tam] = f->heap[maior];
    f->heap[maior] = temp;

    heapify(f, tam, maior);
  }
}
*/

/*
// returns the index of the parent node
int parent(int i) {
    return (i - 1) / 2;
}

// return the index of the left child 
int left_child(int i) {
    return 2*i + 1;
}

// return the index of the right child 
int right_child(int i) {
    return 2*i + 2;
}

void swap(PONT x, PONT y) {
    PONT temp = x;
    x = y;
    y = temp;
}

void heapify(PFILA f, int i, int tam) {
    int largest = (LCHILD(i) < tam && f->heap[LCHILD(i)]->prioridade > f->heap[i]->prioridade) ? LCHILD(i) : i ;
    if(RCHILD(i) < tam && f->heap[RCHILD(i)]->prioridade > f->heap[largest]->prioridade) {
        largest = RCHILD(i) ;
    }
    if(largest != i) {

        PONT temp = f->heap[i];
        f->heap[i] = f->heap[largest];
        f->heap[largest] = temp;

        heapify(f, largest, tam);
    }
}

// moves the item at position i of array a
// into its appropriate position
void max_heapify(PFILA f, int i, int n){
    // find left child node
    int left = left_child(i);

    // find right child node
    int right = right_child(i);

    // find the largest among 3 nodes
    int largest = i;

    // check if the left node is larger than the current node
    if (left <= n && f->heap[left]->prioridade > f->heap[largest]->prioridade) {
        largest = left;
    }

    // check if the right node is larger than the current node
    if (right <= n && f->heap[right]->prioridade > f->heap[largest]->prioridade) {
        largest = right;
    }

    // swap the largest node with the current node 
    // and repeat this process until the current node is larger than 
    // the right and the left node
    if (largest != i) {
        int temp = f->heap[i]->prioridade;
        f->heap[i]->prioridade = f->heap[largest]->prioridade;
        f->heap[largest]->prioridade = temp;
        max_heapify(f, largest, n);
    }

}

// converts an array into a heap
void build_max_heap(PFILA f, int n) {
    int i;
    for (i = n/2; i >= 0; i--) {
        max_heapify(f, i, n);
    } 
}
*/

int tamanho(PFILA f){
  int tam = f->elementosNoHeap;
  return tam;
}

bool inserirElemento(PFILA f, int id, float prioridade){
  /**/
  if(id < 0 || id >= MAX) return false;
  if(f->referencias[id]->id == id) return false;
              
  /*Alocando memoria para o novo elem.*/
  PONT novo;
  novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;

  /*Coloca na fila 'referencias' de acordo com o id do elem.*/
  f->referencias[id] = novo;

  int ind = tamanho(f);
  if(tamanho(f) == 0){
    f->heap[ind] = novo;
    novo->posicao = ind;
  }

  


  /*Altera o valor da quantidade de elem. no heap*/
  f->elementosNoHeap = f->elementosNoHeap + 1;
  return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
 //
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  //
}

PONT removerElemento(PFILA f){
 //
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  //
}
