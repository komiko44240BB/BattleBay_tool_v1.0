#ifndef SHIPS_H
#define SHIPS_H
#include<stdbool.h>


struct Ship{
    struct Slots* loadout [5];
    char* name;
    float speed;
    int ship_agility;
    int turret_agility;
    unsigned int gear_score;
    unsigned int hit_points;
    unsigned int defence;
};

struct Ship* initialiseShip(char* ship_name, float speed, int ship_agility, int turet_agility, unsigned int hit_points, unsigned int defence);
void setUpShip(struct Ship* s, unsigned int gear[5][2]);

bool addOject(struct Ship* s, struct Object* o);
void removeObject(struct Ship* s, int pos);

bool canAddObject(struct Ship* s,struct Object* o);

void printShipStats(struct Ship* s);
void printLoadout(struct Ship* s);
void printShipName(struct Ship* s);

void deleteShip(struct Ship* s);


#endif //SHIPS_H
