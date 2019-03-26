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

int soma(int x, int y) {
	return x+y;
}

int main () {
	int num1, num2;
	printf("Digite um numero: ");
	scanf("%i", &num1);
	clearBufferKey();
	printf("Digite outro numero: ");
	scanf("%i", &num2);
	clearBufferKey();

	printf("%i + %i = %i\n", num1, num2, soma(num1, num2));

	return 0;
}