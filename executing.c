#include "main.h"
/**
 * this is my executing function
 * i guess we have to take our command as a param
 */
void executing(char **argv, char **envp)
{
	char *path = NULL;
	int err;

	else if(strcmp(argv[0], "cd") == 0)
	{
	changedir((const char *)argv[1], argv[2]);
	}
	else
	{
	path = envi(argv[0]);
	err = execve(path,  argv, envp);
	if (err == -1)
		_err(argv[0]);
}
}
