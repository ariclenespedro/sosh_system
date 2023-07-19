/*
 * cmds.h - sosh command module
 */

#ifndef _CMDS_H_
#define _CMDS_H_

#define MAX_INPUT_LENGTH 256

// Declaração da função strcmp
int strcmp(const char *s1, const char *s2);

// Outras declarações de funções e constantes que podem ser usadas no sosh.c


// Função para executar o interpretador "sosh"
void run_sosh();

// Função para executar o comando "who"
void execute_who();


int cmd_quem();


int cmd_psu();


int cmd_usrbin(char **argv, int argc);


int cmd_exit();


int cmd_help();

#endif
