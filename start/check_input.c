#include "main.h"

/**
 * check_input - check if built-in or ^D
 * @buffer: user cmd
 */

void check_input(char *buffer)
{
	if (strcmp(buffer, "env\n") == 0)
	{
		print_env();
		return ;
	}
	if (strcmp(buffer, "exit\n") == 0)
	{
		handle_exit();
	}
}