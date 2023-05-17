#include "main.h"
/**
 * this is my executing function
 * i guess we have to take our command as a param
 */
void executing(char **argv)
{
	char *path = NULL;
	int status;
	pid_t child;

	if (strcmp(argv[0], "env\n") == 0)
	{
		print_env();
		return;
	}
	if (strcmp(argv[0], "exit\n") == 0)
	{
		exit(0);
	}
	path = envi(argv[0]);
	printf("Executing command: %s\n", path);
	if (path == NULL)
	{
		printf("Command not found: %s\n", argv[0]);
		return;
	}
	printf("Executing: %s\n", path);
	child = fork();
	if (child < 0)
	{
		perror("unable to fork");
		exit(0);
	}
	else if (child == 0)
	{
		execve(path, argv, NULL);
		perror("execve");
		exit(0);
	}
	else
	{
		waitpid(child, &status, 0);
	}
}
