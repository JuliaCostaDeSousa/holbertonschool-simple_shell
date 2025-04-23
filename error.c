#include "main.h"

/**
 * print_not_found - Affiche une erreur si la commande est introuvable
 * @cmd: user command
 */
void print_not_found(char *cmd)
{
	cmd[strcspn(cmd, "\n")] = '\0';
	fprintf(stderr, "./hsh: %s: not found\n", cmd);
}

/**
 * print_permission_denied - Affiche une erreur si la commande existe
 * mais n’est pas exécutable
 * @cmd: user command
 */
void print_permission_denied(char *cmd)
{
	cmd[strcspn(cmd, "\n")] = '\0';
	fprintf(stderr, "./hsh: %s: Permission denied\n", cmd);
}

/**
 * print_exec_format_error - Affiche une erreur si
 * le fichier n’est pas exécutable
 * @cmd: user command
 */
void print_exec_format_error(char *cmd)
{
	cmd[strcspn(cmd, "\n")] = '\0';
	fprintf(stderr, "./hsh: %s: Exec format error\n", cmd);
}
