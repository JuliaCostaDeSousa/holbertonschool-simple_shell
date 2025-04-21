#include "main.h"

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
