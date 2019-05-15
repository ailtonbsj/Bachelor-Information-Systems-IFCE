#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome[30];
	float valorPorHora;
	int horasTrabalhadas;
} Funcionario;

float salario(Funcionario a) {
	return a.valorPorHora * a.horasTrabalhadas;
}

void mostraFuncionario(Funcionario f) {
	printf("{%7.7s, %4.1f, %i h, R$ %6.2f}\n", f.nome,
		f.valorPorHora, f.horasTrabalhadas, salario(f));
}

void mostraFuncionarios(Funcionario fs[], int len) {
	for (int i = 0; i < len; ++i) {
		mostraFuncionario(fs[i]);
	}
}

void selectionSort(Funcionario fs[], int len) {
	int menor;
	int j = 0;
	for (int j = 0; j < len; j++) {
		menor = j;
		for (int i = j+1; i < len; i++) {
			if(salario(fs[i]) < salario(fs[menor])) {
				menor = i;
			}
		}
		Funcionario aux = fs[j];
		fs[j] = fs[menor];
		fs[menor] = aux;
	}
}

int main () {

	Funcionario fs[] = {
		{"Carlos", 10, 40},
		{"Maria", 35, 25},
		{"Suzana", 20, 10},
		{"Carlos", 5, 10},
		{"Flavia", 5, 12}
	};

	mostraFuncionarios(fs, sizeof(fs)/sizeof(Funcionario));
	printf("\nOrdenados por salario:\n");
	selectionSort(fs, sizeof(fs)/sizeof(Funcionario));
	mostraFuncionarios(fs, sizeof(fs)/sizeof(Funcionario));

	return 0;
}