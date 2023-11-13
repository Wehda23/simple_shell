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

    while (string[length++]);

    return (length - 1);
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