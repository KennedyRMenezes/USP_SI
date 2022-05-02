/*****************AEDII - Aula-04*******************/
/*  Implementar a estrutura e operações de grafos  */
/*  utilizando listas de adjacência para:          */
/*  - grafos direcionados                          */
/*  - grafos não direcionados                      */
/***************************************************/


#include <stdio.h>
#include <stdbool.h>            /* variaveis bool assumen valores "true" ou "false" */
#include <malloc.h>

#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500

typedef int TipoPeso;

/*
tipo estruturado taresta: vertice destino, peso, ponteiro p/ prox. aresta
*/
typedef struct taresta{
    int vdest;
    TipoPeso peso;
    struct taresta* prox;
} TipoAresta;

typedef TipoAresta* TipoApontador;


/*
tipo estruturado grafo: vetor de listas de adjacencia (cada posicao contem o ponteiro
para o inicio da lista de adjacencia do vetice); numero de vertices
*/
typedef struct{
    TipoApontador* listaAdj;
    int numVertices;
    int numArestas;
} TipoGrafo;

/*Libera o espaço ocupado por um grafo*/
void liberaGrafo(TipoGrafo* grafo){};

/*Obtem o transposto de um grafo direcionado*/
//void grafoTransposto(Grafo, GrafoT){};

/*Obtem a aresta de menor peso de um grafo com peso nas arestas*/
int retiraMin(TipoGrafo* grafo){};

/*
 void inicializaGrafo(TipoGrafo* grafo, int nv):  Cria um grafo com n vertices.
 Aloca espaco para o vetor de apontadores de listas de adjacencias e,
 para cada vertice, inicializa o apontador de sua lista de adjacencia.
 Retorna true se inicializou com sucesso e false caso contrario.
 Vertices vao de 1 a nv.
*/
TipoGrafo* inicializaGrafo(int nv){

    if(nv > MAXNUMVERTICES){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices maior que o permitido DE %d.\n", MAXNUMVERTICES);

    }

    if(nv <= 0){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices deve ser positivo.\n");
    }

    //Alocar memória para o grafo (grafo)
    TipoGrafo* grafo = malloc(sizeof(TipoGrafo));

    //Aumentar o numero de vertices
    grafo->numVertices = nv;
    grafo->numArestas = 0;

    //Alocar memória para lista de adj.
    grafo->listaAdj = malloc(nv * sizeof(TipoApontador));

    //Colocar NULL na lista de adj.
    int i;
    for(i = 0; i < nv; i++){
        grafo->listaAdj[i] = NULL;
    }
    
    return grafo;
};

/*
 void insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo):
 Insere NÃO ORDENADO a aresta (v1, v2) com peso "peso" no grafo.
 Nao verifica se a aresta ja existe.
*/
void insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo){};

/*
 bool existeAresta(int v1, int v2, TipoGrafo *grafo):
 Retorna true se existe a aresta (v1, v2) no grafo e false caso contrário
*/
bool existeAresta(int v1, int v2, TipoGrafo *grafo){};

/*
 bool removeAresta(int v1, int v2, TipoPeso* peso, TipoGrafo *grafo);
 Remove a aresta (v1, v2) do grafo.
 Se a aresta existia, coloca o peso dessa aresta em "peso" e retorna true,
 caso contrario retorna false (e "peso" é inalterado).
*/
bool removeAresta(int v1, int v2, TipoPeso* peso, TipoGrafo *grafo){};

/*
 bool listaAdjVazia(int v, TipoGrafo* grafo):
 Retorna true se a lista de adjacencia (de vertices adjacentes) do vertice v é vazia, e false caso
contrário.
*/
bool listaAdjVazia(int v, TipoGrafo* grafo){};

/*
 TipoApontador primeiroListaAdj(int v, TipoGrafo* grafo):
 Retorna o endereco do primeiro vertice da lista de adjacencia de v
 ou NULL se a lista de adjacencia estiver vazia.
*/
TipoApontador primeiroListaAdj(int v, TipoGrafo* grafo){};


/*
 TipoApontador proxListaAdj(int v, TipoGrafo* grafo):
 Retorna o proximo vertice adjacente a v, partindo do vertice "prox" adjacente a v
 ou NULL se a lista de adjacencia tiver terminado sem um novo proximo.
*/
TipoApontador proxListaAdj(int v, TipoGrafo* grafo, TipoApontador prox){};

/*
 void imprimeGrafo(TipoGrafo* grafo):
 Imprime os vertices e arestas do grafo no seguinte formato:
 v1: (adj11, peso11); (adj12, peso12); ...
 v2: (adj21, peso21); (adj22, peso22); ...
 Assuma que cada vértice é um inteiro de até 2 dígitos.
*/
void imprimeGrafo(TipoGrafo* grafo){};


int main(){}
