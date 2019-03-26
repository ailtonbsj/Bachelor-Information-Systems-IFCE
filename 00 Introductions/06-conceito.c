#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

/* Limpa buffer do teclado para Windows e Linux */
void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

float mediaPonderada(float n1, float n2, float n3) {
	return (n1+n2*2+n3*3)/6;
}

int main () {
	float n1, n2, n3, m;
	
	printf("Digite a n1: ");
	scanf("%f", &n1);
	clearBufferKey();
	printf("Digite a n2: ");
	scanf("%f", &n2);
	clearBufferKey();
	printf("Digite a n3: ");
	scanf("%f", &n3);
	clearBufferKey();
	
	m = mediaPonderada(n1, n2, n3);
	
	if(m >= 9) printf("Conceito A");
	else if(m >= 7.5) printf("Conceito B");
	else if(m >= 6) printf("Conceito C");
	else if(m >= 4) printf("Conceito D");
	else printf("Conceito E");
	printf("\n");
	return 0;
}