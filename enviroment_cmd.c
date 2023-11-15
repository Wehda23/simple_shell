#include "waheed.h"

/**
 * print_env - function that prints enviromental variables.
 * @file: execution file name.
 */
void print_env(void)
{
	char **env;

		for (env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env); /* Print each environment variable */
		}
}