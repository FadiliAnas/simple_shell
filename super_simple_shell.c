#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main (void)
{
	char *buffer = 0;
	size_t buffer_size ;
	ssize_t return_value;
	char *argv[] = {".", 0};

    int counter = 0;

	int x;

	while(1)
	{    
	buffer = malloc(sizeof(char)*buffer_size);
	write(1,"$ ", 2);
       
	return_value = getline(&buffer, &buffer_size, stdin);
	write(1,"\n", 1);
    while (buffer[counter] != '\n')
        counter++;
    buffer[counter] = '\0';
    x = fork();

	if(x != 0)
		wait(0);
	else
	{
        execve(buffer, argv, 0 );
	}  
	}
    return (0);
}
