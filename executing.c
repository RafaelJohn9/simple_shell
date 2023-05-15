#include "main.h"
/**
 * this is my executing function
 * i guess we have to take our command as a param
 */
void executing(char **argv)
{
	char *path = NULL;
	int err;

	path = envi(argv[0]);
	err = execve(path,  argv, NULL);
	if (err == -1)
		perror("ERROR");
}
