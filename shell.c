#include "main.h"
/**
 * main - this is our shell
 * @ac: unusedparam
 * @av: unusedparam
 * @envp: the env param
 * return: exit value
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **envp)
{
	size_t n;
	char **argv = NULL, *buff = NULL;
	int i = 0, argc = 0, exitv = -1;
	char *buff_cpy = NULL, *token = NULL;
	ssize_t exiting;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 4);
		exiting = getline(&buff, &n, stdin);
		if (exiting == -1)
		exit(EXIT_SUCCESS);
		buff_cpy = strdup(buff);
		token = strtok(buff, " \n");
		if (token == NULL)
			continue;
		while (token)
		{
			argc++;
			token = strtok(NULL, " \n");
		}
		argv = malloc(sizeof(char *) * argc + 1);
		if (argv == NULL)
			return (0);
		token = strtok(buff_cpy, " \n");
		for (i = 0; i < argc; i++)
		{
			argv[i] = token;
			token = strtok(NULL, " \n");
		}
		exitv = _iexit(argv);
		if (exitv != -1)
			exit(exitv);
		argv[i] = NULL;
		if (fork() == 0)
			executing(argv, envp);
		else
		{
			wait(NULL);
			argc = 0;
		}
		free(argv);
		free(buff_cpy);
		free(buff);
	}
	return (0);
}
