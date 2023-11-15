#include "waheed.h"

/**
 * _strcat - function that concatenates a string
 * @dest: The destination string where 'src' will be appended.
 * @src: The string to be appended to 'dest'.
 * Return: A pointer to the resulting concatenated string 'dest'.
 */
char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (original_dest);
}
