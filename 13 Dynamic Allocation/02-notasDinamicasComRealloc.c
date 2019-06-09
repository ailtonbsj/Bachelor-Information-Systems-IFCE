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

int main () {
	float *notas = malloc(1);

	do {
		int n;
		float soma = 0;
		printf("Digite a quantidade de notas:\n");
		scanf("%d", &n);
		clearBufferKey();
		if(n == 0) exit(0);

		notas = (float*) realloc(notas, n*sizeof(float));
		if(notas != NULL) {
			for (int i = 0; i < n; ++i)	{
				printf("Digite a nota %i: ", i+1);
				scanf("%f", &notas[i]);
			}
		}

		for (int i = 0; i < n; ++i)	soma += notas[i];
		printf("A media eh: %0.2f\n", soma/n);
		free(notas);
	} while(1);

	return 0;
}