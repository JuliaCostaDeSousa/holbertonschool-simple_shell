#include "main.h"

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char **array_path = NULL;
	char *path = getenv("PATH"), *new_path = NULL, *dossier = NULL, *path_copy, *dossier_copy, *new_dossier_copy;
	unsigned int i, j, check_found = 0;
	struct stat st;

	if (path == NULL)
	{
		printf("La variable PATH n'est pas définie.");
		return (1);
	}

	if (ac != 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	path_copy = strdup(path);
	array_path = split_string(path_copy, ":");
	while (av[i])
	{
		check_found = 0;
		printf("file to check : %s\n", av[i]);

		for (j = 0; array_path[j] != NULL; j++)
		{
			dossier_copy = strdup(array_path[j]);
			dossier = strcat(dossier_copy, "/");
			if (dossier == NULL)
			return (1);
			new_dossier_copy = strdup(dossier);
			new_path = strcat(new_dossier_copy, av[i]);
			if (new_path == NULL)
			return (1);
			printf("original path : %s\n", array_path[j]);
			printf("new path : %s\n", new_path);
			if (stat(new_path, &st) == 0)
			{
				check_found = 1;
				printf("Found in PATH : %s\n", new_path);
				break;
			}
			free(new_path);
			free(dossier_copy);
		}
		i++;
		if (check_found == 0)
		{
			perror("Error:");
			printf("Not found in PATH\n");
		}
	}

	free_array(array_path);
	return (0);
}