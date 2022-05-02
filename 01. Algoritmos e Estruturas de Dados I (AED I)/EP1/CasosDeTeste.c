z
/*###########################################################################*/

void teste1(){ // [A] inserir - 0,25
  PLISTA f = criarListaGAB123();
  if(inserirNovoProduto(f, 1, 0, 3, 4)) printf("Insercao retornou true\n");
  else printf("Insercao retornou false\n");
  exibirLogGAB123(f);
}

void teste2(){ // [A] inserir - 0,1
  PLISTA f = criarListaGAB123();
  if(inserirNovoProduto(f, -1, 2, 3, 4)) printf("Insercao retornou true\n");
  else printf("Insercao retornou false\n");
  exibirLogGAB123(f);
}

void teste3(){ // [A] inserir - 0,1
  PLISTA f = criarListaGAB123();
  if(inserirNovoProduto(f, 2, 2, 0, 4)) printf("Insercao retornou true\n");
  else printf("Insercao retornou false\n");
  exibirLogGAB123(f);
}

void teste4(){ // [A] inserir - 0,1
  PLISTA f = criarListaGAB123();
  if(inserirNovoProduto(f, 1, 2, 3, 0)) printf("Insercao retornou true\n");
  else printf("Insercao retornou false\n");
  exibirLogGAB123(f);
}


void teste5(){ // [A] inserir - 0,1
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 1, 1, 3, 4);
  if(inserirNovoProduto(f, 1, 1, 5, 6)) printf("Insercao retornou true\n");
  else printf("Insercao retornou false\n");
  exibirLogGAB123(f);
}


void teste6(){ // [A] inserir - 0,1
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 3, 3, 3, 4);
  if(inserirNovoProduto(f, 3, 3, 5, 6)) printf("Insercao retornou true\n");
  else printf("Insercao retornou false\n");
  exibirLogGAB123(f);
}



void teste7(){ // [A] inserir - 0,1
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 2, 3, 4, 5);
  if(atualizarValorDoProduto(f, 2, 0)) printf("Atualizacao retornou true\n");
  else printf("Atualizacao retornou false\n");

  exibirLogGAB123(f);
}

void teste8(){ // [A] inserir - 0,15
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 2, 3, 4, 5);
  if(atualizarValorDoProduto(f, 2, 6)) printf("Atualizacao retornou true\n");
  else printf("Atualizacao retornou false\n");

  exibirLogGAB123(f);
}


void teste9(){ // [A] inserir - 0,35
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 2, 3, 4, 5);
  if(removerItensDeUmProduto(f, 2, 4)) printf("Remocao retornou true\n");
  else printf("Remocao retornou false\n");

  exibirLogGAB123(f);
}

void teste10(){ // [A] inserir - 0,15
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 2, 3, 5, 5);
  if(removerItensDeUmProduto(f, 2, 4)) printf("Remocao retornou true\n");
  else printf("Remocao retornou false\n");

  exibirLogGAB123(f);
}








void teste11(){ // [A] inserir - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 1, 1, 3, 4);
  inserirNovoProduto(f, 5, 1, 7, 8);
  inserirNovoProduto(f, 9, 1, 11, 12);
  exibirLogGAB123(f);
}


void teste12(){ // [B] inserir 1 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 2, 2, 2, 2);
  inserirNovoProduto(f, 9, 1, 11, 12);
  inserirNovoProduto(f, 5, 1, 7, 8);
  inserirNovoProduto(f, 1, 1, 3, 4);
  inserirNovoProduto(f, 9, 9, 9, 9);
  exibirLogGAB123(f);
}


void teste13(){ // [C] inserir 2 - 1,0
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 5, 1, 7, 8);
  inserirNovoProduto(f, 9, 1, 11, 12);
  inserirNovoProduto(f, 50, 1, 48, 47);
  inserirNovoProduto(f, 46, 1, 44, 43);
  inserirNovoProduto(f, 1, 1, 3, 4);
  inserirNovoProduto(f, 42, 1, 40, 39);
  inserirNovoProduto(f, 200, 2, 2, 2);
  exibirLogGAB123(f);
}

