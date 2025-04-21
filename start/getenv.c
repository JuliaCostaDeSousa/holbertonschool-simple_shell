#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * _getenv - gets an environment variable
 * @name: name of an environment variable to check
 * Return: valeur de la variable d'environnement ou NULL
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0, equal_index = 0, len_env = 0;
	char *ptr_equal = NULL, *var_nom = NULL, *var_valeur = NULL;

	if (name == NULL)
	return (NULL);

	while (environ[i] != NULL)
	{
		ptr_equal = strchr(environ[i], '=');
		equal_index = ptr_equal - environ[i];

		len_env = strlen(environ[i]);
		var_nom = malloc(equal_index + 1);
		if (var_nom == NULL)
		return (NULL);
		var_nom = strncpy(var_nom, environ[i], equal_index);
		var_nom[equal_index] = '\0';
		var_valeur = malloc(len_env - equal_index + 1);
		var_valeur = strncpy(var_valeur, ptr_equal + 1, len_env - equal_index - 1);
		var_nom[len_env - equal_index - 1] = '\0';
		if (strcmp(name, var_nom) == 0)
		return (var_valeur);
		i++;
	}

	return (NULL);
}


/**
 * main - getenv example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	const char *env_var_name = "LS_COLORS";
	char *env_var_value = NULL;

	env_var_value = _getenv(env_var_name);
	if (env_var_value == NULL)
	return (-1);
	else
	printf("%s = %s\n", env_var_name, env_var_value);

	return (0);
}