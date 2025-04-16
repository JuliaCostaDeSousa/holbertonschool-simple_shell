#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - split a string
 * @buffer: string to split
 * Return: array of char *
 */
char **split_string(char *buffer)
{
    int count_word = 0, i = 0;
    char *str, *temp_str, *separator = " ";
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
 * main - Test du programme
 * Return: Always 0.
 */
int main(void)
{
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");
    read = getline(&buffer, &len, stdin);
    if (read != -1)
    {
        // Retirer le caractère de nouvelle ligne '\n'
        if (buffer[read - 1] == '\n')
            buffer[read - 1] = '\0';

        // Séparer la chaîne en mots
        char **words = split_string(buffer);
        if (words != NULL)
        {
            // Afficher les mots séparés
            for (int i = 0; words[i] != NULL; i++)
                printf("Word %d: %s\n", i, words[i]);

            // Libérer la mémoire allouée pour le tableau de mots
            free_array(words);
        }
        else
        {
            printf("Erreur d'allocation mémoire.\n");
        }
    }

    // Libérer la mémoire allouée pour buffer
    free(buffer);
    return (0);
}