#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **split_line(char *input, char *separator);

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

	if (path == NULL)
	return (-1);

	char *path_copy = strdup(path);
	char **paths = split_line(path_copy, ":");
	struct stat st;
	int i = 0;

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
		}
		else
		{
			printf(" NOT FOUND\n");
		}
		free(path_copy);
	}

	for (i = 0; paths[i]; i++)
	free(paths[i]);
	free(paths);

	return (0);
}

/**
 * split_line - function
 * @input: entry command for user
 * @separator: use for separate the path with ":"
 * Return: Always 0.
 */

char **split_line(char *input, char *separator)
{
	char **tokens = NULL;
	char *token;
	int i = 0;
	int j = 0;
	int bufsize = 10;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		free(input);
		return (NULL);
	}

	token = strtok(input, separator);

	while (token != NULL)
	{
		if (i >= bufsize)
		{
			bufsize *= 2;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (tokens == NULL)
			{
				for (j = 0; j < i; j++)
				free(tokens);
				free(input);
				return (NULL);
			}
		}

		tokens[i] = malloc(strlen(token) + 1);
		if (tokens[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(tokens[j]);
				free(tokens);
				free(input);
				return (NULL);
			}
		}
		strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, separator);
	}

	tokens[i] = NULL;
	return (tokens);
}
