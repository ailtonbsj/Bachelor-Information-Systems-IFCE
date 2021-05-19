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

float soma (float arr[], unsigned len) {
	float sum = 0;
	for(int i = 0; i<len; i++) sum += arr[i];
	return sum;
}

int main () {
	unsigned totalNums = 0;
	float sum = 0, max = 0, min = 9e99;
	float *nums = (float*) malloc(sizeof(float));
	if(nums == NULL) printf("Sem memoria!\n"), exit(1);
	while(1) {
		float num;
		printf("Digite um numero: ");
		scanf("%f", &num);
		clearBufferKey();
		if(num == 0) break;
		totalNums++;
		nums = (float*) realloc(nums, totalNums * sizeof(float));
		if(nums == NULL) printf("Sem memoria!\n"), exit(1);
		nums[totalNums-1] = num;
		sum = soma(nums, totalNums);
		if(num > max) max = num;
		if(num < min) min = num;
		printf("\nO somatorio eh: %0.2f\n", sum);
		printf("Total de numeros: %u\n", totalNums);
		printf("A media eh: %0.2f\n", (float) sum/totalNums);
		printf("Maior numero: %0.2f\n", max);
		printf("Menor numero: %0.2f\n\n", min);
	}
	return 0;
}