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

int buscaBinaria(int v[], int n, int elem) {
	int inicio, meio, final;
	inicio = 0;
	final = n-1;
	while(inicio <= final) {
		meio = (inicio+final)/2;
		if( elem < v[meio] ) final = meio-1;
		else {
			if( elem > v[meio] ) inicio = meio+1;
			else return meio;
		}
	}
	return -1;
}

int buscaBinariaRec(int v[], int inicio, int final, int elem) {
	if(final >= inicio){
		int meio = (inicio + final)/2;
		if(elem > v[meio]) return buscaBinariaRec(v, meio+1, final, elem);
		else if(elem < v[meio]) return buscaBinariaRec(v, inicio, meio-1, elem);
		else return meio;
	}
	return -1;
}

int main () {

	int ord[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	showArray(ord, sizeof(ord)/sizeof(int));
	int b = buscaBinaria(ord, sizeof(ord)/sizeof(int), 4);
	printf("Indice: %i\n", b);
	int br = buscaBinariaRec(ord, 0, sizeof(ord)/sizeof(int)-1, 4);
	printf("Indice: %i\n", br);
	return 0;
}
