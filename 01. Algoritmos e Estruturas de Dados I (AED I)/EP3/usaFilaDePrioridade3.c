#include "filaDePrioridade003.c"

int main() {
	int i;
	float resposta;
	
	PFILA f = criarFila();
	exibirLog(f);
	if(inserirElemento(f, 1, 1)) printf("ok\n");
	else printf("nok (1)\n");
	exibirLog(f);
	if(inserirElemento(f, 3, 3)) printf("ok\n");
	else printf("nok (2)\n");
	exibirLog(f);
	if(inserirElemento(f, 2, 2)) printf("ok\n");
	else printf("nok (3)\n");
	exibirLog(f);
	if(inserirElemento(f, 0, 0)) printf("ok\n");
	else printf("nok (4)\n");
	exibirLog(f);
	if(inserirElemento(f, 5, 5)) printf("ok\n");
	else printf("nok (5)\n");
	exibirLog(f);
	if(aumentarPrioridade(f, 5, 10)) printf("ok\n");
	else printf("nok (6)\n");
	exibirLog(f);
	if(aumentarPrioridade(f, 0, 15)) printf("ok\n");
	else printf("nok (7)\n");
	exibirLog(f);
	if(aumentarPrioridade(f, 3, 4)) printf("ok\n");
	else printf("nok (8)\n");
	exibirLog(f);
	if(aumentarPrioridade(f, 3, 4)) printf("ok\n");
	else printf("nok (9) - esperado, pois a nova prioridade nao eh maior\n");
	exibirLog(f);
	if(aumentarPrioridade(f, 4, 4)) printf("ok\n");
	else printf("nok (10) - esperado, elemento com id=4 nao existe\n");
	exibirLog(f);

	printf("Tamanho: %d\n", tamanho(f));
	printf("Prioridade de cada elemento nas referências:\n");
	for (i = 0; i < MAX; i++)
		if (f->heap[i]) {
			consultarPrioridade(f, i, &resposta);
			printf("id: %d, posição no heap: %d, prioridade: %f\n", i, f->referencias[i]->posicao, resposta);
		}

	return 0;
}
