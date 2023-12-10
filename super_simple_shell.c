#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TOKENS 100

int main (void)
{
	char *buffer = 0;
	size_t buffer_size;
	int x, i;
	/*int counter = 0;*/
	char *token;
	char *tokens[MAX_TOKENS];

	while(1)
	{
		if (getline(&buffer, &buffer_size, stdin) == -1)
		{
			exit(0);
		}
		token = strtok(buffer, " \n");
		i = 0;
		while (token != NULL)
		{
			tokens[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		tokens[i] = NULL;
		x = fork();
		/*while(buffer[counter] != '\n')
			counter++;
		buffer[counter] = '\0';*/
		if(x != 0)
			wait(0);
		else
			execve(tokens[0], tokens, 0);
	}
	return (0);
}
