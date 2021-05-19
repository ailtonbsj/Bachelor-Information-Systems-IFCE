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

typedef struct {
	char nome[60];
	float nota1, nota2, media;
} Aluno;

#define MAX_ALUNOS 2

void maiorNota(Aluno s[], unsigned int max) {
	Aluno maior = s[0];
	for(int i; i < max; i++){
		if((s[i].nota1 >= maior.nota1 && s[i].nota1 >= maior.nota2) ||
		   (s[i].nota2 >= maior.nota1 && s[i].nota2 >= maior.nota2)) maior = s[i];
	}
	printf("\n\n-- Aluno com maior nota ---\n\n");
	printf("Nome: %s\n", maior.nome);
	printf("Nota1: %0.2f\n", maior.nota1);
	printf("Nota2: %0.2f\n", maior.nota2);
}

void maiorMedia(Aluno s[], unsigned int max) {
	Aluno maior = s[0];
	for(int i = 0; i < max; i++){
		if(s[i].media >= maior.media) maior = s[i];
	}
	printf("\n\n-- Aluno com maior média ---\n\n");
	printf("Nome: %s\n", maior.nome);
	printf("Média: %0.2f\n", maior.media);
}

void mostrarEstado(Aluno s[], unsigned int max) {
	printf("\n\n-- Aprovados e Reprovados --\n\n");
	for(int i = 0; i < max; i++){
		printf("%s : ", s[i].nome);

		if(s[i].media >= 7) printf("Aprovado\n");
		else if(s[i].media < 3) printf("Reprovado\n");
		else printf("Recuperação\n"); 
	}
}

int main() {
	Aluno alunos[MAX_ALUNOS];

	for(int i = 0; i < MAX_ALUNOS; i++){
		printf("\n\n--- INSERÇÃO DE DADOS DO ALUNO %d ---\n\n", i+1);

		//Entradas
		printf("Digite o nome do aluno: ");
		rawInput(alunos[i].nome, sizeof(alunos[i].nome));

		printf("Digite a nota 1 do aluno: ");
		scanf("%f", &alunos[i].nota1);
		clearBufferKey();

		printf("Digite a nota 2 do aluno: ");
		scanf("%f", &alunos[i].nota2);
		clearBufferKey();

		alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2.0;
	}

	printf("\n\n--- DADOS DO ALUNOS ---\n");
	for(int i = 0; i < MAX_ALUNOS; i++) {
		printf("\nAluno %d\n", i+1);
		printf("Nome: %s\n", alunos[i].nome);
		printf("Média: %0.2f\n", alunos[i].media);
	}

	maiorNota(alunos, MAX_ALUNOS);
	maiorMedia(alunos, MAX_ALUNOS);
	mostrarEstado(alunos, MAX_ALUNOS);
}