#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

/* UTILS */

char* strupr(char* s) {
	char* tmp = s;
	for (;*tmp;++tmp)
		*tmp = toupper((unsigned char) *tmp);
    return s;
}

/* Limpa buffer do teclado para Windows e Linux */
void clearBufferKey() {
	#ifdef _WIN32
		fflush(stdin);
	#elif linux
		__fpurge(stdin);
	#endif
}

/* Pega strings do teclado sem gerar problemas */
void rawInput(char *buf, unsigned int size) {
	fgets(buf, size, stdin);
	buf[strlen(buf)-1] = '\0';
	clearBufferKey();
}

/* Limpa o terminal completamente */
#define clearTerminal() printf("\033[H\033[J")

/* DATA */

typedef struct data {
	int dia;
	int mes;
	int ano;
} Data;

Data* criaData(int dia, int mes, int ano) {
	Data *d = (Data*) malloc(sizeof(Data));
	d->dia = dia;
	d->mes = mes;
	d->ano = ano;
	return d;
}

char* mostraData(Data *d) {
	char *cats = (char*) malloc(15*sizeof(char));
	sprintf(cats, "%02d/%02d/%02d", d->dia, d->mes, d->ano);
	return cats;
}

/* HORARIO */

typedef struct horario {
	int hora;
	int minuto;
} Horario;

Horario* criaHorario(int hora, int min) {
	Horario *h = (Horario*) malloc(sizeof(Horario));
	h->hora = hora;
	h->minuto = min;
	return h;
}

char* mostraHorario(Horario *h) {
	char *cats = (char*) malloc(8*sizeof(char));
	sprintf(cats, "%02d:%02d", h->hora, h->minuto);
	return cats;
}

/* ATENDIMENTO */

typedef struct atendimento {
	Data *data;
	Horario *horario;
	char medico[255];
	char diagnostico[255];
} Atendimento;

Atendimento* criaAtendimento(Data *d, Horario *h, 
								char medico[], char diag[]) {
	Atendimento *at = (Atendimento*) malloc(sizeof(Atendimento));
	at->data = d;
	at->horario = h;
	strcpy(at->medico, medico);
	strcpy(at->diagnostico, diag);
	return at;
}

char* mostraAtendimento(Atendimento *at) {
	char *cats = (char*) malloc((10+5+255+255+10)*sizeof(char));
	char *data = mostraData(at->data);
 	char *horario = mostraHorario(at->horario);
 	sprintf(cats, " %s %s | %-12.12s | %s", 
 				data, horario, at->medico, at->diagnostico);
 	return cats;
}

void mostraAtendimentos(Atendimento **at, int len) {
	int i;
	if(!len) printf("%12.12s  %s\n", "", "Nenhum atendimento!");
	for (i = 0; i < len; i++)
		printf("%12.12s %s\n", "", mostraAtendimento(at[i]));
}

/* PACIENTE */

typedef struct paciente {
	long cpf;
	char nome[255];
	Data *nascimento;
	Atendimento **atendimentos;
	int lenAtendimentos;
	struct paciente *next;
	struct paciente *prev;
} Paciente;

typedef struct pacientes {
	Paciente *begin, *end;
} Pacientes;

Pacientes *lista;

Paciente* criaPaciente(long cpf, char nome[], Data *nasc, 
						Atendimento **at, int lenAt) {
	Paciente *p = (Paciente*) malloc(sizeof(Paciente));
	p->cpf = cpf;
	p->nascimento = nasc;
	p->atendimentos = at;
	p->lenAtendimentos = lenAt;
	strcpy(p->nome, nome);

	if(!lista) {
		lista = (Pacientes*) malloc(sizeof(Pacientes));
	 	p->prev = NULL;
	 	p->next = NULL;
	 	lista->begin = p;
	 	lista->end = p;
	} else {
	 	p->prev = lista->end;
	 	p->next = NULL;
	 	lista->end->next = p;
	 	lista->end = p;
	}
	return p;
}

