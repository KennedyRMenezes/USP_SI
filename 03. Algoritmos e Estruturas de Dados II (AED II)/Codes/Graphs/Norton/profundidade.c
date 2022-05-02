/*

            Busca em Profundidade (Depth-first search or DFS)

    Buscar mais fundo no grafo sempre que possivel

    A busca para quando encontramos o que queriamos ou visitamos todos os 
        vertices.

    As arestas sao exploradas a partir do vertice 'v' mais recentemente 
        descoberto que ainda tem arestas nao exploradas saindo dele.
    Quandos todas as arestas de 'v' sao exploradas, a busca volta ao
        vertice anterior a 'v' (backtracking) para seguir arestas ainda 
        nao exploradas

    O processo continua até que tenhamos descoberto todos os vertices que
        sao atingiveis a partir do vertice inicial.
    Um vertice 'v' eh atingivel a partir de um vertice 'u' se houver um
        caminho de 'u' a 'v' no grafo.
    Se restarem ainda vertice nao visitados, um eh selecionado e reiniciamos
        a busca a partir dele.
    
    Funcionamento:
        -> Defina um noh inicial.
        -> Escolha um de seus adjacentes ainda nao visitados.
            -> Visite-o.
        -> Repita o processo ate atingir o noh objetivo, ou um noh cuja 
        adjacencia jah tenha sido toda visitada (noh final).
        -> Se atingir um noh final que nao seja objetivo:
            -> Volte ao pai deste;
            -> Continue de um noh irmao ainda nao visitado.
    
    Reescrevendo:
        -> Defina um noh inicial.
        -> Enquanto este nao for um noh objetivo ou final (noh cuja
        adjacencia jah tenha sido toda visitada).
            -> Escolha um de seus adjacentes ainda nao visitados;
            -> Visite-o.
        -> Se o noh final nao eh o objetivo:
            -> Volte ao pai deste;
            -> Se houver pai, repita. Senão escolha outro noh inicial.


    Implementação:
        -> Devemos "colorir" os vertices durante a busca, indicando seu
        estado.
        -> Cada vertice eh;
            # inicialmente branco; 
            # feito amarelo quando descoberto na busca;
            # feito vermelho quando for finalizado (quando sua lista de 
            adjacentes for completamente examinada).
    
    A representacao que melhor se adequa a Busca em Profundidade eh a Lista de 
        Adjacencias

    Se um grafo nao for fortemente conexo o resultado depois de uma busca em 
        profundidade serah dois grafos desconexos (floresta)
*///----
//      | Codigo
//      V

#include "graph_list_norton.c"
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2


void visitaP(GRAFO *g, int u, int *cor){

    /*Ao visitiar um noh, o marcamos com amarelo*/
    cor[u] = AMARELO;

    //TODO: Tempo de descoberta inicial
    //TODO: Saber se há um ciclo (se o vertice for AMARELO || VERMELHO)
    //TODO: Classificar aresta (arvore, retorno, cruzamento)

    /*Entao visitamos sua adjacencia(arestas (u,v) 
        recursivamente)*/
    ADJACENCIA *v = g->adj[u].cab;


    while(v) {
        /*Passa por vertices ainda nao visitados*/
        if(cor[v->vertice] == BRANCO) visitaP(g, v->vertice, cor);
        v = v->prox;
       
        
    }

    /*Depois que passar pela lista de adjacencia do vertice marca
        todos com a cor vermelha*/
    cor[u] = VERMELHO;

    //TODO: Tempo de descoberta final

} // ------
//        | Pergunta?
//        V
/*
    E se quisermos incluir uma chave de busca? (condicao para achar um vertice).

    Chaves de busca sao incluidas inicialmente em VERTICE.

    E verificadas quando o noh eh visitado. (Antes de pintar o noh de amarelo
        coloca-se alguma condicao de parada, seja ela o retorno do indice do
        vertice ou um  'true' se achou o vertice).
    

*/

void profundidade(GRAFO *g){

    /*
        Definindo arranjo de cores, armazena a cor do vertice;
        indice do vertice no arranjo 'adj' em GRAFO seja o 
        mesmo do arranjo 'cor'
    */
    int cor[g->vertices];

    /*define todos com a cor BRANCO*/
    int u;
    for( u = 0; u < g->vertices; u++){
        cor[u] = BRANCO;
    }

    /*
        A verificacao de todos os vertices brancos serve para 
        garantir que, uma vez esgotada uma arvore de busca,
        possamos reiniciar de algum outro vertice nao visitado
    */
    for (u = 0; u < g->vertices; u++){
        if(cor[u] == BRANCO)
            visitaP(g, u, cor);
    }

}