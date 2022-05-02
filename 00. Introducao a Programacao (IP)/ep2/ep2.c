#include <stdio.h>

double y;

//Função que retorna o módulo de um número negativo
double modulo (double x, double n) { 
    y = x*x -n;
    if (y < 0){
        return -y;
    } else {
        return y;
    }
}

int main () {

    double n, e, x, intervaloInicial, intervaloFinal;
    int iteracoes;

    printf("Insira um numero para o calculo da raiz e a aproximacao desejada:\n");
    scanf("%lf %lf", &n, &e);

    //Verificando se os números são negativos
    if(n<0 || e<=0){
        printf("Por favor, insira numeros positivos");

    //Bônus - calculando a raiz entre 0 e 1.
    }else if ( n<=1 ) {
        intervaloFinal = 1;
        intervaloInicial = n;
        iteracoes = 0;
                
        while(modulo(x,n) > e) { 
            x = (intervaloFinal + intervaloInicial)/2;
            if(x*x < n){
                intervaloInicial = x;
            }else{
                intervaloFinal = x;
            }
            iteracoes++;
        }

        printf("Numero de iteracoes: %d\n", iteracoes);
        printf("Diferenca absoluta: %.10f\n", modulo(x,n));
        printf("Raiz Quadrada: %.10f\n", x);

    }else {
        x = n/2;
        intervaloInicial = 0;
        intervaloFinal = n;
        iteracoes = 0;

        while (modulo(x,n) > e) {
            x = (intervaloFinal + intervaloInicial)/2; //reduzindo o tamanho do intervalo a cada interação
            if(x*x > n) {
                intervaloFinal = x;
            }else {
                intervaloInicial = x;
            }
            iteracoes++;
        } 

        printf("Numero de iteracoes: %d\n", iteracoes);
        printf("Diferenca absoluta: %.10f\n", modulo(x,n));
        printf("Raiz Quadrada: %.10f\n", x);
    }

    return 0;
}