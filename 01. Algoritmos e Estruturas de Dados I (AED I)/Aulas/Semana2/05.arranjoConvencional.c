#include <stdio.h>
#include <stdlib.h>

void imprimir(int* w){
	printf("w0: %i, w1: %i, w2: %i\n", w[0], w[1], w[2]);
	printf("&w: %p, w: %p, *w: %i\n", &w, w, *w);
	w[0] = 21;
	w[1] = 23;
	w[2] = 25;
}

int main(){
	int x[3];
	x[0] = 1;
	x[1] = 2;
	x[2] = 7;

	printf("x0: %i, x1: %i, x2: %i\n", x[0], x[1], x[2]);
	printf("&x: %p, x: %p, *x: %i\n", &x, x, *x);

	imprimir(x);

	printf("x0: %i, x1: %i, x2: %i\n", x[0], x[1], x[2]);
	printf("&x: %p, x: %p, *x: %i\n", &x, x, *x);

	int* y = (int*) malloc(sizeof(int)*3);
	y[0] = 4;
	y[1] = 5;
	y[2] = 6;

	printf("y0: %i, y1: %i, y2: %i\n", y[0], y[1], y[2]);
	printf("&y: %p, y: %p, *y: %i\n", &y, y, *y);

	*y = *x;
	printf("y0: %i, y1: %i, y2: %i\n", y[0], y[1], y[2]);
	printf("&y: %p, y: %p, *y: %i\n", &y, y, *y);

	free(y);

	y = (int*) x;
	printf("y0: %i, y1: %i, y2: %i\n", y[0], y[1], y[2]);
	printf("&y: %p, y: %p, *y: %i\n", &y, y, *y);

	y = (int*) &x;
	printf("y0: %i, y1: %i, y2: %i\n", y[0], y[1], y[2]);
	printf("&y: %p, y: %p, *y: %i\n", &y, y, *y);

	return 0;

}

/* Exemplo de saida:
x0: 1, x1: 2, x2: 7
&x: 0x7ffcee1d1f00, x: 0x7ffcee1d1f00, *x: 1
w0: 1, w1: 2, w2: 7
&w: 0x7ffcee1d1ee8, w: 0x7ffcee1d1f00, *w: 1
x0: 21, x1: 23, x2: 25
&x: 0x7ffcee1d1f00, x: 0x7ffcee1d1f00, *x: 21
y0: 4, y1: 5, y2: 6
&y: 0x7ffcee1d1f18, y: 0x91a010, *y: 4
y0: 21, y1: 5, y2: 6
&y: 0x7ffcee1d1f18, y: 0x91a010, *y: 21
y0: 21, y1: 23, y2: 25
&y: 0x7ffcee1d1f18, y: 0x7ffcee1d1f00, *y: 21
y0: 21, y1: 23, y2: 25
&y: 0x7ffcee1d1f18, y: 0x7ffcee1d1f00, *y: 21
*/
