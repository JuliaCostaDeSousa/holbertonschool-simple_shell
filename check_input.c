#include "main.h"

/**
 * check_input - check if built-in
 * @buffer: user cmd
 * Return: 0 if not built-in, 1 if built-in
 */

int check_input(char *buffer)
{
	if (buffer == NULL)
	exit(EXIT_SUCCESS);

	if (strcmp(buffer, "env\n") == 0)
	{
		print_env();
		return (1);
	}
	else if (strcmp(buffer, "exit\n") == 0)
	{
		handle_exit(buffer);
	}

	if (buffer[0] == '\n' || buffer[0] == '\0' || buffer[0] == ' ')
	return (1);

	return (0);
}
