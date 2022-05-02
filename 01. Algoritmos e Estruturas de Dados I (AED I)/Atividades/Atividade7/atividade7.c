#include <stdio.h>
#include <malloc.h>
#define ERRO -1
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT cabeca;
    PONT fim;
} FILA;

//Inicializacao da fila ligada (a fila jah esta criada e eh apontada pelo endereço em f)
void inicializarFila(FILA* f) {
    f->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    f->cabeca->prox = NULL;
    f->fim = f->cabeca;
}

//Retornar o tamanho da fila (numero de elementos)
int tamanho(FILA* f) {
    PONT end = f->cabeca->prox;
    int tam = 0;
    while (end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

//Retornar o tamanho em bytes da fila. Neste caso, isto depende do numero de elementos que estao sendo usados.
int tamanhoEmBytes(FILA* f) {
    return (tamanho(f)*sizeof(ELEMENTO)) + sizeof(FILA);
}

//Destruição da fila (reinicializar) libera a memoria de todos os elementos da fila
void destruirFila(FILA* f){
    PONT end = f->cabeca->prox;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->cabeca->prox = NULL;
    f->fim = f->cabeca;
}

//retornarPrimeiro - retorna o endereço do primeiro elemento da fila e (caso a fila nao esteja vazia) retorna a chave desse elemento na memoria apontada pelo ponteiro ch
PONT retornaPrimeiro(FILA* f, TIPOCHAVE *ch) {
    if(f->cabeca->prox != NULL) *ch = f->cabeca->prox->reg.chave;
    return f->cabeca->prox;
}

//retornaUltimo - retorna o endereco do ultimo elemento da fila e (caso a fila nao esteja vazia) retorna a chave desse elemento na memoria apontada pelo ponteiro ch
PONT retornaUltimo(FILA* f, TIPOCHAVE* ch){
    if (f->cabeca->prox == NULL) return NULL;
    *ch = f->fim->reg.chave;
    return f->fim;
}

//Inserção no fim da fila
bool inserirNaFila(FILA* f, REGISTRO reg) {

    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if(f->cabeca->prox == NULL){
        f->cabeca->prox = novo;
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;
    return true;

}

//Excluir inicio da fila
bool excluirDaFila(FILA* f, REGISTRO* reg){

    if(f->cabeca->prox == NULL){
        return false;
    }
    *reg = f->cabeca->prox->reg;
    PONT apagar = f->cabeca->prox;
    f->cabeca->prox = f->cabeca->prox->prox;
    free(apagar);
    if(f->cabeca->prox == NULL){
        f->fim = f->cabeca;
    }
    return true;
}

//Exibição da fila sequencial
void exibirFila(FILA* f){
    PONT end = f->cabeca->prox;
    printf("Fila: \" ");
    while (end != NULL){
        printf("%d ", end->reg.chave); //soh lembrando TIPOCHAVE = int
        end = end->prox;
    }
    printf("\"\n");
}

//Busca sequencial
PONT buscaSeq(FILA* f, TIPOCHAVE ch){
    PONT pos = f->cabeca->prox;
    while(pos != NULL){
        if(pos->reg.chave == ch) return pos;
        pos = pos->prox;
    }
    return NULL;
}

//Busca sequencial com sentinela alocado dinamicamente
PONT buscaSeqSent1(FILA* f, TIPOCHAVE ch){
    if(!f->cabeca->prox) return NULL;
    PONT sentinela = malloc(sizeof(ELEMENTO));
    sentinela->reg.chave = ch;
    f->fim->prox = sentinela;
    PONT pos = f->cabeca->prox;
    while(pos->reg.chave != ch) pos = pos->prox;
    free(sentinela);
    f->fim->prox = NULL;
    if(pos != sentinela) return pos;
    return NULL;
}

//Busca sequencial com sentinela como variavel local
PONT buscaSequencial2(FILA* f, TIPOCHAVE ch){
    if(!f->cabeca->prox) return NULL;
    ELEMENTO sentinela;
    sentinela.reg.chave = ch;
    f->fim->prox = &sentinela;
    PONT pos = f->cabeca->prox;
    while (pos->reg.chave != ch) pos = pos->prox;
    f->fim->prox = NULL;
    if(pos != &sentinela) return pos;
    return NULL;
}