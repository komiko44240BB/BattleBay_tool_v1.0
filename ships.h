#ifndef SHIPS_H
#define SHIPS_H

struct Ship{
    struct Objects** loadout [8];
    float speed;
    float ship_agility;
    float turet_agility;
    unsigned int gear_score;
    unsigned int hit_points;
    unsigned int defence;
    unsigned int gear [5][4];
};

#endif //SHIPS_H
