#include "waheed.h"

/**
 * cmd_parser - function that is used to parse command.
 * @input: string input.
 * @delim: delimiter according to which the commands are going to be parsed.
 * Return: an array of parsed/semi parsed command. 
 */
char **cmd_parser(char *input, char *delim) 
{
    int bufsize = 64;
    int index = 0;
    char **commands = (char **)malloc(bufsize * sizeof(char *));
    char *token = _strtok(input, delim);

    if (!commands) 
    {
        errprint("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (token != NULL) 
    {
        commands[index] = _strdup(token);
        index++;

        if (index >= bufsize) 
        {
            bufsize += 64;
            commands = (char **)realloc(commands, bufsize * sizeof(char *));
            if (!commands) 
            {
                errprint("Memory reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = _strtok(NULL, delim);
    }
    commands[index] = NULL;

    return (commands);
}

/**
 * free_cmd_result - frees memory allocated by cmd_parser 
 */
void free_cmd_result(char **result)
{
    int i = 0;

    while (result[i] != NULL)
    {
        free(result[i]);
        i++;
    }

    free(result);
}