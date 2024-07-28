#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "objects.h"
#ifndef SHIPS_H
#define SHIPS_H

struct Ship{
    struct Slots* loadout [5];
    char* name;
    float speed;
    float ship_agility;
    float turret_agility;
    unsigned int gear_score;
    unsigned int hit_points;
    unsigned int defence;
};

struct Ship* initialiseShip(char* ship_name, float speed, float ship_agility, float turet_agility, unsigned int hit_points, unsigned int defence);
void setUpShip(struct Ship* s, unsigned int gear[5][2]);

void addOject(struct Ship* s, struct Object* o);
void removeObject(struct Ship* s, int pos);

bool canAddObject(struct Ship* s,struct Object* o);

void printShipStats(struct Ship* s);
void printLoadout(struct Ship* s);
void printShipName(struct Ship* s);

void deleteShip(struct Ship* s);


#endif //SHIPS_H
