#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

/* Limpa buffer do teclado para Windows e Linux */
void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

/* Pega strings do teclado sem gerar problemas */
void rawInput(char *buf, unsigned int size) {
	fgets(buf, size, stdin);
	buf[strlen(buf)-1] = '\0';
	clearBufferKey();
}

typedef struct {
	int Mes;
	int Ano;
	int Dia;
} Data;

typedef struct {
	char nome[255];
	float altura;
	Data nascimento;
} Pessoa;

void criaData(Data *D) {
   (*D).Mes = 1 + (rand() % 12);
   (*D).Ano = 1950 + (rand() % 49);
   (*D).Dia = 1 + (rand() % 30);
}

enum OPCOES {INSERIR = 1, LISTAR, ESPECIFICO};
int criaMenu() {
	int opcao = 0;
	printf("Escolha uma opção\n");
	printf("(1) Inserir uma pessoa\n");
	printf("(2) Listar todas pessoas\n");
	printf("(3) Listar por um dia específico\n");
	printf("Opção: ");
	scanf("%i", &opcao);
	clearBufferKey();
	printf("\e[1;1H\e[2J");
	return opcao;
}

int main () {
	#define MAX 10
	Pessoa pessoas[MAX];
	int indice = -1;
	int diaOp = 0;

	while (1) {
		switch( criaMenu() ){
			case INSERIR:
				if(indice >= (MAX-1)) {
					printf("lista lotada! \n\n");
					break;
				}
				indice++;
				printf("Digite o nome: ");
				rawInput(pessoas[indice].nome, 255);
				printf("Digite a altura: ");
				scanf("%f", &pessoas[indice].altura);
				clearBufferKey();
				criaData(&pessoas[indice].nascimento);
				printf("Usuário Inserido!\n\n");
				break;
			case LISTAR:
				for (int i = 0; i <= indice; i++) {
					printf("----Pessoa %i------\n", i+1);
					printf("Nome: %s\n", pessoas[i].nome);
					printf("Altura: %0.2f\n", pessoas[i].altura);
					printf("Nascimento: %i/%i/%i\n",
						pessoas[i].nascimento.Dia,
						pessoas[i].nascimento.Mes,
							pessoas[i].nascimento.Ano);
				}
				printf("-------------------\n\n");
				break;
			case ESPECIFICO:
				printf("Digite o dia a pesquisar: ");
				scanf("%i", &diaOp);
				for (int i = 0; i <= indice; i++) {
					if(pessoas[i].nascimento.Dia == diaOp){
						printf("----Pessoa %i------\n", i+1);
						printf("Nome: %s\n", pessoas[i].nome);
						printf("Altura: %0.2f\n", pessoas[i].altura);
						printf("Nascimento: %i/%i/%i\n",
							pessoas[i].nascimento.Dia,
							pessoas[i].nascimento.Mes,
							pessoas[i].nascimento.Ano);
					}
				}
				printf("-------------------\n\n");
				break;
			default:
				printf("Opção inválida!\n\n");
		}
	}	
	return 0;
}