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
        int i = 1;
        if (commands[1] != NULL) {
            while (commands[i] != NULL) {
                if (strcmp(commands[i], "$$") == 0) {
                    printf("%d", getpid());
                } else if (strcmp(commands[i], "$?") == 0) {
                    printf("%d", WEXITSTATUS(status));
                } else {
                    printf("%s", commands[i]);
                }

                if (commands[i + 1] != NULL) {
                    printf(" ");
                }
                i++;
            }
        }
        printf("\n");

        exit(EXIT_SUCCESS);
    } else {
        waitpid(pid, &status, 0);
    }
}

/**
 * exit_command - Exit shell
 * @commands: command pass in to the function
 * @file: execution file name.
 */
void exit_command(char **commands)
{
    if (commands[1] != NULL) {
        int exit_status = atoi(commands[1]);
        exit(exit_status);
    } else {
        exit(EXIT_SUCCESS);
    }
}