#include "main.h"
#include <stdlib.h>

#define MAX 100

/**
 * _strtok - used to tokenize a string
 * @string: the string to be tokenized
 * @delim: the delimiters
 * Return: token
 **/
char *  _strtok(char *string, const char *delim)
{
	static char *str = NULL;
	char *buffer = malloc(MAX);
	int i = 0, j = 0, k = 0;
	
	if (buffer == NULL)
	{
		return NULL;
	}
	if (string != NULL)
	{
		str = string;
	}
	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (delim[j] == str[i])
			{
				str = &str[i + 1];
				return (buffer);			}
			j++;
		}
		buffer[k++] = str[i++];
	}
	buffer[k] = '\0';
	str = NULL;
	return (buffer);
}
