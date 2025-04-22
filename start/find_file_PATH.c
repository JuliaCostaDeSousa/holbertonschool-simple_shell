#include "main.h"

/**
 * find_in_path - find if cmd file is in path
 * @command_array: user cmd
 * @environnement: env
 * Return: if found return new path else return NULL
 */
char *find_in_path(char **command_array, char **environnement)
{
	char **array_path = NULL;
	char *path = getenv("PATH"), *new_path = NULL, *dossier = NULL, *path_copy, *dossier_copy, *new_dossier_copy;
	unsigned int j, check_found = 0;
	struct stat st;

	if (path == NULL)
	{
		printf("La variable PATH n'est pas définie.");
		return (NULL);
	}

	path_copy = strdup(path);
	array_path = split_string(path_copy, ":");
	
	check_found = 0;
	printf("file to check : %s\n", command_array[0]);

	for (j = 0; array_path[j] != NULL; j++)
	{
		dossier_copy = strdup(array_path[j]);
		dossier = strcat(dossier_copy, "/");
		if (dossier == NULL)
		return (NULL);
		new_dossier_copy = strdup(dossier);
		new_path = strcat(new_dossier_copy, command_array[0]);
		if (new_path == NULL)
		return (NULL);
		printf("original path : %s\n", array_path[j]);
		printf("new path : %s\n", new_path);
		if (stat(new_path, &st) == 0)
		{
			check_found = 1;
			printf("Found in PATH : %s\n", new_path);
			return (new_path);
		}
		free(new_path);
		free(dossier_copy);
	}
	if (check_found == 0)
	{
		perror("Error:");
		printf("Not found in PATH\n");
	}
	
	free(path_copy);
	free_array(array_path);
	return (NULL);
}