#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	extern char **environ;

	while (*environ != NULL)
	printf("%s\n", *environ++);
}
