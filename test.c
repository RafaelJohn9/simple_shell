#include "main.h"

int main()
{
	char input[] = "Hello, World! This is a test.";
	const char delim[] = " ,.!";
	char *token;
	char *token2;

	token = _strtok(input, delim);
	while (token != NULL)
	{
		printf("%s\n", token);
		free(token);
		token = _strtok(NULL, delim);
	}
	token2 = _strtok(input, delim);
	while (token2 != NULL)
	{
		printf("%s\n", token2);
		free(token2);
		token2 = _strtok(NULL, delim);
	}
	return 0;
}
