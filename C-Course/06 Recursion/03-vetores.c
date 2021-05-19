#include <stdio.h>

int soma (int v[], int n) {
	if(n == 0) return 0;
	else return v[n-1] + soma(v, n-1);
}

int main () {
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	printf("A soma dos itens do array eh: %i\n",
		soma(array, sizeof(array)/sizeof(int)));
	return 0;
}