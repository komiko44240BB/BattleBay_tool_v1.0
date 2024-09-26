#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#ifndef PERKS_H
#define PERKS_H


struct Perk {
    bool is_event;
    unsigned int first_boost_value;
    char* first_boost_type;
    unsigned int second_boost_value;
    char* second_boost_type;
};

struct Perk* createPerk(char* first_boost_type,char* second_boost_type, int first_boost_value,int second_boost_value);

int numberOfPerks(struct Object* o);
void addPerks(struct Object* o);
char** perkLists(struct Object* o);

#endif
