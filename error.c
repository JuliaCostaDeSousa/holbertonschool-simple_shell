#include <stdio.h>

/**
 * print_not_found - Affiche une erreur si la commande est introuvable
 * @cmd_count: command count for error
 * @cmd: user command
 */
void print_not_found(int cmd_count, char *cmd)
{
	fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_count, cmd);
}

/**
 * print_permission_denied - Affiche une erreur si la commande existe
 * mais n’est pas exécutable
 * @cmd_count: command count for error
 * @cmd: user command
 */
void print_permission_denied(int cmd_count, char *cmd)
{
	fprintf(stderr, "./hsh: %d: %s: Permission denied\n", cmd_count, cmd);
}

/**
 * print_exec_format_error - Affiche une erreur si
 * le fichier n’est pas exécutable
 * @cmd_count: command count for error
 * @cmd: user command
 */
void print_exec_format_error(int cmd_count, char *cmd)
{
	fprintf(stderr, "./hsh: %d: %s: Exec format error\n", cmd_count, cmd);
}
