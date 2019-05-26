#include <stdio.h>

double diver(double val){
	double ans = 1;
	for(int i = 1; i < val; i++){
		ans += 1.0/i;
	}
	return ans;
}

int main(){
	printf("%f\n", diver(1));
	printf("%f\n", diver(2));
	printf("%f\n", diver(3));
	printf("%f\n", diver(4));
	printf("%f\n", diver(5));
	printf("%f\n", diver(6));
	printf("%f\n", diver(20));
	printf("%f\n", diver(100));
	printf("%f\n", diver(1000));
	printf("%f\n", diver(10000));
	printf("%f\n", diver(100000));
	printf("%f\n", diver(10000000));
	printf("%f\n", diver(100000000));
	printf("%f\n", diver(1000000000));
	return 0;
}