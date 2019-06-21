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
	int inLoop = 1;
	while(inLoop) {
		if(!start->next) inLoop = 0;
		printf("%i\n", start->data);
		start = start->next;
	}
}

void showListReverse(Doubly *desc) {
	Node *end = desc->end;
	int inLoop = 1;
	while(inLoop) {
		if(!end->prev) inLoop = 0;
		printf("%i\n", end->data);
		end = end->prev;
	}
}

int isOrdened(Doubly *desc) {
	Node *start = desc->start;
	int aux = (int) -pow(2, 8*sizeof(int));
	int inLoop = 1;
	int ascOrd = 1, descOrd = 1;
	while(inLoop) {
		if(!start->next) inLoop = 0;
		if( !(start->data > aux) ) {
			ascOrd = 0;
			break;
		}
		aux = start->data;
		start = start->next;
	}
	start = desc->start;
	aux = (int) pow(2, 8*sizeof(int));
	inLoop = 1;
	while(inLoop) {
		if(!start->next) inLoop = 0;
		if( !(start->data < aux) ) {
			descOrd = 0;
			break;
		}
		aux = start->data;
		start = start->next;
	}
	return ascOrd || descOrd;
}


int main () {

	Doubly *list = addItemAfter(list, 10);

	//Desc
	list = addItemAfter(list, 9);
	list = addItemAfter(list, 8);
	list = addItemBefore(list, 11);
	list = addItemBefore(list, 12);
	list = addItemBefore(list, 13);
	//Asc
	// list = addItemAfter(list, 11);
	// list = addItemAfter(list, 12);
	showList(list);
	//showListReverse(list);
	printf("The list is %s\n", 
		isOrdened(list) ? "ordened!" : "not ordened!");
	return 0;
}