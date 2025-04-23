#include "main.h"

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
	free(temp_str);

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
			free_array(array);
			return (NULL);
		}
		str = strtok(NULL, delimiter);
		i++;
	}
	array[i] = NULL;
	free(temp_str);
	return (array);
}
