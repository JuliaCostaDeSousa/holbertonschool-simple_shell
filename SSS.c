#include "main.h"

/**
 * main - Super Simple Shell
 * Return: Always 0.
 */

int main(__attribute__((unused)) int ac,__attribute__((unused)) char **av, char **env)
{
	char *buffer = NULL;
	char **words;
	size_t len = 0;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO);
	int cmd_count = 0;

	while (1)
	{
		if (interactive)
			printf("#cisfun$ ");
		read = getline(&buffer, &len, stdin);
		if (read != -1)
		{
			cmd_count++;
			if (check_input(buffer) == 1)
			continue;
			words = split_string(buffer, " \n");
			if (words != NULL)
			{
				check_file(words, env, cmd_count);
			}
		}
		else
		{
			free(buffer);
			if (interactive)
			printf("\n");
			exit(0);
		}
		free(buffer);
		buffer = NULL;
		len = 0;
	}
	return (0);
}
