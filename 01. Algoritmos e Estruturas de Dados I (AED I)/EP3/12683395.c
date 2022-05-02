/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <04> - Prof. Luciano Antonio Digiampietri                     **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <Kennedy Rohab Menezes da Silva>               <12683395>     **/
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
  // busca o filho esquerdo do noh
  int left = filhoEsq(index);

   // busca o filho direito do noh
  int right = filhoDir(index);

  // acha o maior entre os 3 nohs
  int largest = index;

  // verifica se o noh esq. eh maior que o noh atual
  if (left <= tam && f->heap[left]->prioridade > f->heap[largest]->prioridade) {
    largest = left;
  }

  // verifica se o noh dir. eh maior que o noh atual
  if (right <= tam && f->heap[right]->prioridade > f->heap[largest]->prioridade) {
    largest = right;
  }

  // troca o maior noh com o noh atual
  // repetir ateh o noh atual ser maior que o 
  // da direita e o da esquerda
  if (largest != index) {
    PONT temp = f->heap[index];
    f->heap[index] = f->heap[largest];
    f->heap[largest] = temp;
    max_heapify(f, largest, tam);
  }

}

bool inserirElemento(PFILA f, int id, float prioridade){

  //Condicoes para rodar a funcao
  if(id < 0 || id >= MAX) return false;
  if(buscaId(f, id)) return false;

  //Alocando e atribuindo os valores ao elemento
  PONT novo;
  novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;
  f->referencias[id] = novo;

  //Iniciando atribuicao
  int size = tamanho(f);
  f->heap[size] = novo;
  novo->posicao = size;

  //Laco que irah colocar os elementos no lugar correto e arrumar a posicao
  while (size != 0 && f->heap[pai(size)]->prioridade < f->heap[size]->prioridade){
    PONT temp = f->heap[pai(size)]; // elemento ------------
    int temp1 = f->heap[pai(size)]->posicao; // posicao ------------
    int temp2 = f->heap[size]->posicao; // posicao ------------

    f->heap[pai(size)]->posicao = temp2; // posicao ------------
    f->heap[pai(size)] = f->heap[size]; // elemento ------------
    f->heap[size]->posicao = temp1; // posicao ------------
    f->heap[size] = temp; // elemento ------------
    size = pai(size);
  }

  //Adicionando um no contador de elementos
  f->elementosNoHeap = f->elementosNoHeap + 1;
  return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  //Condicoes para rodar a funcao
  if(id < 0 || id >= MAX) return false;
  if(!buscaId(f, id)) return false;
  if(f->referencias[id]->prioridade >= novaPrioridade) return false;

  //Atribuindo nova prioridade ao elemento
  f->referencias[id]->prioridade = novaPrioridade;
  
  //Achando a posicao do elemento no heap
  int posi = f->referencias[id]->posicao;

  //Laco que irah colocar os elementos no lugar correto e arrumar a posicao
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
  //Condicoes para rodar a funcao
  if(id < 0 || id >= MAX) return false;
  if(!buscaId(f, id)) return false;
  if(f->referencias[id]->prioridade < novaPrioridade) return false;

   //Atribuindo nova prioridade ao elemento
  f->referencias[id]->prioridade = novaPrioridade;

  //Fazendo max-heapify
  int size = tamanho(f);
  max_heapify(f, 0, size);

  //Organizando as posicoes apos os elementos estarem nos locais corretos
  for(int i = 0; i < size; i++){
    f->heap[i]->posicao = i;
  }

  return true;
}

PONT removerElemento(PFILA f){
  //Condicao para rodar a funcao
  if(tamanho(f) == 0) return NULL;

  int posNovaRaiz = tamanho(f)-1; //Ultimo elem. serah a nova raiz
  int idElemExcl = f->heap[0]->id; //Guardando id do elem. excluido
  PONT elemExcl = f->heap[0]; //Guardando elem. excluido
  f->heap[0] = f->heap[posNovaRaiz]; //Colocando nova raiz no lugar
 
  //Fazendo o maz heapify apos excluir o elemento
  int size = tamanho(f) - 1;
  max_heapify(f, 0, size);

  //Organizando as posicoes apos os elementos estarem nos locais corretos
  for(int i = 0; i < size; i++){
    f->heap[i]->posicao = i;
  }

  f->referencias[idElemExcl] = NULL; //Colocadno NULL no lugar do elem. excluido pelo id
  f->elementosNoHeap = f->elementosNoHeap - 1; //Diminuindo quantidade de elem. no heap
  return elemExcl; //Retornando elem. excluido
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  //Condicoes para rodar a funcao
  if(id < 0 || id >= MAX) return false;
  if(!buscaId(f, id)) return false;

  //Atribuindo a prioridade na variavel passada como parametro
  *resposta = f->referencias[id]->prioridade;

  return true;
}