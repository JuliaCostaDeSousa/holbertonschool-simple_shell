#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * split_string - split a string
 * @buffer: string to split
 * @delimiter: delimiter
 * Return: array of words
 */
char **split_string(char *buffer, char *delimiter)
{
	int count_word = 0, i = 0;
	char *str, *temp_str;
	char **array;

	if (buffer == NULL)
	return (NULL);
	
	temp_str = strdup(buffer);
	if (temp_str == NULL)
	return (NULL);
	str = strtok(temp_str, delimiter);
	while (str != NULL)
	{
		count_word++;
		str = strtok(NULL, delimiter);
	}
	free (temp_str);

	array = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (array == NULL)
	return (NULL);

	temp_str = strdup(buffer);
	if (temp_str == NULL)
	return (NULL);
	str = strtok(temp_str, delimiter);
	while (str != NULL)
	{
		array[i] = strdup(str);
		if (array[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			free(array[j]);

			free(array);
			return (NULL);
		}
		str = strtok(NULL, delimiter);
		i++;
	}
	array[i] = NULL;
	return (array);
}

void free_array(char **array)
{
	int i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);  // Libérer chaque mot
		i++;
	}
	free(array);  // Libérer le tableau lui-même
}


int main(void)
{
	char *buffer = NULL, *argv[2];
	char **words;
	size_t len = 0;
	ssize_t read;
	extern char **environ;
	int status;
	pid_t child_pid;

	while (1)
	{
		printf("#Julia_SSS$ ");
		read = getline(&buffer, &len, stdin);
		if (read != -1)
		{
			if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';

			words = split_string(buffer, " ");
			if (words != NULL && words[1] == NULL)
			{
				child_pid = fork();
				if (child_pid == -1)
				{
					printf("Echec du fork.\n");
					perror("Error:");
				}
				if (child_pid == 0)
				{
					argv[0] = words[0];
					argv[1] = NULL;
					if (access(words[0], X_OK) == 0)
					{
						if (execve(argv[0], argv, environ) == -1)
						{
							printf("Echec de l'éxecution de la commande.\n");
							perror("Error:");
						}
					}
					else
					{
						printf("Commande non trouvée.\n");
						perror("Error:");
					}                   
				}
				else
				{
					wait(&status);
				}
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
	return (0);
}
