#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void clearBufferKey () {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

void rawInput (char *buf, unsigned size) {
	fgets(buf, size, stdin);
	buf[strlen(buf)-1] = '\0';
	clearBufferKey();
}

typedef struct {
	char marca[255];
	char modelo[255];
	unsigned ano;
	float preco;
} Carro;

void imprimeCarro (Carro *car) {
	printf("----------------\n");
	printf("Marca: %s\n", car->marca);
	printf("Modelo: %s\n", car->modelo);
	printf("Ano: %u\n", car->ano);
	printf("Preço: %0.2f\n", car->preco);
}


int main () {
	Carro carros[] = {
		{"Ford", "Mustang", 2017, 315900.00},
		{"Ford", "Focus", 2007, 68990.00},
		{"Volkswagen", "Fusca", 2017, 20000.00}
	};

	enum OPCAO {MARCA = 1, ANO, PRECO};
	int opcao;
	printf("Buscar por:\n(1) Marca\n(2) Ano\n(3) Preço\n\nOpçao: ");
	scanf("%i", &opcao);
	clearBufferKey();
	
	char queryStr[255] = {};
	int queryInt = -1;
	float queryFloat = -1;
	switch(opcao) {
		case MARCA:
			printf("Digite a marca: ");
			rawInput(queryStr, 255);
			break;
		case ANO:
			printf("Digite o ano: ");
			scanf("%i", &queryInt);
			clearBufferKey();
			break;
		case PRECO:
			printf("Digite o preço: ");
			scanf("%f", &queryFloat);
			clearBufferKey();
			break;
		default:
			printf("Opçao Invalida!\n");
	}

	for (int i=0; i < sizeof(carros)/sizeof(Carro); i++) {
		if(strlen(queryStr) != 0){
			if(strstr(carros[i].marca, queryStr) != NULL) {
				imprimeCarro(&carros[i]);
			}
		} else if(queryInt != -1) {
			if(carros[i].ano == queryInt) {
				imprimeCarro(&carros[i]);
			}

		} else if(queryFloat != -1) {
			if(carros[i].preco > queryFloat) {
				imprimeCarro(&carros[i]);
			}
		}
	}

	return 0;
}