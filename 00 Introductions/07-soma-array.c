#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

/* Limpa buffer do teclado para Windows e Linux */
void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

int soma(int x, int y) {
	return x+y;
}

int main () {
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for(int i = 0; i < sizeof(nums)/sizeof(int)-1; i++) {
		nums[i] = soma(nums[i], nums[i+1]);
		printf("%i\n", nums[i]);
	}

	return 0;
}