#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"
#include "simulation.h"
#include "fichiers.h"



int main() {
    int choice;
    printf("Bienvenue chez RYLS&CO\n.Nous vous proposons une petite simulation.\n");
    printf("1 - Lancer la simulation\n");
    printf("2 - Historique Precedent\n");
    printf("Votre choix : ");
    scanf("%d", &choice);

    if (choice == 1) {
        simulation();
    } else if (choice == 2) {
        analysis();
    } else {
        printf("Choix invalide\n");
    }

    return 0;
}
