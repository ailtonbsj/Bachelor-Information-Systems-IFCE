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

void bubbleSort(int *v, int fim) {
	int continua;
	int len = fim;
	do {
		continua = 0;
		for (int i = 0; i < fim-1; i++)	{
			if(v[i] > v[i+1]) {
				int aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				continua = i;
			}
		}
		fim--;
		showArray(v, len);
	} while(continua != 0);
}

void selectionSort(int *v, int n){
	int menor;
	for (int i = 0; i < n-1; i++) {
		menor = i;
		for(int j = i+1; j < n; j++) {
			if(v[j] < v[menor]) menor = j;
		}
		if( i != menor) {
			int aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
		showArray(v, n);
	}
}

void insertionSort(int v[], int len) {
	for (int i = 1; i < len; i++) {
		int j = i;
		while(j > 0) {
			if( v[j-1] > v[j] ) {
				int aux = v[j-1];
				v[j-1] = v[j];
				v[j] = aux;
				j--;
			} else {
				break;
			}
		}
		showArray(v, len);
	}
}

int main () {
	int arr1[] = {11, 9, 7, 5, 3, 1};
	int arr2[] = {5, 7, 2, 8, 1, 6};
	int arr3[] = {11, 9, 7, 5, 3, 1};

	printf("Teste de Mesa do bubbleSort:\n");
	showArray(arr1, sizeof(arr1)/sizeof(int));
	bubbleSort(arr1, sizeof(arr1)/sizeof(int));

	printf("Teste de Mesa do selectionSort:\n");
	showArray(arr2, sizeof(arr2)/sizeof(int));
	selectionSort(arr2, sizeof(arr2)/sizeof(int));

	printf("Teste de Mesa do insertionSort:\n");
	showArray(arr3, sizeof(arr3)/sizeof(int));
	insertionSort(arr3, sizeof(arr3)/sizeof(int));
	return 0;
}