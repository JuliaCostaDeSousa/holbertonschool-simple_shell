# 💻 holbertonschool-simple_shell

## 📌 Description

Ce projet est une implémentation d’un **interpréteur de ligne de commande UNIX** minimaliste en langage **C**.  
Il permet à l’utilisateur d’interagir avec le système en exécutant des commandes simples, à la manière d’un shell classique comme `bash`.

Il prend en charge :

- L’affichage d’un prompt personnalisé (`#cisfun$`)
- La lecture des entrées utilisateur
- L’exécution de commandes avec `execve()`
- La gestion d’erreurs et de signaux de fin de fichier (`EOF`)
- Deux commandes intégrées : `exit` et `env`

---

## ⚙️ Fonctionnalités principales

- ✅ Prompt interactif (`#cisfun$`)
- ✅ Lecture de l'entrée utilisateur via `getline()`
- ✅ Création de processus avec `fork()` et exécution avec `execve()`
- ✅ Gestion des erreurs (commande non trouvée, échec d’exécution)
- ✅ Commandes **built-ins** :
  - `exit` : Quitte le shell
  - `env` : Affiche les variables d’environnement
- ✅ Gestion de la fin de fichier (Ctrl+D)

---

## Flowchart 
![flowchart simpleshell](https://github.com/JuliaCostaDeSousa/holbertonschool-simple_shell/blob/main/Flowchart%20-%20Simple%20Shell.jpg?raw=true)
___

## Man page
[man_1_simple_shell](https://github.com/JuliaCostaDeSousa/holbertonschool-simple_shell/blob/main/man_1_simple_shell)

___

## 🛠️ Compilation

Utilisez la commande suivante pour compiler tous les fichiers sources :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## 🚀 Utilisation

### 🔁 Mode interactif

Lancez le shell de manière classique :

```bash
./hsh
```
Exemple :
```bash
$ ./hsh
#cisfun$ echo hello
hello
#cisfun$
```

### 📡 Mode non interactif (pipe ou redirection)

Vous pouvez également passer des commandes au shell via un pipe :
```bash
echo "echo hello" | ./hsh
hello
```


## 💬 Commandes prises en charge

Exemples de commandes exécutables :

- `ls`: Liste les fichiers et dossiers
- `env`:	Affiche les variables d’environnement
- `exit`:	Quitte le shell
---

## 🔧 Appels système utilisés
- `fork()`	Crée un processus enfant
- `execve()`	Exécute un programme
- `wait()`	Attend la fin d’un processus enfant
- `getline()`	Lit la saisie utilisateur
- `perror()`	Affiche une erreur sur la sortie standard d’erreurs
---

## 🔍 Fonctions internes notables

- `check_input()` : Analyse l'entrée utilisateur (par exemple pour `exit` ou `env`)
- `split_string()` : Sépare une ligne en mots (utilise `strtok`)
- `check_file()` : Vérifie si une commande est exécutable, si oui, l’exécute avec `execve()`
___

## 🧠 Vérification des fuites mémoire

Pour vérifier qu’il n’y a pas de fuite mémoire, utilisez Valgrind :

```bash
valgrind --leak-check=full ./hsh
```
Cela vous permet de tracer toute fuite potentielle et d'améliorer la gestion mémoire du programme.
___

## 🌐 Variables d'environnement
Le shell utilise la variable globale `environ` pour accéder et passer les variables d'environnement à `execve()`.
___

## Auteurs : 
Projet réalisé par Julia Costa de Sousa et Angela Rhin.
