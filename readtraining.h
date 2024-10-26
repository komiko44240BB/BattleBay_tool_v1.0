#ifndef READTRAINING_H
#define READTRAINING_H

struct Training {
    unsigned int size;
    char** type;
    float* value;
};
struct Training* createTraining(unsigned int training_lvl);
struct Training* readTraining(char* object_name);
#endif
