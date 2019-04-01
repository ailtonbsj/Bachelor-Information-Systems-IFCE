#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

void rawInput(char *buf, unsigned int size) {
	fgets(buf, size, stdin);
	buf[strlen(buf)-1] = '\0';
	clearBufferKey();
}

void calculaAreaRetangulo(float base, float altura, float *area, float *perimetro){
	*area = base*altura;
	*perimetro = 2*base+2*altura;
}

int main() {
	float base, altura, area, perimetro;

	// entradas
	printf("Digite a base: ");
	scanf("%f", &base);
	printf("\nDigite a Altura: ");
	scanf("%f", &altura);
	calculaAreaRetangulo(base, altura, &area, &perimetro);
	printf("\nA area é: %0.2f\nO perimetro é: %0.2f\n", area, perimetro);
}