Paciente* novoPaciente(long cpf, char nome[], 
						int dia, int mes, int ano){
	return criaPaciente(cpf, nome, criaData(dia, mes, ano), NULL, 0);
}

void mostraPaciente(Paciente *p) {
	printf("-------------------------------------------------------------------\n");
	if(p) {
		printf("%12.12s: %ld\n","CPF", p->cpf);
		printf("%12.12s: %s\n", "NOME", p->nome);
		printf("%12.12s: %s\n", "NASCIMENTO", mostraData(p->nascimento));
		printf("%12.12s: (%i)\n", "ATENDIMENTOS", p->lenAtendimentos);
		mostraAtendimentos(p->atendimentos, p->lenAtendimentos);
	} else printf("Paciente nao encontrado!\n");
}

void mostraPacientes(Pacientes *l) {
	Paciente *p = l->begin;
	int inLoop = 1;
	while(inLoop) {
		if(!p->next) inLoop = 0;
		clearTerminal();
		printf("---LISTAGEM DE TODOS OS PACIENTES------(Hospital System C)---------\n\n");
		mostraPaciente(p);
		getchar();
		clearBufferKey();
		p = p->next;
	}
}

Paciente* obterPacientePorCPF(long cpf, Pacientes *l) {
	Paciente *p = l->begin;
	int inLoop = 1;
	while(inLoop) {
		if(!p->next) inLoop = 0;
		if(p->cpf == cpf) return p;
		p = p->next;
	}
	return NULL;
}

Paciente* obterPacientePorNome(char nome[], int dia, int mes,
									int ano, Pacientes *l) {
	Paciente *p = l->begin;
	char *origem = (char*) malloc(255*sizeof(char));
	char *busca = (char*) malloc(255*sizeof(char));
	strcpy(origem, nome);
	origem = strupr(origem);
	int inLoop = 1;
	while(inLoop) {
		if(!p->next) inLoop = 0;
		strcpy(busca, p->nome);
		busca = strupr(busca);
		if(strstr(busca, origem) &&
			p->nascimento->dia == dia &&
			p->nascimento->mes == mes &&
			p->nascimento->ano == ano) return p;
		p = p->next;
	}
	return NULL;
}

/* FILA DE PACIENTES */

typedef enum prioridade {
	EMERGENCIA, URGENCIA, POUCO_URGENTE, NAO_URGENTE
} Prioridade;

char prioridadeTxt[][15] = {
	"Emergencia", "Urgencia", "Pouco Urgente", "Nao Urgente"
};

typedef struct pacienteEmfila {
	Paciente *paciente;
	Prioridade prioridade;
	struct pacienteEmfila *prev;
	struct pacienteEmfila *next;
} PacienteEmFila;

void mostraPacienteEmFila(PacienteEmFila * p) {
	printf("%12.12s | %11.11ld | %10.10s | %s\n", 
		p->paciente->nome,
		p->paciente->cpf,
		mostraData(p->paciente->nascimento),
		prioridadeTxt[p->prioridade]
	);
}

typedef struct filaDePaciente {
	PacienteEmFila *begin, *end;
} FilaDePaciente;

FilaDePaciente *fila;

void addNaFilaDePaciente(Paciente *p, Prioridade prio) {
	PacienteEmFila *pf = (PacienteEmFila*) malloc(sizeof(PacienteEmFila));
	pf->paciente = p;
	pf->prioridade = prio;
	if(!fila) {
		fila = (FilaDePaciente*) malloc(sizeof(FilaDePaciente));
		pf->prev = NULL;
		pf->next = NULL;
		fila->begin = pf;
		fila->end = pf;
	} else {
		PacienteEmFila *atual = fila->end, *ant;
		int inLoop = 1;
		while(atual) {
			if(atual->prioridade <= prio) break;
			ant = atual;
			atual = atual->prev;
		}
		if(atual) {
			pf->prev = atual;
			pf->next = atual->next;
			if(atual->next) atual->next->prev = pf;
			else fila->end = pf;
			atual->next = pf;
		} else {
			pf->prev = NULL;
			pf->next = ant;
			ant->prev = pf;
			fila->begin = pf;
		}
	}
}

