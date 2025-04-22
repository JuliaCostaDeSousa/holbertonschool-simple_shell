#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "main.h"

/**
 * main - find file in path
 * @argc: number of argument
 * @argv: array of characters
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	const char *name = "PATH";
	char *path = getenv(name);
	struct stat st;
	int i = 0;

	if (path == NULL)
	return (-1);

	char *path_copy = strdup(path);
	char **paths = split_line(path_copy, ":");

	for (i = 0; paths[i]; i++)
	{
		printf("%s\n", paths[i]);
	}

	if (argc != 2)
	{
		printf("Usage: %s _which filename ...\n", argv[0]);
		return (1);
	}
	else
	{
		if (stat(argv[1], &st) == 0)
		{
			printf(" FOUND\n");
			return (0);
		}
		else
		{
			printf(" NOT FOUND\n");
			return (-1);
		}
	}

	for (i = 0; paths[i]; i++)
	free(paths[i]);
	free(path_copy);
	free(paths);
	return (0);
}
