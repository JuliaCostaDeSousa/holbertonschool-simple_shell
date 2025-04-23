#include "main.h"

/**
 * handle_exit - termine proprement le processus en libérant la mémoire
 * @buffer: pointeur vers la ligne de commande à libérer
*/

void handle_exit(char *buffer)
{
	free(buffer);
	exit(0);
}

