#include "shell.h"
#include <string.h>
/**
 * my_strtok - functin that tokenizes a string
 * @str: string
 * @delimiters: delimiters
 *
 * Return: token
 */
char *my_strtok(char *str, const char *delimiters)
{
	char *nexttoken = NULL;
	char *currenttoken;

	if (str != NULL)
	{
		nexttoken = str;
	}
	else if (nexttoken == NULL)
	{
		return (NULL);
	}
	while (*nexttoken != '\0' && strchr(delimiters, *nexttoken) != NULL)
	{
		nexttoken++;
	}
	if (*nexttoken == '\0')
	{
		nexttoken = NULL;
		return (NULL);
	}
	currenttoken = nexttoken;

	while (*nexttoken != '\0' && strchr(delimiters, *nexttoken) == NULL)
	{
		nexttoken++;
	}
	if (*nexttoken == '\0')
	{
		nexttoken = NULL;
	}
	else
	{
		*nexttoken = '\0';
		nexttoken++;
	}
	return (currenttoken);
}
