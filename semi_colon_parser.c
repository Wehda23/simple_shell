#include "waheed.h"

/**
 * remove_surrounding_spaces - Removes both preceding and trailing spaces in a string.
 * @str: Input string.
 * Return: Pointer to the modified string.
 */
char *remove_surrounding_spaces(char *str)
{
    int i, j = 0, len = strlen(str);

    while (str[j] == ' ' || str[j] == '\t')
    {
        j++;
    }

    for (i = 0; str[i + j] != '\0'; i++)
    {
        str[i] = str[i + j];
    }

    len -= j;

    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'))
    {
        len--;
    }

    str[len] = '\0';

    return (str);
}

/**
 * semicolon_parser - Function to parse commands based on semicolon delimiter.
 * @input: String input containing multiple commands separated by semicolons.
 * Return: An array of parsed commands.
 */
char **semicolon_parser(char *input)
{
    int bufsize = BUFFER;
    int index = 0;
    char **commands = (char **)malloc(bufsize * sizeof(char *));
    char *token = strtok(input, ";&");
    
    if (!commands) 
    {
        errprint("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (token != NULL) 
    {
        if (index >= bufsize - 1) 
        {
            bufsize += BUFFER;
            commands = (char **)realloc(commands, bufsize * sizeof(char *));
            if (!commands) 
            {
                errprint("Memory reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = remove_surrounding_spaces(token); 
        commands[index++] = strdup(token);
        token = strtok(NULL, ";&");
    }
    commands[index] = NULL;

    return (commands);
}

/**
 * free_semicolon_memory - Function to deallocate memory allocated,
 *          for commands parsed by semicolon_parser.
 * @commands: Pointer to the array of parsed commands.
 */
void free_semicolon_memory(char **commands)
{
    int i;

    if (commands != NULL) 
    {
        for (i = 0; commands[i] != NULL; i++) 
        {
            free(commands[i]);
        }
        free(commands);
    }
}