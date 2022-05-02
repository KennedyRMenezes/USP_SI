#include "filapreferencial.h"

PFILA criarFila(){
    PFILA res = (PFILA) malloc(sizeof(FILAPREFERENCIAL));
    res->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    res->inicioNaoPref = res->cabeca;
    res->cabeca->id = -1;
    res->cabeca->ehPreferencial = false;
    res->cabeca->ant = res->cabeca;
    res->cabeca->prox = res->cabeca;
    return res;
}

int tamanho(PFILA f){
	PONT atual = f->cabeca->prox;
	int tam = 0;
	while (atual != f->cabeca) {
		atual = atual->prox;
		tam++;
	}
	return tam;
}

PONT buscarID(PFILA f, int id){
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		if (atual->id == id) return atual;
		atual = atual->prox;
	}
	return NULL;
}

void exibirLog(PFILA f){
	int numElementos = tamanho(f);
	printf("\nLog fila [elementos: %i]\t- Inicio:", numElementos);
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		printf(" [%i;%i]", atual->id, atual->ehPreferencial);
		atual = atual->prox;
	}
	printf("\n                       \t-    Fim:");
	atual = f->cabeca->ant;
	while (atual != f->cabeca) {
		printf(" [%i;%i]", atual->id, atual->ehPreferencial);
		atual = atual->ant;
	}
	printf("\n\n");
}

bool consultarPreferencial(PFILA f, int id){
	PONT atual = f->cabeca->prox;
	while (atual != f->cabeca) {
		if (atual->id == id) return atual->ehPreferencial;
		atual = atual->prox;
	}
	return -1;
}

bool inserirPessoaNaFila(PFILA f, int id, bool ehPreferencial){

  /*Verifica se id eh invalido e se jah existe um id na lista*/
  if(id < 0) return false;
  if(buscarID(f, id) != NULL) return false;

  PONT novo;
  novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->ehPreferencial = ehPreferencial;

  /*Se for preferencial faz a manipulação a partir do 'inicioNaoPref'(iNP) que valera tanto se o iNP
  apontar para o 'cabeca' tanto se apontar para alguma pessoa sem direito ao atendimento preferencial.

  Se nao for preferencial e se ja houver um nao-Preferencial(nP) na lista esse nP-novo sera inserido
  apos o nP ja existente e os ponteiros ajustados como mostra nas linhas 95-98. Se nao tiver nenhum 
  nP ele sera o primeiro entao a iNP deve apontar para esta pessoa e fazer as mesmas alteracoes de 
  ponteiros como se fosse outra pessoa nP entrando na lista.*/
  if(ehPreferencial){
      novo->ant = f->inicioNaoPref->ant;
      novo->prox = f->inicioNaoPref;
      f->inicioNaoPref->ant->prox = novo;
      f->inicioNaoPref->ant = novo;
  }else{
      if(f->inicioNaoPref == f->cabeca) f->inicioNaoPref = novo;
      novo->prox = f->cabeca;
      novo->ant = f->cabeca->ant;
      f->cabeca->ant->prox = novo;
      f->cabeca->ant = novo;
    }
  return true;
}

bool atenderPrimeiraDaFila(PFILA f, int* id){

  /*Nao da para atender se ninguem na lista houver*/
	if(tamanho(f) == 0) return false;

  int idAtual = f->cabeca->prox->id;
  *id = idAtual;

  PONT atual = buscarID(f, idAtual);

  /*Se a pessoa a ser atendida for uma nP, o iNP passara para a proxima da fila que pode 
  ser uma nP ou a proxima sera o 'cabeca' (linha 119).

  Caso contrario, a primeira pessoa da fila sera uma Preferencial(Pf) e as unicas alteracoes
  necessarias serao as de ponteiros como segue nas linhas 120-122. Apos isso eh necessario que
  se exclua a memoria da pessoa excluida.*/
  if(atual == f->inicioNaoPref) f->inicioNaoPref = atual->prox;
  f->cabeca->prox = f->cabeca->prox->prox;
  f->cabeca->prox->ant = f->cabeca;
  free(atual);
	return true;
}

bool desistirDaFila(PFILA f, int id){

  PONT atual = buscarID(f, id);

  /*Retorna falso se nao houver a pessoa ou se seu id for negativo*/
  if(!atual) return false;
  if(id == -1) return false;

  /*Se a pessoa desistir do atendimento for uma nP, o iNP passara para a proxima da fila (linha 139)
  que pode ser uma nP ou a proxima sera o 'cabeca' e seus ponteiros ajustados (linhas 140-142). 
  Isso ocorrera, apenas as linhas (140-142), do mesmo modo para outras pessoas. Isso é importante para 
  que aponte para o local certo e que a funcao de insercao, apos a desistencia de uma pessoa, possa 
  inserir outra com os ponteiros ajustados. A pessoa a desistir tera sua memoria removida (linha 142)*/
  if(atual == f->inicioNaoPref) f->inicioNaoPref = atual->prox;
  atual->prox->ant = atual->ant;
  atual->ant->prox = atual->prox;
  free(atual);
  return true;
}
