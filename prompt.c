#include <stdio.h>
#include <stdlib.h>

/**
 * main - prompt.c
 * Return: Always 0.
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 32;
	ssize_t characters;

	printf("$ ");
	characters = getline(&buffer, &bufsize, stdin);
	if (characters != -1)
	printf("%s", buffer);
	free(buffer);

	return (0);
}
