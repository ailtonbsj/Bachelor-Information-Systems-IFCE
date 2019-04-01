#include <stdio.h>

struct Ponto {
	int x;
	int y;
};

int dentroRet (struct Ponto* v1, struct Ponto* v2, struct Ponto* p);

int main() {
	struct Ponto a1 = {1, 2};
	struct Ponto a2 = {7, 6};
	struct Ponto P = {4, 4};
	struct Ponto G = {8, 1};
	struct Ponto M = {2, 7};
	dentroRet(&a1, &a2, &P);
	dentroRet(&a1, &a2, &G);
	dentroRet(&a1, &a2, &M);
	return 0;
}

int dentroRet (struct Ponto* v1, struct Ponto* v2, struct Ponto* p) {
	if( (p->x > v1->x) && (p->x < v2->x) &&
		(p->y > v1->y) && (p->y < v2->y) ){
		printf("O Ponto P(%i,%i) esta dentro do Retangulo(A,B).\n",
			p->x, p->y );
	} else printf("O Ponto P(%i,%i) esta fora do Retangulo(A,B).\n",
			p->x, p->y );
}