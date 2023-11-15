#include "waheed.h"



/**
 * cprint - function used to print a string
 * @string: the string that is going to be printed to standard output.
 */
void cprint(char *string)
{
	if (string != NULL)
	{
		write(STDERR_FILENO, string, _strlen(string));
	}
}

/**
 * errprint - function used to prints to stderr
 * @string: the string that is going to be printed to standard error.
 */
void errprint(char *string)
{
	if (string != (NULL))
	{
		write(STDERR_FILENO, string, _strlen(string));
	}
}

/**
 * print_commands - print commands from command array.
 * @commands: commands to print.
 */
void print_commands(char **commands)
{
	int index = 0;

	if (commands != NULL)
	{
		cprint("\n");
		while (commands[index] != NULL)
		{
			cprint(commands[index]);
			cprint("\n");
			index++;
		}
	}

}
