#include "main.h"

/**
 * main - Super Simple Shell
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *absolut_path = NULL;
	char **words;
	size_t len = 0;
	ssize_t read;
	struct stat st;

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&buffer, &len, stdin);
		if (read != -1)
		{
			if (check_input(buffer) == 1)
			continue;
			words = split_string(buffer, " \n");
			if (words != NULL)
			{
				if (stat(words[0], &st) == 0)
				{
					fork_call(words, env);
					free_array(words);
				}
				else
				{
					absolut_path = find_in_path(words, env);
					if (absolut_path != NULL)
					{
						fork_call(absolut_path, env);
						free_array(words);
					}
					else
					{
						printf("Erreur d'allocation mémoire.\n");
						free_array(words);
					}
				}
			}
		}
		else
		{
			free(buffer);
			printf("\n");
			exit(0);
		}
	}
	free(buffer);
	buffer = NULL;
	len = 0;
	return(0);
}
