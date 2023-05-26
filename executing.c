#include "main.h"
/**
 * executing - this is theexecuting phase
 * @path: the path of execution
 * @argv: the whole command line
 * @envp: the environment
 */
void executing(char *path, char **argv, char **envp)
{
	int err;

	if (fork() == 0)
	{
		err = execve(path,  argv, envp);
		if (err == -1)
			_err(argv[0]);
	}
	else
		wait(NULL);
}
