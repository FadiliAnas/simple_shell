#include "main.h"


char **paths_to_check(char **env)
{
	int i, j;
	char *tok, *path_token, *env_val;
	char **full_paths;

	for (i = 0; env[i] != NULL; i++)
	{
		tok = strtok(env[i], "=");
		if (strcmp(tok, "PATH") == 0)
		{
			env_val = strtok(NULL, "\n");
			path_token = strtok(env_val, ":");

			full_paths = malloc(5000);
			if (full_paths == NULL)
			{
				exit(0);
				return (NULL);
			}

			j = 0;
			while (path_token != NULL)
			{
				full_paths[j] = path_token;
				path_token = strtok(NULL, ":");
				j++;
			}
			full_paths[j] = NULL;
			return (full_paths);
		}

	}
	return (NULL);
}


int path(char *command, char **env, char **tokens, char *name_of_shell)
{
	int x, j;
	char *commands_full_path;
	char **full_paths = NULL;


	full_paths = paths_to_check(env);
	if (full_paths == NULL)
	{
		write(2, name_of_shell, strlen(name_of_shell));
		write(2, ": 1: ", 5);
		write(2, tokens[0], strlen(tokens[0]));
		write(2, ": not found\n", 12);
		exit(127);
	}

	j = 0;
	while (full_paths[j])
	{
		commands_full_path = str_concat(full_paths[j], str_concat("/", command));
		if (access(commands_full_path, X_OK) == 0)
		{
			x = fork();
			if (x != 0)
			{
				wait(&status);
				status >>= 8;
				return (0);
			}
			else
				execve(commands_full_path, tokens, NULL);
		}
		j++;
	}

	write(2, name_of_shell, strlen(name_of_shell));
	write(2, ": 1: ", 5);
	write(2, tokens[0], strlen(tokens[0]));
	write(2, ": not found\n", 12);
	status = 127;

	return (1);
}
int check_fullpath(char *token)
{
	int i;

	for (i = 0; token[i] != '\0' ; i++)
	{
		if (token[i] == '/')
			return (1);
	}
	return (0);
}



int main(int argc __attribute__((unused)), char *argv[])
{
	char *buffer = 0;
	size_t buffer_size;
	ssize_t get_line;
	int x, i;
	char *token;
	char *tokens[MAX_TOKENS];
	char *name_of_shell = argv[0];

	status = 0;

	while (1)
	{
		get_line = getline(&buffer, &buffer_size, stdin);
		if (buffer[0] == '\n' || (strncmp(buffer, "exit", 4) == 0))
			break;
		if (get_line == '\0' || get_line == EOF)
			break;

		token = strtok(buffer, " \n");
		if (token == NULL)
			continue;
		i = 0;
		while (token != NULL)
		{
			tokens[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		tokens[i] = NULL;

		if (!check_fullpath(tokens[0]))
		{
			if (path(tokens[0], environ, tokens, name_of_shell) == 0)
				continue;
		}
		else
		{
			if (access(tokens[0], X_OK) == 0)
			{
				x = fork();
				if (x != 0)
				{
					wait(&status);
					status >>= 8;
				}
				else
					execve(tokens[0], tokens, environ);
			}
			else
			{
				write(2, name_of_shell, strlen(name_of_shell));
				write(2, ": 1: ", 5);
				write(2, tokens[0], strlen(tokens[0]));
				write(2, ": not found\n", 12);
				status = 127;
			}
		}
	}
	return (status);
}
