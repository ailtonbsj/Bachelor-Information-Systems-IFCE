#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

struct Endereco {
	char rua[60];
	unsigned int numero;
	char cidade[60];
	char estado[60];
	unsigned int cep;
};

struct Pessoa {
	char nome[60];
	unsigned int idade;
	struct Endereco endereco;	
};

int main() {
	struct Pessoa p1;

	// Entradas
	printf("Digite o nome da pessoa (máximo 60 letras): ");
	fgets(p1.nome, sizeof(p1.nome), stdin);

	printf("Digite a idade da pessoa: ");
	scanf("%u", &p1.idade);
	clearBufferKey();

	printf("Digite a rua da pessoa (máximo 60 letras): ");
	fgets(p1.endereco.rua, sizeof(p1.endereco.rua), stdin);

	printf("Digite o numero da casa ou Ap.: ");
	scanf("%u", &p1.endereco.numero);
	clearBufferKey();

	printf("Digite a cidade da pessoa (máximo 60 letras): ");
	fgets(p1.endereco.cidade, sizeof(p1.endereco.cidade), stdin);

	printf("Digite o estado onde mora (máximo 60 letras): ");
	fgets(p1.endereco.estado, sizeof(p1.endereco.estado), stdin);

	printf("Digite o CEP (somente números): ");
	scanf("%u", &p1.endereco.cep);
	clearBufferKey();

	// Saidas
	printf("\nSAIDA:\n\n");
	printf("Nome: %s", p1.nome);
	printf("Idade: %u\n", p1.idade);
	printf("Rua: %s", p1.endereco.rua);
	printf("Numero: %u\n", p1.endereco.numero);
	printf("Cidade: %s", p1.endereco.cidade);
	printf("Estado: %s", p1.endereco.estado);
	printf("CEP: %u\n", p1.endereco.cep);
}