#include "main.h"

/**
 * *_strchr - Locates the first occurrence of a character in a string.
 * @s: String to search.
 * @c: Character to find.
 * Return: Pointer to the first occurrence of the character.
 */
char *_strchr(char *s, char c)
{
	int index = 0;

	while (s[index] != c && s[index] != '\0')
	{
		index++;
	}
	if (s[index] == c)
	{
		return (s + index);
	}
	return (NULL);
}
