#ifndef READTRAINING_H
#define READTRAINING_H

struct Training {
    unsigned int size;
    char** type;
    float* value;
};

struct Training* readTraining(struct Object* o,char* object_name);
#endif
