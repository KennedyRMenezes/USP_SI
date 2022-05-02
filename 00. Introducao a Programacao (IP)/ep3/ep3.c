#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define VALOR_MAXIMO 255
#define RETA "RETA"
#define RETANGULO_CONTORNO "RETANGULO_CONTORNO"
#define RETANGULO_PREENCHIDO "RETANGULO_PREENCHIDO"
#define CLONA "CLONA"
#define CLONA_INV "CLONA_INV"
#define CLONA_HOR "CLONA_HOR"
#define CLONA_VER "CLONA_VER"
#define FIM "FIM"

typedef struct {

	int altura;
	int largura;
	int ** matriz;

} Imagem;

typedef struct {

	int x;
	int y; 

} Ponto2D;

Imagem * cria_imagem(int largura, int altura){

	Imagem * imagem = (Imagem *) malloc(sizeof(Imagem));

	int i, j; 

	imagem->altura = altura;
	imagem->largura = largura;	
	imagem->matriz = (int **) malloc(altura * sizeof(int*));
	for (i = 0; i < altura; i++) 
		{imagem->matriz[i] = (int *) malloc (largura * sizeof(int));
		}

	for(i=0; i<imagem->altura; i++) //deixa a matriz inteira preta
    	{for(j=0; j<imagem->largura; j++)
		imagem->matriz[i][j] = 0;
		}

	return imagem;
}

void libera_imagem(Imagem * imagem){

	int lin;

	for(lin = 0; lin < imagem->altura; lin++) 
		free(imagem->matriz[lin]);

	free(imagem->matriz);
	free(imagem);		
}

void salva(Imagem * imagem, char * nomeArquivo){

	int lin, col;
	FILE * saida = fopen(nomeArquivo, "w");

	if(saida)
		{fprintf(saida, "P2\n%d %d\n%d\n", imagem->largura, imagem->altura, VALOR_MAXIMO);
		for(lin = 0; lin < imagem->altura; lin++)
			{for(col = 0; col < imagem->largura; col++)
				{fprintf(saida, (col == 0 ? "%d" : " %d"), imagem->matriz[lin][col]);  				
				}
			fprintf(saida, "\n");
			}
		}

	fclose(saida); 
}

void reta(Imagem * imagem, Ponto2D p1, Ponto2D p2, int cor){
	
	int i, distx, disty, parte;
	float vary, varx, fdistx, fdisty;

	distx = abs(p2.x-p1.x);//distancia absoluta entre coordenadas x
	disty = abs(p2.y-p1.y);//distancia absoluta entre coordenadas y
	fdistx = (float)p2.x-(float)p1.x;
	fdisty = (float)p2.y-(float)p1.y;
	
	if(distx > disty)  
		{vary = fdisty/fdistx;//o quanto y vai variar para cada iteração em x
		if(p1.x > p2.x)
			{vary = -vary;
			for(i = 0; i <= distx; i++)
				{parte = lround(vary * i);
				imagem->matriz[p1.y + parte][p1.x - i] = cor;
				}
			}
		else	
			{for(i = 0; i <= distx; i++)
				{parte = lround(vary * i);
				imagem->matriz[p1.y + parte][p1.x + i] = cor;
				}
			}
		}
	else                                
		{varx = fdistx/fdisty;//o quanto x vai variar para cada iteração em y
		if(p1.y > p2.y)
			{varx = -varx;
			for(i = 0; i <= disty; i++)
				{parte = lround(varx * i);
				imagem->matriz[p1.y - i][p1.x + parte] = cor;
				}
			}
		else	
			{for(i = 0; i <= disty; i++)
				{parte = lround(varx * i);
				imagem->matriz[p1.y + i][p1.x + parte] = cor;
				}
			}
		}
}

void retangulo_contorno(Imagem * imagem, Ponto2D p1, Ponto2D p2, int cor){
	
	int i;
	
	//desenha cada um dos lados individualmente
	if(p1.x < p2.x && p1.y < p2.y)
		{for(i=p1.x; i<=p2.x; i++)
			{imagem->matriz[p1.y][i] = cor; // Horizontal ➡
			}

		for(i=p1.x; i<=p2.x; i++)
			{imagem->matriz[p2.y][i] = cor; // Horizontal ➡
			}
		
		for(i=p1.y; i<=p2.y; i++)
			{imagem->matriz[i][p2.x] = cor; // Vertical ⬆
			}
		
		for(i=p1.y; i<=p2.y; i++)
			{imagem->matriz[i][p1.x] = cor; // Vertical ⬆
			}
		}
	
	if(p1.x < p2.x && p1.y > p2.y)
		{for(i=p1.x; i<=p2.x; i++)
			{imagem->matriz[p1.y][i] = cor; // Horizontal ➡
			}

		for(i=p1.x; i<=p2.x; i++)
			{imagem->matriz[p2.y][i] = cor; // Horizontal ➡
			}
		
		for(i=p2.y; i<=p1.y; i++)
			{imagem->matriz[i][p2.x] = cor; // Vertical ⬆
			}
		
		for(i=p2.y; i<=p1.y; i++)
			{imagem->matriz[i][p1.x] = cor; // Vertical ⬆
			}
		}

	if(p1.x > p2.x && p1.y < p2.y)
		{for(i=p2.x; i<=p1.x; i++)
			{imagem->matriz[p1.y][i] = cor; // Horizontal ➡
			}

		for(i=p2.x; i<=p1.x; i++)
			{imagem->matriz[p2.y][i] = cor; // Horizontal ➡
			}
		
		for(i=p1.y; i<=p2.y; i++)
			{imagem->matriz[i][p2.x] = cor; // Vertical ⬆
			}
		
		for(i=p1.y; i<=p2.y; i++)
			{imagem->matriz[i][p1.x] = cor; // Vertical ⬆
			}
		}

	if(p1.x > p2.x && p1.y > p2.y)
		{for(i=p2.x; i<=p1.x; i++)
			{imagem->matriz[p1.y][i] = cor; // Horizontal ➡
			}

		for(i=p2.x; i<=p1.x; i++)
			{imagem->matriz[p2.y][i] = cor; // Horizontal ➡
			}
		
		for(i=p2.y; i<=p1.y; i++)
			{imagem->matriz[i][p2.x] = cor; // Vertical ⬆
			}
		
		for(i=p2.y; i<=p1.y; i++)
			{imagem->matriz[i][p1.x] = cor; // Vertical ⬆
			}
		}
	
}

