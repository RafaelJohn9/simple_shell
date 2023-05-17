#include "main.h"
/**
 * print_env:prints environ
 */
void print_env(void)
{
	char **env = environ;
	
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * envi-this is my envirnoment to deal with path
 * @command:command received
 * Return:always 0
 */
char *envi(char *command)
{
	char *cmd = NULL, *env_list = NULL;
	int command_length, token_length;

	cmd = "/bin";
	token_length = strlen(cmd);
	command_length = strlen(command);
	env_list = malloc(token_length + command_length + 2);
	if (env_list == NULL)
	{
		perror("Failed to allocate memory");
		return NULL;
	}
	strcpy(env_list, cmd);
	strcat(env_list, "/");
	strcat(env_list, command);
	printf("Checking:%s\n", env_list); 
	if (access(env_list, F_OK | X_OK) == 0)
	{
		return (env_list);
	}
	else
	{
		free(env_list);
		perror("File does not exist or cannot be accessed");
		perror("no such file exist");
	}
	return (env_list);
}
