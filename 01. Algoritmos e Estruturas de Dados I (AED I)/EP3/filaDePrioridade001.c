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
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

bool buscaId (PFILA f, int id){

  int i;
  for (i=0;i<f->elementosNoHeap;i++) {
    if(f->referencias[i]->id == id) return true;
    else return false;
  }

}

int buscaMenorPrioridade(PFILA f, float prioridade){

  PONT atual;
  int i;

  for(i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    if(atual->prioridade <= prioridade) return i; /*Vai retornar a posicao do elem.*/
  }

}

int tamanho(PFILA f){
  int tam = f->elementosNoHeap;
  return tam;
}

bool inserirElemento(PFILA f, int id, float prioridade){
  /**/
  if(id < 0 || id >= MAX) return false;
  if(buscaId(f, id) != false) return false;
              
  /*Alocando memoria para o novo elem.*/
  PONT novo;
  novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;

  /*Coloca na fila 'referencias' de acordo com o id do elem.*/
  f->referencias[id] = novo;

  /*Decidindo a posicao do elem. no heap*/
  if(tamanho(f) == 0){ /*Se nao houver nenhum elem. o novo serah inserido na 1a posicao*/

    f->heap[0] = novo;
    novo->posicao = 0;

  }else{ /*Se jah houver um elem...*/

    if(prioridade > f->heap[0]->prioridade){ /*...e a prioridade for maior que a do 1o elem. empurara todos uma posição para frente*/

      int tam = tamanho(f);

        for(int aloc = MAX-1; aloc > tam-1; aloc--){
          f->heap[aloc] = f->heap[aloc--];
        }

      f->heap[0] = novo;
      novo->posicao = 0;

    }else{ /*... e a prioridade nao for maior que a do 1o, devemos achar onde colocar este elem. Devemos encontrar o primeiro elem. menor que o novo e colocar ele na frente.*/
      int posicao = buscaMenorPrioridade(f, prioridade);

      for(int aloc = MAX-1; aloc > posicao; aloc--){
        f->heap[aloc] = f->heap[aloc--];
      }

      f->heap[posicao] = novo;
      novo->posicao = posicao;

    }

  }
  /*Altera o valor da quantidade de elem. no heap*/
   f->elementosNoHeap = f->elementosNoHeap + 1;
   return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  // bool res = false;

  // if(id < 0 || id >= MAX) return false;
  // if(buscaId(f, id) != true) return false;
  // if(f->heap[id]->prioridade >= novaPrioridade) return false;

  // return res;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  // bool res = false;

  // if(id < 0 || id >= MAX) return false;
  // if(buscaId(f, id) != false) return false;
  // if(f->heap[id]->prioridade <= novaPrioridade) return false;

  // return res;
}

PONT removerElemento(PFILA f){
  // PONT res = NULL;

  // /* COMPLETAR */

  // return res;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){

  // if(id < 0 || id >= MAX) return false;
  // if(buscaId(f, id) != true) return false;
  // *resposta = f->heap[id]->prioridade;

  // return true;
}
