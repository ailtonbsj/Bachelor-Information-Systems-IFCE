#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.c"
#include "services.c"
#include "queue.c"

// Ponteiros globais da Lista de Servico e Fila de Atendimento
Service *serviceHead = NULL;
Queues *queues = NULL;

// Guarda ultima chave(senha) atendida ou cancelada
int lastKey = -1;

/* Escreve na Tela a Lista de servicoes e exibe opcoes de
Adicionar ou excluir servico a Lista encadeada e grava em arquivo */
void servicesMenu()
{
    enum
    {
        ADD = '1',
        REMOVE = '2',
        GOBACK = '3'
    } menu;
    char name[50];
    bool goBack = false;
    while (!goBack)
    {
        clearTerminal();
        printf("Servicos atualmente adicionados:\n\n");
        listService(serviceHead);
        printf("\n\nOpcoes: [1] Adicionar [2] Apagar [3] Voltar\n");
        printf("Digite uma opcao: ");

        char option = pressAnyKey();
        switch (option)
        {
        case ADD:
            printf("\n\nDigite um novo nome de servico: ");
            rawInput(name, sizeof(name) / sizeof(char));
            serviceHead = addService(serviceHead, name);
            putStorageService(serviceHead, SERVICES_FILE);
            break;
        case REMOVE:
            printf("\n\nDigite o nome de servico: ");
            rawInput(name, sizeof(name) / sizeof(char));
            Service *item = getService(serviceHead, name);
            serviceHead = removeService(serviceHead, item);
            putStorageService(serviceHead, SERVICES_FILE);
            break;
        case GOBACK:
            goBack = true;
            break;
        default:
            invalidOption();
        }
    }
}

/* Escreve na tela ultimo item com status de espera
e exibe opcoes de Atender e Cancelar */
void doCheckIn()
{
    char option;
    queues = getStorageQueue(queues, QUEUES_FILES);
    clearTerminal();
    Queue *curr = NULL;
    curr = firstQueueByStatus(queues->tail, WAIT);
    if (curr == NULL)
    {
        printf("\n\nNao ha usuarios em espera!\n\n");
        pressAnyKey();
    }
    else
    {
        printf("Por favor usuario de senha abaixo compareca a recepcao.\n");
        printf("\n\nSenha: %010d\n", atoi(curr->key));
        printf("Servico: %s\n\n\n", curr->service);
        printf("Opcoes: [1] Realizar atendimento [2] Cancelar atendimento [3] Voltar\n\n");
        printf("Digite uma opcao: ");
        option = pressAnyKey();
        if (option == '1')
        {
            curr->status = READY;
            putStorageQueue(queues->tail, QUEUES_FILES);
            lastKey = atoi(curr->key);
        }
        else if (option == '2')
        {
            curr->status = CANCELED;
            putStorageQueue(queues->tail, QUEUES_FILES);
            lastKey = atoi(curr->key);
        }
        else if (option == '3')
            return;
        else
        {
            invalidOption();
        }
    }
}

// Escreve na Tela a lista de atendimentos cancelados com opcao de desfazer
void undoCancelView()
{
    char option;
    bool goBack = false;
    char key[50];
    Queue *curr;
    while (!goBack)
    {
        queues = getStorageQueue(queues, QUEUES_FILES);
        clearTerminal();
        printf("Filas de senhas canceladas:\n\n");
        printf(" Chave    Servico                          Prioridade   Estado    \n");
        printf(" -------+--------------------------------+------------+-----------\n");
        if (!listQueueByStatus(queues->head, CANCELED, false))
            printf("Lista vazia!\n");
        printf("\n\nOpcoes: [1] Desfazer cancelamento [2] Voltar\n");
        printf("Digite uma opcao: ");
        option = pressAnyKey();
        if (option == '1')
        {
            printf("Digite a senha para desfazer o cancelamento: ");
            rawInput(key, sizeof(key) / sizeof(char));
            curr = getQueueBykey(queues->tail, key);
            if (curr != NULL)
            {
                curr->status = WAIT;
                putStorageQueue(queues->tail, QUEUES_FILES);
            }
            else
                invalidOption();
        }
        else if (option == '2')
            goBack = true;
        else
            invalidOption();
    }
}

// Exibe a Tela Inicial com Menus
void initialMenu()
{
    enum
    {
        SERVICES = '1',
        CHECKIN = '2',
        LIST_CANCELED = '3',
        LIST_READY = '4',
        LIST_WAIT = '5',
        LIST_QUEUE = '6',
        GOBACK = '7'
    } menu;
    bool goBack = false;

    // Loop infitino para so fechar o app se escolher no menu
    while (!goBack)
    {
        clearTerminal();
        printf("Bem vindo ao Clinic Manager!\n\n\n");
        if (lastKey == -1)
            printf("Ultima senha chamada: NENHUMA\n\n\nOpcoes:\n");
        else
            printf("Ultima senha chamada: %010d\n\n\nOpcoes:\n", lastKey);
        printf("1 - Gerenciar Servicos\n");
        printf("2 - Realizar/Cancelar Atendimento\n");
        printf("3 - Desfazer cancelamento\n");
        printf("4 - Listar Atendidos\n");
        printf("5 - Lista de espera\n");
        printf("6 - Listar toda a fila\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");

        char option = pressAnyKey();
        switch (option)
        {
        case SERVICES:
            servicesMenu();
            break;
        case CHECKIN:
            doCheckIn();
            break;
        case LIST_CANCELED:
            undoCancelView();
            break;
        case LIST_READY:
            queues = getStorageQueue(queues, QUEUES_FILES);
            clearTerminal();
            printf("Atendimentos ja realizados:\n\n");
            printf(" Chave    Servico                          Prioridade   Estado    \n");
            printf(" -------+--------------------------------+------------+-----------\n");
            listQueueByStatus(queues->head, READY, false);
            pressAnyKey();
            break;
        case LIST_WAIT:
            queues = getStorageQueue(queues, QUEUES_FILES);
            clearTerminal();
            printf("Fila de espera registrada:\n\n");
            printf(" Chave    Servico                          Prioridade   Estado    \n");
            printf(" -------+--------------------------------+------------+-----------\n");
            listQueueByStatus(queues->head, WAIT, false);
            pressAnyKey();
            break;
        case LIST_QUEUE:
            queues = getStorageQueue(queues, QUEUES_FILES);
            clearTerminal();
            printf("Fila completa registrada:\n\n");
            printf(" Chave    Servico                          Prioridade   Estado    \n");
            printf(" -------+--------------------------------+------------+-----------\n");
            listQueue(queues->head);
            pressAnyKey();
            break;
        case GOBACK:
        {
            goBack = true;
            break;
        }
        default:
            invalidOption();
        }
    }
}

void main()
{

    // Ler arquivo service.txt e atualiza a Lista de servicos
    serviceHead = getStorageService(serviceHead, SERVICES_FILE);
    // Cria uma Fila de Atendimento
    queues = newQueues(queues);
    // Ler arquivo queue.cvs e atualiza a Pilha de atendimentos
    queues = getStorageQueue(queues, QUEUES_FILES);
    // Chama tela inicial com Menu
    initialMenu();
}
