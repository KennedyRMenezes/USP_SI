/******************************************************************************
//     usaArvoreDeBuscaBinaria.c
// Este programa interage com o usuario para o gerenciamento de arvore binaria
   de busca.
******************************************************************************/
#include "43.arvoreDeBuscaBinaria.c"
#include <stdio.h>

void inserir(PONT *l){
  TIPOCHAVE ch;
  scanf("%d",&ch);
  if (inserirNo(l,ch)) printf("Elemento %d inserido corretamente.\n",ch);
  else printf("Nao foi possivel inserir elemento %d.\n",ch);
}

void buscar(NO *l){
  TIPOCHAVE ch;
  scanf("%d",&ch);
  PONT posicao = buscaBinaria(ch,l);
  if (posicao != NULL) printf("Elemento %d encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar elemento %d.\n",ch);
}

void exibirEmOrdem(NO *l){
   printf("Em ordem: ");
   exibirArvoreEmOrdem(l); printf("\n");
}

void exibirPreOrdem(NO *l){
   printf("Pre ordem: ");
   exibirArvorePreOrdem(l); printf("\n");
}

void exibirPosOrdem(NO *l){
   printf("Pos ordem: ");
   exibirArvorePosOrdem(l); printf("\n");
}


void excluir(PONT *l){
  TIPOCHAVE ch;
  scanf("%d",&ch);
  if (excluirNo(l,ch)) printf("Elemento %d excluido corretamente.\n",ch);
  else printf("Nao foi possivel excluir elemento %d.\n",ch);
}


void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1\n");
  printf("   e <chave1>: excluir elemento com chave=chave1\n");
  printf("   d : destruir (zerar) NO\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   b <chave1>: exibir posicao do elemento com chave=chave1\n");
  printf("   x : exibir arvore em ordem.\n");
  printf("   y: exibir arvore em PRE-ordem.\n");
  printf("   z : exibir arvore em POS-ordem.\n");

}

void destruir(PONT *l){
     destruirArvore(l);
     printf("Arvore zerada (toda memoria liberada).\n");
}

int main(){
  PONT raiz;
  inicializar(&raiz);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir(&raiz); break;
      case 'e' : excluir(&raiz); break;
      case 'd' : destruir(&raiz); break;
      case 'h' : help(); break;
      case 'b' : buscar(raiz); break;
      case 'x' : exibirEmOrdem(raiz); break;
      case 'y' : exibirPreOrdem(raiz); break;
      case 'z' : exibirPosOrdem(raiz); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
