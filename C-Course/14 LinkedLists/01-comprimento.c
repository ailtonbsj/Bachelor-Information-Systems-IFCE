#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct listaEncadeada {
	int val;
	struct listaEncadeada *next;
} Lista;

Lista *criarLista(Lista *head, int val) {
	Lista *new = (Lista*) malloc(sizeof(Lista));
	if(head) head->next = new;
	new->val = val;
	new->next = NULL;
	return new;
}

Lista *iniciarLista(int val) {
	return criarLista(NULL, val);
}

void adicionar(Lista *list, int val) {
	while(list->next) list = list->next;
	criarLista(list, val);
}

void mostrar(Lista *list) {
	printf("%i ", list->val);
	if(list->next) mostrar(list->next);
	else printf("\n");
}

int comprimento (Lista * lista) {
	int cont = 0;
	if(lista) {
		cont = 1;
		while(lista->next) lista = lista->next, cont++;
	}
	return cont;
}

int main () {
	Lista *list = iniciarLista(0);
	adicionar(list, 1);
	adicionar(list, 2);
	adicionar(list, 3);
	adicionar(list, 7);
	mostrar(list);
	printf("Comprimento: %i\n", comprimento(list));
	return 0;
}