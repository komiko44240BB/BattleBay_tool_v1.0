#ifndef SHIPS_H
#define SHIPS_H

struct Ship{
    struct Object** loadout [8];
    float speed;
    float ship_agility;
    float turet_agility;
    unsigned int gear_score;
    unsigned int hit_points;
    unsigned int defence;
    unsigned int gear [5][4];
};

struct Ship* createShip();

void addOject(struct Ship* s, struct Object* o);
void removeObject(struct Ship* s, int pos);

void printShipStats(struct Ship* s);
void printLoadout(struct Ship* s);

void deleteShip(struct Ship* s);


#endif //SHIPS_H
