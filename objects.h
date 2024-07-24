#ifndef OBJECTS_H
#define OBJECTS_H

struct Object{
    char rarity;
    unsigned int level;
    float base_stat;
    float cool_down;
    float range;
    float projectile_speed;
    float critical_hit_chance;
    float critcal_hit_multiplier;
    float radius;
    float spread;
    unsigned int amount_of_projectiles;
    float duration;
};

struct Object* createObject(char rarity, unsigned int level, float base_stat, float cool_down, float range, float projectile_speed, float critical_hit_chance, float critcal_hit_multiplier, float radius, float spread, unsigned int amount_of_projectiles, float duration);

void printObject(struct Object* o);

void deleteObject(struct Object* o);


#endif //OBJECTS_H
