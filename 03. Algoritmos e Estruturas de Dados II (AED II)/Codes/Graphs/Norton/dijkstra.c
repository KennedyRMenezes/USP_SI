/*

            Algoritmo de Dijkstra

    Vimos que a busca em largura nos dah o menor caminho entre um vertice inicial
        e todos os demais no grafo.
    O caminho eh medido em numeros de arestas, ignorando quaisquer pesos que estas
        tenham.
    Para varios problemas, contudo, o peso nas arestas eh crucial, quando queremos
        achar a rota mis curta entre duas cidades.
    
    Para isso usamos o algoritmo de Dijkstra: algoritmo que calcula o caminho mais
        curto, em termos do peso total das arestas, entre um noh inicial e todos os
        demais nohs no grafo. O peso total das arestas eh a soma dos pesos das
        arestas que compoem o caminho
    
    Funcionamento:
        Para cada vertice 'v' do grafo, mantemos um atributo 'd[v]' que eh um limite
            superior para o peso do caminho mais curto do noh inicial 's' a 'v'
        Dizemos que 'd[v]' é uma estimativa de caminho mais curto, inicialmente
            feito 'infinity'
        Tambem armazenamos o vertice que precede v(p[v] - precedente de v) no 
            caminho mais curto de 's' a 'v'
    
    Algoritmo:
        --> Faca a estimativa de distancia de 's' a qualquer vertice ser infinita
            --> Exceto claro, a distancia de 's' a 's', que é 0
            --> Ou seja, d[s] = 0 e d[v] = inifinity para todo 'v' diferente de 's'
        
        --> Faça os precedentes dos nohs serem um valor qualquer
            --> Na prática, podemos fazer p[v] = -1, já que não temos vertice de 
            indice -1 na estrutura GRAFO
        
        --> Marque todos os vertices como "abertos" (Não tenho a distancia definitiva
        para nenhum/ avertos significa o valor de d[v] é uma estimativa ("chute"))

        --> Enquanto houver vertice aberrto:
            --> Escolha o vertice aberto 'u' cuja estivamativa seja a menor dentre
            os demais abertos
            --> Feche 'u'
            --> Para todo noh aberto 'v' na adjacencia de 'u':
                --> Some d[u] ao peso da aresta(u, v)
                --> Caso a soma seja menor que d[v], atualize d[v] e faca p[v] = u

        **Este procedimento eh chamado de relaxamento da aresta (u, v)**
            
    Resumindo:
        --> Inicialize o grafo com d[s] = 0, d[v] = infinity, para todo 'v' != 's', e
            p[v] = -1 para todo 'v'
        --> Faca abero[v] = true para todo 'v' no grafo.
        --> Enquanto houver vertice aberto:
            --> Escolha 'u' cuja estimativa seja a menor dentre os abertos
            --> Feche 'u'
            --> Para todo noh aberto 'v' na adjacencia de 'u':
                --> Relaxe a aresta (u, v)

    Observações
        --> Fechamos um noh 'u' somente se jah conhecemos a menor distancia deste ao
            noh inicial 's'
        --> Entao fazemos o relaxamento de seus vizinhos:
            --> Sabemos a menor distancia de 's' a 'u' 
            --> Temos a estimativa de 's' a 'v', 'v' vizinho de 'u'
            --> Buscamos saber se a distancia de 's' a 'u' mais a distancia de (u,v)
                eh melhor que a estimativa atual de 's' a 'v'. Se for, atualizamos
                essa estimativa
        
        --> Note que, alem da distancia, o caminho tambem pode ser obtido. Basta
            olhar os antecedentes, percorrendo noh final ao inicial.
*/ // Implementação |
//                  |
//                  V

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     // para usar o INT_MAX
#include "graph_list_norton.c"
#include "profundidade.c"
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;



// *d: array de distancia, *p: predecessor, s: ponto inicial
void inicializaD(GRAFO *g, int *d, int *p, int s){
    int v;
    for(v = 0; v < g->vertices; v++){
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0;
}

// relaxar arestas de 'u' a 'v'
void relaxa(GRAFO *g, int *d, int *p, int u, int v){

    ADJACENCIA *ad = g->adj[u].cab;
    while (ad && ad->vertice != v)
        ad = ad->prox;
    if(ad){
        if (d[v] > d[u] + ad->peso){
            d[v] = d[u] + ad->peso;
            p[v] = u;
        }
    }
}

int *dijkstra(GRAFO *g, int s){

    /*Alocando distancias para arranjo de distancias*/
    int *d = (int *)malloc(g->vertices*sizeof(int));

    /*Alocando arranjo de predecessores*/
    int p[g->vertices];
    bool aberto[g->vertices];
    inicializaD(g,d,p,s);

    /*Inicializa arranjo de abertos com true*/
    int i;
    for(i = 0; i < g->vertices; i++)
        aberto[i] = true;

    while (existeAberto(g, aberto)){
        int u = menorDist(g, aberto, d);
        /*Fechou*/
        aberto[u] = false;

        /*Para cada noh na adjacencia desse u que foi fechado relaxa a aresta*/
        ADJACENCIA *ad = g->adj[u].cab;
        while(ad){
            relaxa(g,d,p,u,ad->vertice);
            ad = ad->prox;
        }
    }

    /*Ao final tem-se todas as distancias do arranjo e entao eh retornado*/
    return d;
}


bool existeAberto(GRAFO *g, int *aberto){

    int i;
    for(i = 0; i < g->vertices; i++)
        if (aberto[i]) return (true);
    return (false);

}

/*dentro todos abertos deve retornar o com a menor distancia*/
int menorDist(GRAFO *g, int *aberto, int *d){

    /*Ao encontrar o primeiro aberto quebra o laço 
        e 'i' terah o indice do noh aberto*/
    int i;
    for(i = 0; i < g->vertices; i++)
        if (aberto[i]) break;
    
    /*Se varreu e nao encontrou retorna -1*/
    if(i == g->vertices) return -1;

    /*Se encontrou assume este como noh como de menor estimativa de distancia*/
    int menor = i;

    /*Substitui o valor de 'menor' se encontrar uma distancia menor.*/
    for(i = menor+1; i < g->vertices; i++)
        if (aberto[i] && (d[menor]>d[i])) 
            menor = i; //atualiza indice do vertice com menor distancia

    return menor;
}

/*

    !Dijkstra tem um limitante importante:
    
        --> Os pesos das arestas devem ser nao-negativos.

        --> Além disso, a implementação de 'existeAberto' e 'menorDist' é crucial
            para a velocidade do algoritmo.

        --> A implementacao aqui mostrada nao eh a mais rapida.

        --> Para uma melhor, busque uma implementação com filas de prioridade

*/




