#include "main.h"
/**
 * free_array - libère l'espace mémoire d'un tableau de char *
 * @array: tableau de char * à libérer
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
