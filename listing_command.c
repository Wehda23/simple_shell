#include "waheed"


/**
 * ls_command - functions that list a directory 
 * @commands: command pass in to the function
 */
void ls_command(char **commands, char *file)
{
    if (execve("/bin/ls", commands, NULL) == -1)
    {
        perror(file);
    }
}