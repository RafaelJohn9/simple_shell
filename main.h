#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
char  *envi(char *command);
char * _strtok(char *string, const char *delim);
void executing(char **argv, char **envp);
ssize_t _getline(char **line, size_t *n, FILE *fp);
void _err(char *arg);
void changedir(const char *str1, char *str2);
int _iexit(char **argv);


#endif
