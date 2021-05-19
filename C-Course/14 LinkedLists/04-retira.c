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

void retira_inicio(Lista *l) {
	Lista *next = l->next;
	if(next){
		l->val = next->val;
		l->next = next->next;
	}
}

void retira_final(Lista *l) {
	Lista *last;
	if(l->next) {
		while(l->next) last = l, l = l->next;
		last->next = NULL;
		free(l);
	}
}

int main () {
	Lista *list = iniciarLista(0);
	adicionar(list, 1);
	adicionar(list, 2);
	adicionar(list, 3);
	adicionar(list, 4);
	adicionar(list, 5);
	adicionar(list, 6);
	adicionar(list, 7);
	adicionar(list, 8);
	mostrar(list);
	retira_inicio(list);
	retira_inicio(list);
	mostrar(list);
	retira_final(list);
	retira_final(list);
	mostrar(list);
	return 0;
}