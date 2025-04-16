#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/**
  * _strlen - returns the length of a string
  * Description: returns the length of a string
  * @s: string
  * Return: length of a string
  */
unsigned int _strlen(char *s)
{
	unsigned int index = 0;

	while ((*(s + index) != '\0'))
	{
		index++;
	}
	return (index);
}
/**
 * str_concat - concatenates two strings
 *
 * @s1: string 1 to be appended
 * @s2: string to append
 * Return: pointer to new allocated space with s2 appended to s1
 */

char *str_concat(char *s1, char *s2)
{
char *s3 = NULL;
unsigned int index = 0;
unsigned int len_s1;
unsigned int len_s2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
len_s1 = _strlen(s1);
len_s2 = _strlen(s2);

s3 = malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
	{
		return (NULL);
	}
	for (; index < _strlen(s1); index++)
	{
		*(s3 + index) = *(s1 + index);
	}
	for (; index < (_strlen(s1) + _strlen(s2)); index++)
	{
		*(s3 + index) = *(s2 + (index - _strlen(s1)));
	}
*(s3 + index) = '\0';
return (s3);
}

/**
 * split_string - split a string
 * @buffer: string to split
 * Return: array of words
 */
char **split_string(char *buffer)
{
    int count_word = 0, i = 0;
    char *str, *temp_str, *separator = ":";
    char **array;

    if (buffer == NULL)
    return (NULL);
    
    temp_str = strdup(buffer);
    if (temp_str == NULL)
    return (NULL);
    str = strtok(temp_str, separator);
    while (str != NULL)
    {
        count_word++;
        str = strtok(NULL, separator);
    }
    free (temp_str);

    array = (char **)malloc(sizeof(char *) * (count_word + 1));
    if (array == NULL)
    return (NULL);

    temp_str = strdup(buffer);
    if (temp_str == NULL)
    return (NULL);
    str = strtok(temp_str, separator);
    while (str != NULL)
    {
        array[i] = strdup(str);
        if (array[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            free(array[j]);

            free(array);
            return (NULL);
        }
        str = strtok(NULL, separator);
        i++;
    }
    array[i] = NULL;
    return (array);
}

void free_array(char **array)
{
    int i = 0;
    while (array[i] != NULL)
    {
        free(array[i]);  // Libérer chaque mot
        i++;
    }
    free(array);  // Libérer le tableau lui-même
}

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    char **array_path = NULL;
    char *path = getenv("PATH"), *new_path = NULL, *dossier = NULL;
    unsigned int i, j, check_found = 0;
    struct stat st;

    if (path == NULL)
    {
        printf("La variable PATH n'est pas définie.");
        return (1);
    }

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    array_path = split_string(path);
    while (av[i])
    {
        check_found = 0;
        printf("file to check : %s\n", av[i]);

        for (j = 0; array_path[j] != NULL; j++)
        {
            dossier = str_concat(array_path[j], "/");
            if (dossier == NULL)
            return (1);
            new_path = str_concat(dossier, av[i]);
            if (new_path == NULL)
            return (1);
            if (stat(new_path, &st) == 0)
            {
                check_found = 1;
                printf("Found in PATH : %s\n", new_path);
                break;
            }
            free(new_path);
            free(dossier);
        }
        i++;
        if (check_found == 0)
        {
            perror("Error:");
            printf("Not found in PATH\n");
        }
    }
    free_array(array_path);
    return (0);
}