#include "main.h"

/**
 * check_input - check if built-in
 * @buffer: user cmd
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
		handle_exit();
	}
	return (0);
}