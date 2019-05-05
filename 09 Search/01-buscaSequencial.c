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

int buscaSequencialRec(int *v, int n, int elem) {
	if( n == 0 ) return -1;
	else {
		if(elem == v[n-1]) return n-1;
		return buscaSequencialRec(v, n-1, elem);
	}
}

int buscaOrdenada(int *v, int n, int elem) {
	for (int i = 0; i < n; i++)	{
		if(elem == v[i]) return i;
		else if(elem < v[i]) return -1;
	}
}

int main () {

	int arr[] = {5, 2, 6, 1, 3, 7, 4, 9, 8};
	showArray(arr, sizeof(arr)/sizeof(int));

	int q = 1;
	printf("O valor %i estah no indice %i.\n", q, 
		buscaSequencial(arr, sizeof(arr)/sizeof(int), q) );
	printf("O valor %i estah no indice %i.\n", q, 
		buscaSequencialRec(arr, sizeof(arr)/sizeof(int), q) );

	int ord[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
	int qq = 4;
	showArray(ord, sizeof(ord)/sizeof(int));
	printf("O valor %i estah no indice %i.\n", qq, 
		buscaOrdenada(ord, sizeof(ord)/sizeof(int), qq) );

	return 0;
}