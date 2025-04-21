#include "main.h"

/**
 * fork_call - creation d'un processus enfant
 * @command_array: array avec la commande utilisateur
 * @environnement: environnement
 */

void fork_call(char **command_array, char **environnement)
{
	char *argv[2];
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("Echec du fork.\n");
		perror("Error:");
	}
	if (child_pid == 0)
	{
		argv[0] = command_array[0];
		argv[1] = NULL;
		if (access(command_array[0], X_OK) == 0)
		{
			if (execve(argv[0], argv, environnement) == -1)
			{
				printf("Echec de l'éxecution de la commande.\n");
				perror("Error:");
			}
		}
		else
		{
			printf("Commande non trouvée.\n");
			perror("Error:");
		}                   
	}
	else
	{
		wait(&status);
	}
}
