#include <stdio.h>
#include <math.h>

int ehValido;
int qualTipo;
int oAngulo;
double altura;
double area;

// -------------------------------------------- TRIÂNGULO É VÁLIDO OU NÃO -------------------------------------------------
int trianguloValido (int l1, int l2, int l3) {
    int a = l2 - l3;
    int b = l1 - l3;
    int c = l1 - l2;

    int abs(int x); //função para receber o resultado da conta e transformar em módulo

    //verificando a condição de existência de um triângulo pela fórmula ↓
    // | b - c | < a < b + c
    // | a - c | < b < a + c
    // | a - b | < c < a + b
    if ((abs((a)) < l1 && l1 < l2 + l3) && (abs((b)) < l2 && l2 < l1 + l3) && (abs((c)) < l3 && l3 < l1 + l3)) {
        ehValido = 1; //variável para fazer validação na hora de imprimir
    }
    else {
        ehValido = 0; 
    }
}

// ----------------------------------------------- TIPO DO TRIÂNGULO ------------------------------------------------------
int tipoDoTriangulo (int l1, int l2, int l3) {
    //verificando possibilidades de tipos de triangulo a partir de seus lados
    int a = l1 == l2; 
    int b = l2 == l3;
    int c = l2 != l3;
    int d = l1 != l2;
    int e = l1 == l3;

    if (a && b) { // TRIÂNGULO EQUILÁTERO
        qualTipo = 1; //variável para saber qual o tipo na hora de imprimir
    }
    else if ((a && c) || (b && d) || (d && e)) { // TRIÂNGULO ISOSCELES
        qualTipo = 2;
    }
    else if (c && d) { // TRIÂNGULO ESCALENO
        qualTipo = 3;
    }
    else {
         printf("ERROR\n"); 
    }
}

// ----------------------------------------------- ÂNGULO DO TRIÂNGULO ------------------------------------------------------
int anguloDoTriangulo (int l1, int l2, int l3) {
    int a;
    int b;
    int c;

    //Encontra o maior lado do triângulo
    if (l1 >= l2 && l1 >= l3) {
        a = l1; b = l2; c = l3;
    }
    else if (l2 >= l1 && l2 >= l3) {
        a = l2; b = l1; c = l3;
    }
    else {
        a = l3; b = l1; c = l2;
    }

    if((a*a) < (b*b + c*c)) {
        oAngulo = 1; // variável para saber o ângulo na hora de imprimir - triângulo acutângulo, ângulo agudo
    }
    else if ((a*a) == (b*b + c*c)) {
        oAngulo = 2; // triângulo retângulo; ângulo reto
    }
    else {
        oAngulo = 3; // triângulo obtusângulo; ângulo obtuso
    }
}

// ----------------------------------------------- ÁREA DO TRIÂNGULO ------------------------------------------------------
double areaDoTriangulo (int l1, int l2, int l3) {
    int a;
    int b;
    int c;

    //Escolhendo o tipo do triângulo para o cálculo da área
    if(qualTipo == 1) { // TRIÂNGULO EQUILÁTERO - l².√3/4
        area = (l1 * l1) * sqrt(3) / 4;
    }
    else if(qualTipo == 2) { // TRIÂNGULO ISOSCELES - b.h/2 - aqui foi necessário achar a altura primeiro
        if (l1 == l2) {
            altura = sqrt((l1 * l1) - (l3/2) * (l3/2)); // achando a altura.
            area = (altura * l3) / 2;
        }
        else if ( l2 == l3) {
            altura = sqrt((l2 * l2) - (l1/2) * (l1/2));
            area = (altura * l1) / 2;
        }
        else if ( l3 == l1) {
            altura = sqrt((l3 * l3) - (l2/2) * (l2/2));
            area = (altura * l2) / 2;
        }
    }
    else if(qualTipo == 3) { // TRIÂNGULO ESCALENO - b.h/2 - aqui foi necessário desconsiderar a hipotenusa (maior lado)
        if (l1 >= l2 && l1 >= l3) {
            a = l1; b = l2; c = l3;
            area = b * c / 2;
        }
        else if (l2 >= l1 && l2 >= l3) {
            a = l2; b = l1; c = l3;
            area = b * c / 2;
        }
        else {
            a = l3; b = l1; c = l2;
            area = b * c / 2;
        }
    }
}

//------------------------------------------------- VALIDA E IMPRIME ------------------------------------------------------
int funcaoQueValidaEImprime () {
    //Verifica se é um triângulo válido
    if(ehValido == 1) {

        printf("Medidas dos lados formam um triangulo: VALIDO\n");

        // Print do Tipo de Triângulo ---------------------------------

        if(qualTipo == 1) {
            printf("Classificacao em funcao dos lados: EQUILATERO\n");
        }
        else if (qualTipo == 2) {
            printf("Classificacao em funcao dos lados: ISOSCELES\n");
        }
        else if (qualTipo == 3) {
            printf("Classificacao em funcao dos lados: ESCALENO\n");
        }

        // Print do Ângulo do Triângulo--------------------------------

        if(oAngulo == 1) {
            printf("Classificacao em funcao dos angulos: AGUDO\n");
        }
        else if (oAngulo == 2) {
            printf("Classificacao em funcao dos angulos: RETO\n");
        }
        else if (oAngulo == 3) {
            printf("Classificacao em funcao dos angulos: OBTUSO\n");
        }

        // Print da Área do Triângulo --------------------------------

        printf("Area do triangulo: %.4lf\n", area);
    }
    else {
        printf("Medidas dos lados formam um triangulo: INVALIDO\n");
    }
}

// ------------------------------------------------------- MAIN -----------------------------------------------------------
int main () {

    int l1;
    int l2;
    int l3;

    printf("Insira as medidas do triangulo\n: ");
    scanf("%d %d %d", &l1, &l2, &l3 );

    trianguloValido(l1,l2,l3);
    tipoDoTriangulo(l1,l2,l3);
    anguloDoTriangulo(l1,l2,l3);
    areaDoTriangulo(l1,l2,l3);
    funcaoQueValidaEImprime();

    return 0;
}
