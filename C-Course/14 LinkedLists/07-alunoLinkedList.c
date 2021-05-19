#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

struct Aluno {
	int matricula;
	char nome[255];
	struct Aluno *proximo;
};

struct descritor {
	struct Aluno *inicio;
	struct Aluno *fim;
	int qnt;
};

typedef struct descritor Descritor;
typedef struct Aluno Student;

void adicionar(Descritor *des, int mat, char nome[]) {
	Student *s = (Student*) malloc(sizeof(Student));
	s->matricula = mat;
	strcpy(s->nome, nome);
	s->proximo = NULL;

	if(!des->inicio) {
		des->inicio = s;
	}
	if(!des->fim) {
		des->fim = s;
	} else {
		des->fim->proximo = s;
		des->fim = des->fim->proximo;
	}
	des->qnt++;
}

void mostra(Descritor *des) {
	int inLoop = 1;
	while(inLoop){
		if(!des->inicio->proximo) inLoop = 0;
		printf("%s\n", des->inicio->nome);
		des->inicio = des->inicio->proximo;
	}
}

void removeItem(Descritor *des) {
	Student *aux = des->inicio;
	des->inicio = des->inicio->proximo;
	free(aux);
	des->qnt--;
}

int main () {
	Descritor *s = (Descritor*) malloc(sizeof(Descritor));
	adicionar(s, 1, "Joao");
	adicionar(s, 2, "Maria");
	adicionar(s, 3, "Jose");
	removeItem(s);
	adicionar(s, 4, "Helio");
	mostra(s);
	printf("Quantidade: %i\n", s->qnt);
	return 0;
}