#include "waheed.h"


/**
 * ls_command - functions that list a directory
 * @commands: command pass in to the function
 * @file: execution file name.
 */
void ls_command(char **commands, char *file)
{
    pid_t pid = fork();
    int status;
    if (pid == -1) {
        perror(file);
    } else if (pid == 0) {
        if (execve("/bin/ls", commands, NULL) == -1) {
            perror(file);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

/**
 * echo_command - functions that implements echo cmd 
 * @commands: command pass in to the function
 * @file: execution file name.
 */
void echo_command(char **commands, char *file)
{
    pid_t pid = fork();
    int status;
    if (pid == -1) {
        perror(file);
    } else if (pid == 0) {
        if (execve("/bin/echo", commands, NULL) == -1) {
            perror(file);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}


