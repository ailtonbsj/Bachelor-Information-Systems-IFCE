#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

////// UTILS ///////

/* Escreve parte de um vetor na tela limitado com inicio e fim */
int showPartOfArray(int v[], int start, int end){
	printf("[ ");
	for (int i = start; i <= end; ++i) {
		if(i != start) printf(", ");
		printf("%i", v[i]);
	}
	printf(" ]\n");
}

/* Escreve o vetor completo na tela passando como argumento seu comprimento */
int showArray(int v[], int len){
	showPartOfArray(v, 0, len-1);
}

//////// ALGORITMO QUICK SORT RECURSIVO ///////////

/* Incrementa recursivamente enquando indice esquerdo for menor que pivo */
void incrementa(int *v, int *esq, int pivo){
	if(v[*esq] <= pivo)
		(*esq)++, incrementa(v, esq, pivo);
}

/* Decrementa recursivamente enquando indice direito for maior que pivo */
void decrementa(int *v, int *dir, int pivo){
	if(v[*dir] > pivo)
		(*dir)--, decrementa(v, dir, pivo);
}

/* Troca valores recursivamente rearranjando-os enquando indice esquerdo for menor */
void rearranja(int *v, int *esq, int *dir, int pivo){
	int aux;
	if(*esq < *dir) {
		incrementa(v, esq, pivo);
		decrementa(v, dir, pivo);
		if(*esq < *dir){
			aux = v[*esq];
			v[*esq] = v[*dir];
			v[*dir] = aux;
		}
		rearranja(v, esq, dir, pivo);
	}
}

/* Particiona o valor conforme modelo do algoritmo */
int particiona(int v[], int inicio, int fim) {
	int esq, dir, pivo;
	esq = inicio;
	dir = fim;
	pivo = v[inicio];
	rearranja(v, &esq, &dir, pivo);
	v[inicio] = v[dir];
	v[dir] = pivo;
	return dir;
}

/* Ordena o vetor utilizando o algoritmo Quick Sort Recursivamente */
void quickSort(int v[], int inicio, int fim){
	int pivo;
	if(fim > inicio) {	
		pivo = particiona(v, inicio, fim);
		quickSort(v, inicio, pivo-1);
		quickSort(v, pivo+1, fim);
	}
}

//////////////// TESTE //////////////////

int main () {
	int arr[] = {3, 6, 5, 7, -1, 8, 4, 1, 9, 0, -2, 2};

	printf("Dados Brutos:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	
	quickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	printf("\nOrdenados por Merge Sort:\n");
	showArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}
