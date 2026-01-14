
#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"

void BlackBox_initialization (BlackBox *b) {
    b->debut = NULL;
    b->nb_frames = 0;
}

void recording_cycle(BlackBox *b, float v, float temp, long time) {
    Frame *nouvelle = calloc(1, sizeof(Frame));
    if (nouvelle==NULL) return;

    nouvelle->timestamp = time;
    nouvelle->vitesse = v;
    nouvelle->temperature_moteur = temp;

    if (b->debut == NULL) {
        b->debut = nouvelle;
        b->nb_frames = 1;
    } else {
        Frame *courant = b->debut;
        while (courant->suivant)
            courant = courant->suivant;

        courant->suivant = nouvelle;

        if (b->nb_frames < MAX_FRAMES) {
            b->nb_frames++;
        } else {
            Frame *ancienne = b->debut;
            b->debut = ancienne->suivant;
            free(ancienne);
            printf("Rotation : ancienne trame supprimée\n");
        }
    }

    printf("Enregistrement [%ld] (Mémoire %d/10)\n",time, b->nb_frames);
}
