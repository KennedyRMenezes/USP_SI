/******************************************************************************
//     multiplasPilhasEstaticas.c
// Este programa gerencia NP pilhas implementadas em um arranjo
   (implementacao estatica).
// Cada pilha tem tamanho inicial MAX/NP, que pode ser alterado. A soma total
   dos elementos das pilhas eh limitado por MAX.
// Usaremos arranjos para guardarem a base e o topo das pilhas.
******************************************************************************/
#include <stdio.h>
#define true 1
#define false 0
#define ERRO -1

#define MAX 8 // tamanho do arranjo A
#define NP 4 // nro. de pilhas compartilhando o arranjo (numeradas de 0 a NP - 1)

typedef int TIPOCHAVE;

typedef int bool;

typedef struct {
  TIPOCHAVE A[MAX];
  int base[NP+1]; // pilhas [0..NP-1] + pilha[NP] auxiliar (a "pilha[NP]" facilitar� a verifica��o se a pilha NP-1 est� completa)
  int topo[NP+1];
} PILHAMULTIPLA;

/* Inicializacao da pilha m�ltipla */
void inicializarPilhaMultipla(PILHAMULTIPLA* p){
  int i;
  for(i = 0; i <= NP ; i++){
    p->base[i] = (i * (MAX / NP));
    p->topo[i] = p->base[i] - 1;
  }
}

/* Destruicao da pilha m�ltipla */
void destruirPilhaMultipla(PILHAMULTIPLA* p){
  inicializarPilhaMultipla(p);
}

/* Quantos elementos existem na pilha k  */
int tamanhoPilhaK(PILHAMULTIPLA* p, int k) {
  if (k<0 || k>=NP) return ERRO;
  return p->topo[k] - p->base[k] + 1;
}

/* Tamanho em bytes total ds pilhas  */
int tamanhoEmBytesPilhas() {
  return sizeof(PILHAMULTIPLA);
}

/* Quantos elementos existem na soma das pilhas */
int tamanhoTotalPilhas(PILHAMULTIPLA* p) {
  int tamanho = 0;
  int i;
  for (i=0;i<NP;i++) tamanho += tamanhoPilhaK(p,i);
  return tamanho;
}

/* Fun��o que verifica se a pilha k esta cheia? */
bool pilhaKcheia(PILHAMULTIPLA* p, int k) {
  if(p->topo[k] == p->base[k + 1] - 1) return true;
  else return false;
}

/* Desloca pilha k uma posi��o para a direita, se poss�vel */
bool paraDireita(PILHAMULTIPLA* p, int k) {
  int i;
  if( (k < 1) || (k > NP-1) ) return  false; // �ndice inv�lido
  if( (p->topo[k] < p->base[k + 1] - 1)){
    for(i = p->topo[k]; i >= p->base[k]; i--) p->A[i+1] = p->A[i];
    p->topo[k]++;
    p->base[k]++;
    return true;
  }
  return false;
}

/* Desloca pilha k uma posi��o para a esquerda, se possivel */
bool paraEsquerda(PILHAMULTIPLA* p, int k) {
  int i;
  if( (k < 1) || (k > NP-1) ) return  false; // �ndice inv�lido
  if(p->topo[k-1] < p->base[k] - 1){
    for(i = p->base[k]; i <= p->topo[k]; i++) p->A[i-1] = p->A[i];
    p->topo[k]--;
    p->base[k]--;
    return true;
  }
  return false;
}

/* Inserir um novo item no topo da pilha k  */
bool pushK(TIPOCHAVE ch, PILHAMULTIPLA* p, int k) {
  if (k<0 || k>=NP) return false;
  int j;
  if (pilhaKcheia(p,k)){
    // desloca p/direita todas as pilhas de [k+1..NP-1] em ordem reversa
    for( j = NP-1; j > k; j--) paraDireita(p, j);
    if(pilhaKcheia(p, k)){ // se a pilha continua cheia
        // desloca p/esquerda todas as pilhas de [1..k] (mas n�o a pilha 0)
        for( j = 1; j <= k; j++) paraEsquerda(p, j);
        if(pilhaKcheia(p, k)) return false;
    }
  }
  p->topo[k]++;
  p->A[p->topo[k]] = ch;
  return true;
}

/* Retirar um item da pilha k, ou -1  */
bool popK(PILHAMULTIPLA* p, TIPOCHAVE* ch, int k){
  if (k<0 || k>=NP) return false;
  if(p->topo[k] >= p->base[k]) {
    *ch = p->A[p->topo[k]];
    p->topo[k]--;
    return true;
  } 
  return false;
}

/* Retorna posi��o do topo da pilha (e chave no endere�o passado por ch), ou -1  */
int retornarElemento(PILHAMULTIPLA* p, int k, TIPOCHAVE* ch){
  if (k<0 || k>=NP) return ERRO;
  if(p->topo[k] >= p->base[k]) {
    *ch =p->A[p->topo[k]];
    return p->topo[k];
  }
  return ERRO;
}
