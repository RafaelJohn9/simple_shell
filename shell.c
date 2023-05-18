#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/wait.h>
int main(int ac, char **av, char **envp)
{
	size_t n;
	char *sign = "^_^:", **argv = NULL, *buff = NULL, *delim = " \n";
	int i = 0, argc = 0, err;
	char *buff_cpy = NULL, *token = NULL, *path = "/bin/";
	ssize_t exiting;

	while (1)
		{
	write(STDIN_FILENO, "^_^ ", 4);
		exiting = _getline(&buff, &n, stdin);
		buff_cpy = strdup(buff);
		token = strtok(buff, delim);
		if (strcmp(token, "exit") == 0 || exiting == -1)
		{
			fflush(stdin);
			printf("Exiting ..\n");
		exit(-1);
		}
	while (token)
		{
			argc++;
		token = strtok(NULL, delim);
		}
	argv = malloc(sizeof(char*) * argc * 5);
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
