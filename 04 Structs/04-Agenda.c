#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

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

/* Estrutura de um compromisso */
typedef struct {
	struct {
		unsigned dia, mes, ano;
	} data;
	struct {
		unsigned hora, minuto, segundo;
	} horario;
	char descricao[255];
} Compromisso;

/* Cria uma nova estrutura do tipo Compromisso */
Compromisso newCompromisso (unsigned dia, unsigned mes, unsigned ano,
 unsigned hora, unsigned min, unsigned seg, char desc[]){
	Compromisso c;
	c.data.dia = dia;
	c.data.mes = mes;
	c.data.ano = ano;
	c.horario.hora = hora;
	c.horario.minuto = min;
	c.horario.segundo = seg;
	strcpy(c.descricao, desc);
	return c;
}

/* Exibe um compromisso na tela */
void showCompromisso (Compromisso c) {
	printf("----------------------------\n");
	printf(" Data: %02u/%02u/%02u  %02u:%02u:%02u\n", c.data.dia, c.data.mes, c.data.ano,
		c.horario.hora, c.horario.minuto, c.horario.segundo);
	printf(" %s\n", c.descricao);
}

/* Lista todos os compromissos */
void listCompromissos (Compromisso c[], unsigned size) {
	if(size == 0) printf(" A Lista está vazia!\n");
	for(int i = 0; i < size; i++){
		showCompromisso(c[i]);
	}
}

/* Captura informações do teclado para gerar novo compromisso */
Compromisso insertCompromisso(){
	unsigned dia, mes, ano, hora, min, seg;
	char desc[255];

	printf("Digite a data no formato (DD/MM/YYYY): ");
	scanf("%u/%u/%u", &dia, &mes, &ano);
	clearBufferKey();

	printf("Digite o horario no formato (HH:mm:ss): ");
	scanf("%u:%u:%u", &hora, &min, &seg);
	clearBufferKey();

	printf("Digite a descrição: ");
	rawInput(desc, sizeof(desc));

	return newCompromisso(dia, mes, ano, hora, min, seg, desc);
}

/* Função principal de execução da Agenda */
void main () {
	char acao;
	int totalCompromissos = 0;

	Compromisso *c = (Compromisso*) malloc(sizeof(Compromisso));
	if(c == NULL) printf("Sem memoria!\n"), exit(1);
	
	/* Loop Infinito para o programa não terminar sozinho */
	while(1) {
		printf("Qual tarefa deseja executar? (L)istar, (A)dicionar ou (S)air: ");
		acao = getchar();
		clearBufferKey();

		clearTerminal();
		printf("---AGENDA DE COMPROMISSOS---\n");

		switch(acao){
		case 'L':
			listCompromissos(c, totalCompromissos);
			printf("----------------------------\n");
			break;
		case 'A':
			totalCompromissos++;
			c = (Compromisso *) realloc(c, totalCompromissos * sizeof(Compromisso));
			if(c == NULL) printf("Sem memoria!\n"), exit(1);
			c[totalCompromissos-1] = insertCompromisso();
			printf("\nDados inseridos na lista!\n\n");
			break;
		default:
			printf("\nSaindo do programa...\n");
			exit(0);
		}
	}
}
