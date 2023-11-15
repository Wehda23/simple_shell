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
    char replacement = '_';
    char **commands = (char **)malloc(bufsize * sizeof(char *));
    char *input_replaced = replace_space_within_quotes(input, replacement);
    char *token = _strtok(input_replaced, delim);

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

    revert_replacement_to_spaces(&commands, replacement);

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

/**
 * Replaces spaces within quotes with a specified character.
 * @input: Input string.
 * @replacement: Replacement character for spaces within quotes.
 * Return: Pointer to the modified string.
 */
char *replace_space_within_quotes(char *input, char replacement)
{
    int inside_quotes = 0;
    int len = _strlen(input), i;

    for (i = 0; i < len; i++)
    {
        if (input[i] == '\"' || input[i] == '\'')
        {
            inside_quotes = !inside_quotes;
        }
        if (inside_quotes && input[i] == ' ')
        {
            input[i] = replacement;
        }
    }

    return (input);
}

/**
 * Reverts replacement characters back to spaces within quotes.
 * @commands: Array of commands.
 */
void revert_replacement_to_spaces(char ***commands, char replacement)
{
    int len, i, j;

    for (i = 0; (*commands)[i] != NULL; i++)
    {
        len = strlen((*commands)[i]);
        for (j = 0; j < len; j++)
        {
            if ((*commands)[i][j] == replacement)
            {
                (*commands)[i][j] = ' ';
            }
        }
    }
}