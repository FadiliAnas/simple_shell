/**
 * _strlen - Returns the length of a string.
 * @s: String to calculate the length.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}
