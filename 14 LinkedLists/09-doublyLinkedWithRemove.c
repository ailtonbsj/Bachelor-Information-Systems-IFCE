#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
} Node;

typedef struct doubly {
	Node *start, *end;
} Doubly;

Doubly* addItemBefore(Doubly *desc, int val) {
	Node *n = (Node*) malloc(sizeof(Node));
	n->data = val;
	if(!desc) {
		desc = (Doubly*) malloc(sizeof(Doubly));
		n->prev = NULL;
		n->next = NULL;
		desc->start = n;
		desc->end = n;
	} else {
		n->prev = NULL;
		n->next = desc->start;
		desc->start->prev = n;
		desc->start = n;
	}
	return desc;
}

Doubly* addItemAfter(Doubly *desc, int val) {
	Node *n = (Node*) malloc(sizeof(Node));
	n->data = val;
	if(!desc) {
		desc = (Doubly*) malloc(sizeof(Doubly));
		n->prev = NULL;
		n->next = NULL;
		desc->start = n;
		desc->end = n;
	} else {
		n->prev = desc->end;
		n->next = NULL;
		desc->end->next = n;
		desc->end = n;
	}
}

void showList(Doubly *desc) {
	Node *start = desc->start;
	int inLoop = 1, passedFirst = 0;
	while(inLoop) {
		if(!start->next) inLoop = 0;
		if(passedFirst) printf(",");
		passedFirst = 1;
		printf(" %i", start->data);
		start = start->next;
	}
	printf("\n");
}

Doubly* removeItemStart(Doubly* des) {
	if(des->start->next) {
		Node *n = des->start->next;
		free(des->start);
		des->start = n;
		des->start->prev = NULL;
	} else {
		free(des->start);
		des->start = NULL;
		des->end = NULL;
	}
	return des;
}

Doubly* removeItemEnd(Doubly *des) {
	if(des->end->prev) {
		Node *p = des->end->prev;
		free(des->end);
		des->end = p;
		des->end->next = NULL;
	} else {
		free(des->end);
		des->start = NULL;
		des->end = NULL;
	}
	return des;
}

int main () {
	Doubly *list = addItemAfter(list, 10);
	list = addItemAfter(list, 9);
	list = addItemAfter(list, 8);
	list = addItemBefore(list, 11);
	list = addItemBefore(list, 12);
	list = addItemBefore(list, 13);

	printf("List:");
	showList(list);

	list = removeItemStart(list);
	list = removeItemStart(list);
	printf("List:");
	showList(list);

	list = removeItemEnd(list);
	list = removeItemEnd(list);
	printf("List:");
	showList(list);
	return 0;
}