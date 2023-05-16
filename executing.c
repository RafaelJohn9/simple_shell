#include "main.h"
/**
 * this is my executing function
 * i guess we have to take our command as a param
 */
void executing(char **argv)
{
	char *path = NULL;
	int err;

	if (strcmp(argv[0], "env\n") == 0)
	{
		print_env();
	}
	if (argv[0] == "exit\n")
	{
		exit(0);
	}
	path = envi(argv[0]);
	err = execve(path,  argv, NULL);
	if (err == -1)
	{
		perror("ERROR");
	}
}
