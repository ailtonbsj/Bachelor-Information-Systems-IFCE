#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

unsigned includes(int arr[], unsigned len, int num) {
	unsigned cont = 0;
	for (int i = 0; i < len; i++) {
		if(arr[i] == num) cont++;
	}
	return cont;
}

int main () {
	int arr[] = {1, 2, 3, 2, 3, 4, 2, 3, 5, 3, 5};
	int search = 3;
	printf("O %i aparece %u vezes.\n",
		search,
		includes(arr, sizeof(arr)/sizeof(int), search));

	return 0;
}