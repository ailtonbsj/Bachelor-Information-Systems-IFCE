#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct {
	int dia, mes, ano;
} Data;

typedef struct {
	int hora, minuto, segundo;
} Horario;

typedef struct {
	char descricao[255];
	char local[255];
	Data data;
	Horario horario;
} Compromisso;

int main () {
	Compromisso c;
	
	printf("Digite a descricao: ");
	rawInput(c.descricao, 255);

	printf("Digite o local: ");
	rawInput(c.local, 255);

	printf("Digite o dia (1-31): ");
	scanf("%i", &c.data.dia);
	clearBufferKey();

	printf("Digite o mes (1-12): ");
	scanf("%i", &c.data.mes);
	clearBufferKey();

	printf("Digite o ano: ");
	scanf("%i", &c.data.ano);
	clearBufferKey();

	printf("Digite a hora (0-23): ");
	scanf("%i", &c.horario.hora);
	clearBufferKey();

	printf("Digite o minuto (0-59): ");
	scanf("%i", &c.horario.minuto);
	clearBufferKey();

	printf("Digite o segundo (0-59): ");
	scanf("%i", &c.horario.segundo);
	clearBufferKey();

	printf("\n\nDescriçao: %s\n", c.descricao);
	printf("Local: %s\n", c.local);
	printf("Data: %02i/%02i/%04i\n", c.data.dia,
		c.data.mes, c.data.ano);
	printf("Horario: %02i:%02i:%02i\n", c.horario.hora,
		c.horario.minuto, c.horario.segundo);

	return 0;
}