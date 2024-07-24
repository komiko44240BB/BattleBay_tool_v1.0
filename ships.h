#ifndef SHIPS_H
#define SHIPS_H




struct Ship{
    struct Objects** loadout [8];
    float speed;
    float ship_agility;
    float turet_agility;
    int gear_score;
    int hit_points;
    int defence;
    int num_red;
    int max_red;
    int num_blue;
    int max_blue;
    int num_yellow;
    int max_yellow;
    int num_green;
    int max_green;
    int num_teal;
    int max_teal;
};

#endif //SHIPS_H
