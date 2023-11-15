#include "waheed.h"

/**
 * execute_command - execute shell commands. 
 * @cmd: command lines.
 * @file: file name of shell.
 * Return: 0 in case of success else failure.
 */
int execute_command(char **cmd, char *file)
{
    int status;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror(file);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (0);
		else if (WEXITSTATUS(status) == 2)
			return (2);
		else if (WEXITSTATUS(status) == 127)
			return (127);
	}
	return (127);
}


/**
 * execute_echo - function that execute echo builtin.
 * @cmd: commands parsed from cmd_parse.
 * Return: 0 Upon Success -1 Upon Failure.
 */
int execute_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}