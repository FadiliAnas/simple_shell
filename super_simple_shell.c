#include "main.h"


char *path(char *command, char **env)
{
	int i, j;
	char *tok, *path_token, *commands_full_path, *env_val;
	char *full_paths[1024];

	for (i = 0; env[i] != NULL; i++)
	{
		tok = strtok(env[i], "=");
		if (strcmp(tok, "PATH"))
		{
			env_val = strtok(NULL, "\n");
			path_token = strtok(env_val, ":");
			j = 0;
			while (path_token != NULL)
			{
				full_paths[j] = path_token;
				path_token = strtok(NULL, "\n");
				j++;
			}
			full_paths[j] = NULL;
			j = 0;
			while (full_paths[j])
			{
				commands_full_path = str_concat(full_paths[j], command);
				if (access(commands_full_path, X_OK) == 0)
					return (commands_full_path);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

int check_fullpath(char *token)
{
	int i;

	for (i = 0; (token + i) != NULL ; i++)
	{
		if (token[i] == '/')
			return (1);
	}
	return (0);
}



int main(void)
{
	extern char **environ;
	char *buffer = 0;
	size_t buffer_size;
	int x, i;
	char *token;
	char *tokens[MAX_TOKENS];
	char *_path;


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


		if (!check_fullpath(tokens[0]))
		{
			_path = path(tokens[0], environ);
			if (_path == NULL)
				perror("not found");
			x = fork();
			if (x != 0)
				wait (0);
			else
				execve(_path, tokens, environ);
		}
		else
		{
			x = fork();
			if(x != 0)
				wait(0);
			else
				execve(tokens[0], tokens, environ);
		}
	}
	return (0);
}
