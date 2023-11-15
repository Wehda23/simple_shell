#include "waheed.h"

/**
 * getUserInput - Get the User Input object
 * Return: char* pointer to a string.
 */
char *getUserInput()
{
	int index = 0, readStatus, bufferSize = BUFFER;
	char currentChar = 0;
	char *inputBuffer, *processedInput;

	inputBuffer = (char *)malloc(bufferSize * sizeof(char));
	if (inputBuffer == NULL)
	{
		return (NULL);
	}

	while (currentChar != EOF && currentChar != '\n')
	{
		fflush(stdin);
		readStatus = read(STDIN_FILENO, &currentChar, 1);

		if (readStatus == 0)
		{
			free(inputBuffer);
			exit(EXIT_SUCCESS);
		}

		inputBuffer[index] = currentChar;

		if (inputBuffer[0] == '\n')
		{
			return (handleEnter(inputBuffer));
		}

		if (index >= bufferSize)
		{
			inputBuffer = realloc(inputBuffer, (bufferSize + 2) * sizeof(char));
			if (inputBuffer == NULL)
			{
				free(inputBuffer);
				return (NULL);
			}
		}

		index++;
	}

	inputBuffer[index] = '\0';
	processedInput = removeLeadingSpaces(inputBuffer);
	processedInput = remove_semicolon(processedInput);
	free(inputBuffer);

	handleHashtag(processedInput);
	return (processedInput);
}

/**
 * handleEnter - handles enter press button.
 * @input: string input.
 * Return: char* end line.
 */
char *handleEnter(char *input)
{
	free(input);
	return ("\0");
}

/**
 * removeLeadingSpaces - function that removes leading spaces in string.
 * @input: string input.
 * Return: char* pointer.
 */
char *removeLeadingSpaces(char *input)
{
	int i = 0, j = 0;
	char *processedInput;

	processedInput = (char *)malloc((_strlen(input) + 1) * sizeof(char));
	if (processedInput == NULL)
	{
		free(processedInput);
		return (NULL);
	}

	while (input[i] == ' ')
	{
		i++;
	}

	for (; input[i + 1] != '\0'; i++)
	{
		processedInput[j] = input[i];
		j++;
	}

	processedInput[j] = '\0';

	if (processedInput[0] == '\0' || processedInput[0] == '#')
	{
		free(processedInput);
		return ("\0");
	}

	return (processedInput);
}

/**
 * handleHashtag - handles the comments #
 * @input: string input.
 */
void handleHashtag(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#' && input[i - 1] == ' ' && input[i + 1] == ' ')
		{
			input[i] = '\0';
		}
	}
}

/**
 * remove_semicolon - Removes a preceding semicolon, if exists.
 * @str: Input string to modify.
 * Return: Modified string with semicolon removed if found at the beginning.
 */
char *remove_semicolon(char *str)
{
	int i = 0, j = 0;
	char *buff;

	if (str[i] == ';')
	{
		i++;
	}

	buff = (char *)malloc((strlen(str) - i + 1) * sizeof(char));
	if (buff == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		buff[j] = str[i];
		i++;
		j++;
	}
	buff[j] = '\0';

	return (buff);
}
