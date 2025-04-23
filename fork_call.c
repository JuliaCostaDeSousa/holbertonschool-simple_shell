#include "main.h"
/**
 * fork_call - creation d'un processus enfant
 * @command_array: array avec la commande utilisateur
 * @env: environnement
 * @buffer: commande user entière
 */

void fork_call(char **command_array, char **env, char *buffer)
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
		if (execve(command_array[0], command_array, env) == -1)
		{
			if (errno == EACCES)
			print_permission_denied(command_array[0]);
			else if (errno == ENOEXEC)
			print_exec_format_error(command_array[0]);
			else if (errno == ENOENT)
			print_not_found(buffer);

			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
