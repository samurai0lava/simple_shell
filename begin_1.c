#include "shell.h"

/**
 * _begin - Execute a command in a child process
 * @args: Array of command arguments
 * Return: 1 on success, -1 on failure
 */
int _begin(char **args)
{
	pid_t pid;
	int stat;
	char *cmd;

	pid = fork();
	if (pid == 0)
	{
		cmd = get_thepath(args[0]);
		if (cmd)
		{
			execve(cmd, args, NULL);
		}
		else
		{
			perror("command not found");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		perror("error forking");
	}
	else
	{
		do {
			waitpid(pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}

	return (1);
}

