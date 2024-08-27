# So_Long

**So_Long** est un jeu en 2D développé dans le cadre du programme de l'école 42. Le joueur contrôle un personnage qui doit naviguer dans un labyrinthe, collecter des objets, et atteindre une sortie. Le jeu utilise la bibliothèque graphique MiniLibX pour gérer l'affichage et les événements.

## Fonctionnalités

- **Gestion des Sprites et des Images** : Chargement et gestion des images au format XPM pour représenter les différents éléments graphiques du jeu (personnage principal, objets collectables, murs, sorties).
- **Système de Collision** : Détection et gestion des collisions avec les murs, les objets collectables, et la sortie pour contrôler les déplacements du personnage.
- **Création Dynamique de la Carte** : Lecture des fichiers de carte `.ber` pour générer la structure du niveau. La carte est construite dynamiquement, ligne par ligne, en reliant chaque cellule aux précédentes pour former une structure cohérente.
- **Animations des Personnages** : Utilisation de listes chaînées pour gérer les animations du personnage principal, avec alternance des sprites en fonction des actions du joueur.
- **Gestion des Événements en Temps Réel** : Implémentation de boucles d'événements pour gérer les déplacements du joueur et les mises à jour de l'affichage en temps réel.

## Installation

Pour installer et exécuter **So_Long**, suivez les étapes ci-dessous :

1. Clonez ce dépôt sur votre machine locale :
    ```bash
    git clone https://github.com/votre-nom-utilisateur/so_long.git
    ```

2. Accédez au répertoire du projet :
    ```bash
    cd so_long
    ```

3. Compilez le projet en utilisant `make` :
    ```bash
    make
    ```

4. Exécutez le jeu avec un fichier de carte `.ber` en argument :
    ```bash
    ./so_long maps/map.ber
    ```

## Utilisation

**So_Long** se joue en utilisant les touches directionnelles du clavier pour déplacer le personnage. Le but est de collecter tous les objets sur la carte et de se rendre à la sortie pour gagner la partie.

## Fichiers de Carte

Les cartes sont stockées dans des fichiers `.ber`. Voici un exemple de format de carte :

```111111
100001
101C01
10P0E1
111111
```


- `1` : Mur
- `0` : Sol
- `C` : Collectable
- `P` : Position de départ du joueur
- `E` : Sortie

## Dépendances

Le projet **So_Long** dépend de la bibliothèque **MiniLibX**. Assurez-vous que **MiniLibX** est installée sur votre machine. Si ce n'est pas le cas, vous pouvez la récupérer et la compiler via les commandes suivantes :

```bash
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux && make
