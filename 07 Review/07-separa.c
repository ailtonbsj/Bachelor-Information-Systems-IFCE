#include <stdio.h>

void divide (float num, int *inteira, float *frac);

int main () {
	int inteiro;
	float fracao;
	divide(5.22, &inteiro, &fracao);
	printf("Parte inteira: %i\n", inteiro);
	printf("Parte fracionaria: %f\n", fracao);
	return 0;
}

void divide (float num, int *inteira, float *frac) {
	*inteira = (int) num;
	*frac = num - *inteira;
}