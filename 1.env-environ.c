#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - main
* @ac: the number of arguments passed to the program
 * @av: an array of strings (pointers to char)
 * @env: array of strings that represents the environment
 * Return: always 0
 */

int main(int ac, char **av, char **env)
{
	int i = 0;
	extern char **environ;

	while (environ[i] && env[i] != NULL)
	{
		printf("Address of environ: %p\n", (void *) &environ);
		printf("Address of env: %p\n", (void *) &env);
		i++;
	}

	return (0);
}
