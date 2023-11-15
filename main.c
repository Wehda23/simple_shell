#include "waheed.h"


/**
 * main - Entry function for simple shell
 * Return: 0 in case of success otherwise 1 in case of failure.
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    char *read_input, **cmd;
    int index = 0;
    
    while (1)
    {
        prompt();
        read_input = getUserInput();
        cmd = cmd_parser(read_input, " ");

        while (cmd[index] != NULL)
        {
            cprint(cmd[index]);
            cprint("\n");
            index++;
        }
        free_cmd_result(cmd);
    }
    return (0);
}