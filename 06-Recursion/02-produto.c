#include <stdio.h>

int produto (int x, int n) {
	if( n == 0 ) return 1;
	else return x * produto(x, n-1);
}

int main () {
	printf("Produto de 2^3 = %i\n", produto(2,3));
	printf("Produto de 2^6 = %i\n", produto(2,6));
	printf("Produto de 3^4 = %i\n", produto(3,4));
	return 0;
}