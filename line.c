#include "main.h"
/**
 * command - recieve tokenize and return the input
 * @command: the command to check for
 * Return: array of string
 */
char *command(char *command)
{
	char *buff = NULL;

	buff = envi(command);
	if (buff)
	{
		return (buff);
	}
	else
	{
		_err(command);
	}
	return (NULL);
}
