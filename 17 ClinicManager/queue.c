// Nome do arquivo onde Fila é armazeanda
#define QUEUES_FILES "queue.csv"
#define MAXLINE_QUEUE 150

// Define tipos de prioridades do atendimento NORMAL ou ALTA
typedef enum
{
    NORMAL,
    HIGH
} Priority;

// Define tipos de estatos do atendimento ESPERANDO, ATENDIDO E CANCELADO
typedef enum
{
    WAIT,
    READY,
    CANCELED
} Status;

// Estrutura da Lista duplamente encadeada que define um item da Fila
typedef struct queue
{
    char key[50];
    char service[50];
    Priority type;
    Status status;
    struct queue *previous;
    struct queue *next;
} Queue;

// Estrutura representa a Fila com ponteiros cabeça e calda
typedef struct queues
{
    Queue *head;
    Queue *tail;
} Queues;

// Inicializa um Fila alocando memoria para os 2 ponteiros
Queues *newQueues(Queues *queues)
{
    queues = (Queues *)malloc(sizeof(Queues));
    queues->head = NULL;
    queues->tail = NULL;
    return queues;
}

/* Cria um item da Fila passando chave, serviço, prioridade e estado, alocando memoria e
   atualizando a cabeça da Fila */
Queue *addQueue(Queue *oldHead, char key[], char service[], Priority type, Status status)
{
    Queue *item = (Queue *)malloc(sizeof(Queue));
    strcpy(item->key, key);
    strcpy(item->service, service);
    item->type = type;
    item->status = status;
    item->next = oldHead;
    item->previous = NULL;
    if (oldHead != NULL)
        oldHead->previous = item;
    return item;
}

// Escreve na tela todos os item da Fila de atendimento
void listQueue(Queue *head)
{
    if (head != NULL)
    {
        char statusChar[50];
        if (head->status == WAIT)
            strcpy(statusChar, "Esperando");
        else if (head->status == READY)
            strcpy(statusChar, "Atendido");
        else if (head->status == CANCELED)
            strcpy(statusChar, "Cancelado");
        printf(
            " %05d    %-30s   %-8s     %-10s\n",
            atoi(head->key), head->service,
            head->type == 0 ? "NORMAL" : "ALTA",
            statusChar);
        if (head->next != NULL)
            listQueue(head->next);
    }
    else
        printf("Lista vazia\n");
}

// Escreve na tela todos os itens da Fila de atendimento filtrada por status
bool listQueueByStatus(Queue *head, Status status, bool hasItens)
{
    if (head != NULL)
    {
        char statusChar[50];
        if (head->status == WAIT)
            strcpy(statusChar, "Esperando");
        else if (head->status == READY)
            strcpy(statusChar, "Atendido");
        else if (head->status == CANCELED)
            strcpy(statusChar, "Cancelado");

        if (head->status == status)
        {
            printf(
                " %05d    %-30s   %-8s     %-10s\n",
                atoi(head->key), head->service,
                head->type == 0 ? "NORMAL" : "ALTA",
                statusChar);
            hasItens = true;
        }
        if (head->next != NULL)
            return listQueueByStatus(head->next, status, hasItens);
    } else {
        hasItens = true;
        printf("Lista vazia\n");
    }
    return hasItens;
}

/* Grava em arquivo todos os itens da Fila de atendimento. Cada variavel da estrutura é
salvo separadas por virgula. O tipo e estado de atendimento é salvo como um inteiro */
void putStorageQueue(Queue *tail, char fileName[])
{
    FILE *fp;
    fp = fopen(fileName, "w");
    if (tail != NULL)
    {
        Queue *item = tail;
        do
        {
            fprintf(fp, "%s,%s,%d,%d\n", item->key, item->service, item->type, item->status);
            item = item->previous;

        } while (item != NULL);
    }
    fclose(fp);
}

// Remove todos os itens da Fila de atendimento de forma recursiva e desalocando memória
Queue *removeAllQueue(Queue *head) {
    if(head != NULL) {
        Queue *next = head->next;
        free(head);
        if(next != NULL) removeAllQueue(next);
    }
    return NULL;
}

/* Ler arquivo e popula a Fila de atendimento. Cada linha no arquivo
  é lido como string depois explodido e salvo no item de Fila */
Queues *getStorageQueue(Queues *queues, char fileName[])
{
    bool isFirst = false;
    char line[MAXLINE_QUEUE] = {0};
    char key[50], service[50];
    Priority type;
    Status status;
    FILE *fp;
    fp = fopen(fileName, "r");
    // Se arquivo nao existir o if abaixo cria ele
    if (!fp)
    {
        putStorageQueue(queues->head, fileName);
        return queues;
    }
    queues->head = removeAllQueue(queues->head);
    queues->tail = queues->head;
    while (fgets(line, MAXLINE_QUEUE, fp))
    {
        char *token;
        strtok(line, "\n");
        strcpy(key, strtok(line, ","));
        strcpy(service, strtok(NULL, ","));
        type = atoi(strtok(NULL, ","));
        status = atoi(strtok(NULL, ","));
        if (queues->head == NULL)
            isFirst = true;
        queues->head = addQueue(queues->head, key, service, type, status);
        if (isFirst)
        {
            queues->tail = queues->head;
            isFirst = false;
        }
    }
    fclose(fp);
    return queues;
}

/* Pega o primeiro item da Fila tenha determinado status,
para ser mais rapido a busca acontece da calda para a cabeça */
Queue *firstQueueByStatus(Queue *tail, Status status)
{
    if (tail != NULL)
    {
        if (tail->status == WAIT)
            return tail;
        else
        {
            if (tail->previous != NULL)
                return firstQueueByStatus(tail->previous, status);
            else
                return NULL;
        }
    }
    return NULL;
}

// Pega o item da Fila que tenha determinada chave(senha)
Queue *getQueueBykey(Queue *tail, char key[])
{
    if (tail != NULL)
    {
        if (strcmp(tail->key, key) == 0) return tail;
        else
        {
            if (tail->previous != NULL)
                return getQueueBykey(tail->previous, key);
            else
                return NULL;
        }
    }
    return NULL;
}
