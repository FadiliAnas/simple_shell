#include "main.h"

/**
 * str_concat - Concatenates two strings.
 *
 * @s1: string.
 * @s2: string.
 *
 * Return: NULL on failure, pointer on success.
 **/

char *str_concat(char *s1, char *s2)
{
	char *string;
	int len1, len2, i, j;

	len1 = 0;
	len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	string = malloc((len1 + len2 + 1) * sizeof(char));

	if (string == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		string[i] = s1[i];
	for (j = 0; j < len2; j++)
		string[i + j] = s2[j];

	string[i + j] = '\0';

	return (string);
}
