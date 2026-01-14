
#include <stdio.h>
#include "fichiers.h"

void dump_memory(BlackBox *b) {
    FILE *f = fopen("crash.bin", "wb");
    if(f==NULL) {
    return;
    }
    Frame *cur = b->debut;
    while (cur) {
        fwrite(cur, sizeof(Frame), 1, f);
        cur = cur->suivant;
    }
    fclose(f);
}

void analysis() {
    FILE *f = fopen("crash.bin", "rb");
    if (f== NULL){
        printf("Erreur ouverture crash.bin\n");
        return;
    }

    Frame fr;
    float somme_v = 0;
    float temp_max = 0;
    int count = 0;

    while (fread(&fr, sizeof(Frame), 1, f)) {
        somme_v += fr.vitesse;
        if (fr.temperature_moteur > temp_max)
            temp_max = fr.temperature_moteur;
        count++;
    }

    fclose(f);

    if (count > 0) {
        printf("Vitesse moyenne : %.2f km/h\n", somme_v / count);
        printf("Temperature max : %.2f °C\n", temp_max);
        printf("Merci pour votre tour a bord de notre petite manège.\nG---O---O---D---B---Y---E");
    }
}
