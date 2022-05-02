#include <stdlib.h>
#include <stdio.h>

typedef struct aux {

  int id;
  struct aux* mae;
  struct aux* pai;

} PESSOA;

PESSOA* inicializar(int id){

  PESSOA* x = (PESSOA*) malloc(sizeof(PESSOA));
  x->id = id;
  x->mae = NULL;
  x->pai = NULL;
  return x;

}

void registrar(PESSOA* filho, PESSOA* mae, PESSOA* pai){

  filho->mae = mae; // mae campo a ser acessado; mae parametro
  filho->pai = pai;
  
}

int main(){
  PESSOA* m = inicializar(1);   
  PESSOA* p = inicializar(2);
  PESSOA* f = inicializar(3);

  registrar(f, m, p);
  
  printf("%p %p %p\n", f, f->mae, f->pai);    

  return 0;
}