void teste14(){ // [D] inserir 3 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 1, 2, 3, 4);
  inserirNovoProduto(f, -1, 2, 3, 4);
  inserirNovoProduto(f, 1, -2, 3, 4);
  inserirNovoProduto(f, 1, 2, -3, 4);
  inserirNovoProduto(f, 1, 2, 3, -4);
  inserirNovoProduto(f, 1, 2, 3, 4);
  inserirNovoProduto(f, 2, 20, 2, 2);
  exibirLogGAB123(f);
}


void teste15(){ // [E] inserir 4 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 1, 3, 3, 4);
  inserirNovoProduto(f, 2, 3, 3, 4);
  inserirNovoProduto(f, 3, 3, 3, 3);
  inserirNovoProduto(f, 200, 2, 2, 2);

  exibirLogGAB123(f);
}

void teste16(){ // [F] inserir 5 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProduto(f, 1, 4, 3, 3);
  inserirNovoProduto(f, 2, 4, 3, 4);
  inserirNovoProduto(f, 3, 4, 4, 3);
  inserirNovoProduto(f, 4, 4, 2, 3);
  inserirNovoProduto(f, 200, 2, 2, 2);

  exibirLogGAB123(f);
}


void teste17(){ // [G] removerItensDeUmProduto 1 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 1, 2, 3, 4);
  inserirNovoProdutoGAB123(f, 5, 2, 7, 8);
  inserirNovoProdutoGAB123(f, 9, 2, 11, 12);
  inserirNovoProdutoGAB123(f, 100, 1, 1, 1);

  bool res = removerItensDeUmProduto(f, 1, 1);
  res = removerItensDeUmProduto(f, 5, 1);
  res = removerItensDeUmProduto(f, 9, 1);

  exibirLogGAB123(f);
}

void teste18(){ // [H] removerItensDeUmProduto 2 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 100, 1, 1, 1);
  inserirNovoProdutoGAB123(f, 1, 3, 3, 5);
  inserirNovoProdutoGAB123(f, 5, 3, 7, 8);
  inserirNovoProdutoGAB123(f, 9, 3, 11, 12);

  bool res = removerItensDeUmProduto(f, 9, 10);
  res = removerItensDeUmProduto(f, 5, 6);
  res = removerItensDeUmProduto(f, 9, 2);
  exibirLogGAB123(f);
}


void teste19(){ // [I] removerItensDeUmProduto 3 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 3, 3, 3, 3);
  inserirNovoProdutoGAB123(f, 1, 2, 6, 4);
  inserirNovoProdutoGAB123(f, 5, 6, 7, 8);
  inserirNovoProdutoGAB123(f, 9, 10, 11, 12);

  bool res = removerItensDeUmProduto(f, 9, 9);
  res = removerItensDeUmProduto(f, 5, 4);

  exibirLogGAB123(f);
}


void teste20(){ // [J] removerItensDeUmProduto 1 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 3, 3, 3, 3);
  inserirNovoProdutoGAB123(f, 1, 2, 3, 5);
  inserirNovoProdutoGAB123(f, 5, 2, 7, 8);
  inserirNovoProdutoGAB123(f, 9, 2, 11, 12);

  bool res = removerItensDeUmProduto(f, 1, 3);
  res = removerItensDeUmProduto(f, 9, 11);
  exibirLogGAB123(f);
}




void teste21(){ // [K] atualizarValorDoProduto 2 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 300, 1, 3, 3);
  inserirNovoProdutoGAB123(f, 1, 2, 3, 4);
  inserirNovoProdutoGAB123(f, 5, 2, 7, 8);
  inserirNovoProdutoGAB123(f, 9, 2, 11, 12);

  bool res = atualizarValorDoProduto(f, 1, 1);
  res = atualizarValorDoProduto(f, 5, 1);
  res = atualizarValorDoProduto(f, 9, 1);

  exibirLogGAB123(f);
}


