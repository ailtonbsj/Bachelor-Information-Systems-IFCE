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
	}
}

int main () {

	int arr[] = {7, 4, 3, 1, 5, 2, 6};
	showArray(arr, sizeof(arr)/sizeof(int));
	selectionSort(arr, sizeof(arr)/sizeof(int));
	showArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}