
# 🚗 BlackBoxProject — Enregistreur de données embarqué en C

![Langage](https://img.shields.io/badge/Langage-C-00599C?logo=c&logoColor=white)
![Projet](https://img.shields.io/badge/Projet-académique-5F7293)
![Outil](https://img.shields.io/badge/IDE-Code%3A%3ABlocks-555555)

## 🎯 Présentation

**BlackBoxProject** est un projet académique en langage **C** qui simule une boîte noire pour un véhicule expérimental.

Il enregistre la vitesse, la température moteur et un horodatage logique, conserve les **10 dernières trames** en mémoire et permet de sauvegarder puis d'analyser les mesures.

Ce projet met en pratique les **structures de données dynamiques**, les **pointeurs**, la **gestion de la mémoire** et les **fichiers binaires**.

## ⚙️ Fonctionnalités

- Simulation interactive : `A` pour accélérer et `F` pour freiner.
- Mise à jour de la vitesse et de la température moteur à chaque cycle.
- Stockage des mesures dans une **liste chaînée** limitée à `MAX_FRAMES = 10`.
- Suppression de la trame la plus ancienne lorsque la capacité est atteinte.
- Enregistrement des dernières trames dans `crash.bin` à l'arrêt du véhicule ou en cas de surchauffe.
- Lecture du fichier binaire pour calculer la **vitesse moyenne** et la **température maximale**.

> **Précision :** le fichier `crash.bin` est également enregistré lors d'un arrêt normal du véhicule. Son nom ne signifie donc pas qu'un accident a nécessairement eu lieu.

## 🧩 Architecture

| Fichier | Responsabilité |
|---|---|
| `main.c` | Menu principal et choix entre simulation et analyse d'un historique |
| `memoire.c` / `memoire.h` | Structures `Frame` et `BlackBox`, initialisation et gestion des 10 trames |
| `simulation.c` / `simulation.h` | Simulation de la conduite et de la température moteur |
| `Fichiers.c` / `fichiers.h` | Écriture du fichier binaire et calcul des indicateurs |

Chaque trame contient un **timestamp**, une **vitesse**, une **température moteur** et un pointeur vers la trame suivante.

## ▶️ Compilation et utilisation

### Avec GCC

Depuis la racine du dépôt :

```bash
gcc -std=c11 -Wall -Wextra main.c memoire.c simulation.c Fichiers.c -o blackbox
```

Sous Linux ou macOS :

```bash
./blackbox
```

Sous Windows, avec GCC / MinGW, compilez avec `-o blackbox.exe` puis lancez `blackbox.exe`.

### Utilisation

1. Choisir `1` pour lancer une nouvelle simulation ou `2` pour analyser le fichier `crash.bin` existant.
2. Pendant la simulation, saisir `A` pour accélérer ou `F` pour freiner.
3. À l'arrêt (`vitesse = 0`) ou lorsque la température dépasse **110 °C**, les trames conservées sont enregistrées et analysées.
4. Consulter la vitesse moyenne et la température maximale affichées dans le terminal.

## 🧪 Scénarios à explorer

- **Accélération :** observer l'évolution de la vitesse et de la température.
- **Freinage :** observer la réduction de vitesse jusqu'à l'arrêt.
- **Capacité mémoire :** dépasser dix cycles et vérifier que seules les dix dernières trames sont conservées.
- **Surchauffe :** poursuivre la simulation jusqu'au dépassement du seuil de 110 °C.
- **Historique :** relancer le programme et choisir l'option `2` après une première sauvegarde.

Ces scénarios décrivent des vérifications possibles ; ils ne constituent pas une suite de tests automatisés.

## 🛠️ Compétences mobilisées

**Langage C** · **Listes chaînées** · **Allocation dynamique (`calloc`, `free`)** · **Pointeurs** · **Fichiers binaires** · **Programmation modulaire** · **Tests manuels**

## 🔎 Limites et pistes d'amélioration

- Ajouter une fonction de libération de toutes les trames restantes en fin de simulation.
- Vérifier les valeurs de retour de `scanf`, `fwrite` et `fread`.
- Sérialiser explicitement les champs plutôt que d'écrire la structure complète, qui contient un pointeur et dépend de la plateforme.
- Ajouter des tests automatisés et documenter les résultats.
- Améliorer la performance d'ajout des trames en conservant un pointeur vers la fin de la liste.

## 👩‍💻 Auteurs

**Youmnath MOUTAIROU** — Étudiante ingénieure à l'ESIGELEC, parcours Intelligence Artificielle & Big Data.
**Rafeek MARCOS** — Étudiant ingénieur à l'ESIGELEC.
**Leah ALLEY** — Étudiante ingénieure à l'EIGSI.
**David DJOSSOU** — Étudiant ingénieur à l'ESIGELEC.
**Shanya de SOUZA** — Étudiante ingénieure à BUILDERS.





📧 [E-mail professionnel](mailto:youmnath.moutairou@groupe-esigelec.org) · 💼 [LinkedIn](https://www.linkedin.com/in/youmnath-moutairou/) · 🐙 [Portfolio GitHub](https://github.com/Youmnath)

