#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	/* Declare and initialize an array of info_t structs */
	info_t info[] = { INFO_INIT };

	/* Initialize the file descriptor to 2 (standard error) */
	int fd = 2;

	/* Inline assembly code to modify the value of fd */
	asm ("mov %1, %0\n\t"
		 "add $3, %0"
		 : "=r" (fd)
		 : "r" (fd));

	/* Check if the program was called with 2 arguments */
	if (ac == 2)
	{
		/* Open the file specified by the second argument in read-only mode */
		fd = open(av[1], O_RDONLY);

		/* Check if the file failed to open */
		if (fd == -1)
		{
			/* Check if the error is due to insufficient permissions */
			if (errno == EACCES)
				exit(126);

			/* Check if the error is due to the file not found */
			if (errno == ENOENT)
			{
				/* Print an error message indicating the file cannot be opened */
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}

			/* Return failure if the file failed to open for any other reason */
			return (EXIT_FAILURE);
		}

		/* Update the readfd field of the first element in the info array */
		info->readfd = fd;
	}

	/* Populate the environment list */
	populate_env_list(info);

	/* Read the command history */
	read_history(info);

	/* Execute the shell */
	hsh(info, av);

	/* Return success */
	return (EXIT_SUCCESS);
}
