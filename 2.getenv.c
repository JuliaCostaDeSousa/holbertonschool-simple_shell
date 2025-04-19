#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _getenv - search the environment list
 * @name: environment variable name
 * Return: pointer to the value string or NULL if it doesn't exist
 */

char *_getenv(const char *name)
{
	int i = 0;
	extern char **environ;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
		environ[i][strlen(name)] == '=')
		{
			return (environ[i] + strlen(name) + 1);
		}

		i++;
	}

	return (NULL);
}

