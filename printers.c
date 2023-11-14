#include "waheed.h"



/**
 * print_commands - function that prints all commands entered
 * @commands: list commands entered
 */
void print_commands(char **commands)
{
    int index = 0;
    while (commands[index] != NULL)
    {
        printf("Command entered: %s\n", commands[index]);
        index++;
    }
}