#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

int showPartOfArray(char v[], int start, int end){
	printf("[ ");
	for (int i = start; i <= end; ++i) {
		if(i != start) printf(", ");
		printf("%c", v[i]);
	}
	printf(" ]\n");
}

int showArray(char v[], int len){
	showPartOfArray(v, 0, len-1);
}

int particiona(char v[], int inicio, int fim) {
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = fim;
	pivo = v[inicio];
	while(esq < dir) {
		while(v[esq] >= pivo) esq++;
		while(v[dir] < pivo) dir--;
		if(esq < dir){
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}
	v[inicio] = v[dir];
	v[dir] = pivo;
	return dir;
}

void quickSort(char v[], int inicio, int fim){
	int pivo;
	if(fim > inicio) {		
		pivo = particiona(v, inicio, fim);
		quickSort(v, inicio, pivo-1);
		quickSort(v, pivo+1, fim);
	}
}

int main () {
	char texto[] = "inconstitucional";

	printf("Dados Brutos:\n");
	showArray(texto, sizeof(texto)/sizeof(char)-1);
	
	quickSort(texto, 0, sizeof(texto)/sizeof(char)-2);

	printf("\nOrdenados por Merge Sort:\n");
	showArray(texto, sizeof(texto)/sizeof(char)-1);
	return 0;
}
