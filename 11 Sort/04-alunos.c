#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	float media;
} Aluno;

void showAluno(Aluno a) {
	printf("{\"%s\", %0.2f}\n", a.nome, a.media);
}

void showAlunos(Aluno a[], int len) {
	for (int i = 0; i < len; ++i) {
		showAluno(a[i]);
	}
}

void selectionSort(Aluno v[], int n){
	int menor;
	for (int i = 0; i < n-1;i++) {
		menor = i;
		for(int j = i+1; j < n; j++) {
			if(v[j].media < v[menor].media) menor = j;
		}
		if( i != menor) {
			Aluno aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
	}
}

int main () {

	Aluno alunos[] = {
		{"Joao", 7}, {"Maria", 6}, {"Flavio", 8},
		{"Peter", 5},{"Lily", 10}, {"Megan", 9}
	};

	printf("Dados brutos:\n");
	showAlunos(alunos, sizeof(alunos)/sizeof(Aluno));

	selectionSort(alunos, sizeof(alunos)/sizeof(Aluno));
	printf("Depois do selectionSort:\n");
	showAlunos(alunos, sizeof(alunos)/sizeof(Aluno));
	return 0;
}