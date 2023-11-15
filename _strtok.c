#include "waheed.h"


/**
 * _strtok - Function that tokenize (splits) string into array of tokens.
 * @command: pointer to a command string.
 * @delim: delimiter to split by.
 * Return: array of tokens generated from the command string input.
 */
char *_strtok(char *command, char *delim)
{
	static char *lastToken;
	char *token;

	if (command != NULL)
		lastToken = command;
	if (lastToken == NULL)
		return (NULL);

	token = lastToken + strspn(lastToken, delim);

	if (*token == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	lastToken = token + strcspn(token, delim);
	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}
	else
		lastToken = (NULL);

	return (token);
}


/**
 * get_commands - Get the commands object
 * @command: user input as string.
 * @commands: array that stores commands.
 * Return: char** type list of commands.
 */
void get_commands(char *command, char ***commands)
{
	char *token = _strtok(command, " ");
	int initial_capacity = 2;
	int command_index = 0;
	int current_capacity = initial_capacity;

	*commands = (char **)malloc(initial_capacity * sizeof(char *));
	if (*commands == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		if (command_index >= current_capacity - 1)
		{
			current_capacity *= 2;
			*commands = (char **)realloc(*commands, current_capacity * sizeof(char *));
			if (*commands == NULL)
			{
				fprintf(stderr, "Memory reallocation failed\n");
				exit(EXIT_FAILURE);
			}
		}
		(*commands)[command_index] = strdup(token);

		if ((*commands)[command_index] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}

		token = _strtok(NULL, " "); /* Move to the next token */
		command_index++;
	}

	(*commands)[command_index] = NULL;
}
