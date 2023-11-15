#include "waheed.h"



/**
 * cprint - function used to print a string 
 * @string: the string that is going to be printed to standard output. 
 */
void cprint(char *string)
{
    if (string != NULL)
    {
        write(1, string, _strlen(string));
    }
}

/**
 * cprint - function used to prints to stderr
 * @string: the string that is going to be printed to standard error. 
 */
void errprint(char *string)
{
    if (string != (NULL))
    {
        write(STDERR_FILENO, string, _strlen(string));
    }
}