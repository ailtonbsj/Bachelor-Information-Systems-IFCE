# Lista de Exercícios

> Compilado no Linux versão 64 bits

## 01

Faça um algoritmo para organizar a fila de atendimentos de um hospital. Os pacientes são atendidos de acordo com a urgência no atendimento (1-> Emergência; 2-> Urgência; 3-> Pouco urgente; 4->Não urgente). O hospital mantêm um registro de todos os pacientes atendidos com: cpf (identificador), nome, data de nascimento e todos os atendimentos realizados (histórico de saúde) do paciente.
Quando um paciente chega para ser atendido, uma prioridade é definida para seu atendimento. Em um atendimento é registrado a data e hora do atendimento, o nome do médico e o diagnóstico. Para auxiliar no diagnóstico, mostre os últimos 3 atendimentos do paciente (caso existam). Ao final do atendimento, esse registro é guardado no histórico do paciente.

![](01-hospitalSystem.gif?raw=true)

## 03

Crie um algoritmo para gerenciar 2 pilhas dentro de um vetor ao mesmo tempo de modo que não ocorra estouro de memória e os valores de uma pilha não sobreponham os valores da outra.
