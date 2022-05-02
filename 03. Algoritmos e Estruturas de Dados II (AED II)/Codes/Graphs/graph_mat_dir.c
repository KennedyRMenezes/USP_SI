/*****************AEDII - Aula-03*******************/
/*  Implemente (em C) a estrutura de dados e as    */
/*  operações aqui definidas, utilizando matriz de */
/*  adjacência, para grafos direcionados.          */
/***************************************************/

/***************************************************/
/*  O que mudaria na implementação de grafos       */
/*  não direcionados?                              */
/***************************************************/


#include <stdio.h>
#include <stdbool.h>            /* variaveis bool assumen valores "true" ou "false" */
#include <stdlib.h>

#define MAXNUMVERTICES 100
#define AN 0                   /* aresta nula, ou seja, valor que representa ausencia de aresta*/
#define VERTICE_INVALIDO -1     /* numero de vertices invalidos ou ausentes */

typedef int TipoPeso;
typedef struct{
    TipoPeso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
    int numVertices;
    int numArestas;
} TipoGrafo;
typedef int TipoApontador;

/*Libera o espaço ocupado por um grafo*/
void liberaGrafo(TipoGrafo* grafo){
  /*Nao precisa fazer nada para matrizes de adjacencia*/
};

/*Obtem a aresta de menor peso de um grafo com peso nas arestas*/
int retiraMin(TipoGrafo* grafo){

  int menor;
  int aux = 0;
  //double l = (numVertices*(numVertices-1)/2);
  for (int i = 0; i <grafo->numVertices;i++){
    for(int j = 0; j < grafo->numVertices; j++){
      if(grafo->mat[i][j] !=0){
        aux+=1;
        if(aux == 1){
          menor = grafo->mat[i][j];
        }else{
          if(grafo->mat[i][j] < menor){
            menor = grafo->mat[i][j];
          }
        }
      }
    }
  }

  return menor;
};

/*
 void inicializaGrafo(TipoGrafo* grafo, int nv): Inicializa um grafo com nv vértices
 Preenche as células com AN (representando ausência de aresta)
 Vértices vão de 1 a nv.
*/
void inicializaGrafo(TipoGrafo* grafo, int nv){
    int i, j;

    if(nv > MAXNUMVERTICES){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices maior que o permitido DE %d.\n", MAXNUMVERTICES);

    }

    if(nv <= 0){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices deve ser positivo.\n");
    }

    grafo->numVertices = nv+1;

    for(i = 0; i <= grafo->numVertices; i++){
        for(j = 0; j <= grafo->numVertices; j++){
            if(i == 0){
              grafo->mat[i][j] = j;
            }else if(j == 0){
              grafo->mat[i][j] = i;
            }else{
              grafo->mat[i][j] = AN;
            }
        }
    }
};

/*Obtem o transposto de um grafo direcionado*/
void grafoTransposto(TipoGrafo* grafo, TipoGrafo* grafoT){

  int numvert = grafo->numVertices-1;
  inicializaGrafo(grafoT, numvert);

  for(int i = 0; i < grafo->numVertices; i++){
    for(int j = 0; j < grafo->numVertices; j++){
      grafoT->mat[i][j] = grafo->mat[j][i];
    }
  }
};

/*
 void insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo):
 Insere a aresta (v1, v2) com peso "peso" no grafo
*/
void insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo){
    grafo->mat[v1][v2] = peso;
    grafo->numArestas +=1;
};

/*
 bool existeAresta(int v1, int v2, TipoGrafo *grafo):
 Retorna true se existe a aresta (v1, v2) no grafo e false caso contrário
*/
bool existeAresta(int v1, int v2, TipoGrafo *grafo){
  if(grafo->mat[v1][v2]){
    return true;
  }
};

/*
 bool removeAresta(int v1, int v2, TipoPeso* peso, TipoGrafo *grafo);
 Remove a aresta (v1, v2) do grafo colocando AN em sua celula (representando ausencia
de aresta).
 Se a aresta existia, coloca o peso dessa aresta em "peso" e retorna true,
 caso contrario retorna false (e "peso" é inalterado).
*/
bool removeAresta(int v1, int v2, TipoPeso* peso, TipoGrafo *grafo){
  if(grafo->mat[v1][v2]){
    *peso = grafo->mat[v1][v2];
    grafo->mat[v1][v2] = AN;
    return true;
  }
  return false;
};

/*
 bool listaAdjVazia(int v, TipoGrafo* grafo):
 Retorna true se a lista de adjacencia (de vertices adjacentes) do vertice v é vazia, e false caso
contrário.
*/
bool listaAdjVazia(int v, TipoGrafo* grafo){

  // for (int i = 0; i < grafo->numVertices; i++){
  //   if (existeAresta(i, v, grafo)) return false;
  // }
  //   return true;

  printf("Lista de adjacencia do vertice %d: ", v);
  for (int i = 0; i < grafo->numVertices; i++){
    if(i != 0){
      if(grafo->mat[i][v] != AN)
        printf("%d(%d)", grafo->mat[i][v], i);
    }
  }
    return true;

};

/*
 TipoApontador primeiroListaAdj(int v, TipoGrafo* grafo):
 Retorna o primeiro vertice da lista de adjacencia de v.
*/
TipoApontador primeiroListaAdj(int v, TipoGrafo* grafo){
  int i;
  i = 0;
  for (i = 0; i < grafo->numVertices; i++){
    if (existeAresta(i, v, grafo)) return i;
  }

};


