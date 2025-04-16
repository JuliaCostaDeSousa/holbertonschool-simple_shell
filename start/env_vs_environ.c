#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("environ : %p\n", (void *)&environ[i]);
        i++;
    }
    i = 0;
    while (env[i] != NULL)
    {
        printf("env : %p\n", (void *)&env[i]);
        i++;
    }
}
