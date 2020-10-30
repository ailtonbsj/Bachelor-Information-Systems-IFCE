#ifdef _WIN32
#include <stdio.h>
#elif linux
#include <stdio_ext.h>
#endif

// Habilita suporte a boleanos true e false
typedef enum
{
    false,
    true
} bool;

// Limpa buffer do teclado para Windows e Linux
void clearBufferKey()
{
#ifdef _WIN32
    fflush(stdin);
#elif linux
    __fpurge(stdin);
#endif
}

// Limpa o terminal completamente
#ifdef _WIN32
#define clearTerminal() system("cls")
#elif linux
#define clearTerminal() printf("\033[H\033[J")
#endif

// Pega strings do teclado sem gerar problemas
void rawInput(char *buf, unsigned int size)
{
    clearBufferKey();
    fgets(buf, size, stdin);
    buf[strlen(buf) - 1] = '\0';
    clearBufferKey();
}

// Pega um caractere do Teclado
char pressAnyKey() {
    char buf;
    clearBufferKey();
    buf = getchar();
    clearBufferKey();
    return buf;
}

// Notifica opcao invalida
void invalidOption()
{
    printf("\nOpcao Invalida! Pressione qualquer tecla para continuar...");
    pressAnyKey();
}
