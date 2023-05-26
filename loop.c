#include "main.h"
/**
 * loop - looping for input and tokenizing it
 * Return: array of string that holds the input
 */
char **loop(void)
{
	size_t n = 0;
	char **argv = NULL, *buff = NULL, *buff_cpy = NULL;
	int i = 0, argc = 0;
	char *token = NULL;
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
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
	{
		free(buff_cpy);
		free(buff);
		return (NULL);
	}
	argc = 0;
	i = 0;
	token = strtok(buff_cpy, " \n");
	while (token)
	{
		argv[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	free(buff);
	free(buff_cpy);
	return (argv);
}
