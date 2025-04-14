# holbertonschool-simple_shell

## Description

Ce projet est une implémentation d’un shell minimaliste en langage C. Le shell permet à l’utilisateur d’interagir avec le système d’exploitation, d’exécuter des commandes, et de gérer les processus comme un shell Unix classique (ex : bash).

---

## Fonctions principales

- Affichage d’un prompt
- Lecture de la commande utilisateur
- Analyse de la commande et des arguments
- Exécution de commandes à l’aide des appels système `fork`, `execve` et `wait`
- Gestion des erreurs (commande non trouvée, mauvaise syntaxe, etc.)
- Support de la commande `exit`
- Affichage des variables d’environnement avec `env`

---

## Utilisation

### Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic *.c -o hsh

Lancement du shell
./hsh
Mode interactif
$ ./hsh
$ ls -l
$ pwd
$ exit
Mode non interactif
echo "ls -l" | ./hsh
Exemples de commandes prises en charge

ls
pwd
echo
env
exit

Fichiers importants

main.c : boucle principale du shell
prompt.c : affichage du prompt
parser.c : analyse de la ligne de commande
executor.c : gestion des processus
builtins.c : commandes intégrées (exit, env, etc.)
utils.c : fonctions utilitaires (gestion du PATH, mémoire, etc.)

Appels système utilisés

fork()
execve()
wait()
access()
getline()
perror()
Variables d’environnement

La variable globale environ est utilisée pour accéder aux variables d’environnement du système. Elle est transmise à execve() pour exécuter les commandes dans le même environnement.

