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
	}
}

void insertionSort2(int v[], int len) {
	int j;
	for (int i = 1; i < len; ++i) {
		int aux = v[i];
		for (j = i; (j > 0) && (aux < v[j-1]); j--)	{
			v[j] = v[j-1];
		}
		v[j] = aux;
	}
}

int main () {

	int arr[] = {7, 4, 3, 1, 5, 2, 6};
	showArray(arr, sizeof(arr)/sizeof(int));
	insertionSort(arr, sizeof(arr)/sizeof(int));
	showArray(arr, sizeof(arr)/sizeof(int));

	int arr2[] = {7, 4, 3, 1, 5, 2, 6};
	showArray(arr2, sizeof(arr2)/sizeof(int));
	insertionSort2(arr2, sizeof(arr2)/sizeof(int));
	showArray(arr2, sizeof(arr2)/sizeof(int));
	return 0;
}