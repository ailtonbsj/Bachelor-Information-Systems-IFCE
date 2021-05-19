#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

/* Limpa buffer do teclado para Windows e Linux */
void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

/* Pega strings do teclado sem gerar problemas */
void rawInput(char *buf, unsigned int size) {
	fgets(buf, size, stdin);
	buf[strlen(buf)-1] = '\0';
	clearBufferKey();
}

void menoresQueCiquenta(float preco[], unsigned len) {
	unsigned inferior = 0;
	for (int i = 0; i < len; i++)
		if(preco[i] < 50) inferior++;
	printf("\nTotal de produtos inferior a R$50: %u\n", inferior);
}

void entreCinquentaECem(float preco[], char prods[][255], unsigned len){
	printf("\nProdutos entre R$50 e R$100:\n");
	for (int i = 0; i < len; i++) {
		if(preco[i] >= 50 && preco[i] <= 100){
			printf("%s\n", prods[i]);
		}
	}
}

void superioresQueCem(float precos[], unsigned len) {
	float cont = 0, soma = 0;
	for (int i = 0; i < len; i++) {
		if(precos[i] > 100){
			soma += precos[i];
			cont++;
		}
	}
	printf("\nMédia dos produtos superiores a R$100: %0.2f\n", (float) soma/cont);
}

int main () {
	#define MAX 5
	char produtos[MAX][255];
	float precos[MAX];

	for (int i = 0; i < MAX; i++)	{
		printf("Digite o nome do produto %i: ", i);
		rawInput(produtos[i], 255);
		printf("Digite o preço do produto %i: ", i);
		scanf("%f", &precos[i]);
		clearBufferKey();
	}

	menoresQueCiquenta(precos, MAX);
	entreCinquentaECem(precos, produtos, MAX);
	superioresQueCem(precos, MAX);

	return 0;
}