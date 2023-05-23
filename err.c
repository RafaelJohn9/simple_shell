#include "main.h"
/**
 * err - this is my error print function
 * @arg: this is the argument given
 */

void _err(char *arg)
{
	char *a = "hsh: 1: ";
	char *b = " not found";

	write(2, a, strlen(a));
	write(2, arg, strlen(arg));
	write(2, ":", 1);
	write(2, b, strlen(b));
	write(2, "\n", 1);
}
