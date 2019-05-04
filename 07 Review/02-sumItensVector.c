#include <stdio.h>
#include <stdlib.h>

float numbers[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

float sumItem(float v[], unsigned length){
	if(length == 0) return 0;
	else {
		return v[length-1] + sumItem(v, length-1);
	}
}

int main() {
	float res = sumItem(numbers, sizeof(numbers)/sizeof(float));
	printf("Somatório: %0.2f\n", res);
}