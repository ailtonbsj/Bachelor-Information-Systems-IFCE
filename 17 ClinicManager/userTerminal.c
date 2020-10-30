#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.c"
#include "services.c"
#include "queue.c"

// Ponteiros globais da Lista de Serviço e Fila de Atendimento
Service *serviceHead = NULL;
Queues *queues = NULL;

// Exibe a Tela de escolha de servico e gera nova senha
void generateKeyView()
{
    int lenService = 0, numOption;
    char option[50];
    bool goBack = false, isfirst = false;
    // Loop Infinito enquanto não escolher opção Sair
    while (!goBack)
    {
        queues = getStorageQueue(queues, QUEUES_FILES);
        clearTerminal();
        printf("\n\nPara qual servico voce deseja atendimento ?\n\n");
        lenService = listServiceByindex(serviceHead, 1);
        if (lenService == 0)
        {
            printf("\n\nO sistema nao contem servicos!\n\n");
            pressAnyKey();
            exit(1);
        }
        printf("%d - Voltar\n", lenService+1);
        printf("\n\nDigite a sua escolha: ");
        rawInput(option, sizeof(option) / sizeof(char));
        numOption = atoi(option);
        if (numOption > 0 && numOption <= lenService)
        {
            int key = 0;
            char keyChar [50];
            Service *serviceChoosed = NULL;
            serviceChoosed = getServiceByIndex(serviceHead, numOption-1);
            if(queues->head != NULL) key = atoi(queues->head->key) + 1;
            sprintf(keyChar, "%d", key);
            if(queues->head == NULL) isfirst = true;
            queues->head = addQueue(queues->head, keyChar, serviceChoosed->name, NORMAL, WAIT);
            if(isfirst) {
                queues->tail = queues->head;
                isfirst = false;
            }
            putStorageQueue(queues->tail, QUEUES_FILES);
            clearTerminal();
            printf("\n\nSua senha de espera eh:\n\n");
            printf("SENHA: %010d\n", key);
            printf("SERVICO: %s\n\n", serviceChoosed->name);
            printf("Pressione qualquer tecla para voltar para o inicio...");
            pressAnyKey();
            goBack = true;
        }
        else if(numOption == lenService+1) goBack = true;
        else
            invalidOption();
    }
}

// Exibe a Tela Inicial com Menu Voltar e Gerar Nova Senha
void initialMenuView()
{
    enum
    {
        GENERATE_KEY = '1',
        GOBACK = '2'
    } menu;

    char option;
    bool goBack = false;
    while (!goBack)
    {
        clearTerminal();
        printf("Bem vindo ao Clinic Manager!\n\n");
        printf("Escolha uma opcao:\n\n");
        printf("%c - Gerar Senha de espera\n", GENERATE_KEY);
        printf("%c - Sair\n\n", GOBACK);
        printf("Digite sua opcao: ");
        option = pressAnyKey();
        switch (option)
        {
        case GENERATE_KEY:
            generateKeyView();
            break;
        case GOBACK:
            goBack = true;
            break;
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
    initialMenuView();
}