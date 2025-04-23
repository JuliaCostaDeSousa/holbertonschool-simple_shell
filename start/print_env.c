#include "main.h"

/**
 * print_env - print the environnement
 */
void print_env(void)
{
	while (*environ != NULL)
	printf("%s\n", *environ++);
}
