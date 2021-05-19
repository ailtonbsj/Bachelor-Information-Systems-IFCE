#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

void showArray(int *v, int len) {
	printf("[ ");
	for (int i = 0; i < len; ++i) {
		if(i != 0) printf(", ");
		printf("%i", v[i]);
	}
	printf(" ]\n");
}

void insertionSort(int v[], int len) {
	int cont = 0;
	for (int i = 1; i < len; i++) {
		int j = i;
		while(j > 0) {
			if( v[j-1] > v[j] ) {
				int aux = v[j-1];
				v[j-1] = v[j];
				v[j] = aux;
				j--;
				printf("Troca Numero: %i\n", ++cont);
			showArray(v, len);	
			} else {
				break;
			}
		}
	}
}

int main () {

	int arr[] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};
	showArray(arr, sizeof(arr)/sizeof(int));
	insertionSort(arr, sizeof(arr)/sizeof(int));
	return 0;
}