#ifndef MAIN_H
#define MAIN_H 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

extern char **environ;
int status;

void cmd_exe(char **commandTokens, char **environmentVariables);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_getenviron(char *name);
void exitOut();

#endif
