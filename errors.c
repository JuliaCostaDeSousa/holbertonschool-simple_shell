#include "main.h"

/**
 * print_not_found - Affiche une erreur si commande introuvable
 * @cmd_count: compteur de commande valide pour l'affichage des erreurs
 * @cmd: commande rentrée par l'utilisateur
 */
void print_not_found(int cmd_count, char *cmd)
{
	cmd[strcspn(cmd, "\n")] = '\0';
	fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_count, cmd);
}

/**
 * print_permission_denied - Affiche une erreur si permission non autorisée
 * @cmd_count: compteur de commande valide pour l'affichage des erreurs
 * @cmd: commande rentrée par l'utilisateur
 */
void print_permission_denied(int cmd_count, char *cmd)
{
	cmd[strcspn(cmd, "\n")] = '\0';
	fprintf(stderr, "./hsh: %d: %s: Permission denied\n", cmd_count, cmd);
}

/**
 * print_exec_format_error - Affiche une erreur si commande non exécutable
 * @cmd_count: compteur de commande valide pour l'affichage des erreurs
 * @cmd: commande rentrée par l'utilisateur
 */
void print_exec_format_error(int cmd_count, char *cmd)
{
	cmd[strcspn(cmd, "\n")] = '\0';
	fprintf(stderr, "./hsh: %d: %s: Exec format error\n", cmd_count, cmd);
}
