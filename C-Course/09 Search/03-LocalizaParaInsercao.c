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

int localizaPosicao(int *v, int n, int elem){
	for (int i = 0; i < n; i++)	{
		if( elem < v[i] ) return i;
	}
	return n;
}

int main () {

	int arr[] = {1, 2, 6, 8, 10, 15, 17, 20, 29};
	showArray(arr, sizeof(arr)/sizeof(int));

	int p = -1;
	int q = 13;
	p = localizaPosicao(arr, sizeof(arr)/sizeof(int), q);
	printf("Posicao %i\n", p);

	return 0;
}