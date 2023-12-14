#include "main.h"

extern char **environ;

/**
 * _getenv - Get the value of an environment variable.
 * @name: Name of the environment variable.
 * Return: The value of the environment variable or NULL if not found.
 */

char *_getenviron(char *name)
{
	int i;
	char *vector;
	char *tween;
	char *token;
	char *variable;

	i = 0;

	while (environ[i])
	{

		tween = _strdup(environ[i]);

		vector = strtok(tween, "=");

		if (_strcmp(vector, name) == 0)
		{
			variable = strtok(NULL, "\n");

			token = _strdup(variable);

			free(tween);
			return (token);
		}
		free(tween), tween = NULL;

		i++;
	}
	return (NULL);
}
