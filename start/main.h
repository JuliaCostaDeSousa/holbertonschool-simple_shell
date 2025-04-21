#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char **split_string(char *buffer, char *delimiter);
void free_array(char **array);
void print_env(void);
void fork_call(char **command_array, char **environnement);
#endif
