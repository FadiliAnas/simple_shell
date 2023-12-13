#ifndef MAIN_H
#define MAIN_H 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TOKENS 1024

extern char **environ;
int status;

char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
int path(char *command, char **env, char **tokens, char *name_of_shell);
int check_fullpath(char *token);
char **paths_to_check(char **env);



#endif
