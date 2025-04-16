#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 * @argc: nb of argument
 * @argv: value og argument
 * Return: Always 0.
 */
int main(void)
{
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");
    read = getline(&buffer, &len, stdin);
    if (read == -1)
    return (-1);
    printf("%s", buffer);
    free(buffer);
    return (0);
}
