#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char matricula[10];
	char nome[30];
	float nota1, nota2, nota3;
} Aluno;

float mediaDoAluno(Aluno a) {
	return (a.nota1 + a.nota2 + a.nota3) / 3.0;
}

void mostraAluno(Aluno a) {
	printf("{%s, %-8.8s, %4.1f, %4.1f, %4.1f, m = %4.1f}\n", 
		a.matricula, a.nome, a.nota1, a.nota2,
		a.nota3, mediaDoAluno(a));
}

void mostraAlunos(Aluno as[], int len) {
	for (int i = 0; i < len; i++) {
		mostraAluno(as[i]);
	}
}

void bubbleSort(Aluno as[], int len) {
	int trocou;
	while(len--) {
		trocou = 1;
		for (int i = 0; i < len; i++) {
			if(mediaDoAluno(as[i]) < mediaDoAluno(as[i+1])){
				Aluno aux = as[i];
				as[i] = as[i+1];
				as[i+1] = aux;
				trocou = 0;
			}
		}
		if(trocou) break;
	}
}

int main () {

	Aluno as[] = {
		{"201801001", "Joao", 7, 8, 9},
		{"201700602", "Michael", 6, 7, 6},
		{"201902001", "Flavio", 7, 6, 10},
		{"201702034", "Fabiola", 10, 9, 8},
		{"201801002", "Bela", 9, 5, 6}
	};

	mostraAlunos(as, sizeof(as)/sizeof(Aluno));
	bubbleSort(as, sizeof(as)/sizeof(Aluno));
	printf("\nOrdenados por media:\n");
	mostraAlunos(as, sizeof(as)/sizeof(Aluno));

	return 0;
}