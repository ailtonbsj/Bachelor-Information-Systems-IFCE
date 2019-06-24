# Lista de Exercícios

> Compilado no Linux versão 64 bits

## 01

Faça um algoritmo para organizar a fila de atendimentos de um hospital. Os pacientes são atendidos de acordo com a urgência no atendimento (1-> Emergência; 2-> Urgência; 3-> Pouco urgente; 4->Não urgente). O hospital mantêm um registro de todos os pacientes atendidos com: cpf (identificador), nome, data de nascimento e todos os atendimentos realizados (histórico de saúde) do paciente.
Quando um paciente chega para ser atendido, uma prioridade é definida para seu atendimento. Em um atendimento é registrado a data e hora do atendimento, o nome do médico e o diagnóstico. Para auxiliar no diagnóstico, mostre os últimos 3 atendimentos do paciente (caso existam). Ao final do atendimento, esse registro é guardado no histórico do paciente.

![](01-hospitalSystem.gif?raw=true)

## 02

Escalonamento por alternância circular (Round Robin).

- A cada processo é atribuído um intervalo de tempo, o quantum, no qual ele é permitido executar;
- Se no final do quantum o processo não terminou, a CPU sofre uma preempção e outro processo entra para executar;
- Quando um processo termina o seu quantum, ele é colocado no final da fila

#### Como compilar

Use o terminal:
```bash
gcc 02-processos.c -l pthread -o 02-processos
```

#### Como executar

Use o terminal:
```bash
./02-processos
```

## 03

Crie um algoritmo para gerenciar 2 pilhas dentro de um vetor ao mesmo tempo de modo que não ocorra estouro de memória e os valores de uma pilha não sobreponham os valores da outra.
