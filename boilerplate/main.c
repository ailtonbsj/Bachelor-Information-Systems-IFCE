#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.c"

void main()
{
    // Cria duas variais
    char name[50] = {'\0'};
    bool hasCat = false;

    // Limpa terminal
    clearTerminal();
    // Escreve na Tela
    printf("Nome completo: ");
    // Pega texto do usuario e salva em string
    rawInput(name, sizeof(name) / sizeof(char));
    // Escreve na Tela
    printf("Tem gato? [s] Sim [n] Nao : ");
    // Pega uma tecla do usuario e converte em booleano
    hasCat = pressAnyKey() == 's' ? true : false;
    // Escreve os resultados na Tela
    printf("\n\nNome: %s\nTem gato: %s\n\n", name, hasCat ? "Sim": "Nao");
    // Espera pressionar uma tecla para sair
    pressAnyKey();
}
