#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

/*Adjacencia representa efetivamente uma aresta*/
typedef struct adjacencia{
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice{
    /*Cabeca da lista ligada de suas adjacencias*/
    ADJACENCIA *cab;
}VERTICE;

typedef struct grafo{
    int vertices;
    int arestas;
    /*Arranjo de vertices que compoe o grafo*/
    VERTICE *adj;
}GRAFO;


/*Inicializando um grafo*/
GRAFO *criaGrafo(int v){

    /*Inicializa grafo alocando memoria e definindo numero de vertices e arestas*/
    GRAFO *g = (GRAFO*)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;

    /*Alocando memoria para a lsita de adjacencia*/
    g->adj = (VERTICE*)malloc(v*sizeof(VERTICE));

    /*Populando a lista de adjacencia com NULL*/
    int i;
    for(i=0; i < v; i++){
        g->adj[i].cab = NULL;
    }

    return g;
}

 
/*Adjacencia eh como se fosse a ponta da setinha, falta criar a aresta ainda*/
ADJACENCIA *criaAdj(int v, int peso){

    ADJACENCIA *temp = (ADJACENCIA*)malloc(sizeof(ADJACENCIA));
    
    /*Vertice final e peso*/
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;

    return temp;

}

/*Cria uma aresta dirigida. Se for para um grado nao-dirigido eh soh chamar
o procedimento duas vezes de vi-->vf e de vf-->vi*/
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){

    if(!gr) return false;
    if((vf < 0) || (vf >= gr->vertices)) return false;
    if((vi < 0) || (vi >= gr->vertices)) return false;

    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;
    gr->arestas++;

    return true;

}

void imprime(GRAFO *gr){

    if(!gr) printf("Grafo inválido!");

    printf("Vertices: %d. Arestas: %d.\n", gr->vertices, gr->arestas);

    int i;
    for(i = 0; i < gr->vertices; i++) {
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;

        while(ad){
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }

        printf("\n");
    }

}


// int main(void){

//     GRAFO *gr = criaGrafo(5);

//     criaAresta(gr, 0, 1, 2);
//     criaAresta(gr, 1, 2, 10);
//     criaAresta(gr, 2, 2, 4);
//     criaAresta(gr, 2, 0, 12);
//     criaAresta(gr, 2, 4, 40);
//     criaAresta(gr, 3, 1, 3);
//     criaAresta(gr, 4, 3, 8);

//     imprime(gr);
// }