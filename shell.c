#include "main.h"
int main(int ac, char **av, char **envp)
{
	size_t n;
	char **argv = NULL, *buff = NULL, *delim = " \n";
	int i = 0, argc = 0, exitv;
	char *buff_cpy = NULL, *token = NULL, *token2 = NULL;
	ssize_t exiting;

	(void)ac;
	(void)av;
	while (1)
	{
		write(STDIN_FILENO, "#: ", 3);
		exiting = _getline(&buff, &n, stdin);
		buff_cpy = strdup(buff);
		token = strtok(buff, delim);
		while (token)
		{
			argc++;
			token = strtok(NULL, delim);
		}
		argv = malloc(sizeof(char *) * argc * 5);
		token = strtok(buff_cpy, delim);
		for (i = 0; i < argc; i++)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
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
	}
	return (0);
}
