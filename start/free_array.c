#include "main.h"
/**
 * free_array - free an array of str
 * @array: array to set free
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
