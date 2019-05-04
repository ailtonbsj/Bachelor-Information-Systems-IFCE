#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int somatorio(int n, int first){
	if(n == 0) return 0;
	else {
		if(first != 0) printf("+");
		printf(" %d ", n);
		return n + somatorio(n-1, 1);
	}
}

int main() {
	printf(" = %d\n\n", somatorio(10, 0));
	return 0;
}