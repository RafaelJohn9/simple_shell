#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
extern char **environ;

char  *envi(char *command);
void print_env();
void executing(char **argv);