void teste22(){ // [L] atualizarValorDoProduto 3 - 0,25
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 1, 2, 3, 4);
  bool res = atualizarValorDoProduto(f, 9, 1);

  exibirLogGAB123(f);
}


void teste23(){ // [M] atualizarValorDoProduto 2 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 300, 1, 3, 3);
  inserirNovoProdutoGAB123(f, 1, 4, 3, 4);
  inserirNovoProdutoGAB123(f, 5, 4, 7, 8);
  inserirNovoProdutoGAB123(f, 9, 4, 11, 12);

  bool res = atualizarValorDoProduto(f, 1, 100);

  exibirLogGAB123(f);
}



void teste24(){ // [N] atualizarValorDoProduto 1 - 0,25
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 300, 4, 3, 3);
  inserirNovoProdutoGAB123(f, 1, 2, 4, 1);
  inserirNovoProdutoGAB123(f, 5, 2, 3, 2);
  inserirNovoProdutoGAB123(f, 9, 2, 11, 3);

  bool res = atualizarValorDoProduto(f, 5, 11);
  exibirLogGAB123(f);
  res = atualizarValorDoProduto(f, 5, 12);
  exibirLogGAB123(f);
  res = atualizarValorDoProduto(f, 5, 1);
  exibirLogGAB123(f);
}


void teste25(){ // [O] atualizarValorDoProduto 1 - 0,75
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 300, 1, 3, 3);
  inserirNovoProdutoGAB123(f, 1, 3, 4, 1);
  inserirNovoProdutoGAB123(f, 5, 3, 3, 2);
  inserirNovoProdutoGAB123(f, 9, 3, 4, 3);

  bool res = atualizarValorDoProduto(f, 7, 11);
  exibirLogGAB123(f);
  res = atualizarValorDoProduto(f, 3, -12);
  exibirLogGAB123(f);
  res = atualizarValorDoProduto(f, 9, 1);
  exibirLogGAB123(f);
}



void teste26(){ // [P] atualizarValorDoProduto 1 - 0,5
  PLISTA f = criarListaGAB123();
  inserirNovoProdutoGAB123(f, 300, 5, 3, 3);
  inserirNovoProdutoGAB123(f, 1, 2, 4, 3);
  inserirNovoProdutoGAB123(f, 5, 2, 4, 3);
  inserirNovoProdutoGAB123(f, 9, 2, 5, 3);

  bool res = atualizarValorDoProduto(f, 9, 1);
  exibirLogGAB123(f);
  res = atualizarValorDoProduto(f, 1, 1);
  exibirLogGAB123(f);
  res = atualizarValorDoProduto(f, 5, 1);
  exibirLogGAB123(f);
}


