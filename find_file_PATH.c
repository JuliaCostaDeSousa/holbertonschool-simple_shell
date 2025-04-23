#include "main.h"

/**
 * build_path - build new path with command and check if exist
 * @path_dir:  directory of the path to check
 * @command: user command
 * Return: pointer to new_path if exist, else NULL
 */
char *build_path(char *path_dir, char *command)
{
	char *new_path = NULL;
	struct stat st;

	if (path_dir == NULL || command == NULL)
	return (NULL);

	new_path = malloc(strlen(path_dir) + strlen(command) + 2);
	if (new_path == NULL)
	return (NULL);

	sprintf(new_path, "%s/%s", path_dir, command);

	if (stat(new_path, &st) == 0)
	return (new_path);

	free(new_path);
	return (NULL);
}

/**
 * find_in_path - find if cmd file is in path
 * @command_array: user cmd
 * Return: if found return new path else return NULL
 */
char *find_in_path(char **command_array)
{
	char **array_path = NULL;
	char *path = _getenv("PATH"), *new_path = NULL, *path_copy = NULL;
	unsigned int j;

	if (path == NULL)
	return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
	return (NULL);
	array_path = split_string(path_copy, ":");
	if (array_path == NULL)
	{
		free(path);
		free(path_copy);
		return (NULL);
	}
	for (j = 0; array_path[j] != NULL; j++)
	{
		new_path = build_path(array_path[j], command_array[0]);

		if (new_path != NULL)
		{
			free(path);
			free(path_copy);
			free_array(array_path);
			return (new_path);
		}
	}
	free(path);
	free(path_copy);
	free_array(array_path);
	return (NULL);
}
