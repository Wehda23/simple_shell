#include "waheed.h"


/**
 * main - Entry function for simple shell.
 * @argc: number of arguements entered.
 * @argv: array of arguments entered.
 * Return: 0 in case of success, 1 incase of failure. 
 */
int main(__attribute__((unused)) int argc, char **argv)
{
    /* Buffer to read user input */
    char read_input[COMMAND_BUFFER_SIZE], **cmd; 
    int nread = 0;

    while (1)
    {   
        prompt(); /* Prompt ($ )*/
        nread = _getline(STDIN_FILENO, read_input, COMMAND_BUFFER_SIZE);
        
        if (nread >= 0)
        {
            printf("You entered : %s\n", read_input);
            get_commands(read_input, &cmd);
            print_commands(cmd);
            /* Check echo, cd, env, ls etc..*/
            if (_strcmp(cmd[0], "echo") == 0)
            {
                printf("Im echoing\n");
            } 
            else if (_strcmp(cmd[0], "cd") == 0)
            {
                printf("Im changing directory\n");
            } 
            else if (_strcmp(cmd[0], "env") == 0) 
            {
                printf("Im displaying environment variables\n");
            } 
            else if (_strcmp(cmd[0], "ls") == 0 || strcmp(cmd[0], "/bin/ls") == 0)
            {
                ls_command(cmd, argv[0]);
            }
            else if (_strcmp(cmd[0], "alias") == 0)
            {
                exit(EXIT_SUCCESS);
            }
            else if (_strcmp(cmd[0], "exit") == 0)
            {
                exit(EXIT_SUCCESS);
            }
            else
            {
                printf("%s: %s: command not found\n", argv[0], cmd[0]);
                
            }
            free_commands(&cmd);
        }
        else
        {
            perror("hsh");
            exit(EXIT_FAILURE);
        }
    }/* While end */
    return (0);
}