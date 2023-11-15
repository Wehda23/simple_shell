#include "waheed.h"


/**
 * main - Entry function for simple shell
 * Return: 0 in case of success otherwise 1 in case of failure.
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    char *read_input, **cmd, **semicolon_cmd;
    int semi_colon_count = 0;

    while (1)
    {
        prompt();
        read_input = getUserInput();
        semicolon_cmd = semicolon_parser(read_input);
        
        while (semicolon_cmd[semi_colon_count])
        {
            cmd = cmd_parser(semicolon_cmd[semi_colon_count++], " ");
            if (exit_check(cmd[0]) == 0)
            {
                cprint("exiting program ");
            }
            else
            {
                print_commands(cmd);
                cprint("Command is: ");
                cprint(cmd[0]);
            }
            cprint("\n");
            free_cmd_result(&cmd);
        }
        semi_colon_count = 0;
        free_semicolon_memory(&semicolon_cmd);
    }
    return (0);
}