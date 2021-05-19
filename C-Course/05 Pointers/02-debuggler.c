#include <stdio.h>

int main () {
	int a = 25;
	printf("----------\nDebug: a = %d\n-----------\n", a);
	int *pa = &a;
	printf("----------\nDebug: a = %d\n*pa = %p\n-----------\n", a, pa);
	int b = *pa + a;
	printf("----------\nDebug: a = %d\n*pa = %p\nb = %d\n-----------\n", a, pa, b);
	printf("%d %p %p %d %d %p\n", a, pa, &a, *pa, b, &b);
	return 0;
}