#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} Node;

Node *createNode(Node *head, int val) {
	Node *novo = (Node*) malloc(sizeof(Node));
	novo->val = val;
	novo->next = NULL;
	if(head) head->next = novo;
	return novo; 
}

Node *startList(int x) {
	return createNode(NULL, x);
}

void freeList(Node *list) {
	if(list->next) freeList(list->next);
	free(list);
}

void insertBefore(Node *nd, int x) {
	Node *nextTmp = nd->next;
	Node *novo = createNode(nd, nd->val);
	nd->val = x;
	novo->next = nextTmp;
}

void insertAfter(Node *nd, int x) {
	while(nd->next) nd = nd->next;
	Node *novo = createNode(nd, x);
}

void showNodes(Node *nd) {
	printf("%i ", nd->val);
	if(nd->next) showNodes(nd->next);
	else printf("\n");
}

void removeFirst(Node *list) {
	Node *next = list->next;
	if(next){
		list->val = next->val;
		list->next = next->next;
	}
}

void removeLast(Node *list) {
	Node *last;
	if(list->next) {
		while(list->next) last = list, list = list->next;
		last->next = NULL;
		free(list);
	}
}

void insertBeforePosition(Node *nd, int pos, int x) {
	Node *last, *novo, *tmp;
	if(pos > 0) {
		while(nd->next) {
			if(!pos--) break;
			last = nd;
			nd = nd->next;
		}
		if(pos <= 0){
			tmp = last->next;
			novo = createNode(last, x);
			novo->next = tmp;
		} else {
			novo = createNode(nd, x);
		}
	} else printf("Pos need to be major then 0.\n"), exit(1);
}

void removeNodeByPosition(Node *list, int pos) {
	Node *last;
	if(pos > 0) {
		while(list->next) {
			if(!pos--) break;
			last = list;
			list = list->next;
		}
		if(pos <= 0) {
			last->next = list->next;
		}
	} else printf("Pos need to be major then 0.\n"), exit(1);
}

int main() {
	Node *list = (Node*) startList(0);
	insertBefore(list, 1);
	insertBefore(list, 2);
	insertBefore(list, 3);
	showNodes(list);

	insertBefore(list, 4);
	insertBefore(list, 5);
	insertBefore(list, 6);
	showNodes(list);

	insertAfter(list, 7);
	insertAfter(list, 8);
	insertAfter(list, 9);
	showNodes(list);

	removeFirst(list);
	showNodes(list);

	removeFirst(list);
	showNodes(list);

	removeLast(list);
	showNodes(list);

	insertBeforePosition(list, 1, 10);
	showNodes(list);
	insertBeforePosition(list, 4, 11);
	showNodes(list);
	insertBeforePosition(list, 6, 12);
	showNodes(list);
	insertBeforePosition(list, 60, 13);
	insertBeforePosition(list, 100, 14);
	showNodes(list);

	removeNodeByPosition(list, 2);
	showNodes(list);

	freeList(list);
	return 0;
}