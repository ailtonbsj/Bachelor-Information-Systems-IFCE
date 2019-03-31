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

typedef struct {
	char nome[60];
	unsigned int matricula;
	char curso[60];
} Aluno;

int main(){
	Aluno alunos[5];

	for(int i = 0; i<5; i++){
		printf("\n\n--- INSERÇÃO DE DADOS DO ALUNO %d ---\n\n", i+1);

		//Entradas
		printf("Digite o nome do aluno: ");
		fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

		printf("Digite a matrícula do aluno: ");
		scanf("%u", &alunos[i].matricula);
		clearBufferKey();

		printf("Digite o curso do aluno: ");
		fgets(alunos[i].curso, sizeof(alunos[i].curso), stdin);
	}

	printf("\n\n--- DADOS DO ALUNOS ---\n\n");
	for(int i = 0; i<5; i++){
		printf("\nAluno %d\n", i+1);
		printf("Nome: %s", alunos[i].nome);
		printf("Matrícula: %u\n", alunos[i].matricula);
		printf("Curso: %s", alunos[i].curso);
	}
}