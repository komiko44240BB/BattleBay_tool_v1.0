#include "objects.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Object* createObject(char rarity, unsigned int level, float base_stat, float cool_down, float range, float projectile_speed, float critical_hit_chance, float critcal_hit_multiplier, float radius, float spread, unsigned int amount_of_projectiles, float duration) {
    struct Object* o = (struct Object*)malloc(sizeof(struct Object));
    if(o == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    o->rarity = rarity;
    o->level = level;
    o->base_stat = base_stat;
    o->cool_down = cool_down;
    o->range = range;
    o->projectile_speed = projectile_speed;
    o->critical_hit_chance = critical_hit_chance;
    o->critcal_hit_multiplier = critcal_hit_multiplier;
    o->radius = radius;
    o->spread = spread;
    o->amount_of_projectiles = amount_of_projectiles;
    o->duration = duration;

    return o;
}