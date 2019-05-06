#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int matricula;
	char nome[45];
	float media;
} Aluno;

void showAluno(Aluno a){
	printf("{%i, %s, %0.2f}\n", a.matricula, a.nome, a.media);
}

void showAlunos(Aluno a[], int len){
	for (int i = 0; i < len; ++i) {
		showAluno(a[i]);
	}
}

void troca(Aluno *a, Aluno *b){
	Aluno c = *a;
	*a = *b;
	*b = c;
}

void bubbleSort(Aluno a[], int len){
	int continua;
	do {
		continua = 0;
		for (int i = 0; i < len-1; i++) {
			if(a[i].media < a[i+1].media) {
				troca(&a[i], &a[i+1]);
				continua = i;
			}
			else if(a[i].media == a[i+1].media){
				if(strcmp(a[i].nome, a[i+1].nome) > 0) {
					troca(&a[i], &a[i+1]);
					continua = i;
				}
			}
		}
		len--;
	} while(continua != 0);
}

int main () {

	Aluno al[] = {
		{1, "João", 7.0},
		{2, "Jarbas", 10.0},
		{3, "Gil", 7.0},
		{4, "Ailton", 8.0},
		{5, "Alda", 10.0},
		{6, "Paulo", 7.0}
	};

	printf("Vetor Bruto:\n");
	showAlunos(al, sizeof(al)/sizeof(Aluno));

	printf("\n\nVetor Ordenado:\n");
	bubbleSort(al, sizeof(al)/sizeof(Aluno));
	showAlunos(al, sizeof(al)/sizeof(Aluno));

	return 0;
}