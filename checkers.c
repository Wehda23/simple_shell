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

/**
 * buildin_checks - function matches string with builtin commands.
 * @string: the string to be compared to builtin commands.
 * Return: 0 in case of success, 1 in case of failure. 
 */
int buildin_checks(char *string)
{
	if (_strcmp(string, "echo") == 0)
		return (0);
	else if (_strcmp(string, "env") == 0)
		return (0);
	else if (_strcmp(string, "cd") == 0)
		return (0);
	else if (_strcmp(string, "env") == 0)
		return (0);
	else if (_strcmp(string, "setenv") == 0)
		return (0);
	else if (_strcmp(string, "unsetenv") == 0)
		return (0);

	return (1);
}
