#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

void showArray(int *v, int n) {
	printf("[ ");
	for (int i = 0; i < n; i++)	{
		if(i > 0) printf(", ");
		printf("%d", v[i]);
	}
	printf(" ]\n");
}

void imprimeOrdenadosSemRepetidos(int v[], int n){
	printf("[ ");
	int aux = -999999999;
	for (int i = 0; i < n; i++)	{
		if(aux != v[i]) {
			if(i > 0) printf(", ");
			printf("%d", v[i]);
			aux = v[i];
		}
	}
	printf(" ]\n");	
}

void oneSort(int *v, int len) {
	for (int i = 0; i < len-1; i++)	{
		if(v[i] > v[i+1]) {
			int aux = v[i];
			v[i] = v[i+1];
			v[i+1] = aux;
		}
	}
}

void sort(int *v, int len){
	for (int i = 0; i < len; ++i) {
		oneSort(v, len);
	}
}

int main () {

	printf("Ordenados\n");
	int ord[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 6, 7, 8, 8, 8};
	showArray(ord, sizeof(ord)/sizeof(int));
	imprimeOrdenadosSemRepetidos(ord, sizeof(ord)/sizeof(int));

	printf("\n\nNão-ordenados\n");
	int desord[] = {1, 3, 5, 6, 4, 2, 5, 3, 7, 1, 8, 8, 3, 8};
	showArray(desord, sizeof(desord)/sizeof(int));
	sort(desord, sizeof(desord)/sizeof(int));
	imprimeOrdenadosSemRepetidos(desord, sizeof(desord)/sizeof(int));

	return 0;
}