void mostraFilaDePaciente(FilaDePaciente *fila) {
	PacienteEmFila *pf = fila->begin;

	if(fila->begin) {
		printf("%12.12s | %-11.11s | %-10.10s | %-12.12s \n",
			"NOME", "CPF", "NASCIMENTO", "PRIORIDADE");
		printf("%12.12s + %-11.11s + %-10.10s + %-15.15s \n",
			"--------------", "-----------", "----------", "----------------");
		int inLoop = 1;
		while(inLoop) {
			if(!pf->next) inLoop = 0;
			mostraPacienteEmFila(pf);
			pf = pf->next;
		}
	} else printf(" A fila esta vazia!\n");
}

PacienteEmFila* obterPacienteEmFila(FilaDePaciente *f, Paciente *p) {
	PacienteEmFila *pf = f->begin;
	int inLoop = 1;
	while(inLoop) {
		if(!pf->next) inLoop = 0;
		if(pf->paciente->cpf == p->cpf) return pf;
		pf = pf->next;
	}
	return NULL;
}

Paciente* removeDaFilaDePaciente(Paciente *p, char medico[], char diag[]) {
	PacienteEmFila *pf = obterPacienteEmFila(fila, p);
	if(pf) {
		if(!p->atendimentos) {
			p->atendimentos = (Atendimento**) malloc(sizeof(Atendimento*));
		} else {
			p->atendimentos = (Atendimento**) realloc(
					p->atendimentos, p->lenAtendimentos*sizeof(Atendimento*)
			);
		}
		p->atendimentos[p->lenAtendimentos] = criaAtendimento(
			criaData(22, 6, 2019), criaHorario(1, 0), medico, diag
		);
		p->lenAtendimentos++;
		if(pf->prev) {
			pf->prev->next = pf->next;
		} else {
			fila->begin = pf->next;
		}
		if(pf->next) {
			pf->next->prev = pf->prev;
		} else {
			fila->end = pf->prev;
		}
		if(!pf->prev && !pf->next) {
			free(fila);
			fila = NULL;
		}
		free(pf);
		return p;
	}
	printf("ERRO: O paciente nao esta na lista!\n");
	return NULL;
}

/* TELAS */

void alert(char msg[]) {
	clearTerminal();
	printf("%s\n\n", msg);
	getchar();
	clearBufferKey();
}

char telaListaDeEspera() {
	char acao;
	clearTerminal();
	printf("---FILA DE ESPERA-----------(Hospital System C)---------------------\n\n");
	if(fila) mostraFilaDePaciente(fila);
	else printf(" A fila esta vazia!");
	printf("\n--------------------------------------------------------------------\n");
	printf(" 1.Novo | 2.Busca por CPF | 3.Busca por Nome | 4.Ver todos | 5.Sair\n");
	printf("--------------------------------------------------------------------\n");
	printf("Digite a opcao: ");
	acao = getchar();
	clearBufferKey();
	return acao;
}

void componenteAddNaFila(Paciente *p) {
	int prioridade;
	printf("%s\n%s\n%s\n%s\n%s\n%s",
		"Defina a prioridade:",
		"1. Emergencia",
		"2. Urgencia",
		"3. Pouco Urgente",
		"4. Nao Urgente",
		"Digite a opcao: ");
	scanf("%d", &prioridade);
	clearBufferKey();
	addNaFilaDePaciente(p, prioridade-1);
}

void telaNovoPaciente() {
	long cpf;
	int dia, mes, ano, cadastra;
	char nome[255];
	clearTerminal();
	printf("---NOVO PACIENTE-----------(Hospital System C)---------------------\n\n");
	
	printf("Digite o CPF: ");
	scanf("%ld", &cpf);
	clearBufferKey();
	
	printf("Digite o Nome: ");
	rawInput(nome, sizeof(nome)/sizeof(char));
	
	printf("Digite a data de nascimento no formato (DD/MM/YYYY): ");
	scanf("%u/%u/%u", &dia, &mes, &ano);
	clearBufferKey();

	Paciente *p = novoPaciente(cpf, nome, dia, mes, ano);

	printf("Adicionar a lista de espera (S ou N): ");
	cadastra = getchar();
	clearBufferKey();

	if(cadastra == 'S' || cadastra == 's') {
		componenteAddNaFila(p);
	}

	alert("Paciente cadastrado com sucesso!!!");
}

