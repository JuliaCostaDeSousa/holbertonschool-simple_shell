#include "main.h"

/**
 * check_file - check if file exist
 * @words: user cmd
 * @env: environnement
 * @cmd_count: command count for error print
 */
void check_file(char **words, char **env, int cmd_count)
{
	struct stat st;
	char *absolut_path = NULL;

	if (stat(words[0], &st) == 0)
	{
		fork_call(words, env, cmd_count);
		free_array(words);
	}
	else
	{
		absolut_path = find_in_path(words);
		if (absolut_path != NULL)
		{
			free(words[0]);
			words[0] = absolut_path;
			fork_call(words, env, cmd_count);
			free_array(words);
		}
		else
		{
			print_not_found(cmd_count, words[0]);
			free_array(words);
			exit(127);
		}
	}
}
