#include <stdio.h>

void troca (int *n, int *m) {
	int tmp = *n; *n = *m, *m = tmp;
}

int main () {
	int a = 20;
	int b = 10;
	printf("Digite o valor de A: ");
	scanf("%i", &a);
	printf("Digite o valor de B: ");
	scanf("%i", &b);
	printf("Valor e A = %i e B = %i\n", a, b);
	troca(&a, &b);
	printf("Valor e A = %i e B = %i\n", a, b);
	return 0;
}