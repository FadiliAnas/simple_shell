#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: char*
 * Return: char*
 */
char *_strdup(char *str)
{
	char *duplicate;
	int size;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}
	size = _strlen(str) + 1;
	duplicate = malloc(size * sizeof(char));

	if (duplicate == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		duplicate[i] = str[i];
	}

	return (duplicate);
}
