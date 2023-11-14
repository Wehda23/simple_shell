#include "waheed.h"



void print_env(char *file)
{
    pid_t pid = fork();
    int status;
    char **env;
    
    if (pid == -1)
    {
        perror(file);
    } 
    else if (pid == 0)
    {
        for (env = environ; *env != NULL; env++)
        {
            printf("%s\n", *env); /* Print each environment variable */
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}