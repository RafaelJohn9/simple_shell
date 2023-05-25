#include "main.h"
/**
 * loop - looping for input and tokenizing it
 * Return: array of string that holds the input
 */

char **loop(void)
{
	size_t n = 0;
	char **argv = NULL, *buff = NULL;
	int i = 0, argc = 0, j = 0;
	char *token = NULL;
	ssize_t exiting;

	exiting = getline(&buff, &n, stdin);
	if (exiting == -1)
	{
		free(buff);
		exit(EXIT_SUCCESS);
	}
	token = strtok(buff, " \n");
	if (!token)
	{
		free(buff);
		return (NULL);
	}
	while (token)
	{
		argc++;
		token = strtok(NULL, " \n");
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
	{
		free(buff);
		return (NULL);
	}
	token = strtok(buff, " \n");
	while (token)
	{
		argv[i] = strdup(token);
		if (!argv[i])
		{
			for (j = 0; j < i; j++)
			{
				free(argv[j]);
			}
			free(argv);
			free(buff);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	free(buff);
	return (argv);
}
