#include "main.h"

/**
 * changedir-changes dir
 * @str1:input str
 * @str2:checks for extra arg
 */
void changedir(const char *str1, char *str2)
{
	const char *home = getenv("HOME");
	static char pwd[199];
	int i;

	if (str2 != NULL)
	{
		printf("too many arguments");
		return;
	}
	if (str1 == NULL)
	{
		getcwd(pwd, 199);
		chdir(home);
		return;
	}
	printf("%s\n", pwd);
	i = chdir(str1);
	if (i == 0)
	{
		getcwd(pwd, 199);
		return;
	}
	else if (strcmp(str1, "~") == 0)
	{
		getcwd(pwd, 199);
		printf("%s\n", pwd);
		chdir(home);
		return;
	}
	else if (strcmp(str1, "-") == 0)
	{
		printf("%s\n", pwd);
		fflush(stdout);
		chdir(pwd);
		return;
	}
	else
	{
		printf("invalid arg");
		return;
	}
	return;
}
