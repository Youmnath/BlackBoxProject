
#ifndef MEMOIRE_H
#define MEMOIRE_H

#define MAX_FRAMES 10

typedef struct Frame {
    long timestamp;
    float vitesse;
    float temperature_moteur;
    struct Frame *suivant;
} Frame;

typedef struct {
    Frame *debut;
    int nb_frames;
} BlackBox;

void BlackBox_initialization (BlackBox *b) ;
void recording_cycle(BlackBox *b, float v, float temp, long time) ;


#endif
