#include "main.h"
/**
 * exit - this is the exit func
 * @argv: the command to check
 * Return: -1 if we arent  exit, i
 */
int _iexit(char **argv)
{
	int i;

	if (strcmp(argv[0], "exit") == 0 && argv[1])
	{
		i = atoi(argv[1]);
		return (i);
	}
	else if (strcmp(argv[0], "exit") == 0)
	return (0);
	else
		return (-1);
}
