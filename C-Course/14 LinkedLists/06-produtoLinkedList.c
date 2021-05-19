#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
	int codigo;
	char nome[20];
	float valor;
	int qntEstoque;
} Produto;

typedef struct node {
	Produto produto;
	struct node *proximo;
} Node;

void mostraProduto(Produto p) {
	printf("{%i, %s, %0.2f, %i}\n",
		p.codigo, p.nome, p.valor, p.qntEstoque);
}

Node* adicionarNodeNoInicio(Node *tail, int codigo, char nome[20],
	float valor, int estoque) {
	Node *node = (Node*) malloc(sizeof(Node));

	Produto produto;
	produto.codigo = codigo;
	produto.valor = valor;
	produto.qntEstoque = estoque;
	strcpy(produto.nome, nome);

	node->produto = produto;
	if(!tail) node->proximo = NULL;
	else node->proximo = tail;
	return node;
}

void mostraLista(Node *node) {
	int inLoop = 1;
	while(inLoop) {
		if(!node->proximo) inLoop = 0;
		mostraProduto(node->produto);
		node = node->proximo;
	}
}

Node* obterProdutoDeMaiorValor(Node *node) {
	float maior = -99e99;
	Node *posicao = NULL;
	int inLoop = 1;
	while(inLoop) {
		if(!node->proximo) inLoop = 0;
		float pValor = node->produto.valor;
		if(pValor > maior) {
			maior = pValor;
			posicao = node;
		}
		node = node->proximo;
	}
	return posicao;
}

void mostraProdutosComEstoqueBaixo(Node *node) {
	int inLoop = 1;
	while(inLoop) {
		if(!node->proximo) inLoop = 0;
		if(node->produto.qntEstoque < 10)
			mostraProduto(node->produto);
		node = node->proximo;
	}
}

int tamanhoDaLista(Node *node) {
	int inLoop = 1, cont = 0;
	while(inLoop) {
		if(!node->proximo) inLoop = 0;
		cont++;
		node = node->proximo;
	}
	return cont;
}

void removeProdutosAbaixoDeCinco(Node *node) {
	int inLoop = 1;
	Node *nodeAnt = NULL;
	while(inLoop) {
		if(!node->proximo) inLoop = 0;
		if(node->produto.valor < 5) {
			if(nodeAnt) {
				nodeAnt->proximo = node->proximo;
				free(node);	
			} else {
				Node *prox = node->proximo;
				free(node);
				*node = *prox;
			}
		}
		nodeAnt = node;
		node = node->proximo;
	}
}

int main() {
	Node *lista;
	lista = adicionarNodeNoInicio(NULL, 0, "Mario", 4, 20);
	lista = adicionarNodeNoInicio(lista, 1, "Joao", 10, 1);
	lista = adicionarNodeNoInicio(lista, 2, "Maria", 60, 20);
	lista = adicionarNodeNoInicio(lista, 4, "Kaio", 3, 4);
	lista = adicionarNodeNoInicio(lista, 3, "Jose", 30, 30);
	lista = adicionarNodeNoInicio(lista, 5, "Sabrina", 2, 23);
	mostraLista(lista);
	Node *maior = obterProdutoDeMaiorValor(lista);
	printf("Maior Produto:\n");
	mostraProduto(maior->produto);
	printf("Estoque baixo:\n");
	mostraProdutosComEstoqueBaixo(lista);
	printf("Tamanho da Lista: %i\n", tamanhoDaLista(lista));
	removeProdutosAbaixoDeCinco(lista);
	printf("Produtos acima de 5:\n");
	mostraLista(lista);
	return 0;
}