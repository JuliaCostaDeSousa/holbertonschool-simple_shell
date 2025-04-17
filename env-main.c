#include <stdio.h>

/**
 * main - prints the environment
 * @ac: the number of arguments passed to the program
 * @av: an array of strings (pointers to char)
 * @env: array of strings that represents the environment
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
