# Exercícios da Aula 03

## 01

Defina um struct para uma pessoa com os dados: `Nome, Idade, CPF, Salário`.

Resposta:
```c
struct Pessoa {
	char nome[255];
	unsigned idade;
	char cpf[11];
	float salario;
}
```

## 02

Criar uma estrutura para armazenar os dados de um funcionário:
- num_funcionario → int
- Salario → double
- data_contratacao → data: (dia, mês, ano)

Resposta:
```c
struct Funcionario {
	int num_funcionario;
	double salario;
	struct Data {
		unsigned dia;
		unsigned mes;
		unsigned ano;
	}
}
```

## 03

Crie uma estrutura com os dados de um aluno:
- Código (inteiro)
- Nome (string, 50 caracteres)
- N1, N2, N3 (notas, float)

Resposta:
```c
struct Aluno {
	int codigo;
	char nome[50];
	float n1, n2, n3;
}
```

## 04

Utilize a struct de aluno declarada anteriormente. Crie um vetor com 5 alunos e preencha os dados. Imprima todos os dados da struct. Percorra o vetor declarado, calculando a média aritmética de cada um dos alunos.

