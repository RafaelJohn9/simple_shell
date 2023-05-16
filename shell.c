#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

int main(void)
{
	char input[MAX_LEN], *token = NULL, *delim = " \n\t", *arg[MAX_LEN] = {NULL};
	int count = 0;
	int *status = malloc(sizeof(int));
	pid_t child;

	while (1)
	{
		printf(">>>");
		if (fgets(input, MAX_LEN, stdin) == NULL || input[0] == '\n')
		{
			break;
		}
		token = strtok(input, delim);
		arg[count++] = strdup(token);
		while (token)
		{
			token = strtok(NULL, delim);
			if (token)
			{
				arg[count++] = strdup(token);
			}
		}
		arg[count] = NULL;
		child = fork();
		if (child == 0)
		{
			if (execve(arg[0], arg, NULL) == -1)
			{
				perror("invalid arg;");
				break;
			}
		}
		else if (child < 0)
		{
			perror("child not responding");
			exit(-1);
		}
		else
		{
			waitpid(child, status, 0);
		}
		for (int i = 0; i < count; i++)
		{
			free(arg[i]);
			arg[i] = NULL;
		}
		count = 0;
	}
	free(status);
	return (0);
}			