void retangulo_preenchido(Imagem * imagem, Ponto2D p1, Ponto2D p2, int cor){
	
	int i, j;
	
	//percorre a área completa entre p1 e p2 e preenche com a cor
	if(p1.x < p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[i][j] = cor;
				}
			}
		}

	if(p1.x < p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[i][j] = cor;
				}
			}
		}

	if(p1.x > p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[i][j] = cor;
				}
			}
		}

	if(p1.x > p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[i][j] = cor;
				}
			}
		}
}

void clona(Imagem * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3){
	
	int i, j;

	//um if para cada disposição de p1 e p2 no plano
	if(p1.x < p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p1.x] = imagem->matriz[i][j];
				}
			}
		}

	if(p1.x < p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p1.x] = imagem->matriz[i][j];
				}
			}
		}

	if(p1.x > p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p2.x] = imagem->matriz[i][j];
				}
			}
		}

	if(p1.x > p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p2.x] = imagem->matriz[i][j];
				}
			}
		}

}

void clona_inverte_cor(Imagem * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3){
	
	int i, j;

	//um if para cada disposição de p1 e p2 no plano
	if(p1.x < p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p1.x] = VALOR_MAXIMO - imagem->matriz[i][j];
				}
			}
		}

	if(p1.x < p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p1.x] = VALOR_MAXIMO - imagem->matriz[i][j];
				}
			}
		}

	if(p1.x > p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p2.x] = VALOR_MAXIMO - imagem->matriz[i][j];
				}
			}
		}

	if(p1.x > p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p2.x] = VALOR_MAXIMO - imagem->matriz[i][j];
				}
			}
		}


	
}

void clona_espelha_horizontal(Imagem * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3){
	int i, j;

	//um if para cada disposição de p1 e p2 no plano
	if(p1.x < p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p1.x] = imagem->matriz[i][p1.x + p2.x - j];
				}
			}
		}

	if(p1.x < p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p1.x] = imagem->matriz[i][p1.x + p2.x - j];
				}
			}
		}

	if(p1.x > p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p2.x] = imagem->matriz[i][p2.x + p1.x - j];
				}
			}
		}

	if(p1.x > p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p2.x] = imagem->matriz[i][p2.x + p1.x - j];
				}
			}
		}


}

void clona_espelha_vertical(Imagem * imagem, Ponto2D p1, Ponto2D p2, Ponto2D p3){
	int i, j; 

	//um if para cada disposição de p1 e p2 no plano
	if(p1.x < p2.x && p1.y < p2.y) 
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p1.x] = imagem->matriz[p2.y + p1.y - i][j];
				}
			}
		}
	
	if(p1.x < p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p1.x; j<=p2.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p1.x] = imagem->matriz[p2.y + p1.y - i][j];
				}
			}
		}

	if(p1.x > p2.x && p1.y < p2.y)
		{for(i=p1.y; i<=p2.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p1.y][p3.x + j - p2.x] = imagem->matriz[p1.y + p2.y - i][j];
				}
			}
		}

	if(p1.x > p2.x && p1.y > p2.y)
		{for(i=p2.y; i<=p1.y; i++)
    		{for(j=p2.x; j<=p1.x; j++)
				{imagem->matriz[p3.y + i - p2.y][p3.x + j - p2.x] = imagem->matriz[p2.y + p1.y - i][j];
				}
			}
		}	
}

int main(){

	int largura, altura, cor;
	char operacao[32], nome_arquivo[256];
	Imagem * img;

	scanf("%s %d %d", nome_arquivo, &largura, &altura);
	img = cria_imagem(largura, altura);

	Ponto2D p1, p2, p3;

	while(scanf("%s", operacao) == 1 && strcmp(operacao, FIM) != 0){

		if (strcmp(operacao, "RETANGULO_PREENCHIDO") == 0)
			{scanf("%d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &cor);
			retangulo_preenchido(img, p1, p2, cor);
			}

		if (strcmp(operacao, "RETA") == 0)
			{scanf("%d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &cor);
			reta(img, p1, p2, cor);
			}

		if (strcmp(operacao, "RETANGULO_CONTORNO") == 0)
			{scanf("%d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &cor);
			retangulo_contorno(img, p1, p2, cor);
			}

		if (strcmp(operacao, "CLONA") == 0)
			{scanf("%d %d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
			clona(img, p1, p2, p3);
			}
			
		if (strcmp(operacao, "CLONA_INV") == 0)
			{scanf("%d %d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
			clona_inverte_cor(img, p1, p2, p3);
			}

		if (strcmp(operacao, "CLONA_HOR") == 0)
			{scanf("%d %d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
			clona_espelha_horizontal(img, p1, p2, p3);
			}

		if (strcmp(operacao, "CLONA_VER") == 0)
			{scanf("%d %d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
			clona_espelha_vertical(img, p1, p2, p3);
			}
	}
	
	salva(img, nome_arquivo);
	libera_imagem(img);
	return 0;	
}
