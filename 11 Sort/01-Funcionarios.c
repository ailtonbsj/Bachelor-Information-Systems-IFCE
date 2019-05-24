#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[50];
	int dia, mes;
} Funcionario;

void showFuncionario(Funcionario f) {
	printf("{%s, %i / %i}\n", f.nome, f.mes, f.dia);
}

void showFuncionarios(Funcionario fs[], int len) {
	int i;
	for (i = 0; i < len; i++)	{
		showFuncionario(fs[i]);
	}
}

void bubbleSort(Funcionario fs[], int len){
	int continua;
	do {
		int i;
		continua = 0;
		for (i = 0; i < len-1; i++)	{
			if(fs[i].mes > fs[i+1].mes){
				Funcionario aux = fs[i];
				fs[i] = fs[i+1];
				fs[i+1] = aux;
				continua = i;
			}
			else if(fs[i].mes == fs[i+1].mes){
				if(fs[i].dia > fs[i+1].dia) {
					Funcionario aux = fs[i];
					fs[i] = fs[i+1];
					fs[i+1] = aux;
					continua = i;
				}
			}
		}
		len--;
	} while(continua != 0);
}

int main() {

	Funcionario fs[] = {
		{"Joao", 3, 8},
		{"Maria", 5, 6},
		{"Roberto", 5, 7},
		{"Jose", 2, 6},
		{"Jiba", 4, 7}
	};

	printf("Dados brutos:\n");
	showFuncionarios(fs, sizeof(fs)/sizeof(Funcionario) );

	printf("\n\nDados ordenados:\n");
	bubbleSort(fs, sizeof(fs)/sizeof(Funcionario));
	showFuncionarios(fs, sizeof(fs)/sizeof(Funcionario) );
	return 0;
}
