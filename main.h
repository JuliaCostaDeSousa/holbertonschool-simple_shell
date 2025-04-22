#ifndef MAIN_H
#define MAIN_H

extern char **environ;
char *_getenv(const char *name);
char **split_line(char *input, char *separator);
void print_env(void);

#endif
