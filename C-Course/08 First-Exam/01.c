/* JOSE AILTON BATISTA DA SILVA */

#include <stdio.h>

int mdc(unsigned x, unsigned y) {
	int r = x % y;
	if(r == 0) return y;
	else mdc(y, r);
}

int main () {
	printf("O MDC de 10 e 2 eh: %i\n", mdc(10, 2));
	printf("O MDC de 100 e 40 eh: %i\n", mdc(100, 40));
	printf("O MDC de 200 e 41 eh: %i\n", mdc(200, 41));
	return 0;
}