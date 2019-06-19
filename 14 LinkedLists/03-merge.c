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
	if(list) {
		printf("%i ", list->val);
		if(list->next) mostrar(list->next);
		else printf("\n");
	}
}

Lista* merge (Lista *l1, Lista *l2) {
	Lista *uniao, *rest;
	Lista *frag1 = l1, *frag2 = l2;
	int first = 1;
	int notNull = 1;
	while(notNull){
		if(!(l1->next && l2->next)) notNull = 0;
		if(first == 1) {
			uniao = iniciarLista(l1->val);
			first = 0;
		} else adicionar(uniao, l1->val);
	adicionar(uniao, l2->val);
		l1 = l1->next;
		l2 = l2->next;
	}

	notNull = 1;
	if(!l1 && !l2) notNull = 0;
	else if(l1) rest = l1;
	else if(l2) rest = l2;

	while(notNull) {
		if(!rest->next) notNull = 0;
		adicionar(uniao, rest->val);
		rest = rest->next;
	}
	while(frag1){
		Lista *tmp = frag1;
		frag1 = frag1->next;
		free(tmp);
	}
	while(frag2){
		Lista *tmp = frag2;
		frag2 = frag2->next;
		free(tmp);
	}
	return uniao;
}

int main () {
	Lista *lista1 = iniciarLista(2);
	adicionar(lista1, 4);
	adicionar(lista1, 1);
	// adicionar(lista1, 5);
	// adicionar(lista1, 8);
	// adicionar(lista1, 9);
	
	Lista *lista2 = iniciarLista(7);
	adicionar(lista2, 3);
	adicionar(lista2, 9);
	adicionar(lista2, 6);
	adicionar(lista2, 10);
	adicionar(lista2, 11);
	
	printf("Lista 1: ");
	mostrar(lista1);
	printf("Lista 2: ");
	mostrar(lista2);

	Lista *uniao = merge(lista1, lista2);
	printf("  Uniao: ");
	mostrar(uniao);
	return 0;
}