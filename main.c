#include "main.h"

/**
 *
 *
 */
int main(void)
{
	char **arg;
	size_t num = 1024;
	size_t *a = &num;

	arg = malloc(1024);
	while (1)
	{
		printf(">>>");
		getline(arg, a, stdin);
		executing(arg);
	}
	return (0);
}
