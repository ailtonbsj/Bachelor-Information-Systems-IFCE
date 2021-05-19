// Nome do arquivo onde Lista é armazeanda
#define SERVICES_FILE "services.txt"
#define MAXLINE_SERVICE 150


// Estrutura da List encadeada de Serviço
typedef struct service
{
    char name[50];
    struct service *next;
} Service;

// Adiciona novo serviço a Lista, alocando memoria e atualizando a cabeça da Lista
Service *addService(Service *oldHead, char name[])
{
    Service *item = (Service *)malloc(sizeof(Service));
    strcpy(item->name, name);
    item->next = oldHead;
    return item;
}

// Obtem um item da Lista de serviço buscando por nome de forma recursiva
Service *getService(Service *head, char name[])
{
    if (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
            return head;
        else
        {
            if (head->next != NULL)
                return getService(head->next, name);
            else
                return NULL;
        }
    }
    return NULL;
}

// Obtem um item da Lista de serviço buscando por indice de forma recursiva
Service *getServiceByIndex(Service *head, int index)
{
    if (head != NULL)
    {
        if (index == 0) return head;
        else
        {
            if (head->next != NULL)
                return getServiceByIndex(head->next, index-1);
            else
                return NULL;
        }
    }
    return NULL;
}

// Escreve na tela toda a Lista de Serviços de forma recursiva
void listService(Service *head)
{
    if (head != NULL)
    {
        printf("- %s\n", head->name);
        if (head->next != NULL)
            listService(head->next);
    }
    else
        printf("Lista vazia\n");
}

// Escreve na tela toda a Lista de serviços de forma numerada por indice
int listServiceByindex(Service *head, int index)
{
    if (head != NULL)
    {
        printf("%d - %s\n", index, head->name);
        if (head->next != NULL)
            return listServiceByindex(head->next, index + 1);
        else
            return index;
    }
    else
        return 0;
}

// Remove um item da Lista de serviços, libera a memoria e atualiza o ponteiro proximo
Service *removeService(Service *head, Service *item)
{
    if (head != NULL && item != NULL)
    {
        if (head == item)
            head = item->next;
        else
        {
            Service *previous = head;
            while (previous->next != item)
                previous = previous->next;
            previous->next = item->next;
        }
        free(item);
        return head;
    }
}

// Salva toda Lista de serviço em um arquivo, cada linha representa um item de serviço
void putStorageService(Service *head, char fileName[])
{
    FILE *fp;
    fp = fopen(fileName, "w");
    if (head != NULL)
    {
        Service *item = head;
        do
        {
            fputs(item->name, fp);
            fputs("\n", fp);
            item = item->next;

        } while (item != NULL);
    }
    fclose(fp);
}

// Ler o arquivo e popula a Lista de serviços
Service *getStorageService(Service *head, char fileName[])
{
    char line[MAXLINE_SERVICE] = {0};
    FILE *fp;
    fp = fopen(fileName, "r");
    if (!fp)
    {
        putStorageService(head, fileName);
        return head;
    }
    while (fgets(line, MAXLINE_SERVICE, fp))
    {
        strtok(line, "\n");
        head = addService(head, line);
    }
    fclose(fp);
    return head;
}
