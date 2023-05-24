#include "main.h"
int main(int ac, char **av, char **envp)
{
	size_t n;
	char **argv = NULL, *buff = NULL, *delim = " \n";
	int i = 0, argc = 0;
	char *buff_cpy = NULL, *token = NULL, *token2 = NULL;
	ssize_t exiting;

	(void)ac;
	(void)av;
	while (1)
	{
		write(STDIN_FILENO, "^_^ ", 4);
		exiting = getline(&buff, &n, stdin);
		buff_cpy = strdup(buff);
		if (buff_cpy == NULL)
		{
			continue;
		}
		token = strtok(buff, delim);
		if (strcmp(token, "exit") == 0 || exiting == -1)
		{
			token = strtok(NULL, delim);
			if (token)
			{
				printf("%s\n", token);
			}
			exit(-1);
		}
		else if (strcmp(token, "cd") == 0)
		{
			token = strtok(NULL, delim);
			token2 = strtok(NULL, delim);
			changedir((const char *)token, token2);
			continue;
		}
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
		argv[i] = NULL;
		if (fork() == 0)
		{
			executing(argv, envp);
		}
		else
		{
			wait(NULL);
			argc = 0;
		}
	}
	return (0);
}
