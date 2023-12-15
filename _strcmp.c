#include "main.h"

/**
 * _strcmp - Compares string values.
 * @string1: First string to compare.
 * @string2: Second string to compare.
 *
 * Return: The difference between the first differing characters.
 */
int _strcmp(char *string1, char *string2)
{
    int i = 0;

    while (string1[i] != '\0' && string2[i] != '\0')
    {
        if (string1[i] != string2[i])
        {
            return (string1[i] - string2[i]);
        }
        i++;
    }

    return (0);
}
