#ifndef READTRAINING_H
#define READTRAINING_H

struct Training {
    char** type;
    float* value;
};


struct Training* readTraining(struct Object* o,char* object_name);


#endif
