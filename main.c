#include "waheed.h"



int main()
{
    char read_commands[COMMAND_BUFFER_SIZE]; /* Buffer to read user input */
    int nread = 0;

    while (1)
    {   
        prompt(); /* Prompt ($ )*/
        nread = _getline(STDIN_FILENO, read_commands, COMMAND_BUFFER_SIZE);
        printf("%d\n", nread);

        if (nread > 0)
        {
            printf(" You entered : %s", read_commands);
        }
        else
        {
            perror("Program failed to read commands.");
            exit(EXIT_FAILURE);
        }
        
    }
    return (0);
}