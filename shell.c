#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/wait.h>
int main(void)
{
	size_t n;
	char *sign = "^_^:", **argv = NULL, *buff = NULL, *delim = " \n";
	int i = 0, argc = 0, err;
	char *buff_cpy = NULL, *token = NULL, *path = "/bin/";

	while (1)
	{
		printf("%s",sign);
		getline(&buff, &n, stdin);
		buff_cpy = strdup(buff);
		token = strtok(buff, delim);
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
 	executing(argv);
	}
	else
	{
		wait(NULL);
	argc = 0;
	printf("lets begin again");
	}
	}
	free(buff_cpy), free(argv);
	return (0);
}
