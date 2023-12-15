#include "main.h"

void cmd_exe(char **tokens, char **env)
{
	pid_t child_pid = fork();
	char *path_env = _getenviron("PATH");
	char *path_copy = NULL;
	char *directory;
	char *full_exec_path = NULL;
	size_t directory_length;
	size_t command_length;

	if (path_env != NULL)
	{
		path_copy = _strdup(path_env);
		directory = strtok(path_copy, ":");
	}

	if (child_pid == -1)
		perror("fork");

	else if (child_pid == 0)
	{
		if (_strchr(tokens[0], '/') != NULL)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				perror("execve");
				exit(status);
			}
		}

		while (directory)
		{
			command_length = _strlen(tokens[0]);
			directory_length = _strlen(directory);

			full_exec_path = malloc(directory_length + command_length + 3);
			_strcpy(full_exec_path, directory);

			full_exec_path[directory_length] = '/';
			_strcpy(full_exec_path + directory_length + 1, tokens[0]);

			if (access(full_exec_path, F_OK) == 0)
			{
				if (execve(full_exec_path, tokens, env) != -1)
				{
					free(full_exec_path);
					free(path_copy);
					free(tokens);

					exit(status);
				}
			}

			free(full_exec_path);
			directory = strtok(NULL, ":");
		}

		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		free(path_copy);
		/*
		   free(tokens);
		   */
		status = 127;
	}
	else
	{
		wait(&status);
		free(path_env);
		free(path_copy);
		free(full_exec_path);
		status >>= 8;
	}
}

