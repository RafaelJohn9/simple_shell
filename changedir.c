#include "main.h"

/**
 * changedir-changes dir
 * @str1:input str
 * @str2:checks for extra arg
 */
void changedir(const char *str1, char *str2)
{
	const char *home = getenv("HOME");
	static char pwd0[199];
	static char pwd1[199];
	int i;

	if (str2 != NULL)
	{
		fprintf(stderr, "too many arguments\n");
		return;
	}
	if (str1 == NULL)
	{
		getcwd(pwd0, 199);
		chdir(home);
		return;
	}
	getcwd(pwd0, 199);
	i = chdir(str1);
	if (i == 0)
	{
		strcpy(pwd1, pwd0);
		return;
	}
	else if (strcmp(str1, "~") == 0)
	{
		getcwd(pwd1, 199);
		chdir(home);
		return;
	}
	else if (strcmp(str1, "-") == 0)
	{
		printf("%s\n", pwd1);
		fflush(stdout);
		chdir(pwd1);
		return;
	}
	else
	{
		fprintf(stderr, "invalid arg\n");
		return;
	}
	return;
}
