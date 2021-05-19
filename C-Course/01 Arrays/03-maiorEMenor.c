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

float maior(float arr[], unsigned len) {
	float maior = -9e99;
	for (int i = 0; i < len; i++) {
		if(arr[i] > maior) maior = arr[i];
	}
	return maior;
}

float menor(float arr[], unsigned len) {
	float menor = 9e99;
	for (int i = 0; i < len; i++) {
		if(arr[i] < menor) menor = arr[i];
	}
	return menor;
}

int main () {
	float nums[10];
	for (int i = 0; i < 10; i++) {
		printf("Digite o numero %i: ", i+1);
		scanf("%f", &nums[i]);
		clearBufferKey();
	}

	printf("Maior elemento %0.2f\n",
		maior(nums, sizeof(nums)/sizeof(float)));
	printf("Menor elemento %0.2f\n", 
		menor(nums, sizeof(nums)/sizeof(float)));
	
	return 0;
}