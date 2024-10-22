#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "objects.h"


struct Object* createObject(char* rarity, char* name, unsigned int level, float base_stat, float cool_down, float range, float projectile_speed, float critical_hit_chance, float critcal_hit_multiplier, float radius, float spread, unsigned int amount_of_projectiles, float duration, unsigned int slot_points, float combo_dmg_boost) {
    struct Object* o = malloc(sizeof(struct Object));
    if(o == NULL) {
        return NULL;
    }
    o->name = strdup(name);
    o->rarity = strdup(rarity);
    o->type = -1;
    o->level = level;
    o->training_level = 0;
    o->base_stat = base_stat;
    o->cool_down = cool_down;
    o->range = range;
    o->projectile_speed = projectile_speed;
    o->critical_hit_chance = critical_hit_chance;
    o->critical_hit_multiplier = critcal_hit_multiplier;
    o->radius = radius;
    o->spread = spread;
    o->amount_of_projectiles = amount_of_projectiles;
    o->duration = duration;
    o->combo_dmg_boost = combo_dmg_boost;
    o->slot_points = slot_points;
    for(int i = 0 ; i < 4; i++){
        o->perk_list[i] = NULL;
    }
    o->next = NULL;
    return o;
}

int getObjectType(struct Object* o) {
    if(o == NULL){
        return -1;
    }
    return o->type;
}

int getObjectPoints(struct Object* o) {
    return o->slot_points;
}

void printObject(struct Object* o) {
    if (o == NULL){
        return;
    }
    if(o->level != 0){
        printf("%s :",o->name);
        printf(" level %d\n",o->level);
        if(o->base_stat != 0){
            printf("Base stat: %.2f\n",o->base_stat);
        }
        if(o->cool_down != 0){
            printf("Cooldown: %.2f\n",o->cool_down);
        }
        if(o->range != 0){
            printf("Range :%.2f\n",o->range);
        }
        if(o->projectile_speed != 0){
            printf("Proj speed :%.2f\n",o->projectile_speed);
        }
        if(o->critical_hit_chance != 0){
            printf("crit hit chance :%.2f\n",o->critical_hit_chance);
        }
        if(o->critical_hit_multiplier != 0){
            printf("Crit hit mult :%.2f\n",o->critical_hit_multiplier);
        }
        if(o->radius != 0){
            printf("Radius :%.2f\n",o->radius);
        }
        if(o->spread != 0){
            printf("Spread :%.2f\n",o->spread);
        }
        if(o->amount_of_projectiles > 1){
            printf("Amnt of proj :%d\n",o->amount_of_projectiles);
        }
        if(o->duration != 0){
            printf("Duration :%.2f\n",o->duration);
        }
    }
}

void deleteObject(struct Object* o) {
    if (o == NULL){  // handle null pointer
        return;
    }
    // free the rarity string
    free(o->rarity);
    free(o->name);
    // free the current object
    free(o);
}

void editObjectType(struct Object* o, unsigned int type) {
    type--;
    o->type = type;

}


void addPerk(struct Perk* p, struct Object* o) {
    if(o == NULL || p == NULL){
        return;
    }
    for(int i = 0; i<4; i++){
        if(o->perk_list[i]== NULL){
            o->perk_list[i] = p;
            printf("Perk was added succesfully\n");
            return;
        }
    }
    printf("Perk could not be  added, what did you try to bypass ?\n");
}