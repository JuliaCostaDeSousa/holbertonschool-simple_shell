#include "main.h"
/**
 * fork_call - creation d'un processus enfant
 * @command_array: array avec la commande utilisateur
 * @cmd_count: command count for error
 * @buffer: commande user entière
 */

void fork_call(char **command_array, int cmd_count, char *buffer)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		return;
	}
	if (child_pid == 0)
	{
		errno = 0;
		if (execve(command_array[0], command_array, environ) == -1)
		{
			if (errno == EACCES)
			print_permission_denied(cmd_count, command_array[0]);
			else if (errno == ENOEXEC)
			print_exec_format_error(cmd_count, command_array[0]);
			else if (errno == ENOENT)
			print_not_found(cmd_count, command_array[0]);

			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
