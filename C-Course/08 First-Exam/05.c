/* JOSE AILTON BATISTA DA SILVA */

#include <stdio.h>

void calc_esfera(float R, float *area, float *volume){
	*area = 4 * 3.14 * (R * R);
	*volume = (4.0/3.0) * 3.14 * (R * R * R);
}

int main () {
	float area, vol;
	calc_esfera(2, &area, &vol);
	printf("Esfera tem raio 2.\n");
	printf("Area: %f\nVolume: %f\n", area, vol);
	return 0;
}