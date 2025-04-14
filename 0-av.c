#include <stdio.h>

/**
 * main - av
 * @ac: the number of items in av
 * @av: NULL terminated array of strings
 * Return: Always 0.
 */


int main(__attribute__((unused)) int ac, char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
