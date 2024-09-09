#include "perks.h"
#ifndef OBJECTS_H
#define OBJECTS_H

struct Object {
    char* rarity;
    char* name;
    int type;
    unsigned int level;
    unsigned int training_level;
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
    float combo_dmg_boost;
    unsigned int slot_points;
    unsigned int amount_of_perks;
    struct Perk* perk_list [4];
    struct Object* next;
};


struct Slots {
    int type;
    unsigned int slot_amount;
    unsigned int occipied_slots;
    unsigned int slot_points;
    unsigned int used_points;
    struct Object* head;
};

struct Object* createObject(char* rarity,char* name ,unsigned int level, float base_stat, float cool_down, float range, float projectile_speed, float critical_hit_chance, float critcal_hit_multiplier, float radius, float spread, unsigned int amount_of_projectiles, float duration, unsigned int slot_points, float combo_dmg_boost);

int getObjectType(struct Object* o);
int getObjectPoints(struct Object* o);

void editObjectType(struct Object* o, unsigned int type);

void printObject(struct Object* o);

void deleteObject(struct Object* o);

struct Slots* createSlots();

#endif
