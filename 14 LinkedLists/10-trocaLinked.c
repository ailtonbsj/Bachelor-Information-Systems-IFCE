#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int val;
	struct node *next;  
} Node;

Node *createNode(Node *first, int val) {
	Node *second = (Node*) malloc(sizeof(Node));
	second->val = val;
	if(first) {
		first->next = second;	
	}
	second->next = NULL;
}

Node *initList(int val) {
	return createNode(NULL, val);
}

void show(Node *node) {
	printf("%i ", node->val);
	if(node->next) show(node->next);
	else printf("\n");
}

void add(Node *node, int val) {
	while(node->next) {
		node = node->next;	
	}
	Node *second = createNode(node, val);
}

int existItem(Node *list, int val) {
	int isNull = 1;
	while(isNull) {
		if(!list->next) isNull = 0;
		if(list->val == val) return 1;
		list = list->next;
	}
	return 0;
}

int troca(Node *list, int a, int b) {
	Node *tmpA, *tmpB;
	int tmp;
	if(!existItem(list, a) || !existItem(list, b)) {
		printf("Um dos itens nao existe na lista!\n");
		return 0;
	}
	int isNull = 1;
	while(isNull){
		if(!list->next) isNull = 0;
		if(list->val == a) {
			tmpA = list;
		}
		if(list->val == b){
			tmpB = list;
		}
		list = list->next;
	}
	tmp = tmpA->val;
	tmpA->val = tmpB->val;
	tmpB->val = tmp;
}

int main() {
	Node *list = initList(3);
	add(list, 1);
	add(list, 7);
	add(list, 5);
	add(list, 4);
	add(list, 9);
	show(list);
	troca(list, 7, 4);
	show(list);
	troca(list, 5, 9);
	show(list);
	troca(list, 4, 3);
	show(list);
	return 0;
}
