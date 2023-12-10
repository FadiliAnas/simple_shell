#ifndef MAIN_H
#define MAIN_H 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TOKENS 100

extern char **environ;
int status;

char *str_concat(char *s1, char *s2);
char *path(char *command, char **env);
int check_fullpath(char *token);




#endif
