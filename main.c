#include "main.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	/* Initialize variables */
	ssize_t r = 0; /* Stores the return value of get_input() */
	int builtin_ret = 0; /* Stores the return value of find_builtin() */

	/* Main shell loop */
	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info); /* Clear the info struct */
		if (interactive(info)) /* Check if shell is running in interactive mode */
			_puts("$ "); /* Print the shell prompt */
		_eputchar(BUF_FLUSH); /* Flush the output buffer */
		r = get_input(info); /* Get user input */
		if (r != -1)
		{
			set_info(info, av); /* Set the info struct with command line arguments */
			builtin_ret = find_builtin(info); /* Check if the command is a builtin */
			if (builtin_ret == -1)
				find_cmd(info); /* Find and execute the command */
		}
		else if (interactive(info))
			_putchar('\n'); /* Print a \n if shell is in interactive mode */
		free_info(info, 0); /* Free allocated memory in the info struct */
	}

	write_history(info); /* Write command history to file */
	free_info(info, 1); /* Free allocated memory in the info struct and exit */

	if (!interactive(info) && info->status)
		exit(info->status); /* Exit if in not in interactive mode */

	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status); /* Exit  if builtin signals exit() */
		exit(info->err_num); /* Exit with error number if builtin signals exit */
	}

	return (builtin_ret); /* Return the final return value of the shell */
}

/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
