#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

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

int main() {
	char nome[255];
	unsigned idade;

	printf("Digite o nome: ");
	rawInput(nome, 255);

	printf("Digite a idade: ");
	scanf("%u", &idade);
	clearBufferKey();

	printf("%s possui %u, ", nome, idade);
	if(idade >= 18)
		printf("portanto eh maior de idade.\n");
	else printf("portanto eh menor de idade.\n");

	return 0;
}