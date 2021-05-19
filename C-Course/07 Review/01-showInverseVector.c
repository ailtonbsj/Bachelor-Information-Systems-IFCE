#include <stdio.h>
#include <stdlib.h>

float numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

int printItem(float v[], unsigned length){
	if(length == 0) return 0;
	else {
		printf("%0.2f, ", v[length-1]);
		printItem(v, length-1);
	}
}

int main() {
	printItem(numbers, sizeof(numbers)/sizeof(float));
	printf("\n");
}