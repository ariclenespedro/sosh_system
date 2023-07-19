#include "cmds.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void execute_who_command() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execlp("who", "who", NULL);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        wait(&status);
    }
}

void execute_psu_command() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execlp("ps", "ps", "u", NULL);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        wait(&status);
    }
}

void show_help() {
    printf("Comandos suportados:\n");
    printf("quem - executa o comando Unix who.\n");
    printf("psu - lista os processos em execução do utilizador.\n");
    printf("help - lista os comandos suportados.\n");
    printf("exit - sai da shell.\n");
}

int main() {
    char input_buffer[MAX_INPUT_LENGTH];

    while (1) {
        printf("sosh> ");
        if (fgets(input_buffer, MAX_INPUT_LENGTH, stdin) == NULL) {
            // Check for EOF (Ctrl-D)
            break;
        }

        // Remover a quebra de linha no final da string
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Verificar o comando introduzido pelo utilizador
        if (strcmp(input_buffer, "quem") == 0) {
            execute_who_command();
        } else if (strcmp(input_buffer, "psu") == 0) {
            execute_psu_command();
        } else if (strcmp(input_buffer, "help") == 0) {
            show_help();
        } else if (strcmp(input_buffer, "exit") == 0) {
            break;
        } else {
            printf("Comando não suportado: %s\n", input_buffer);
        }
    }

    return EXIT_SUCCESS;
}

