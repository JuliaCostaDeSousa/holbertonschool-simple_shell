#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

int check_input(char *buffer);
void check_file(char **words, int cmd_count, char *buffer);
void print_not_found(int cmd_count, char *buffer);
void print_permission_denied(int cmd_count, char *cmd);
void print_exec_format_error(int cmd_count, char *cmd);
void fork_call(char **command_array, int cmd_count, char *buffer);
char *_getenv(const char *name);
void free_array(char **array);
char *build_path(char *path_dir, char *command);
char *find_in_path(char **command_array);
char **split_string(char *buffer, char *delimiter);
void print_env(void);
void handle_exit(char *buffer);

#endif
