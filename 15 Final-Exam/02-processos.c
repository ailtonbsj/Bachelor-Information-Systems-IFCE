#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct processo {
	int pid;
	int quantum;
} Processo;

int totalDeProcessos = 0;
int processoAtual = 0;
Processo **fila;

Processo *criaProcesso(Processo **fila, int pid, int quantum) {
	totalDeProcessos++;
	Processo *p = (Processo*) malloc(sizeof(Processo));
	p->pid = pid;
	p->quantum = quantum;
	fila[totalDeProcessos-1] = p;
	printf("Processo %i iniciado!\n", pid);
	return p;
}

int timeout = 20;
void cpu() {
	fila = (Processo**) malloc(sizeof(Processo*));
	criaProcesso(fila, 1, 1);
	criaProcesso(fila, 2, 4);
	criaProcesso(fila, 3, 7);
	while(1) {
		printf("Executando processo %i\n", fila[processoAtual]->pid);
		if(!timeout--) criaProcesso(fila, 4, 5);
		sleep(1);
	}
}

/* Simulacao Interrupcao por Relogio do Sistema com pseudo thereading */
void* relogio(void* args) {
	int tempo = 0;
    while(1) {
    	if(tempo > 0) tempo--;
    	else {
   			processoAtual++;
   			if(processoAtual >= totalDeProcessos) processoAtual = 0;
			tempo = fila[processoAtual]->quantum;
    	}
    	sleep(1);
    }
}

int main() {
    pthread_t id;
    int ret = pthread_create(&id,NULL,&relogio,NULL);
    if(ret) printf("Erro ao criar Thread!"), exit(1);
    cpu();
    return 0;
}
