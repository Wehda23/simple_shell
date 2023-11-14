#include "waheed.h"


/**
 * print_env - function that prints enviromental variables.
 * @file: execution file name.
 */
void print_env(char *file)
{
	pid_t pid = fork();
	int status;
	char **env;

	if (pid == -1)
	{
		perror(file);
	}
	else if (pid == 0)
	{
		for (env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env); /* Print each environment variable */
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * add_env - function that adds an enviromental variable.
 * @commands: command pass in to the function
 * @file: execution file name.
 */
void add_env(char **commands, char *file)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror(file);
	}
	else if (pid == 0)
	{
		if (commands[1] != NULL && commands[2] != NULL)
		{
			if (setenv(commands[1], commands[2], 1) != 0)
			{
				perror(file);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			printf("%s: Missing field, example setenv VARIABLE VALUE\n", file);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * remove_env - function that removes an enviromental variable.
 * @commands: command pass in to the function
 * @file: execution file name.
 */
void remove_env(char **commands, char *file)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror(file);
	}
	else if (pid == 0)
	{
		if (commands[1] != NULL)
		{
			if (unsetenv(commands[1]) != 0)
			{
				perror(file);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			printf("%s: Missing field, example setenv VARIABLE\n", file);
		}

	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
