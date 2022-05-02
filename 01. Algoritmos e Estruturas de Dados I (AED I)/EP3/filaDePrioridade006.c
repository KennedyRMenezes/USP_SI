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

int tamanho(PFILA f){
  int tam = f->elementosNoHeap;
  return tam;
}

int pai(int indice){
  return (indice - 1) / 2;
}

int filhoEsq(int i){
  return (2*i) + 1;
}

int filhoDir(int i){
  return (2*i) + 2;
}

bool buscaId(PFILA f, int id){
  for(int i = 0; i < f->elementosNoHeap; i++){
    if(f->heap[i]->id == id) return true;
  }
  return false;
}

void max_heapify(PFILA f, int index, int tam){
  // find left child node
  int left = filhoEsq(index);

  // find right child node
  int right = filhoDir(index);

  // find the largest among 3 nodes
  int largest = index;

  // check if the left node is larger than the current node
  if (left <= tam && f->heap[left]->prioridade > f->heap[largest]->prioridade) {
    largest = left;
  }

  // check if the right node is larger than the current node
  if (right <= tam && f->heap[right]->prioridade > f->heap[largest]->prioridade) {
    largest = right;
  }

  // swap the largest node with the current node
  // and repeat this process until the current node is larger than
  // the right and the left node
  if (largest != index) {
    PONT temp = f->heap[index];
    f->heap[index] = f->heap[largest];
    f->heap[largest] = temp;
    max_heapify(f, largest, tam);
  }

}

bool inserirElemento(PFILA f, int id, float prioridade){

  if(id < 0 || id >= MAX) return false;
  if(buscaId(f, id)) return false;

  PONT novo;
  novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;

  f->referencias[id] = novo;

  int size = tamanho(f);

  f->heap[size] = novo;
  novo->posicao = size;

  while (size != 0 && f->heap[pai(size)]->prioridade < f->heap[size]->prioridade){
    PONT temp = f->heap[pai(size)];
    int temp1 = f->heap[pai(size)]->posicao; // posicao ------------
    int temp2 = f->heap[size]->posicao; // posicao ------------

    f->heap[pai(size)]->posicao = temp2; // posicao ------------
    f->heap[pai(size)] = f->heap[size];
    f->heap[size]->posicao = temp1; // posicao ------------
    f->heap[size] = temp;
    size = pai(size);
  }

  f->elementosNoHeap = f->elementosNoHeap + 1;
  return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  if(id < 0 || id >= MAX) return false;
  if(!buscaId(f, id)) return false;
  if(f->referencias[id]->prioridade >= novaPrioridade) return false;

  f->referencias[id]->prioridade = novaPrioridade;
  
  int posi = f->referencias[id]->posicao;

  while (novaPrioridade > f->heap[pai(posi)]->prioridade){
    PONT temp = f->heap[pai(posi)];
    int aux = f->heap[pai(posi)]->posicao;
    int aux2 = f->heap[posi]->posicao;

    f->heap[pai(posi)]->posicao = aux2;
    f->heap[pai(posi)] = f->heap[posi];
    f->heap[posi]->posicao = aux;
    f->heap[posi] = temp;
    posi = pai(posi);
  }

  return true;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  if(id < 0 || id >= MAX) return false;
  if(!buscaId(f, id)) return false;
  if(f->referencias[id]->prioridade < novaPrioridade) return false;
  f->referencias[id]->prioridade = novaPrioridade;

  int size = tamanho(f);
  max_heapify(f, 0, size);

  for(int i = 0; i < size; i++){
    f->heap[i]->posicao = i;
  }

  return true;
}

PONT removerElemento(PFILA f){
  if(tamanho(f) == 0) return NULL;

  int posNovaRaiz = tamanho(f)-1; //Ultimo elem. serah a nova raiz
  int idElemExcl = f->heap[0]->id; //Guardando id do elem. excluido
  PONT elemExcl = f->heap[0]; //Guardando elem. excluido
  f->heap[0] = f->heap[posNovaRaiz]; //Colocando nova raiz no lugar
 
  int size = tamanho(f) - 1;
  max_heapify(f, 0, size);

  for(int i = 0; i < size; i++){
    f->heap[i]->posicao = i;
  }

  f->referencias[idElemExcl] = NULL; //Colocadno NULL no lugar do elem. excluido pelo id
  f->elementosNoHeap = f->elementosNoHeap - 1; //Diminuindo quantidade de elem. no heap
  return elemExcl; //Retornando elem. excluido
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
   if(id < 0 || id >= MAX) return false;
   if(!buscaId(f, id)) return false;
   *resposta = f->referencias[id]->prioridade;

   return true;
}