void teste27(){ // [Q] teste multiplo 1 - 1,0
  PLISTA f = criarListaGAB123();
  int id;
  int tipo;
  int quantidade;
  int valor;
  bool res;

  printf("################# INSERINDO #######################\n");

  exibirLogGAB123(f);
  res = inserirNovoProduto(f, 2, 2, 22, 23);
  if(res) printf("Insercao retornou true (1)\n");
  else printf("Insercao retornou false (1)\n");
  exibirLogGAB123(f);
  res = inserirNovoProduto(f, 4, 2, 4, 4);
  if(res) printf("Insercao retornou true (3)\n");
  else printf("Insercao retornou false (2)\n");
  exibirLogGAB123(f);
  res = inserirNovoProduto(f, 6, 2, 8, 9);
  if(res) printf("Insercao retornou true (4)\n");
  else printf("Insercao retornou false (3)\n");
  exibirLogGAB123(f);
  res = inserirNovoProduto(f, 3, 2, 22, 23);
  if(res) printf("Insercao retornou true (2)\n");
  else printf("Insercao retornou false (4)\n");
  exibirLogGAB123(f);

  res = inserirNovoProduto(f, -5, 6, 7, 8);
  if(res) printf("Insercao retornou true (5)\n");
  else printf("Insercao retornou false (5)\n");
  exibirLogGAB123(f);

  res = inserirNovoProduto(f, 5, -6, 7, 8);
  if(res) printf("Insercao retornou true (6)\n");
  else printf("Insercao retornou false (6)\n");
  exibirLogGAB123(f);

  res = inserirNovoProduto(f, 5, 6, -7, 8);
  if(res) printf("Insercao retornou true (7)\n");
  else printf("Insercao retornou false (7)\n");
  exibirLogGAB123(f);

  res = inserirNovoProduto(f, 5, 6, 7, -8);
  if(res) printf("Insercao retornou true (4)\n");
  else printf("Insercao retornou false (8)\n");
  exibirLogGAB123(f);
 
  res = inserirNovoProduto(f, 3, 21, 9, 9);
  if(res) printf("Insercao retornou true (2)\n");
  else printf("Insercao retornou false (9)\n");
  exibirLogGAB123(f);


  printf("################# REMOVENDO #######################\n");
  res = removerItensDeUmProduto(f, 4, 1);
  if(res) printf("Remocao retornou true (1)\n");
  else printf("Remocao retornou false (1)\n");
  exibirLogGAB123(f);

  res = removerItensDeUmProduto(f, 6, 7);
  if(res) printf("Remocao retornou true (2)\n");
  else printf("Remocao retornou false (2)\n");
  exibirLogGAB123(f);

  res = removerItensDeUmProduto(f, 3, 22);
  if(res) printf("Remocao retornou true (3)\n");
  else printf("Remocao retornou false (3)\n");
  exibirLogGAB123(f);


  res = removerItensDeUmProduto(f, 20, 1);
  if(res) printf("Remocao retornou true (4)\n");
  else printf("Remocao retornou false (4)\n");
  exibirLogGAB123(f);

  res = removerItensDeUmProduto(f, 5, 10);
  if(res) printf("Remocao retornou true (5)\n");
  else printf("Remocao retornou false (5)\n");
  exibirLogGAB123(f);

  res = removerItensDeUmProduto(f, 4, 0);
  if(res) printf("Remocao retornou true (6)\n");
  else printf("Remocao retornou false (6)\n");
  exibirLogGAB123(f);



  printf("################# ATUALIZANDO VALOR #######\n");

  res = atualizarValorDoProduto(f, 6, 1);
  if(res) printf("Atualizacao retornou true (1)\n");
  else printf("Atualizacao retornou false (1)\n");
  exibirLogGAB123(f);

  res = atualizarValorDoProduto(f, 6, 20);
  if(res) printf("Atualizacao retornou true (2)\n");
  else printf("Atualizacao retornou false (2)\n");
  exibirLogGAB123(f);

  res = atualizarValorDoProduto(f, 6, 600);
  if(res) printf("Atualizacao retornou true (3)\n");
  else printf("Atualizacao retornou false (3)\n");
  exibirLogGAB123(f);


  res = atualizarValorDoProduto(f, 6, 0);
  if(res) printf("Atualizacao retornou true (4)\n");
  else printf("Atualizacao retornou false (4)\n");
  exibirLogGAB123(f);

  res = atualizarValorDoProduto(f, 6, -100);
  if(res) printf("Atualizacao retornou true (5)\n");
  else printf("Atualizacao retornou false (5)\n");
  exibirLogGAB123(f);

  res = atualizarValorDoProduto(f, 61, 600);
  if(res) printf("Atualizacao retornou true (6)\n");
  else printf("Atualizacao retornou false (6)\n");
  exibirLogGAB123(f);

 

  res = atualizarValorDoProduto(f, 6, 3);
  if(res) printf("Atualizacao retornou true (7)\n");
  else printf("Atualizacao retornou false (7)\n");
  exibirLogGAB123(f);

  res = atualizarValorDoProduto(f, 4, 200);
  if(res) printf("Atualizacao retornou true (8)\n");
  else printf("Atualizacao retornou false (8)\n");
  exibirLogGAB123(f);

  res = atualizarValorDoProduto(f, 2, 20);
  if(res) printf("Atualizacao retornou true (9)\n");
  else printf("Atualizacao retornou false (9)\n");
  exibirLogGAB123(f);

  exibirLogGAB123(f);
}