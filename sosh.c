#include "sosh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_who_command() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execl("/usr/bin/who", "who", NULL);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        wait(&status);
    }
}

int main() {
    char input_buffer[MAX_INPUT_LENGTH];

    while (1) {
        printf("sosh> ");
        if (fgets(input_buffer, MAX_INPUT_LENGTH, stdin) == NULL) {
            // Check for EOF (Ctrl-D)
            break;
        }

        // TODO: Implement command parsing and execution
        // For now, we will execute the "who" command
        if (strcmp(input_buffer, "who\n") == 0) {
            execute_who_command();
        } else if (strcmp(input_buffer, "exit\n") == 0) {
            break;
        } else {
            printf("Command not supported\n");
        }
    }

    return EXIT_SUCCESS;
}

