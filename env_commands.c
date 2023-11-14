#include "waheed.h"



void print_env(char *file)
{
    pid_t pid = fork();
    int status;
    if (pid == -1)
    {
        perror(file);
    } 
    else if (pid == 0)
    {
        for (char **env = environ; *env != NULL; env++)
        {
            printf("%s\n", *env); /* Print each environment variable */
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}