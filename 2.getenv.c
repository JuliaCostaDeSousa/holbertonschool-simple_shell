#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _getenv - search the environment list
 * @name: environment variable name
 * Return: pointer to the value string or NULL if it doesn't exist
 */

char *_getenv(const char *name)
{
	if (name == NULL)
    return (NULL);

	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name) == 0 && environ[i] == '=')
		{
			return (environ[i] + strlen(name) + 1);
		}

		i++;
	}

	return (NULL);
}

