# Lista de Exercícios

> Compilado no Linux versão 64 bits

## 01

Implemente uma função que tenha como valor de retorno o comprimento de uma lista encadeada, isto é, que calcule o número de nós de uma lista. Essa função deve obedecer ao protótipo:

```c
int comprimento (Lista * lista)
```

## 02

Considerando listas de valores inteiros, implemente uma função que receba como parâmetros uma lista encadeada e um valor inteiro x e retire da lista todas as ocorrências de x. Essa função deve obedecer ao protótipo:

```c
void retira_n (Lista *l, int x)
```

## 03

Implemente uma função que construa uma nova lista, intercalando os nós de outras duas listas passadas como parâmetros. Essa função deve retornar a nova lista resultante, criada dentro da função, conforme ilustrado abaixo. Ao final da função, as listas originais
devem ficar vazias e ser liberadas. Se uma lista tiver mais elementos que a outra, os elementos excedentes são transferidos na mesma ordem para a nova lista. Essa função deve obedecer ao protótipo:

```c
Lista* merge (Lista *l1, Lista* l2)
```

```
lista1 --> [2]->[4]->[1]->NULL  lista2 --> [7]->[3]->[9]->NULL
                               |
                               |
                               | merge(l1, l2)
                               |
                               |
                               v
               [2]->[7]->[4]->[3]->[1]->[9]->NULL
```

## 04

Implemente as funções para retirar elementos do início e do final de uma lista encadeada simples. Os protótipos das funções devem ser:

```c
void retira_inicio (lista *l)
void retira_final (lista *l)
```

## 05

Crie uma lista encadeada simples e funções para mostrar a lista, inserir e remover por posição.
