#include <stdio.h>
#include <stdlib.h>

int nums[] = {1, 2, 3, 4, 3, 2, 1};

int maior (int v[], int len, int major) {
	if(len == 0) return major;
	else
		return maior(v, len-1, v[len] > major ? v[len] : major);
}

int main() {
	printf("O maior item eh: %i\n",
		maior(nums, sizeof(nums)/sizeof(int), -99999));
}