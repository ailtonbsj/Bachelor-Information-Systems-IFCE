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

struct Aluno {
	int codigo;
	char nome[50];
	float n1, n2, n3;
};

void preenche (struct Aluno *aluno, int indice) {
	(*aluno).codigo = indice;
	
	printf("Digite o nome do aluno %i: ", indice+1);
	rawInput((*aluno).nome, 50);

	printf("Digite a nota 1 do aluno %i: ", indice+1);
	scanf("%f",&(*aluno).n1);
	clearBufferKey();

	printf("Digite a nota 2 do aluno %i: ", indice+1);
	scanf("%f",&(*aluno).n2);
	clearBufferKey();

	printf("Digite a nota 3 do aluno %i: ", indice+1);
	scanf("%f",&(*aluno).n3);
	clearBufferKey();
}

void imprime (struct Aluno alunos[], int len) {
	for(int i = 0; i < len; i++) {
		printf("\n-------------\n");
		printf("Codigo: %i\n", alunos[i].codigo);
		printf("Nome: %s\n", alunos[i].nome);
		printf("Nota 1: %0.1f\n", alunos[i].n1);
		printf("Nota 2: %0.1f\n", alunos[i].n2);
		printf("Nota 3: %0.1f\n", alunos[i].n3);
	}
	printf("\n");
}

void media (struct Aluno alunos[], int len) {
	printf("\n----MEDIAS---\n");
	for(int i=0; i < len; i++) {
		float media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3)/3;
		printf("%s --> %0.1f\n", alunos[i].nome, media);
	}
}

int main () {
	#define MAX 5
	struct Aluno alunos[MAX];
	for(int i=0; i < MAX; i++){
		preenche(&alunos[i], i);
	}
	imprime(alunos, sizeof(alunos)/sizeof(struct Aluno));
	media(alunos, sizeof(alunos)/sizeof(struct Aluno));
	return 0;
}