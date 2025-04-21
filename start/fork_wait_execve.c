#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	extern char **environ;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int i = 0, status;
	pid_t my_pid, my_ppid, child_pid;

	printf("Before fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);

	for (; i < 5; i++)
	{
		printf("Fork %d\n", i);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			exit (1);
		}
		if (child_pid == 0)
		{
			my_ppid = getppid();
			child_pid = getpid();
			printf("Child %d pid : %u\n", i, child_pid);
			printf("Child %d ppid %u\n", i, my_ppid);

			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Error:");
				exit (1);
			}
		}
		else
		{
			printf("wait for it\n");
			wait(&status);
		}
	}
	return (0);
}
