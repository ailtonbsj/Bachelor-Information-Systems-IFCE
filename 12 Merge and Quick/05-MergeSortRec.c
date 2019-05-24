#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

////// UTILS ///////

/* Escreve parte de um vetor na tela limitado com inicio e fim */
int showPartOfArray(int v[], int start, int end){
	printf("[ ");
	for (int i = start; i <= end; ++i) {
		if(i != start) printf(", ");
		printf("%i", v[i]);
	}
	printf(" ]\n");
}

/* Escreve o vetor completo na tela passando como argumento seu comprimento */
int showArray(int v[], int len){
	showPartOfArray(v, 0, len-1);
}

//////// ALGORITMO MERGE SORT RECURSIVO ///////////

/* Rearranja valores recursivamente unindo-os no vetor temporario */
void rearranja(int v[], int temp[], int i, int tamanho, int fim1,
						int fim2, int meio, int fim, int p1, int p2){
	if(i < tamanho){
		if(!fim1 && !fim2) {
			temp[i] = v[p1] < v[p2] ? v[p1++] : v[p2++];
			if(p1 > meio) fim1 = 1;
			if(p2 > fim) fim2 = 1;
		} else temp[i] = !fim1 ? v[p1++] : v[p2++];	
		rearranja(v, temp, ++i, tamanho, fim1, fim2, meio, fim, p1, p2);
	}
}

/* Uniao do vetores conforme modelo do algoritmo */
void merge(int *v, int inicio, int meio, int fim) {
	int tamanho = fim - inicio + 1;
	int temp[tamanho];
	rearranja(v, temp, 0, tamanho, 0, 0, meio, fim, inicio, meio + 1);
	for(int j = 0, k = inicio; j < tamanho; j++, k++)
		v[k] = temp[j];	
}

/* Ordena o vetor utilizando o algoritmo Merge Sort Recursivamente */
void mergeSort(int *v, int inicio, int fim){
	int meio;
	if(inicio < fim) {
		meio = (inicio + fim)/2;
		mergeSort(v, inicio, meio);
		mergeSort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
}

//////////////// TESTE //////////////////

int main () {
	int arr[] = {3, 6, 5, 7, 8, -1, -2, 4, 1, 9, 0, 2};

	printf("Dados Brutos:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	
	mergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	printf("\nOrdenados por Merge Sort:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}