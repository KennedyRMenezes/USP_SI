/******************************************************************************
     usaDuasPilhasEstaticas.c
  Este programa interage com o usuario para o gerenciamento de duas pilhas
  alocadas num mesmo arranjo.
******************************************************************************/
#include "multiplasPilhasEstaticas.c"
#include <stdio.h>

void inserir(PILHAMULTIPLA* p){
  int pilha;
  scanf("%i",&pilha);
  TIPOCHAVE ch;
  scanf("%i",&ch);
  if (pushK(ch,p,pilha)) printf("Elemento %i inserido corretamente na pilha %i.\n",ch,pilha);
  else printf("Nao foi possivel inserir elemento %i na pilha %i.\n",ch,pilha);
}

void exibirPrimeiro(PILHAMULTIPLA* p){
  int pilha;
  scanf("%i",&pilha);
  TIPOCHAVE ch;
  int posicao = retornarElemento(p,pilha,&ch);
  if (posicao != -1) printf("Topo da pilha %i: %i encontrado no endereco %i.\n",pilha,ch,posicao);
  else printf("Nao foi possivel encontrar o topo da pilha %i (pilha vazia).\n", pilha);
}

void excluir(PILHAMULTIPLA* p){
  int pilha;
  scanf("%i",&pilha);
  TIPOCHAVE reg;
  if (popK(p,&reg,pilha)) printf("Elemento %i excluido corretamente da pilha %i.\n",reg,pilha);
  else printf("Nao foi possivel excluir elemento pilha %i - pilha vazia.\n", pilha);
}

void meuLog(PILHAMULTIPLA* p){
  printf("Numero de elementos nas pilhas: %i.\n",tamanhoTotalPilhas(p));
  printf("Tamanho da pilha (em bytes): %i.\n",tamanhoEmBytesPilhas());
  int x;
  printf("A:");
  for (x=0;x<MAX;x++) printf("\t%i", p->A[x]);
  printf("\nbase:");
  for (x=0;x<=NP;x++) printf("\t%i", p->base[x]);
  printf("\ntopo:");
  for (x=0;x<=NP;x++) printf("\t%i", p->topo[x]);
  printf("\n");
}

void help(){
  printf("Comandos validos: \n");
  printf("   i <pilha_><chave_>: inserir elemento com chave=chave_, na pilha=pilha_\n");
  printf("   e <pilha_>: excluir elemento da pilha=pilha_\n");
  printf("   d : destruir (zerar) pilhas\n");
  printf("   l : exibir log de utilizacao do pilha\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   p <pilha_>: exibir a chave e o endereco do topo, pilha=pilha_\n");
}

void destruir(PILHAMULTIPLA* p){
     destruirPilhaMultipla(p);
     printf("Pilhas zeradas.\n");
}

int main(){
  PILHAMULTIPLA pilha;
  inicializarPilhaMultipla(&pilha);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir(&pilha); break;
      case 'e' : excluir(&pilha); break;
      case 'd' : destruir(&pilha); break;
      case 'l' : meuLog(&pilha); break;
      case 'h' : help(); break;
      case 'p' : exibirPrimeiro(&pilha); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
