#include "main.h"

/**
 * main - this is our shell
 * @ac: unusedparam
 * @av: unusedparam
 * @envp: the env param
 * Return: exit value
 */
int main(int ac, __attribute__((unused))char **av, char **envp)
{
	char **argv = NULL, *buff = NULL;
	int exitv = -1;

	(void)ac;
	while (1)
	{
		write(STDIN_FILENO, ":) ", 4);
		argv = loop();
		if (argv == NULL)
			continue;
		if (strcmp(argv[0], "exit") == 0)
		{
			exitv = _iexit(argv);
			if (exitv != -1)
				exit(exitv);
		}
		buff = command(argv[0]);
		if (buff)
		{
			executing(buff, argv, envp);
		}
		free(argv);
		free(buff);
			continue;
	}
	return (0);
}
