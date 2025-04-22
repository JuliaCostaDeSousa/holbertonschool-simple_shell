#ifndef MAIN_H
#define MAIN_H

extern char **environ;
int main(int ac, char **av, char **env);
char *_getenv(const char *name);
char **split_line(char *input, char *separator);

#endif
