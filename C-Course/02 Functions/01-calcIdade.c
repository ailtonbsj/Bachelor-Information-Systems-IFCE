#include <stdio.h>

int main () {
	unsigned idade;
	
	printf("Digite o ano de nascimento: ");
	scanf("%u", &idade);

	printf("Sua idade em 2019 é: %u\n", 2019-idade);
	return 0;
}