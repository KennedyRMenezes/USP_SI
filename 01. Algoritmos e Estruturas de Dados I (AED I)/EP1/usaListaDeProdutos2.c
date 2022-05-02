#include "12683395(2.1).c" //listadeprodutos.c

int main() {
  PLISTA f = criarLista();
  int id;
  int tipo;
  int quantidade;
  int valor;
  bool res;

  printf("################# INSERINDO #######################\n");

  exibirLog(f);
  res = inserirNovoProduto(f, 2, 1, 22, 23);
  if(res) printf("Insercao retornou true (1)\n");
  else printf("Insercao retornou false (1)\n");

  /*New*/
  exibirLog(f);
  res = inserirNovoProduto(f, 1, 1, 22, 12);
  if(res) printf("Insercao retornou true (new1)\n");
  else printf("Insercao retornou false (new1)\n");

  exibirLog(f);
  res = inserirNovoProduto(f, 4, 4, 4, 4);
  if(res) printf("Insercao retornou true (2)\n");
  else printf("Insercao retornou false (2)\n");

  /*New*/
  exibirLog(f);
  res = inserirNovoProduto(f, 0, 1, 35, 12);
  if(res) printf("Insercao retornou true (new2)\n");
  else printf("Insercao retornou false (new2)\n");

  /*New*/
  exibirLog(f);
  res = inserirNovoProduto(f, 8, 1, 22, 12);
  if(res) printf("Insercao retornou true (new3)\n");
  else printf("Insercao retornou false (new3)\n");

  exibirLog(f);
  res = inserirNovoProduto(f, 6, 1, 8, 9);
  if(res) printf("Insercao retornou true (3)\n");
  else printf("Insercao retornou false (3)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 3, 1, 22, 23);
  if(res) printf("Insercao retornou true (4)\n");
  else printf("Insercao retornou false (4)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, -5, 6, 7, 8);
  if(res) printf("Insercao retornou true (5)\n");
  else printf("Insercao retornou false (5)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 5, -6, 7, 8);
  if(res) printf("Insercao retornou true (6)\n");
  else printf("Insercao retornou false (6)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 5, 6, -7, 8);
  if(res) printf("Insercao retornou true (7)\n");
  else printf("Insercao retornou false (7)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 5, 6, 7, -8);
  if(res) printf("Insercao retornou true (8)\n");
  else printf("Insercao retornou false (8)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, 3, 1, 9, 9);
  if(res) printf("Insercao retornou true (9)\n");
  else printf("Insercao retornou false (9)\n");
  exibirLog(f);


  printf("################# REMOVENDO #######################\n");
  res = removerItensDeUmProduto(f, 4, 1);
  if(res) printf("Remocao retornou true (1)\n");
  else printf("Remocao retornou false (1)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 2, 1);
  if(res) printf("Remocao retornou true (2)\n");
  else printf("Remocao retornou false (2)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 3, 22);
  if(res) printf("Remocao retornou true (3)\n");
  else printf("Remocao retornou false (3)\n");
  exibirLog(f);


  res = removerItensDeUmProduto(f, 20, 1);
  if(res) printf("Remocao retornou true (4)\n");
  else printf("Remocao retornou false (4)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 5, 10);
  if(res) printf("Remocao retornou true (5)\n");
  else printf("Remocao retornou false (5)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 4, 0);
  if(res) printf("Remocao retornou true (6)\n");
  else printf("Remocao retornou false (6)\n");
  exibirLog(f);



  printf("################# ATUALIZANDO VALOR #######\n");

  res = atualizarValorDoProduto(f, 6, 1);
  if(res) printf("Atualizacao retornou true (1)\n");
  else printf("Atualizacao retornou false (1)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, 600);
  if(res) printf("Atualizacao retornou true (2)\n");
  else printf("Atualizacao retornou false (2)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, 20);
  if(res) printf("Atualizacao retornou true (3)\n");
  else printf("Atualizacao retornou false (3)\n");
  exibirLog(f);


  res = atualizarValorDoProduto(f, 6, 0);
  if(res) printf("Atualizacao retornou true (4)\n");
  else printf("Atualizacao retornou false (4)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, -100);
  if(res) printf("Atualizacao retornou true (5)\n");
  else printf("Atualizacao retornou false (5)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 61, 600);
  if(res) printf("Atualizacao retornou true (6)\n");
  else printf("Atualizacao retornou false (6)\n");
  exibirLog(f);



  res = atualizarValorDoProduto(f, 6, 3);
  if(res) printf("Atualizacao retornou true (7)\n");
  else printf("Atualizacao retornou false (7)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 4, 200);
  if(res) printf("Atualizacao retornou true (8)\n");
  else printf("Atualizacao retornou false (8)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 2, 20);
  if(res) printf("Atualizacao retornou true (9)\n");
  else printf("Atualizacao retornou false (9)\n");
  exibirLog(f);

  return 0;
}
