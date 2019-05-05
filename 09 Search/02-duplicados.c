#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

void showArray(int *v, int n) {
	printf("[ ");
	for (int i = 0; i < n; i++)	{
		printf("%d", v[i]);
		if(i < n-1) printf(", ");
	}
	printf(" ]\n");
}

void buscaDuplicados(int *v, int n, int elem) {
	int cont = 0;
	printf("Indice encontrados:\n");
	for (int i = 0; i < n; i++)	{
		if(elem == v[i]) {
			printf("%i\n", i);
			cont++;
		}
	}
	if(cont == 0) printf("Nenhum indice!\n");
}

int main () {

	int arr[] = {2, 2, 8, 6, 10, 5, 7, 5, 19};
	showArray(arr, sizeof(arr)/sizeof(int));

	int q = 5;
	buscaDuplicados(arr, sizeof(arr)/sizeof(int), q);

	return 0;
}