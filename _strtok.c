#include "waheed.h"

/**
 * check_delim - function that checks delimiter
 * @c: character input
 * @str: const string input
 * Return: integer
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int result = 0;

	while (*str != '\0')
	{
		if (c == *str++)
		{
			result = 1;
			break;
		}
	}

	return (result);
}

/**
 * _strtok - function that memics strtok function
 * @str: string input
 * @delim: string contains all delimiters.
 * Return: Dynammically allocated string.
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	static char *next_token;

	if (str != NULL)
		next_token = str;

	token = next_token;

	if (token == NULL)
		return (NULL);

	while (*token != '\0')
	{
		if (check_delim(*token, delim) == 0)
			break;
		token++;
	}

	if (*token == '\0' || *token == '#')
	{
		next_token = NULL;
		return (NULL);
	}

	next_token = token;

	while (*next_token != '\0')
	{
		if (check_delim(*next_token, delim) == 1)
			break;
		next_token++;
	}

	if (*next_token == '\0')
	{
		next_token = NULL;
	}
	else
	{
		*next_token = '\0';
		next_token++;
		if (*next_token == '\0')
			next_token = NULL;
	}

	return (token);
}
