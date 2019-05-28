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

void insertionSortReverse(int v[], int len) {
	for (int i = 1; i < len; i++) {
		int j = i;
		while(j > 0) {
			if( v[j-1] <= v[j] ) {
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

int main () {

	int arr[] = {7, 4, 3, 1, 5, 2, 6};
	showArray(arr, sizeof(arr)/sizeof(int));
	insertionSortReverse(arr, sizeof(arr)/sizeof(int));
	showArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}