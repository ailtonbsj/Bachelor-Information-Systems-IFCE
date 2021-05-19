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

int buscaSequencial(int *v, int n, int elem) {
	for (int i = 0; i < n; i++)	{
		if(elem == v[i]) return i;
	}
	return -1;
}

void troca(int *v, int n, int elem, int novo) {
	int i = buscaSequencial(v, n, elem);
	v[i] = novo;
}

int main () {

	int arr[] = {5, 2, 6, 1, 3, 7, 4, 9, 8};
	showArray(arr, sizeof(arr)/sizeof(int));

	troca(arr, sizeof(arr)/sizeof(int), 7, 10);
	showArray(arr, sizeof(arr)/sizeof(int));

	return 0;
}
