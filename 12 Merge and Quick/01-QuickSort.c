#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

int showPartOfArray(int v[], int start, int end){
	printf("[ ");
	for (int i = start; i <= end; ++i) {
		if(i != start) printf(", ");
		printf("%i", v[i]);
	}
	printf(" ]\n");
}

int showArray(int v[], int len){
	showPartOfArray(v, 0, len-1);
}

void swap (int *n, int *m) {
	int tmp = *n; *n = *m, *m = tmp;
}

void quickSort(int v[], int inicio, int fim) {
	int aux;
	int i = inicio;
	int j = fim-1;
	int pivo = v[(inicio + fim) / 2];
	while(i <= j) {
		while(v[i] < pivo && i < fim) i++;
		while(v[j] > pivo && j > inicio) j--;
		if(i <= j) {
			swap(v + i++, v + j--);
			showPartOfArray(v, inicio, fim-1);
		}
	}
	if(j > inicio) quickSort(v, inicio, j+1);
	if(i < fim) quickSort(v, i, fim);
}

int main () {
	int arr[] = {3, 6, 5, 7, 8, 4, 1, 9, 0, 2};

	printf("Dados Brutos:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	
	printf("\nTeste de mesa Quick Sort:\n");
	quickSort(arr, 0, sizeof(arr)/sizeof(int));

	printf("\nOrdenados por Quick Sort:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}