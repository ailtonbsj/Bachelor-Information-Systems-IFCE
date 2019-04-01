# Exercícios da Aula 07

## 01

Escreva uma função recursiva para mostrar de traz para frente todos os elementos de um vetor de números reais.

## 02

Escreva uma função para calcular a soma de todos os valores de um vetor de números reais.

## 03

Escreva uma função recursiva para calcular e mostrar o maior elemento de um array de inteiros.

## 04

Crie um struct para representar um compromisso de uma agenda. Cada compromisso possui um texto que descreve o que irá ser feito; um local onde ocorrerá; uma data (dia, mês, ano) e um horário (hora, minutos, segundos).

## 05

Crie um struct para guardar dados de carros de uma concessionaria. Cada carro possui uma marca, modelo, ano de fabricação, preço. Faça buscas no array que guarda os dados mostrando os carros, por exemplo, da marca ‘toyota’, ano de fabricação = 2015 e preço < 60000.

## 06

Escreva um algoritmo que leia dois valores inteiros e chame uma função que receba estes 2 valores de entrada e retorne o maior valor na primeira variável e o menor valor na segunda variável.

## 07

Escreva uma função para separar a parte inteira e a parte fracionária de um número real, seguindo o protótipo: `void divide(float num, int *inteira, float *frac);`.

## 08

Considere uma struct que representa um ponto no plano cartesiano:
```c
struct Ponto {
	int x;
	int y;
}
```
Com essa estrutura podemos mapear um retângulo com a utilização de 2 pontos: um vértice inferior esquerdo v1 e outro superior direito v2.

Crie uma função para descobrir se um dado ponto está dentro ou fora do retângulo. Caso esteja dentro, retorne 1; senão, retorne 0.

Use o protótipo abaixo: `int dentroRet (struct Ponto* v1, struct Ponto* v2, struct Ponto* p);`.

```
  ʌ
 7|       * M(2,7)
  |
 6|   +------------------------+ v2 (7,6)
  |   |                        |
 5|   |                        |
  |   |                        |
 4|   |           * P(4,4)     |
  |   |                        |
 3|   |                        |
  |   |                        |
 2|   +------------------------+
  |   v1 (1,2)
 1|                                 * G(8,1) 
  |
  +-------------------------------------->
  0   1   2   3   4   5   6    7    8    
```