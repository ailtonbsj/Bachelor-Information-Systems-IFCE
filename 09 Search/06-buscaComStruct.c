#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int matricula;
	char nome[30];
	float n1, n2, n3;
} Aluno;

void showAluno(Aluno a) {
	printf("{ %i, %s, %0.1f, %0.1f, %0.1f }\n", 
		a.matricula, a.nome, a.n1, a.n2, a.n3);
}

void showAlunos(Aluno a[], int len) {
	for (int i = 0; i < len; i++) {
		showAluno(a[i]);
	}
}

int buscaSequencialMatricula(Aluno a[], int len, int matricula){
	for (int i = 0; i < len; i++) {
		if(matricula == a[i].matricula) return i;
	}
	return -1;
}

int buscaSequencialNome(Aluno a[], int len, char name[]){
	for (int i = 0; i < len; i++) {
		if(strcmp(name, a[i].nome) == 0) return i;
	}
	return -1;
}

int main () {
	Aluno v[] = {
		{2, "joao", 9.5, 8.0, 9.2},
		{3, "pedro", 7.8, 8.4, 9.9},
		{1, "mariana", 7.8, 8.3, 9.9},
		{4, "beatriz", 7.0, 8.9, 9.5}
	};

	showAlunos(v, sizeof(v)/sizeof(Aluno));
	int mat = 1;
	printf("Matricula %i esta no indice %i.\n", mat,
		buscaSequencialMatricula(v, sizeof(v)/sizeof(Aluno), mat) );
	char nome[] = "beatriz";
	printf("Aluno %s esta no indice %i.\n", nome,
		buscaSequencialNome(v, sizeof(v)/sizeof(Aluno), nome) );
	return 0;
}
