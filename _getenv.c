#include "main.h"

/**
 * _getenv - permet de récupérer une variable d'environnement
 * @name: nom de la variable d'environnement à récupérer
 * Return: valeur de la variable d'environnement ou NULL
 */
char *_getenv(const char *name)
{
	int i = 0;
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
