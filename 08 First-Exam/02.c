/* JOSE AILTON BATISTA DA SILVA */

#include <stdio.h>

unsigned fatorial(unsigned x) {
	if(x == 1) return 1;
	else return x * fatorial(x-1);
}

int main () {
	printf("3! eh igual a: %u\n", fatorial(3));
	printf("5! eh igual a: %u\n", fatorial(5));
	printf("6! eh igual a: %u\n", fatorial(6));
	return 0;
}