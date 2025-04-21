include "main.h"

/**
 * main - Test du programme
 * Return: Always 0.
 */
int main(void)
{
	char **words;
	char *buffer = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&buffer, &len, stdin);
	if (read != -1)
	{
		words = split_string(buffer, " \n");
		if (words != NULL)
		{
			for (int i = 0; words[i] != NULL; i++)
			printf("Word %d: %s\n", i, words[i]);

			free_array(words);
		}
		else
		printf("Erreur d'allocation mémoire.\n");
	}

	free(buffer);
	return(0);
}
