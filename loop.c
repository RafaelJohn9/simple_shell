#include "main.h"
/**
 * loop - looping for input and tokenizing it
 * Return: array of string that holds the input
 */

char **loop(void)
{
	size_t n;
	char **argv = NULL, *buff = NULL;
	int i = 0, argc = 0;
	char *buff_cpy = NULL, *token = NULL;
	ssize_t exiting;

	exiting = getline(&buff, &n, stdin);
	if (exiting == -1)
		exit(EXIT_SUCCESS);
	buff_cpy = strdup(buff);
	token = strtok(buff, " \n");
	if (!token)
		return (NULL);
	while (token)
	{
		argc++;
		token = strtok(NULL, " \n");
	}
	argv = malloc(sizeof(char *) * argc + 1);
	argc = 0;
	i = 0;
	token = strtok(buff_cpy, " \n");
	while (token)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	return (argv);
}
