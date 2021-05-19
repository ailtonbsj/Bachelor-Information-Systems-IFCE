# Clinic Manager & UserTerminal

> Testado no Windows 7 com CodeBlocks e Lubuntu 20.04 com GCC

## Descrição da Questão

Faça uma programa para gerenciar a distribuição de senha de atendimento de uma clínica. O programa deve ter as seguinte funcionalidades:

1. Gerar senha de atendimento; ✓
2. Controlar a fila de senhas de atendimento, podendo:
    1. Liberar senha para atendimento (realizar atendimento); ✓
    2. Cancelar senha de atendimento; ✓
    3. Desfazer o cancelamento de uma senha de atendimento; ✓
    4. Listar as senhas que estão esperando atendimento; ✓
3. Listar as senhas que já foram atendidas; ✓

*Extra*: Criar um algoritmo que possa ser atribuído prioridades as senhas e o atendimento seja feito de acordo com a seguinte regra de atendimento:

- Para cada 1 atendimento normal, caso haja, 2 atendimentos com prioridade deve ser atendido.

*Fala do Cliente*: Preciso de um sistema que possa controlar as senhas de atendimento da minha clínica. Este programa deve possuir uma opção para que o usuário possa escolher o serviço que deseja atendimento e então receba uma senha. Deve ter uma função para chamar a primeira senha na fila de espera de atendimento. Também deve ter funções para cancelar uma senha gerada ou recuperar uma senha que tenha sido cancelada. Além disso, preciso acompanhar as senha que aguardam atendimento e as que já foram atendidas. ✓

*Codificação*: Utilize lista, fila e pilha, todas encadeadas.