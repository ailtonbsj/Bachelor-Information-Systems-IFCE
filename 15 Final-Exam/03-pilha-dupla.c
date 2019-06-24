#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NULO ( (int) pow(2, 8*sizeof(int)) )

typedef enum sentido {
	NEGATIVO = -1, POSITIVO = 1
} Sentido;

typedef struct pilha {
	int inicio;
	int fim;
	Sentido sentido;
	char alias;
	struct pilhaDupla *entrelace;
} Pilha;

typedef struct pilhaDupla {
	int *vetor;
	int length;
	Pilha *primaria;
	Pilha *secundaria;
} PilhaDupla;

PilhaDupla* iniciaPilhaDupla(int length) {
	PilhaDupla *p = (PilhaDupla*) malloc(sizeof(PilhaDupla));
	p->length = length;
	p->vetor = (int*) malloc(length*sizeof(int));
	return p;
}

Pilha* iniciaPilha(PilhaDupla *pd) {
	Sentido s;
	Pilha *p = (Pilha*) malloc(sizeof(Pilha));
	if(!pd->primaria)
		pd->primaria = p, s = NEGATIVO, p->alias = 'A';
	else
		pd->secundaria = p, s = POSITIVO, p->alias = 'B';
	p->sentido = s;
	p->entrelace = pd;
	p->inicio = (s == POSITIVO) ? pd->length/2 : (pd->length/2)-1;
	p->fim = -1;
	return p;
}

void adicionaNaPilha(Pilha *p, int val) {
	printf("Adicionando %i a Pilha %c\n", val, p->alias);

	if( (p->fim == (p->entrelace->length-1)) || (p->fim == 0) ) {
		int ant = p->entrelace->length; // PARA FINS DIDATICO
		p->entrelace->length = p->entrelace->length + 8;
		p->entrelace->vetor = realloc(
			p->entrelace->vetor, p->entrelace->length*sizeof(int));
		for(; ant < (p->entrelace->length)-1; ant++)  // PARA FINS DIDATICO
			p->entrelace->vetor[ant] = 0;             // PARA FINS DIDATICO
		
		if(p->fim == 0) {
			int fim2 = p->entrelace->secundaria->fim;
			int meioPilhas = fim2 / 2;
			int meioVetor = p->entrelace->length / 2;
			int offset = meioVetor - meioPilhas;
			for (int i = fim2; i >= p->entrelace->primaria->fim; i--)
				p->entrelace->vetor[i+offset] = p->entrelace->vetor[i];
			p->entrelace->primaria->fim += offset;
			p->entrelace->primaria->inicio += offset;
			p->entrelace->secundaria->fim += offset;
			p->entrelace->secundaria->inicio += offset;
			for(int i = p->entrelace->primaria->fim-1; i >= 0; i--) // PARA FINS DIDATICO
				p->entrelace->vetor[i] = 0;                         // PARA FINS DIDATICO
		}
	}
	if(p->fim == -1) p->fim = p->inicio;
	else p->fim = p->fim + p->sentido;
	p->entrelace->vetor[p->fim] = val;
}

int removeDaPilha(Pilha *p) {
	int ans = NULO;
	if(p->fim != -1) {
		ans = p->entrelace->vetor[p->fim];
		p->entrelace->vetor[p->fim] = 0;
		if(p->fim == p->inicio) p->fim = -1;
		else p->fim = p->fim - p->sentido;
	}
	return ans;	
}

void removeDaPilhaEMostra(Pilha *p) {
	int aux = removeDaPilha(p);
	if(aux != NULO)	printf("Removendo %i da pilha %c\n", aux, p->alias);
	else printf("Nenhum valor removido! Pilha vazia!\n");
}

void mostraVetor(int vetor[], int len) {
	printf("Vetor completo: ");
	for (int i = 0; i < len; ++i) {
		printf("%i ", vetor[i]);
	}
	printf("\n");
}

void mostraPilha(Pilha *p) {
	printf("PILHA %c: ", p->alias);
	if(p->fim != -1) {
		for (int i = p->inicio; i != (p->fim + p->sentido); i += p->sentido)
			printf(" %i", p->entrelace->vetor[i]);
	}
	printf("\n");
}

int main () {
	PilhaDupla *p = iniciaPilhaDupla(4);
	Pilha *p1 = iniciaPilha(p);
	Pilha *p2 = iniciaPilha(p);

	mostraVetor(p->vetor, p->length);
	adicionaNaPilha(p1, 1);
	adicionaNaPilha(p2, 1);
	mostraVetor(p->vetor, p->length);
	adicionaNaPilha(p1, 2);
	mostraVetor(p->vetor, p->length);
	adicionaNaPilha(p2, 2);
	mostraVetor(p->vetor, p->length);
	removeDaPilhaEMostra(p1);
	removeDaPilhaEMostra(p1);
	removeDaPilhaEMostra(p1);
	mostraVetor(p->vetor, p->length);
	removeDaPilhaEMostra(p2);
	removeDaPilhaEMostra(p2);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	adicionaNaPilha(p1, 1);
	adicionaNaPilha(p1, 2);
	mostraVetor(p->vetor, p->length);
	adicionaNaPilha(p2, 1);
	adicionaNaPilha(p2, 2);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	adicionaNaPilha(p2, 3);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	adicionaNaPilha(p2, 4);
	adicionaNaPilha(p2, 5);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	adicionaNaPilha(p1, 3);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	adicionaNaPilha(p1, 4);
	adicionaNaPilha(p1, 5);
	adicionaNaPilha(p1, 6);
	adicionaNaPilha(p1, 7);
	adicionaNaPilha(p1, 8);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	adicionaNaPilha(p1, 9);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	adicionaNaPilha(p1, 10);
	mostraVetor(p->vetor, p->length);
	mostraPilha(p1);
	mostraPilha(p2);
	return 0;
}