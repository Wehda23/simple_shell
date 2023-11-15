#include "waheed.h"


/**
 * exit_check - function matches string with exit.
 * @string: the string to be compared to exit.
 * Return: 0 in case of success, 1 in case of failure. 
 */
int exit_check(char *string)
{
    if (string != NULL)
    {
        if (_strcmp(string, "exit") == 0)
            return (0);
        else if (_strcmp(string, "\"exit\"")  == 0)
            return (0);
        else if (_strcmp(string, "\'exit\'")  == 0)
            return (0);
    }
    
    return (1);
}