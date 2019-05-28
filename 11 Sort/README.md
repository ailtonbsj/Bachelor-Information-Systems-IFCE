# Ordenação bolha, seleção e inserção

## 01

Considerando o struct Funcionario (char nome[50], int dia, int mês). O dia e mês se referem à data de nascimento. Implemente uma função que receba um vetor do tipo Funcionario e o ordene em ordem crescente de dia de aniversário. Primeiro ordene pelo mês de nascimento. Caso o número do mês seja igual, ordene pelo dia. Utilize o algoritmo de ordenação da bolha.

## 02

Considerando um vetor de inteiros cujos valores estão armazenados em ordem crescente. Usando como base o algoritmo de busca binária, escreva uma função que, dado o vetor e um valor inteiro x, retorne o elemento do vetor que possui valor mais próximo de x. Caso x seja equidistante de dois elementos do vetor, sua função deve retornar o valor do menor deles. Por exemplo, considerando o vetor {3, 7, 10, 14, 16}, sua função deve retornar os valores indicados a seguir  para os diferentes casos listados.

Considere que o valor de x é maior ou igual ao primeiro elemento do vetor e menor ou igual ao último elemento do vetor. Sua função deve ter o seguinte protótipo:

```c
int mais_proximo(int *vet[], int tam, int x)
```

```
+------------+-----------------+
| Valor de x | Valor retornado |
+------------+-----------------+
|     11     |        10       |
+------------+-----------------+
|      5     |         3       |
+------------+-----------------+
|     14     |        14       |
+------------+-----------------+
|     13     |        14       |
+------------+-----------------+
```

## 03

Usando os métodos de ordenação estudados até agora, faça um teste de mesa utilizando as entradas abaixo:

- 11, 9, 7, 5, 3, 1
- 5, 7, 2, 8, 1, 6

## 04

Considerando o struct Aluno (char nome[50] e float media), ordene um vetor do tipo Aluno em ordem alfabética através do selection sort.

## 05

Faça com que o algoritmo insertionSort ordene um vetor de inteiros em ordem decrescente.

## 06

Aplique o algoritmo da bolha em uma string, ordenando as letras em ordem crescente.

## 07

Usando o vetor 72 12 62 69 27 67 41 56 33 74 e um algoritmo de insertion sort informe o número total de trocas necessárias para que o vetor se torne ordenado.
