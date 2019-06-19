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

void retira_n (Lista *l, int x) {
	Lista *list = l, *last = NULL, *tmp;
	int notNull = 1;
	while(notNull) {
		if(!list->next) notNull = 0;
		if(list->val == x && last) {
			tmp = list;
			last->next = list->next;
			list = list->next;
			free(tmp);
			continue;
		}
		last = list;
		list = list->next;
	}
	if(l->val == x){
		tmp = l->next;
		l->val = tmp->val;
		l->next = tmp->next;
		free(tmp);
	}
}

int main () {
	Lista *list = iniciarLista(1);
	adicionar(list, 1);
	adicionar(list, 1);
	adicionar(list, 1);
	adicionar(list, 1);
	adicionar(list, 3);
	adicionar(list, 1);
	adicionar(list, 6);
	adicionar(list, 1);
	adicionar(list, 1);
	mostrar(list);
	printf("Removendo 1's da lista.\n");
	retira_n(list, 1);
	mostrar(list);

	Lista *list2 = iniciarLista(4);
	adicionar(list2, 3);
	adicionar(list2, 3);
	adicionar(list2, 7);
	adicionar(list2, 4);
	adicionar(list2, 5);
	adicionar(list2, 3);
	adicionar(list2, 3);
	mostrar(list2);
	printf("Removendo 3's da lista.\n");
	retira_n(list2, 3);
	mostrar(list2);

	return 0;
}