#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Executes "ls -l /tmp" in 5 child processes
 *
 * Return: Always 0.
 */

int main(void)
{
	int i;
	pid_t pid;
	char *argv[] = {"ls", "-l", "/tmp", NULL};
	extern char **environ;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			execve("/bin/ls", argv, environ);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
