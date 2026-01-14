
#include <stdio.h>
#include "simulation.h"
#include "memoire.h"
#include "fichiers.h"

#define K_CHAUFFE 0.5
#define K_COOL 0.1
#define T_AMB 20.0
#define T_MAX 110.0

void simulation() {
    BlackBox b;
    BlackBox_initialization (&b);

    float v = 0.0, T = T_AMB;
    long t = 0;
    char action;

    while (1) {
        printf("Accelerer (A) / Freiner(F) : ");
        scanf(" %c", &action);

        if (action == 'A' || action == 'a')
            v += 5.0;
        else if (action == 'F' || action == 'f')
            v -= 7.0;
        else {
            printf("Entree incorrecte\n");
            continue;
        }

        if (v < 0) v = 0;

        T = T + (K_CHAUFFE * v) - (K_COOL * (T - T_AMB));

        recording_cycle(&b, v, T, t);

        printf("t=%ld | v=%.1f km/h | T=%.2f°C\n", t, v, T);

        if (v == 0 || T > T_MAX) {
                if(v==0){
                    printf("Oups votre vehicule vient de s'arreter...\n");
                }
                if(T>T_MAX){
            printf("CRASH detecte → Sauvegarde des donnees\n");
                }
            dump_memory(&b);
            analysis();
            break;
        }
        t++;
    }
}
