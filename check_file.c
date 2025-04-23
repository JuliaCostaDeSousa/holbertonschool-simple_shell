#include "main.h"

/**
 * check_file - check if file exist
 * @words: user cmd
 * @cmd_count: command count for error print
 * @buffer: commande user entière
 */
void check_file(char **words, int cmd_count, char *buffer)
{
	struct stat st;
	char *absolut_path = NULL;

	if (strchr(words[0], '/') != NULL)
	{
		if (stat(words[0], &st) == 0)
		{
			fork_call(words, cmd_count, buffer);
			free_array(words);
		}
		else
		{
			free_array(words);
			print_not_found(cmd_count, buffer);
		}
	}
	else
	{
		absolut_path = find_in_path(words);
		if (absolut_path != NULL)
		{
			free(words[0]);
			words[0] = absolut_path;
			fork_call(words, cmd_count, buffer);
			free_array(words);
		}
		else
		{
			print_not_found(cmd_count, buffer);
			free_array(words);
		}
	}
}
