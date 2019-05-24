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

void merge(int *v, int inicio, int meio, int fim) {
	int fim1 = 0, fim2 = 0;
	int tamanho = fim - inicio + 1;
	int temp[tamanho];
	int p1 = inicio;
	int p2 = meio + 1;
	for (int i = 0; i < tamanho; i++) {
		if(!fim1 && !fim2) {
			temp[i] = v[p1] < v[p2] ? v[p1++] : v[p2++];
			if(p1 > meio) fim1 = 1;
			if(p2 > fim) fim2 = 1;
		} else temp[i] = !fim1 ? v[p1++] : v[p2++];
	}
	for(int j = 0, k = inicio; j < tamanho; j++, k++)
		v[k] = temp[j];	
}

void mergeSort(int *v, int inicio, int fim){
	int meio;
	if(inicio < fim) {
		meio = (inicio + fim)/2;
		showPartOfArray(v, inicio, meio);
		mergeSort(v, inicio, meio);
		showPartOfArray(v, meio+1, fim);
		mergeSort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
}

int main () {
	int arr[] = {3, 6, 5, 7, 8, 4, 1, 9, 0, 2};

	printf("Dados Brutos:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	
	printf("\nTeste de mesa Merge Sort:\n");
	mergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	printf("\nOrdenados por Merge Sort:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}