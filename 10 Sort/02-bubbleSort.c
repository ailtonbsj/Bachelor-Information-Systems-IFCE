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

void bubbleSort(int *v, int fim) {
	int continua;
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
	} while(continua != 0);
}

int main () {

	int arr[] = {7, 4, 3, 1, 5, 2, 6};
	showArray(arr, sizeof(arr)/sizeof(int));
	bubbleSort(arr, sizeof(arr)/sizeof(int));
	showArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}