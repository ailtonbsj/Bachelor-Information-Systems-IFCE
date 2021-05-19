#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

int mais_proximo(int vet[], int tam, int x){
	int meio;
	int inicio = 0;
	int fim = tam - 1;
	while( (fim - inicio) > 1 ){
		meio = inicio + (fim - inicio) / 2;
		if(x <= vet[meio]) fim = meio;
		else inicio = meio;
	}
	if( (x-vet[inicio]) > (vet[fim]-x) ) return vet[fim];
	else return vet[inicio];
}

int main () {

	int v;
	int arr[] = {3, 7, 10, 14, 16};
	v = mais_proximo(arr, sizeof(arr)/sizeof(int), 11);
	printf("Entrada: %3i | Saída: %3i \n", 11, v);
	v = mais_proximo(arr, sizeof(arr)/sizeof(int), 5);
	printf("Entrada: %3i | Saída: %3i \n", 5, v);
	v = mais_proximo(arr, sizeof(arr)/sizeof(int), 14);
	printf("Entrada: %3i | Saída: %3i \n", 14, v);
	v = mais_proximo(arr, sizeof(arr)/sizeof(int), 13);
	printf("Entrada: %3i | Saída: %3i \n", 13, v);
	return 0;
}