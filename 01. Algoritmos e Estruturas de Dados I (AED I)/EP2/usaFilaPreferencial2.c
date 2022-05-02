#include "12683395.c"

int main() {
	PFILA f = criarFila();
	int id;
	bool ehPreferencial;
	bool res;

	printf("################# INSERINDO ####################### --- 1\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, -1, false);
	if(res) printf("Insercao retornou true (0).\n");
	else printf("Insercao retornou false (0). [OK]\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 1, false);
	if(res) printf("Insercao retornou true (1). [OK]\n");
	else printf("Insercao retornou false (1).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 2, false);
	if(res) printf("Insercao retornou true (2). [OK]\n");
	else printf("Insercao retornou false (2).\n");
	exibirLog(f);

	printf("################# ATENDENDO ####################### --- 1\n");
	exibirLog(f);
	res = atenderPrimeiraDaFila(f, &id);
	if(res) printf("Atendimento retornou true (1), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (1).\n");
	exibirLog(f);

	printf("################# INSERINDO ####################### ---- 2\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 3, false);
	if(res) printf("Insercao retornou true (3). [OK]\n");
	else printf("Insercao retornou false (3).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 4, true);
	if(res) printf("Insercao retornou true (4). [OK]\n");
	else printf("Insercao retornou false (4).\n");
	exibirLog(f);

	printf("################# SAINDO DA FILA ################## ---- 1\n");
	exibirLog(f);
	res = desistirDaFila(f, 3);
	if(res) printf("Desistindo da fila retornou true (1).\n");
	else printf("Desistindo da fila retornou false (1). [OK]\n");
	exibirLog(f);

	printf("################# INSERINDO ####################### ---- 3\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 5, true);
	if(res) printf("Insercao retornou true (5). [OK]\n");
	else printf("Insercao retornou false (5).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 6, true);
	if(res) printf("Insercao retornou true (6). [OK]\n");
	else printf("Insercao retornou false (6).\n");
	exibirLog(f);


	printf("################# ATENDENDO ####################### ----- 2\n");
	exibirLog(f);
	res = atenderPrimeiraDaFila(f, &id);
	if(res) printf("Atendimento retornou true (2), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (2).\n");
	

	exibirLog(f);
	res = atenderPrimeiraDaFila(f, &id);
	if(res) printf("Atendimento retornou true (3), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (3).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFila(f, &id);
	if(res) printf("Atendimento retornou true (4), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (4).\n");

	exibirLog(f);
	res = atenderPrimeiraDaFila(f, &id);
	if(res) printf("Atendimento retornou true (5), id=%i. [OK]\n",id);
	else printf("Atendimento retornou false (5).\n");

	printf("################# INSERINDO PARTE 2 ###############  ----- 1\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 7, true);
	if(res) printf("Insercao retornou true (7). [OK]\n");
	else printf("Insercao retornou false (7).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 8, false);
	if(res) printf("Insercao retornou true (8). [OK]\n");
	else printf("Insercao retornou false (8).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 11, false);
	if(res) printf("Insercao retornou true (7). [OK]\n");
	else printf("Insercao retornou false (7).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 9, true);
	if(res) printf("Insercao retornou true (9). [OK]\n");
	else printf("Insercao retornou false (9).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 10, false);
	if(res) printf("Insercao retornou true (10). [OK]\n");
	else printf("Insercao retornou false (10).\n");
	exibirLog(f);


	printf("################# SAINDO DA FILA ##################  ----- 2\n");

	exibirLog(f);
	res = desistirDaFila(f, 8);
	if(res) printf("Desistindo da fila retornou true (2).\n");
	else printf("Desistindo da fila retornou false (2). [OK]\n");
	exibirLog(f);
	res = desistirDaFila(f, 10);
	if(res) printf("Desistindo da fila retornou true (3). [OK]\n");
	else printf("Desistindo da fila retornou false (3).\n");
	exibirLog(f);
	res = desistirDaFila(f, 7);
	if(res) printf("Desistindo da fila retornou true (4). [OK]\n");
	else printf("Desistindo da fila retornou false (4).\n");
	exibirLog(f);
	res = desistirDaFila(f, 11);
	if(res) printf("Desistindo da fila retornou true (2).\n");
	else printf("Desistindo da fila retornou false (2). [OK]\n");
	exibirLog(f);
	res = desistirDaFila(f, 9);
	if(res) printf("Desistindo da fila retornou true (5). [OK]\n");
	else printf("Desistindo da fila retornou false (5).\n");
	exibirLog(f);

	printf("################# INSERINDO ####################### ---- 3\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 5, true);
	if(res) printf("Insercao retornou true (5). [OK]\n");
	else printf("Insercao retornou false (5).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 6, true);
	if(res) printf("Insercao retornou true (6). [OK]\n");
	else printf("Insercao retornou false (6).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 4, false);
	if(res) printf("Insercao retornou true (5). [OK]\n");
	else printf("Insercao retornou false (5).\n");
	exibirLog(f);
	res = inserirPessoaNaFila(f, 9, false);
	if(res) printf("Insercao retornou true (6). [OK]\n");
	else printf("Insercao retornou false (6).\n");
	exibirLog(f);

	printf("################# SAINDO DA FILA ##################  ----- 2\n");

	exibirLog(f);
	res = desistirDaFila(f, 4);
	if(res) printf("Desistindo da fila retornou true (2).\n");
	else printf("Desistindo da fila retornou false (2). [OK]\n");
	exibirLog(f);

	printf("################# INSERINDO ####################### ---- 3\n");

	exibirLog(f);
	res = inserirPessoaNaFila(f, 33, true);
	if(res) printf("Insercao retornou true (5). [OK]\n");
	else printf("Insercao retornou false (5).\n");
	exibirLog(f);

	return 0;
}
