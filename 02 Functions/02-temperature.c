#include <stdio.h>
#include <stdlib.h>

float temperConvert(float value, char mode){
  if(mode == 'C')
    return (value*9/5)+32;
  else if(mode == 'F')
    return (value-32) * 5/9;
  else {
  	printf("\n\nError!!!\n\n");
    exit(1);
  }
}

int main() {
  float value, result;
  char mode;
  printf("Digite o valor da temperatura: ");
  scanf("%f", &value);
  printf("Digite o formato da temperatura (C ou F):");
  scanf(" %c", &mode);
  result = temperConvert(value, mode);
  printf("Resultado eh: %10.2f\n\n", result);
}
