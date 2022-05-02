#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* gerador(int *arr, int numeros) { /* Funcao geradora de numeros*/
    int i;

    srand(time(NULL));

    for (i = 0; i < numeros; i++)
        arr[i] = rand() % 1000;

    return arr;
}

int* merge(int* array1, int* array2, int size1, int size2) {
  int k, i, j;
  i = j = 0;

  int* array3 = (int*) malloc(sizeof(int)*(size1 + size2));

  for(k = 0; k < size1 + size2; k++)
    array3[k] = ((array1[i] <= array2[j] && i < size1) || j >= size2) ? array1[i++] : array2[j++];

  return array3;
}

void merge_sort(int* array, int size) {
  int m = size/2;
  int* tmp;

  if (size > 1) {
    merge_sort(array, m);
    merge_sort(&array[m], size - m);
  }

  tmp = merge(array, &array[m], m, size - m);

  for(int i = 0; i < size; i++) array[i] = tmp[i];
}

int selection1(int* arr, int tam, int iEhsimo){

    merge_sort(arr, tam);
    return arr[iEhsimo];
}

int main(void){

    /*****  GERADOR DE NUMEROS E INSERINDO-OS NO ARRAY  *****/

    int mult; /*Valor que a ser inseriodo p/ multiplicar por mil*/
    int inicio = 10000; /*Valor inicial*/
    int totalNum = 0;
    
    
    printf("Sera gerado %i nºs vezes o valor a ser inserido: ", inicio);
    scanf("%d", &mult);
    /*Nao aceita valores negativos para a multiplicacao*/
    if(mult > 0) totalNum = inicio * mult;
    else printf("ERRO | Por favor, insira um valor positivo\n");

    int *arr = malloc(totalNum * sizeof(int));

    gerador(arr, totalNum);

    /***** PASSAR O ARRAY PARA ALGORITMO DE ORDENACAO E RETORNA I-ÉSIMO ELEMENTO*****/

    int tam = totalNum;

    double time_spent = 0.0;

    /*Gera um numero aleatorio e acha o indice desse numero no array*/
    int iEhsimo = (rand() % totalNum);

    clock_t begin = clock();
    int achaIEhsimo = selection1(arr, tam, iEhsimo);
    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("O tempo de execucao em segundos foi: %f\n", time_spent);

    return 0;
}