#include "main.h"

/**
 * main - Super Simple Shell
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char **words;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("#Julia_SSS$ ");
		read = getline(&buffer, &len, stdin);
		if (read != -1)
		{
			words = split_string(buffer, " \n");
			if (words != NULL && words[1] == NULL)
			{
				fork_call(words, env);
			}
			else if (words == NULL)
			{
				printf("Erreur d'allocation mémoire.\n");
			}
			else
			{
				printf("On a dit un seul argument chacal.\n");
				free_array(words);
			}
		}
		else
		{
			break;
		}
	}
	free(buffer);
	buffer = NULL;
	len = 0;
	return(0);
}
