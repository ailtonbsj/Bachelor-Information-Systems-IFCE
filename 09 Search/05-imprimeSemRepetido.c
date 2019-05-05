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

int main () {

	int ord[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 6, 7, 8, 8, 8};
	showArray(ord, sizeof(ord)/sizeof(int));
	imprimeOrdenadosSemRepetidos(ord, sizeof(ord)/sizeof(int));
	
	return 0;
}
