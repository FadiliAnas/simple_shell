#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *buffer = 0;
	size_t buffer_size;
	char *argv[] = {".", 0};
	int x;
	int counter = 0;


	while(1)
	{
		if (getline(&buffer, &buffer_size, stdin) == -1)
		{
			exit(0);
		}
		x = fork();
		while(buffer[counter] != '\n')
			counter++;
		buffer[counter] = '\0';
		if(x != 0)
			wait(0);
		else
			execve(buffer, argv, 0);
	}
	return (0);
}