/*
 TipoApontador proxListaAdj(int v, TipoGrafo* grafo, TipoApontador atual):
 Trata-se de um iterador sobre a lista de adjacência do vertice v.
 Retorna o proximo vertice adjacente a v, partindo do vertice "atual" adjacente a v
 ou VERTICE_INVALIDO se a lista de adjacencia tiver terminado sem um novo
 proximo
*/
TipoApontador proxListaAdj(int v, TipoGrafo* grafo, TipoApontador atual){

    for (int i = atual+1; i < grafo->numVertices; i++){
      if(grafo->mat[i][v] != AN){
        return grafo->mat[i][v];
      }
    }

    return VERTICE_INVALIDO;

};

/*
 void imprimeGrafo(TipoGrafo* grafo):
 Imprime a matriz de adjacencia do grafo.
 Assuma que cada vértice e cada peso de aresta são inteiros de até 2 dígitos.
*/
void imprimeGrafo(TipoGrafo* grafo){

    for(int i = 0; i < grafo->numVertices; i++){
        for(int j = 0; j < grafo->numVertices; j++){
            printf("%d  ", grafo->mat[i][j]);
        }
        printf("\n"); /*new line*/
    }
};

void imprimeGrafoT(TipoGrafo* grafoT){
    for(int i = 0; i < grafoT->numVertices; i++){
        for(int j = 0; j < grafoT->numVertices; j++){
            printf("%d  ", grafoT->mat[i][j]);
        }
        printf("\n"); /*new line*/
    }
};

void help(){
  printf("Comandos validos: \n");
  printf("   b : insere aresta\n");
  printf("   i : imprime grafo\n");
  printf("   t : imprime grafo transposto\n");
  printf("   a : imprime lista de adjacencia\n");
  printf("   e : existe aresta?\n");
  printf("   f : qual é o próximo vértice\n");
  printf("   r : remove aresta\n");
  printf("   p : primeiro adjacente\n");
  printf("   l : libera grafo\n");
  printf("   g : faz grafo transposto\n");
  printf("   q : sair (quit)\n\n\n");
}

int main(){

  /*Quantidade de vertices*/
  printf("Insira o numero de vertices.\n");
  int vert;
  scanf("%d", &vert);
  printf("\n");

  TipoPeso guarda; //guarda valor do peso na remocao da aresta
  TipoGrafo grafo;
  TipoGrafo grafoT;
  inicializaGrafo(&grafo, vert);

  /*----------------------------------------------------*/

  /*Gerencia os comandos para acoes com a matriz*/
  help();
  char comando = ' ';
  scanf("%c",&comando);
  int limite = (vert * (vert-1))/(2);
  while (comando != 'q'){
    switch (comando) {
      case 'b' :
        if(limite != 0){
          printf("Insira dois vertices para uma aresta e um peso\n\n");
          int ver1, ver2, pe;
          scanf("%d %d %d", &ver1, &ver2, &pe);
          printf("\n\n\n");
          insereAresta(ver1, ver2, pe, &grafo);
          limite = limite - 1;
          printf("limite de arestas: %d\n\n", limite);
        }else{
          printf("Limite de arestas excedido\n\n");
        }
        break;
      case 'i' :
        printf("\t\t *Grafo impresso*\n\n");
        imprimeGrafo(&grafo);
        printf("\n"); break;
      case 'a' :
        printf("\t\t *Insira vertice para conferir lista de adjacentes*\n\n");
        int v;
        scanf("%d", &v);
        listaAdjVazia(v, &grafo);
        printf("\n\n"); break;
      case 'e' :
        printf("\t\t *Insira aresta para ver se existe*\n\n");
        int ar1, ar2;
        scanf("%d %d", &ar1, &ar2);
        if(existeAresta(ar1, ar2, &grafo)) printf("Aresta existente\n");
        else printf("Aresta inexistente");
        printf("\n"); break;
      case 'f' :
        printf("\t\t *Insira vertice e o atual para saber o próximo*\n\n");
        int vert;
        scanf("%d", &vert);
        int prox = proxListaAdj(vert, &grafo, 1);
        printf("proximo da lista de adjacencia do %d: %d", vert, prox);
        printf("\n\n\n"); break;
      case 'r' :
        printf("\t\t *Insira v1 e v2 para remover aresta*\n\n");
        int are1, are2;
        scanf("%d %d", &are1, &are2);
        removeAresta(are1, are2, &guarda, &grafo);
        limite = limite + 1;
        imprimeGrafo(&grafo);
        printf("\n"); break;
      case 'p' :
        printf("\t\t *Insira vertice para conferir o primeiro adjacente*\n\n");
        int vert1;
        scanf("%d", &vert1);
        listaAdjVazia(v, &grafo);
        printf("\n"); break;
      case 't' :
        printf("\t\t *Grafo transposto impresso*\n\n");
        imprimeGrafoT(&grafoT);
        printf("\n"); break;
      case 'l' :
        printf("\t\t *Libera grafo*\n\n");
        liberaGrafo(&grafo);
        liberaGrafo(&grafoT);
        printf("\n"); break;
      case 'g' :
        printf("\t\t *Fazendo grafo transposto...*");
        grafoTransposto(&grafo, &grafoT);
        printf("\n"); break;
      case 'x' :
        printf("\t\t *Aresta de menor peso*\n\n");
        int menorA = retiraMin(&grafo);
        printf("Menor aresta eh: %d", menorA);
        printf("\n"); break;
      case 'z' :
        printf("\t\t *Libera grafo*\n\n");
        liberaGrafo(&grafo);
        liberaGrafo(&grafoT);
        printf("\n"); break;


      default: {while (comando != '\n') scanf("%c",&comando);};
    }
    scanf("%c",&comando);
  }

}
