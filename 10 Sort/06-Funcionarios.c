#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[50];
	int valorPorHora, totalDeHoras;
} Funcionario;

void showFuncionario(Funcionario f) {
	printf("{%s, %i , %i, R$ %i}\n", f.nome, f.valorPorHora, f.totalDeHoras, f.valorPorHora*f.totalDeHoras);
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
			if(strcmp(fs[i].nome, fs[i+1].nome) > 0){
				Funcionario aux = fs[i];
				fs[i] = fs[i+1];
				fs[i+1] = aux;
				continua = i;
			}
		}
		len--;
	} while(continua != 0);
}

int buscaBinaria(Funcionario fs[], int len, char nome[]){
	int inicio = 0;
	int final = len;
	do {
		int meio;
		meio = (final+inicio)/2;
		if(strcmp(fs[meio].nome, nome) < 0){
			inicio = meio;
		}
		else if(strcmp(fs[meio].nome, nome) > 0){
			final = meio;
		}
		else return meio;
		if((final - inicio) == 1) return -1;
	} while(final != inicio);
}

void estaCadastrado(char nome[], Funcionario arr[], int len){
	int i = buscaBinaria(arr, len, nome);
	if(i == -1) printf("\nUsuario nao esta cadastrado!\n\n");
	else {
		printf("\nUsuario esta cadastrado!\n");
		showFuncionario(arr[i]);
	}
}

void selectionSort(Funcionario fs[], int len){
	int menor;
	for(int i = 0; i < len-1; i++) {
		menor = i;
		for(int j = i+1; j < len; j++){
			int jSal = fs[j].valorPorHora * fs[j].totalDeHoras;
			int menorSal = fs[menor].valorPorHora * fs[menor].totalDeHoras;
			if(jSal > menorSal) menor = j;
		}
		if(i != menor) {
			Funcionario aux = fs[i];
			fs[i] = fs[menor];
			fs[menor] = aux;
		}
	}
}

float mediaDosFuncionarios(Funcionario fs[], int len) {
	float somaSal = 0;
	for (int i = 0; i < len; i++)
		somaSal += fs[i].valorPorHora * fs[i].totalDeHoras;
	return somaSal / len;
}

void insertionSort(Funcionario fs[], int len){
	for (int i = 1; i < len; i++) {
		int j = i;
		while(j > 0) {
			float jMinusOne = fs[j-1].valorPorHora * fs[j-1].totalDeHoras;
			float jNow = fs[j].valorPorHora * fs[j].totalDeHoras;
			if(jMinusOne < jNow) {
				Funcionario aux = fs[j-1];
				fs[j-1] = fs[j];
				fs[j] = aux;
				j--;
			} else break;
		}
	}
}

void showFuncionariosMaioresQue(float val, Funcionario fs[], int len) {
	int i;
	for (i = 0; i < len; i++)	{
		if(fs[i].valorPorHora * fs[i].totalDeHoras >= val)
			showFuncionario(fs[i]);
	}
}

int main() {

	Funcionario fs[] = {
		{"Joao", 3, 8},
		{"Maria", 5, 6},
		{"Roberto", 5, 7},
		{"Jose", 2, 6},
		{"Jiba", 4, 7}
	};

	printf("\nDados ordenados:\n");
	bubbleSort(fs, sizeof(fs)/sizeof(Funcionario));
	showFuncionarios(fs, sizeof(fs)/sizeof(Funcionario) );
 
 	estaCadastrado("Roberto", fs, sizeof(fs)/sizeof(Funcionario));
 	estaCadastrado("Fabio", fs, sizeof(fs)/sizeof(Funcionario));
 	estaCadastrado("Maria", fs, sizeof(fs)/sizeof(Funcionario));
	
	printf("\nUsando SelectionSort:\n");
 	selectionSort(fs, sizeof(fs)/sizeof(Funcionario));
 	showFuncionario(fs[0]);
 	showFuncionario(fs[1]);
 	showFuncionario(fs[2]);

 	float media = mediaDosFuncionarios(fs, sizeof(fs)/sizeof(Funcionario));
 	printf("\nA media dos salarios eh: R$ %0.2f\n", media);
 	insertionSort(fs, sizeof(fs)/sizeof(Funcionario));
 	showFuncionariosMaioresQue(media, fs, sizeof(fs)/sizeof(Funcionario) );
 	
	return 0;
}
