#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: name of an environment variable to check
 * Return: valeur de la variable d'environnement ou NULL
 */
char *_getenv(const char *name)
{
	int i = 0, equal_index = 0, len_env = 0;
	char *var_nom = NULL, *var_valeur = NULL, *result = NULL, *env_copy = NULL;

	if (name == NULL)
	return (NULL);

	while (environ[i] != NULL)
	{

		env_copy = strdup(environ[i]);
		if (env_copy == NULL)
		return (NULL);

		var_nom = strtok(env_copy, "=");
		var_valeur = strtok(NULL, "");

		if (var_nom && var_valeur && strcmp(name, var_nom) == 0)
		{
			result = strdup(var_valeur);
			free(env_copy);
			return (result);
		}
		free(env_copy);
		i++;
	}

	return (NULL);
}
