#include "shell.h"
/**
 * get_line1 - read line from user
 *
 * Return: number of bytes read
 */

char *get_line1()
{
	char *line = NULL;
	size_t line_size = 0;

	if (getline(&line, &line_size, stdin) == -1)
	{
		/*handle end of file*/
		if (feof(stdin))
		{
			free(line);
			return (NULL);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	line[strcspn(line, "\n")] = '\0';

	return (line);
}


/**
 * parse_arguments - parses argments
 * @line: line
 * @command: command
 * @args: args
 * @arg_count: argument count
 *
 * Return: Nothing
 */
void parse_arguments(char *line, char *command, char **args, size_t *arg_count)
{
	char *token;

	*arg_count = 0;
	token = my_strtok(line, " ");
	strcpy(command, token);

	while (*arg_count < MAX_ARG_COUNT - 1 &&
	(token = my_strtok(NULL, " ")) != NULL)
	{
		args[(*arg_count)++] = token;
	}
	args[*arg_count] = NULL;
}