void barraAddOuRemove(Paciente *p) {
	char acao, doutor[255], diag[255];
	printf("\n-------------------------------------------------------------------\n");
	printf(" [1. Adiciona a Fila] [2. Remove da Fila] [3. Sair]\n");
	printf("-------------------------------------------------------------------\n");
	printf("Digite a opcao: ");
	acao = getchar();
	clearBufferKey();
	switch(acao) {
		case '1':
			componenteAddNaFila(p);
			alert("Paciente adicionado na fila!!!");
			break;
		case '2':
			printf("Digite o nome do Medico: ");
			rawInput(doutor, sizeof(doutor)/sizeof(char));

			printf("Digite o diagnostico: ");
			rawInput(diag, sizeof(diag)/sizeof(char));
			
			removeDaFilaDePaciente(p, doutor, diag);

			alert("Paciente removido da fila!!!");
			break;
	}
}

void telaBuscaPorCPF() {
	long cpf;
	clearTerminal();
	printf("---BUSCA POR CPF-----------(Hospital System C)---------------------\n\n");
	
	printf("Digite o CPF: ");
	scanf("%ld", &cpf);
	clearBufferKey();

	Paciente *p = obterPacientePorCPF(cpf, lista);
	mostraPaciente(p);
	if(p) barraAddOuRemove(p);
	else getchar();
}

void telaBuscaPorNome() {
	char nome[255];
	int dia, mes, ano;
	clearTerminal();
	printf("---BUSCA POR NOME----------(Hospital System C)---------------------\n\n");
	
	printf("Digite parte do Nome: ");
	rawInput(nome, sizeof(nome)/sizeof(char));
	
	printf("Digite a data de nascimento no formato (DD/MM/YYYY): ");
	scanf("%u/%u/%u", &dia, &mes, &ano);
	clearBufferKey();

	Paciente *p = obterPacientePorNome(nome, dia, mes, ano, lista);
	mostraPaciente(p);
	if(p) barraAddOuRemove(p);
	else getchar();
}

void telaListaTodos() {
	mostraPacientes(lista);
}

void bancoVirtual();

int main () {
	bancoVirtual();
	while(1) {
		switch(telaListaDeEspera()) {
			case '1':
				telaNovoPaciente();
				break;
			case '2':
				telaBuscaPorCPF();
				break;
			case '3':
				telaBuscaPorNome();
				break;
			case '4':
				telaListaTodos();
				break;
			case '5':
				exit(0);
			default:
				alert("Opcao Invalida!!!");
		}
	}
	return 0;
}

void bancoVirtual() {
	Paciente *p1 = novoPaciente(12345678901, "Steve Rogers", 4, 7, 1920);
	addNaFilaDePaciente(p1, NAO_URGENTE);
	removeDaFilaDePaciente(p1, "Dr. Who", "Asma.");

	Paciente *p2 = novoPaciente(12345678902, "Tony Stark", 29, 5, 1970);
	addNaFilaDePaciente(p2, EMERGENCIA);
	removeDaFilaDePaciente(p2, "Dr. House", "Queimaduras de 4o grau");
	
	Paciente *p3 = novoPaciente(12345678903, "Peter Park", 10, 8, 2001);
	addNaFilaDePaciente(p3, URGENCIA);
	removeDaFilaDePaciente(p3, "Dr. Wilson", "Picada de aracnideo");
	addNaFilaDePaciente(p3, POUCO_URGENTE);
	removeDaFilaDePaciente(p3, "Dr. House", "Fratura exposta");

	addNaFilaDePaciente(p1, EMERGENCIA);
	addNaFilaDePaciente(p2, NAO_URGENTE);
	addNaFilaDePaciente(p3, URGENCIA);
}