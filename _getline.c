#include "main.h"
/**
 * _getline - this is my own implementation for getline
 * @line: the buffer to hold the input
 * @n: the num of chars "kinda useles"
 * @fp:the file pointer
 * Return: num of bites because it will only return -1 if fails
 */
ssize_t _getline(char **line, size_t *n, FILE *fp)
{
	size_t bufflen = 120;
	static ssize_t j;
	ssize_t k;
	int i = 0;
	char *buff;
	char c;

	if (j == 0)
	{
		fflush(fp);
	}
	else
	{
		return (-1);
	}
	j = 0;
	buff = malloc(sizeof(char) * (*n));
	while (c != '\n')
	{
		if (i == (int)(*n) - 1)
		{
			buff = realloc(buff, bufflen);
		}
		else if (i == (int)bufflen - 1)
		{
			bufflen = bufflen * 2;
			buff = realloc(buff, bufflen);
		}
		c = fgetc(fp);
		if (1 == -1 || (i == 0 && j == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && j != 0)
		{
			j++;
			return (-1);
		}
		buff[j] = c;
		j++;
	}
	buff[j] = '\0';
	*line = malloc(bufflen);
	strcpy(*line, buff);
	k = j;
	if (i != 0)
	{
		j = 0;
	}
	free(buff);
	return(k);
}
