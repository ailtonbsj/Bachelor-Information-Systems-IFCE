# Primeira Avaliação de Programação Estruturada

## 01

Escreva uma função recursiva para determinar o máximo divisor comum de dois números inteiros positivos. Para realizar o cálculo deve-se usar o algoritmo de Euclides. Este algoritmo é baseado no fato de que se o resto da divisão (representado por r) de x por y for igual a zero, y é o MDC. Se o resto for diferente de zero, o MDC de x e y é igual ao MDC de y e r. O processo se repete até que o resto da divisão seja zero.

## 02

Escreva uma função recursiva para calcular e retornar o fatorial de um dado número.

## 03

Escreva uma função recursiva para mostrar (na ordem apresentada) e somar os 10 números inteiros de um vetor.

## 04

Crie uma estrutura para representar alunos de uma turma. Essa estrutura deve armazenar o nome do aluno, matricula (int), turma (caracter) e 3 notas. Crie um vetor para guardar 5 alunos.

1. Crie uma função que receba o vetor de alunos e seu tamanho e imprima o nome de todos os aprovados. A aprovação é alcançada com a média aritmética >= 7.
1. Crie uma função que receba o vetor de alunos, seu tamanho e a identificação da turma (letra), calcule a média geral da turma e imprima o nome dos alunos que obtiveram média acima da média da turma.

## 05

Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio R. Os valores calculados devem ser atribuídos aos parâmetros correspondentes. Essa função deve obedecer ao protótipo:

```c
void calc_esfera(float R, float *area, float *volume)
```

A área da superfície e o volume são dados, respectivamente, por:

```
A = 4 * π * R²
V = 4/3 * π * R³
Assuma π = 3.14
```