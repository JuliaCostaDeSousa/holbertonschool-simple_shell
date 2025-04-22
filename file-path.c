#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

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
