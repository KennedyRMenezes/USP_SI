#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* gerador(int *arr, int numeros) { /* Funcao geradora de numeros*/
    int i;

    srand(time(NULL));

    for (i = 0; i < numeros; i++)
        arr[i] = rand() % 1000;

    /*Imprime os numeros gerados aleatoriamente, util apenas para sequencias pequenas
    e para verificar a funcionalidade do código*/

    /*printf("\nNumeros aleatorios\n\n");
    for(i = 0; i < numeros; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");*/


    return arr;
}

void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int* array, int size) {
   
  int pivot = array[size-1];
  int i = -1;
  int j;

  for(j = 0; j < size-1; j++)
    if(array[j] <= pivot)
      troca(&array[++i], &array[j]);
  troca(&array[i+1], &array[j]);

  return i + 1;
}

int selection2(int* arr, int tamanho, int iEhsimo) {

    int q = partition(arr, tamanho);

    if(tamanho == 1) return arr[iEhsimo];
    if(iEhsimo < q) return selection2(arr, q-1, iEhsimo);/*q-1, pois q jah eh maior que o iEhsimo*/
    else if (iEhsimo > q) return selection2(arr + (q+1), tamanho - (q+1), iEhsimo - (q+1));
    else return arr[q];
}

int main () {

    /*****  GERADOR DE NUMEROS E INSERINDO-OS NO ARRAY  *****/

    int mult; /*Valor que a ser inseriodo p/ multiplicar por mil*/
    int inicio = 10000; /*Valor inicial*/
    int totalNum = 0;
    
    printf("Sera gerado %i nºs vezes o valor a ser inserido: ", inicio); 
    scanf("%d", &mult);

    /*Nao aceita valores negativos para a multiplicacao*/
    if(mult > 0) totalNum = inicio * mult;
    else printf("ERRO | Por favor, insira um valor positivo\n");

    int *arr = (int*) malloc(totalNum * sizeof(int));

    gerador(arr, totalNum);

    /***** PASSAR O ARRAY PARA ALGORITMO DE ORDENACAO E RETORNA I-ÉSIMO ELEMENTO*****/

    int tam = totalNum;

    double time_spent = 0.0;
    
    /*Gera um numero aleatorio e acha o indice desse numero no array*/
    int iEhsimo = (rand() % totalNum);

    /********* Indice do i-ehsimo numero a ser encontrado*********/
    /*printf("\n******* i-ehsimo numero: %d ********", iEhsimo);*/

    clock_t begin = clock();
    int achaIEhsimo = selection2(arr, tam, iEhsimo);
    clock_t end = clock();

    /********* Imprime o i-ehsimo numero encontrado *********/
    /*printf("\n\ni-ehsimo numero encontrado: %d\n", achaIEhsimo);*/

    /********* Numeros depois de passarem por selection2 *********/
    /*printf("\nNumeros depois de selection2\n\n");
    for(int b = 0; b < tam; b++){
        printf("%d ", arr[b]);
    }*/

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("O tempo de execucao em segundos foi: %f\n", time_spent);

    return 0;
}
