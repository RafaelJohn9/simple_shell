#include "main.h"
/**
 * envi - this is enviro dealing with path
 * @command: the command to check for
 * Return: the path that works
 */
char *envi(char *command)
{
	char *cmd = NULL, *cmd_cpy = NULL, *env_list = NULL;
	char *env_token = NULL;
	int command_length, token_length;
	struct stat buffer;

	cmd = getenv("PATH");
	cmd_cpy = strdup(cmd);
	command_length = strlen(command);
	env_token = strtok(cmd_cpy, ":");
	while (env_token)
	{
		token_length = strlen(env_token);
		env_list = malloc(token_length + command_length + 2);
		if (env_list == NULL)
		{
		free(cmd);
		return (0);
		}
		env_list = strdup(env_token);
		strcat(env_list, "/");
		strcat(env_list, command);
		strcat(env_list, "\0");
		if (stat(env_list, &buffer) == 0)
		{
			free(cmd_cpy);
			return (env_list);
		}
		else
		{
			free(env_list);
			env_token = strtok(NULL, ":");
		}
	}
	free(cmd_cpy);
	if (stat(command, &buffer) == 0)
		return (command);

	return (NULL);
}
