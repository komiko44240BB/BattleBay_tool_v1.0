#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#ifndef PERKS_H
#define PERKS_H


struct Perk {
    bool is_event;
    float first_boost_value;
    unsigned int first_boost_type;
    float second_boost_value;
    unsigned int second_boost_type;
};

#endif
