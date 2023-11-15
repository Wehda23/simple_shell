#include "waheed.h"

/**
 * execute_command - execute shell commands. 
 * @cmd: command lines.
 * @file: file name of shell. 
 */
void execute_command(char **cmd, char *file)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(file);
        }
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0)
    {
        perror(file);
    } 
    else
    {

        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}