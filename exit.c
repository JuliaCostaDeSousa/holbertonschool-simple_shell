#include "main.h"

/**
 * handle_exit - quitte le shell proprement
 * @buffer: ligne de commande à libérer
*/

void handle_exit(char *buffer)
{
	if (buffer)
	free(buffer);
	exit(EXIT_SUCCESS);
}
