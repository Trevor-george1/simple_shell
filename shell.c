#include "shell.h"
/**
 * main - driver for shell
 * @ac: number of arguments
 * @argv: pointer to string
 *
 * Return: 0
 */
int main(int ac, char *argv[])
{
	FILE *input_stream = stdin;
	bool interactive_mode = isatty(fileno(stdin)) && isatty(fileno(stdout));
	char *line, command[MAX_COMMAND_LENGTH], *args[MAX_ARG_COUNT], *program_name;
	size_t arg_count;

	program_name = (ac > 0) ? argv[0] : "shell";

	while (1)
	{
		if (interactive_mode)
		{
		write(1, "#cisfun$ ", 9);
		}
		line = get_line1();
		if (line == NULL)
		{
			if (interactive_mode)
			{
			printf("\n");
			}
			break;
		}
		if (strcmp(line, "exit") == 0)
		{
			exit(0);
		}
		else if (strncmp(line, "exit ", 5) == 0)
		{
			int status = atoi(line + 5);

			free(line);
			exit(status);
		}
		if (strcmp(line, "env") == 0 && arg_count == 0)
		{
			print_environment();
		}
		parse_arguments(line, command, args, &arg_count);
		executeCommand(command, args, program_name);
		free(line);
	}
	if (input_stream != stdin)
		fclose(input_stream);
	return (0);
}
