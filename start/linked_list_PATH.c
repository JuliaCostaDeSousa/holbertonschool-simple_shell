#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */

typedef struct dliststring_s
{
    char *string;
    struct dliststring_s *prev;
    struct dliststring_s *next;
} dliststring_t;


/**
 * split_string - split a string
 * @buffer: string to split
 * @delimiter: delimiter
 * Return: array of words
 */
char **split_string(char *buffer, char *delimiter)
{
    int count_word = 0, i = 0;
    char *str, *temp_str;
    char **array;

    if (buffer == NULL)
    return (NULL);
    
    temp_str = strdup(buffer);
    if (temp_str == NULL)
    return (NULL);
    str = strtok(temp_str, delimiter);
    while (str != NULL)
    {
        count_word++;
        str = strtok(NULL, delimiter);
    }
    free (temp_str);

    array = (char **)malloc(sizeof(char *) * (count_word + 1));
    if (array == NULL)
    return (NULL);

    temp_str = strdup(buffer);
    if (temp_str == NULL)
    return (NULL);
    str = strtok(temp_str, delimiter);
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
        str = strtok(NULL, delimiter);
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
 * print_dliststring - prints all the elements of a dliststring_t list
 * @h: list
 * Return: number of nodes
 */

size_t print_dliststring(dliststring_t *h)
{
    int node_number = 0;

    if (h == NULL)
    {
        return (node_number);
    }

    while (h != NULL)
    {
        printf("%s\n", h->string);
        node_number++;
        h = h->next;
    }
    return (node_number);
}

/**
 * add_dnodeint_end - adds a new node at the end of a dliststring_t list
 * @head: list
 * @s: element to add
 * Return:  address of the new element, or NULL if it failed
 */

dliststring_t *add_dnodeint_end(dliststring_t **head, char *s)
{
    dliststring_t *new_list, *temp_list;

    if (*head == NULL)
    {
        *head = malloc(sizeof(dliststring_t));
        if (*head == NULL)
        return (NULL);

        (*head)->string = s;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return (*head);
    }

    new_list = (*head);
    while (new_list->next != NULL)
    {
        new_list = new_list->next;
    }

    temp_list = malloc(sizeof(dliststring_t));
    if (temp_list == NULL)
    return (NULL);
    temp_list->string = strdup(s);
    temp_list->prev = new_list;
    temp_list->next = NULL;

    new_list->next = temp_list;

    new_list = new_list->next;

    return (new_list);
}

/**
 * 
 */
int main(void)
{
    dliststring_t *path_list = NULL;
    char **array_path = NULL;
    char *path = getenv("PATH");
    int i = 0;

    if (path == NULL)
    {
        printf("La variable PATH n'est pas définie.");
        return (-1);
    }

    array_path = split_string(path, ":");
    if (array_path == NULL)
    return (-1);

    while(array_path[i] != NULL)
    {
        add_dnodeint_end(&path_list, array_path[i]);
        i++;
    }
    print_dliststring(path_list);

    return (0);
}


