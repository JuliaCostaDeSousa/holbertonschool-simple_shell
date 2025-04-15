#include <stdio.h>
#include <string.h>

/**
 * main - 2.av.c
 * Return: Always 0.
 */

int main(void)
{
	char str[] = "Geeks for Geeks";
	char *token;

	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	return (0);
}
