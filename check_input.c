#include "main.h"

/**
 * check_input - check if built-in
 * @buffer: user cmd
 * Return: 0 if not built-in, 1 if built-in
 */

int check_input(char *buffer)
{
	if (strcmp(buffer, "env\n") == 0)
	{
		print_env();
		return (1);
	}
	else if (strcmp(buffer, "exit\n") == 0)
	{
		handle_exit(buffer);
	}
	else if (strcmp(buffer, "^C\n") == 0)
	{
		handle_exit(buffer);
	}
	else if (strcmp(buffer, "^D\n") == 0)
	{
		handle_exit(buffer);
	}

	return (0);
}
