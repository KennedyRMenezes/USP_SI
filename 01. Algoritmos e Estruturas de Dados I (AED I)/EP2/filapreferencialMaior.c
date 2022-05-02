/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP 2 - Fila Preferencial                                      **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

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

  if(ehPreferencial){
    if(f->cabeca->prox == f->cabeca->ant){/*Estará vazio*/
      f->cabeca->prox = f->cabeca->ant = novo;
      novo->prox = novo->ant = f->cabeca;
      return true;
    }else if(f->inicioNaoPref == f->cabeca){/*Soh tem preferenciais*/
      novo->prox = f->cabeca;
      novo->ant = f->cabeca->ant;
      f->cabeca->ant = novo;
      return true;
    }else{ /*f->inicioNaoPref->id != -1*/ /*Preferenciais e nao-preferenciais*/
      novo->prox = f->inicioNaoPref;
      novo->ant = f->inicioNaoPref->ant;
      f->inicioNaoPref->ant->prox = novo;
      f->inicioNaoPref->ant = novo;
      return true;
    }
  }else{
    /*Se for o primeiro nao-preferencial*/
    if(f->inicioNaoPref == f->cabeca){
      if(tamanho(f) > 0){/*Se for o primeiro nao-preferencial depois de um outro elem. qualquer*/
        f->inicioNaoPref = novo;
        f->cabeca->prox->prox = novo;
        f->cabeca->ant = novo;
        novo->ant = f->cabeca->prox;
        novo->prox = f->cabeca;
        return true;
      }else{
        f->inicioNaoPref = novo;
        f->cabeca->prox = f->cabeca->ant = novo;
        novo->prox = novo->ant = f->cabeca;
        return true;
      }
    }else{/*Jah existe um nao-preferencial na lista*/
      novo->prox = f->cabeca;
      novo->ant = f->cabeca->ant; /*anterior no novo serah anterior do noh cabeca*/
      f->cabeca->ant->prox = novo; /*proximo do anterior ao noh cabeca serah o novo*/
      f->cabeca->ant = novo; /*como é uma lista ligada o ant do noh-cabeca recebe o novo*/
      return true;
    }
  }
}

bool atenderPrimeiraDaFila(PFILA f, int* id){

	if(tamanho(f) == 0) return false;
  int idAtual = f->cabeca->prox->id;
  *id = idAtual;

  PONT atual = (PONT)malloc(sizeof(ELEMENTO));
  atual = buscarID(f, idAtual);

  if(atual->ehPreferencial){
    f->cabeca->prox = f->cabeca->prox->prox;
    f->cabeca->prox->ant = f->cabeca;
  }else{
    f->cabeca->prox = f->cabeca->prox->prox;
    f->cabeca->prox->ant = f->cabeca;
    f->inicioNaoPref = f->inicioNaoPref->prox;
  }

  free(atual);

	return true;
}


bool desistirDaFila(PFILA f, int id){

  if(!buscarID(f, id)) return false;

  PONT atual = (PONT)malloc(sizeof(ELEMENTO));
  atual = buscarID(f, id);

  if(id == -1){
    /*Se o noh cabeca tentar excluir nenhum efeito irah surgir*/
  }else{
    if(atual->ehPreferencial){
      atual->ant->prox = atual->prox;
      atual->prox->ant = atual->ant;
      free(atual);
      return true;
    }else{
      atual->ant->prox = atual->prox;
      atual->prox->ant = atual->ant;
      f->inicioNaoPref = atual->prox;
      free(atual);
      return true;
    }
  }
}
