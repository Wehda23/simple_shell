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
        commands[index] = my_strdup(token);
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
 * @result: array of commands.
 */
void free_cmd_result(char ***result)
{   
    char **temp = *result;
    int i = 0;

    if (result != NULL && *result != NULL) 
    {
        

        while (temp[i] != NULL)
        {
            free(temp[i]);
            i++;
        }

        free(temp);
        *result = NULL;
    }
}