#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(char v[], int fim) {
	int continua;
	fim--;
	do {
		continua = 0;
		for (int i = 0; i < fim-1; i++)	{
			if(v[i] > v[i+1]) {
				char aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				continua = i;
			}
		}
		fim--;
	} while(continua != 0);
}

int main () {
	char palavra[] = "nordestinos";
	printf("Palavra: %s\n", palavra);
	bubbleSort(palavra, sizeof(palavra)/sizeof(char));
	printf("Ordenada: %s\n", palavra);
	return 0;
}