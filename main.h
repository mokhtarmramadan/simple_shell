#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int check_space(char *buff);
char *parce(char *s);
char *conatnte(char *buffer);
void print_env(char **env);
int check_getline(int number, char *buffer, char **env);

#endif /* #ifndef _MAIN_H_ */
