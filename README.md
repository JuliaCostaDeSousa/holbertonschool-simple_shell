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

- ✅ Affichage d’un prompt (`#cisfun$`)
- ✅ Lecture de commandes via `getline()`
- ✅ Exécution des commandes avec `fork()` + `execve()`
- ✅ Gestion des erreurs (commande non trouvée, échec d’exécution, etc.)
- ✅ Commandes **built-ins** :
  - `exit` : Quitte le shell
  - `env` : Affiche les variables d’environnement
- ✅ Gestion de la fin de fichier (Ctrl+D)

---

## 🛠️ Compilation

Utilisez la commande suivante pour compiler tous les fichiers sources :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## 🚀 Utilisation

### 🔁 Mode interactif

Lancez le shell en mode interactif avec la commande suivante :

```bash
./hsh
```
Exemple :
```bash
$ ./hsh
#cisfun$ ls
#cisfun$ exit
```

### 📡 Mode non interactif (via un tube)

Vous pouvez également passer des commandes au shell via un pipe :
```bash
echo "ls" | ./hsh
```

## 💬 Exemples de commandes prises en charge

Voici quelques commandes supportées par ce shell minimaliste :

- `ls`: Liste les fichiers et répertoires
- `env`:	Affiche les variables d’environnement
- `exit`:	Quitte le shell
---

## 🔧 Appels système utilisés
- `fork()`	Crée un processus enfant
- `execve()`	Exécute une commande dans le processus enfant
- `wait()`	Attend la fin d’un processus enfant
- `getline()`	Lit l’entrée utilisateur
- `perror()`	Affiche un message d’erreur sur stderr
---

## 🌐 Variables d'environnement
Le shell utilise la variable globale `environ` pour accéder et passer les variables d'environnement à `execve()`.
___

## ✅ Conclusion
Ce projet est une implémentation de base mais complète d’un mini-shell UNIX.
Il couvre les principes fondamentaux d’un interpréteur de commande, utile pour comprendre les mécanismes de gestion de processus, d’exécution et d’interactions avec l’environnement du système.
