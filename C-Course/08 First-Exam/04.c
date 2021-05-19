/* JOSE AILTON BATISTA DA SILVA */

#include <stdio.h>

typedef struct {
	char nome[255];
	int matricula;
	char turma;
	float n1, n2, n3;
} Aluno;

void mostraAprovados (Aluno as[], int len) {
	int i;
	printf("Alunos aprovados:\n");
	for(i = 0; i < len; i++){
		float media = (as[i].n1 + as[i].n2 + as[i].n3)/3;
		if(media >= 7) printf("%s\n", as[i].nome);
	}
}

void mostraAprovadosPorTurma(Aluno as[], int len, char turma) {
	float somaMedias = 0;
	int contTurma = 0;
	int i;
	for(i = 0; i < len; i++){
		if(as[i].turma == turma){
			somaMedias += (as[i].n1 + as[i].n2 + as[i].n3)/3;
			contTurma++;
		}
	}
	float mediaGeral = somaMedias/contTurma;
	printf("Media geral da turma %c eh %0.2f\n", turma, mediaGeral);
	printf("Alunos acima da media:\n");
	for(i = 0; i < len; i++){
		if(as[i].turma == turma){
			float media = (as[i].n1 + as[i].n2 + as[i].n3)/3;
			if(media > mediaGeral) printf("%s\n", as[i].nome);
		}
	}
}

int main () {
	Aluno alunos[5] = {
		{"Joao", 100, 'A', 8, 7, 9},
		{"Mario", 101, 'A', 2, 3, 1},
		{"Rafael", 200, 'B', 6, 7, 9},
		{"Alan", 201, 'B', 3, 7, 5},
		{"Thiago", 300, 'C', 8, 7, 9}
	};
	mostraAprovados(alunos, sizeof(alunos)/sizeof(Aluno));
	printf("\n\n");
	mostraAprovadosPorTurma(alunos, sizeof(alunos)/sizeof(Aluno),'A');
	printf("\n\n");
	mostraAprovadosPorTurma(alunos, sizeof(alunos)/sizeof(Aluno),'B');
	printf("\n\n");
	mostraAprovadosPorTurma(alunos, sizeof(alunos)/sizeof(Aluno),'C');
	printf("\n\n");
	return 0;
}