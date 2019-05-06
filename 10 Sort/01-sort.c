#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

void showArray(int *v, int len) {
	printf("[ ");
	for (int i = 0; i < len; ++i) {
		if(i != 0) printf(" ,");
		printf("%i", v[i]);
	}
	printf(" ]\n");
}

void oneSort(int *v, int len) {
	for (int i = 0; i < len-1; i++)	{
		if(v[i] > v[i+1]) {
			int aux = v[i];
			v[i] = v[i+1];
			v[i+1] = aux;
		}
	}
}

void sort(int *v, int len){
	for (int i = 0; i < len; ++i) {
		oneSort(v, len);
		showArray(v, len);
	}
}

int main () {

	int arr[] = {7, 4, 3, 1, 5, 2, 6};
	showArray(arr, sizeof(arr)/sizeof(int));
	sort(arr, sizeof(arr)/sizeof(int));

	return 0;
}