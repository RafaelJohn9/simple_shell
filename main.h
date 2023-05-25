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
void executing(char *path, char **argv, char **envp);
void _err(char *arg);
int _iexit(char **argv);
char *command(char *command);
char **loop(void);
#endif
