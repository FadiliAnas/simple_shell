#include "main.h"

/**
 * main - Entry point for the simple shell program.
 * @argumentCount: Number of command-line arguments.
 * @argumentVector: Array of strings representing the command-line arguments.
 * @environment: Array of strings representing the environment variables.
 * Return: Returns 0 on successful execution.
 */

int main(__attribute__((unused)) int argumentCount, __attribute__((unused)) char **argumentVector, char **environment) 
{
	size_t counter = 0;
	char *tok[MAX_TOKENS];
	char *inputBuffer = NULL;
	size_t bufferSize = 0;
	ssize_t Input;

	while (1)
	{

		Input = getline(&inputBuffer, &bufferSize, stdin);

		if (Input == -1)
		{
			free(inputBuffer);
			exit(status);
		}

		inputBuffer[Input - 1] = '\0';

		counter = 0;

		tok[counter] = strtok(inputBuffer, " \n");

		while (tok[counter] != NULL && counter < MAX_TOKENS - 1) 
		{
			if (tok[counter][0] == '#')
			{
				tok[counter] = NULL;
				break;
			}
			counter++;
			tok[counter] = strtok(NULL, " \n");
		}
		if (_strcmp(inputBuffer, "exit") == 0) 
		{
			free(inputBuffer);
			exitOut();
		}
		else if (_strcmp(inputBuffer, "env") == 0) 
		{
			_printenviron();
			continue;
		}
		if (tok[0] == NULL) 
			continue;
		cmd_exe(tok, environment);
	}
	free(inputBuffer);
	return (0);
}

void _printenviron()
{
	int i;
	char *newline = "\n";

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, newline, 1);
	}
}
