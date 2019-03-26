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

void obterPares (
	int ori[], unsigned lenOri, int des[], unsigned *lenDes) {
	*lenDes = 0;
	for(int i = 0; i < lenOri; i++) {
		if((ori[i] % 2) == 0) {
			(*lenDes)++;
			des = (int*) realloc(des, (*lenDes) * sizeof(int));
			des[(*lenDes)-1] = ori[i];
		}
	}
}

void obterImpares(
	int ori[], unsigned lenOri, int des[], unsigned *lenDes) {
	*lenDes = 0;
	for(int i = 0; i < lenOri; i++) {
		if((ori[i] % 2) != 0) {
			(*lenDes)++;
			des = (int*) realloc(des, (*lenDes) * sizeof(int));
			des[(*lenDes)-1] = ori[i];
		}
	}
}

void printArray(int arr[], unsigned len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		printf(" %i", arr[i]);
	 	if(i != len-1) printf(",");
	}
	printf(" ]\n");
}

int soma (int arr[], int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) sum += arr[i];
	return sum;
}

int main () {
	int nums[6];
	int *pars, *impars;
	unsigned lenPars, lenImpars;
	
	pars = (int*) malloc(sizeof(int));
	impars = (int*) malloc(sizeof(int));
	
	for (int i = 0; i < 6; i++) {
		printf("Digite o numero %i: ", i+1);
		scanf("%d", &nums[i]);
		clearBufferKey();
	}
	
	obterPares(nums, 6, pars, &lenPars);
	obterImpares(nums, 6, impars, &lenImpars);
	printArray(pars, lenPars);
	printf("Soma dos pares: %i\n", soma(pars, 6));
	printArray(impars, lenImpars);
	printf("Soma dos impares: %i\n", soma(impars, 6));

	return 0;
}