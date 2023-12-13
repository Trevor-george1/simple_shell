#include "shell.h"
/**
 * print_environment - prints the env
 *
 * Return: Northing
 */
void print_environment(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
