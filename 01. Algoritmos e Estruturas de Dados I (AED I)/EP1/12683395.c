#include "listadeprodutos.h"
#include "malloc.h"

PLISTA criarLista(){
  PLISTA res = (PLISTA) malloc(sizeof(LISTADEPRODUTOS));
  int x;
  for (x = 0; x < NUMTIPOS; x++){
    res->LISTADELISTAS[x]=(PONT) malloc(sizeof(REGISTRO));
    res->LISTADELISTAS[x]->id=-1;
    res->LISTADELISTAS[x]->quantidade=0;
    res->LISTADELISTAS[x]->valorUnitario=0;
    res->LISTADELISTAS[x]->proxProd=NULL;
  }
  return res;
}

int tamanho(PLISTA l){
  int tam = 0;
  int x;
  PONT atual;
  for (x = 0; x < NUMTIPOS; x++){

    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      atual = atual->proxProd;
      tam++;
  }
    }

  return tam;
}

/* Procura id na estrutura inteira */
PONT buscarID(PLISTA l, int id){
  int x;
  PONT atual;
  for (x = 0; x < NUMTIPOS; x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual){
      if (atual->id == id) return atual;
      atual = atual->proxProd;
    }
  }
  return NULL;
}

int buscarTipo(PLISTA l, int id){
  int x;
  PONT atual;
  for (x = 0; x < NUMTIPOS; x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual){
      if (atual->id == id) return x;
      atual = atual->proxProd;
    }
  }
  return -1;
}

/* Procura para um determinado tipo */
PONT buscarIDTipo(PLISTA l, int id, int tipo){
  if (tipo < 0 || tipo >= NUMTIPOS) return NULL;
  PONT atual = l->LISTADELISTAS[tipo]->proxProd;
  while (atual) {
    if (atual->id == id) return atual;
    atual = atual->proxProd;
  }
  return NULL;
}

/* Funcao que acha o anterior*/
PONT buscarIDTipoAnt(PLISTA l, int id, int tipo){
  if (tipo < 0 || tipo >= NUMTIPOS) return NULL;
  PONT atual = l->LISTADELISTAS[tipo]->proxProd;
  PONT anterior = l->LISTADELISTAS[tipo];
  while (atual) {
    if (atual->id == id) return anterior;
    anterior = atual;
    atual = atual->proxProd;
  }
  return NULL;
}

void exibirLog(PLISTA f){

  int numElementos = tamanho(f);
  printf("Log lista [elementos: %i]\n", numElementos);
  int x;
  PONT atual;
  for(x = 0; x < NUMTIPOS; x++){
    printf("  #TIPO: %i -> ", x);
    atual = f->LISTADELISTAS[x]->proxProd;
    while (atual){
      printf(" [%i;%i;%i;$%i]", atual->id, atual->quantidade, atual->valorUnitario, atual->quantidade*atual->valorUnitario);
      atual = atual->proxProd;
    }
    printf("\n");
  }
  printf("\n");
}

int consultarValorUnitario(PLISTA l, int id){
  int x;
  PONT atual;
  for(x = 0; x < NUMTIPOS; x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while(atual){
      if (atual->id == id) return atual->valorUnitario;
      atual = atual->proxProd;
    }
  }
  return 0;
}

bool inserirNovoProduto(PLISTA l, int id, int tipo, int quantidade, int valor){

  /*id, quantidade ou valor negativo retorna false*/
  if(id < 0 || quantidade < 0 || valor < 0) return false;
  /*tipo inválido retorna false*/
  if(tipo < 0 || tipo > NUMTIPOS-1) return false;
  /*se já houver um registro com mesmo id retorna false*/
  if(buscarID(l, id) != NULL){
    if(buscarID(l, id)->id == id) return false;
  }

  /*Alocando memória para um novo produto*/
  PONT novo;
  novo = (PONT) malloc(sizeof(REGISTRO));
  /*inserindo dados do produto; preenchendo campos do produto*/
  novo->id = id;
  novo->proxProd = NULL;
  novo->quantidade = quantidade;
  novo->valorUnitario = valor;

  int valorTotal = valor * quantidade;

  PONT anterior = l->LISTADELISTAS[tipo];
  while(anterior->proxProd && anterior->proxProd->valorUnitario * anterior->proxProd->quantidade < valorTotal){
      anterior = anterior->proxProd;
  }

  novo->proxProd = anterior->proxProd;
  anterior->proxProd = novo;

  return true;
}

bool removerItensDeUmProduto(PLISTA l, int id, int quantidade){
  /* verifica se não há produto com o id na lista */
  if(buscarID(l, id) == NULL) return false;

  int tipoProd = buscarTipo(l, id);
  PONT produto = buscarID(l, id);

  /* quantidade <= 0, ou maior q a quantidade do produto retorna false*/
  if(quantidade <= 0 || quantidade > produto->quantidade ) return false;

  /*Atualizando quantidade*/
  produto->quantidade = produto->quantidade - quantidade;

  PONT ant = buscarIDTipoAnt(l, id, tipoProd);

  /*Se quantidade = 0, arruma os ponteiros e da free na memória do produto*/
  if(produto->quantidade == 0){
    ant->proxProd = produto->proxProd;
    free(produto);
    return true;
  }

  /*Se o valor total do produto ainda for maior que seu anterior nada muda*/
  if(ant->quantidade*ant->valorUnitario < produto->quantidade*produto->valorUnitario) return true;

  /*Criando um novo registro para dar free no produto alocado*/
  REGISTRO novo;
  novo = *produto;
  ant->proxProd = produto->proxProd;/* Arrumando os ponteiros */
  free(produto);

  if(ant->quantidade*ant->valorUnitario > novo.quantidade*novo.valorUnitario){
    inserirNovoProduto(l, novo.id, tipoProd, novo.quantidade, novo.valorUnitario);
  }

  return true;

}

bool atualizarValorDoProduto(PLISTA l, int id, int valor){

  /* verifica se não há id na lista */
  if(buscarID(l, id) == NULL) return false;
  /* valor passado <= 0 */
  if(valor <= 0) return false;

  int tipoProd = buscarTipo(l, id);
  PONT produtoAt = buscarID(l, id);
  produtoAt->valorUnitario = valor;

  PONT pred = buscarIDTipoAnt(l, id, tipoProd);

  /*Criando um novo registro para dar free no produto alocado*/
  REGISTRO novoReg;
  novoReg = *produtoAt;
  pred->proxProd = produtoAt->proxProd;
  free(produtoAt);

  inserirNovoProduto(l, novoReg.id, tipoProd, novoReg.quantidade, novoReg.valorUnitario);//@

  return true;
}
