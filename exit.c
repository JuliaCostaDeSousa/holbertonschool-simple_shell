#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_exit - quitte le shell proprement
 * @buffer: ligne de commande à libérer
 * @words: tableau de mots à libérer
*/

void handle_exit(char *buffer)
{
	if (buffer)
		free(buffer);
	printf("\n");
	exit(0);
}
