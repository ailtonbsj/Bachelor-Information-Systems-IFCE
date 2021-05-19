# Exercícios da Aula 05

## 01

Crie um algoritmo para guardar informações de até 10 pessoas. As informações armazenadas são: nome, a altura e da data de nascimento.

A data de nascimento deve ser gerada aleatoriamente com a função rand(), de acordo com a função abaixo, fazendo uso de ponteiros:
```c
void criaData(Data *D) {
   (*D).Mes = 1 + (rand() % 12);
   (*D).Ano = 1950 + (rand() % 49);
   (*D).Dia = 1 + (rand() % 30);
}
```
Quando o programa iniciar, um menu deve ser exibido com as seguintes opções:
```
(1) inserir uma pessoa
(2) listar todos os dados armazenados
(3) listas as pessoas nascidas em um dia específico (pedir ao usuário ex.: lista dos que nasceram dia 15)
```

## 02

Crie um algoritmo com o código abaixo. Qual a saída esperada? Qual o significado para cada um dos valores? Desenhe uma pilha de execução.
```c
int a = 25;
int *pa = &a;
int b = *pa + a;
printf("%d %p %p %d %d %p\n", a, pa, &a, *pa, b, &b);
```

## 03

Crie um programa para calcular a área e o perímetro de um retângulo. Use o prototipo de função: 
`void calculaAreaRetangulo(float base, float altura, floar *area, float *perimetro);`
