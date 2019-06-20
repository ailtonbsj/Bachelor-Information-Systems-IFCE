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
void retira_inicio (lista *l);
void retira_final (lista *l);
```

## 05

Crie uma lista encadeada simples e funções para mostrar a lista, inserir e remover por posição.

## 06

Use a struct `produto (int codigoProduto, char nomeProduto[20], float valor, int qntEstoque)` juntamente com um lista simplesmente encadeada para resolver as questões abaixo:

- Faça uma função que busque o produto com o maior valor da lista e retorne sua posição.
- Faça uma função que imprima todos os produtos que possuem o estoque abaixo de 10 itens.
- Faça uma função que mostre quantos itens tem cadastrados na lista.
- Faça uma função que remova todos os produtos que possuem valor abaixo de R$ 5,00.

## 07

Considerando uma lista simplesmente encadeada, crie um struct para guardar dados de alunos (numero de matricula, nome). Utilize o elemento inicial (cabeça da lista ou descritor) da seguinte forma:

```c
struct descritor {
	struct Aluno *inicio;
	struct Aluno *fim;
	int qnt;
}
```

Faça os ajustes necessários para utilizar o descritor acima para as operações de inserção, consulta e remoção. Após a criação da lista, faça os ponteiros inicio e fim apontarem para NULL e qnt=0.

## 08

Use uma duplamente encadeada e crie uma função para verificar se a lista está ordenada ou não (em ordem crescente ou decrescente).
