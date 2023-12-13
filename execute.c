#include "shell.h"
/**
 * executeCommand - function that executes a command
 * @command: command
 * @program_name: program name
 *
 * @args: args
 * Return: 0 or 1
 */
void executeCommand(char *command, char **args, char *program_name)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(command, args);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			fprintf(stderr, "%s: 1  %s: No such file or directory\n",
			program_name, command);
		}
	}
}
