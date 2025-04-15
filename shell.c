#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - execute a mini shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 32;
	ssize_t characters;
	pid_t pid;
	char *argv[2] = {buffer, NULL};
	extern char **environ;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters != -1)
		{
			buffer[strlen(buffer) - 1] = '\0';
			argv[0] = buffer;

			pid = fork();
			if (pid == -1)
			{
				perror("Error:");
			}
			else if (pid == 0)
			{
				if (execve(argv[0], argv, environ) == -1)
				{
					perror("Error:");
				}
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			break;
		}
	}
	free(buffer);
	return (0);
}
