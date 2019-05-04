/* JOSE AILTON BATISTA DA SILVA */

#include <stdio.h>

int mostraESoma(int v[], int i,  int len) {
	printf(" %i,", v[i]);
	if(i == (len-1)) return v[i];
	else {
		return v[i] + mostraESoma(v, ++i, len);
	}
}

int main () {
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int soma = mostraESoma(nums, 0, sizeof(nums)/sizeof(int));
	printf("\nA soma eh: %i", soma);
	return 0;
}