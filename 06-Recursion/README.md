# Exercícios da Aula 06

## 01

Soma dos N primeiros números. Exemplo:
```
Soma(5) = 5 + 4 + 3 + 2 + 1
Soma(4) = 4 + 3 + 2 + 1
```

## 02

Calcule uma função recursiva que receba 2 números (x e n) e calcule x<sup>n</sup>.
- Caso base: x<sup>0</sup> = 1
- Caso geral: x<sup>n</sup> = x * x<sup>n-1</sup>

## 03

Usando recursividade, calcule a soma de todos os valores de um array de inteiros.
- Caso base → tamanho do array = 0; soma = 0
- Caso geral → v[n-1] + soma(v, n-1)
