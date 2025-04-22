#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - function main
 * Return: Always 0
 */
int main(void)
{
	char *value = getenv("PATH");

	if (value)
		printf("PATH is: %s\n", value);
	else
		printf("PATH not found\n");

	return (0);
}
