#include "main.h"

/**
 * check_input - check si la commande est un built-in
 * @buffer: commande rentrée par l'utilisateur
 * Return: 1 si c'est un built-in, autrement retourne 0
 */

int check_input(char *buffer)
{
	if (buffer && strcmp(buffer, "env\n") == 0)
	{
		print_env();
		return (1);
	}
	else if (buffer && strcmp(buffer, "exit\n") == 0)
	{
		handle_exit(buffer);
		return (-1);
	}

	if (buffer && (buffer[0] == '\n' || buffer[0] == '\0'))
	return (1);

	return (0);
}
