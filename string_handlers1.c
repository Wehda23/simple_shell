#include "waheed.h"


/**
 * _strlen - function used to return the length of a string.
 * @string: string that we are going get the length of.
 * Return: int returns the length of the string as integer.
 */
int _strlen(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length])
	{
		length++;
	}

	return (length);
}

/**
 * _atoi - function that converts a string number to integer number.
 * @string: pointer to a string.
 * Return: integer value of the string number or 0 on error.
 */
int _atoi(char *string)
{
	int value = 0;

	/* Null string returns 0 */
	if (string == NULL)
		return (0);

	while (*string)
	{
		/* Check if the string represents a number or not */
		if (*string >= '0' && *string <= '9')
		{
			value = (*string - '0') + 10 * value;
			string++;
		}
		else
		{   /* if fails check return (0) */
			return (0);
		}
	}

	return (value);
}


/**
 * _strcmp - function that compares two strings
 * @first: First string input.
 * @second: Second string input.
 * Return: (1) in case strings are identical, (0) in case strings not =
 */
int _strcmp(char *first, char *second)
{
	while (*first != '\0' && *second != '\0')
	{
		if (*first != *second)
		{
			return (1);
		}

		first++;
		second++;
	}
	if (*first != '\0' || *second != '\0')
	{
		return (1);
	}

	return (0);
}

/**
 * my_strdup - Duplicates a string.
 * @str: The string to duplicate.
 * Return: Pointer to the newly allocated duplicated string,
 *         or NULL if insufficient memory was available.
 */
char *my_strdup(const char *str) 
{
    size_t len = strlen(str) + 1;
    char *duplicate = (char *)malloc(len * sizeof(char));

    if (duplicate != NULL)
	{
        memcpy(duplicate, str, len);
    }

    return (duplicate);
}

/**
 * _strncmp - function that compares two strings to required index.
 * @first: The first string to be compared.
 * @second: The second string to be compared.
 * @num: The maximum number of characters to compare.
 * Return: An integer less than, equal to, or greater than zero if 'first' is found,
 * respectively, to be less than, to match, or be greater than 'second'.
 */
int _strncmp(const char *first, const char *second, size_t num)
{
    while (num > 0 && *first && *second && *first == *second)
	{
        first++;
        second++;
        num--;
    }

    if (num == 0)
	{
        return 0;
    }
	else
	{
        return (*(unsigned char *)first - *(unsigned char *)second);
    }
}