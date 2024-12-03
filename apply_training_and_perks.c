#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "objects.h"
#include "perks.h"
#include "readtraining.h"


void applytrainingAndPerks(struct Object* o,const struct Training* t) {
    if(o == NULL || t == NULL){
        return;
    }

    int flat_base_stat = 0;
    int flat_cool_down = 0;
    int flat_range = 0;
    int flat_projectile_speed = 0;
    int flat_critical_hit_chance = 0;
    int flat_critical_hit_multiplier = 0;
    int flat_duration = 0;
    int flat_combo_dmg_boost = 0;

    float percent_base_stat = 1;
    float percent_cool_down = 1;
    float percent_range = 1;
    float percent_projectile_speed = 1;
    float percent_critical_hit_chance = 1;
    float percent_critical_hit_multiplier = 1;
    float percent_duration = 1;
    float percent_combo_dmg_boost = 1;
//( base stat + flat train stat + flat perk stat ) * ( 1 + % perk stat + % train stat ) * ( 1 + % combo train stat + % combo perk stat )

    if (t->size > 0){
        for(unsigned int i = 0 ; i < t->size ; i++ ){
            if(t->value[i] < 1 ){
                if (strcasecmp(t->type[i], "BASE_STAT") == 0) {
                    percent_base_stat += t->value[i];
                } else if (strcasecmp(t->type[i], "COOL_DOWN") == 0) {
                    percent_cool_down -= t->value[i];
                } else if (strcasecmp(t->type[i], "RANGE") == 0) {
                    percent_range += t->value[i];
                } else if (strcasecmp(t->type[i], "PROJECTILE_SPEED") == 0) {
                    percent_projectile_speed += t->value[i];
                } else if (strcasecmp(t->type[i], "CRITICAL_HIT_CHANCE") == 0) {
                    flat_critical_hit_chance += t->value[i];
                } else if (strcasecmp(t->type[i], "CRITICAL_HIT_MULTIPLIER") == 0) {
                    flat_critical_hit_multiplier += t->value[i];
                } else if (strcasecmp(t->type[i], "DURATION") == 0) {
                    percent_duration += t->value[i];
                } else if (strcasecmp(t->type[i], "FROST_DAMAGE") == 0 || strcasecmp(t->type[i], "FIRE_DAMAGE")) {
                    percent_combo_dmg_boost += t->value[i];
                }
            } else if(t->value[i] >= 1){
                if (strcasecmp(t->type[i], "BASE_STAT") == 0) {
                    flat_base_stat  += t->value[i];
                } else if (strcasecmp(t->type[i], "COOL_DOWN") == 0) {
                    flat_cool_down -= t->value[i];
                } else if (strcasecmp(t->type[i], "RANGE") == 0) {
                    flat_range += t->value[i];
                } else if (strcasecmp(t->type[i], "PROJECTILE_SPEED") == 0) {
                    flat_projectile_speed += t->value[i];
                } else if (strcasecmp(t->type[i], "CRITICAL_HIT_CHANCE") == 0) {
                    flat_critical_hit_chance += t->value[i];
                } else if (strcasecmp(t->type[i], "CRITICAL_HIT_MULTIPLIER") == 0) {
                    flat_critical_hit_multiplier += t->value[i];
                } else if (strcasecmp(t->type[i], "DURATION") == 0) {
                    flat_duration += t->value[i];
                } else if (strcasecmp(t->type[i], "FROST_DAMAGE") == 0 || strcasecmp(t->type[i], "FIRE_DAMAGE")) {
                    flat_combo_dmg_boost += t->value[i];
                }
            }
        }
    }

    for(unsigned int i = 0 ; i < 4 ; i++ ){
        if(o->perk_list[i] != NULL){
            struct Perk* p  = o->perk_list[i];
            if(p->first_boost_value < 1 ){
                if (strcasecmp(p->first_boost_type, "BASE_STAT") == 0) {
                    percent_base_stat += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "COOL_DOWN") == 0) {
                    percent_cool_down -= p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "RANGE") == 0) {
                    percent_range += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "PROJECTILE_SPEED") == 0) {
                    percent_projectile_speed += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "CRITICAL_HIT_CHANCE") == 0) {
                    flat_critical_hit_chance += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "CRITICAL_HIT_MULTIPLIER") == 0) {
                    flat_critical_hit_multiplier += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "DURATION") == 0) {
                    percent_duration += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "FROST_DAMAGE") == 0 || strcasecmp(p->first_boost_type, "FIRE_DAMAGE")) {
                    percent_combo_dmg_boost += p->first_boost_value;
                }
            } else if(p->first_boost_value >= 1){
                if (strcasecmp(p->first_boost_type, "BASE_STAT") == 0) {
                    flat_base_stat  -= p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "COOL_DOWN") == 0) {
                    flat_cool_down += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "RANGE") == 0) {
                    flat_range += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "PROJECTILE_SPEED") == 0) {
                    flat_projectile_speed += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "CRITICAL_HIT_CHANCE") == 0) {
                    flat_critical_hit_chance += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "CRITICAL_HIT_MULTIPLIER") == 0) {
                    flat_critical_hit_multiplier += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "DURATION") == 0) {
                    flat_duration += p->first_boost_value;
                } else if (strcasecmp(p->first_boost_type, "FROST_DAMAGE") == 0 || strcasecmp(p->first_boost_type, "FIRE_DAMAGE")) {
                    flat_combo_dmg_boost += p->first_boost_value;
                }
            }
            if(p->second_boost_value < 1 ){
                if (strcasecmp(p->second_boost_type, "BASE_STAT") == 0) {
                    percent_base_stat += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "COOL_DOWN") == 0) {
                    percent_cool_down -= p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "RANGE") == 0) {
                    percent_range += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "PROJECTILE_SPEED") == 0) {
                    percent_projectile_speed += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "CRITICAL_HIT_CHANCE") == 0) {
                    flat_critical_hit_chance += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "CRITICAL_HIT_MULTIPLIER") == 0) {
                    flat_critical_hit_multiplier += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "DURATION") == 0) {
                    percent_duration += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "FROST_DAMAGE") == 0 || strcasecmp(t->type[i], "FIRE_DAMAGE")) {
                    percent_combo_dmg_boost += p->second_boost_value;
                }
            } else if(p->second_boost_value >= 1){
                if (strcasecmp(p->second_boost_type, "BASE_STAT") == 0) {
                    flat_base_stat  += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "COOL_DOWN") == 0) {
                    flat_cool_down -= p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "RANGE") == 0) {
                    flat_range += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "PROJECTILE_SPEED") == 0) {
                    flat_projectile_speed += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "CRITICAL_HIT_CHANCE") == 0) {
                    flat_critical_hit_chance += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "CRITICAL_HIT_MULTIPLIER") == 0) {
                    flat_critical_hit_multiplier += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "DURATION") == 0) {
                    flat_duration += p->second_boost_value;
                } else if (strcasecmp(p->second_boost_type, "FROST_DAMAGE") == 0 || strcasecmp(t->type[i], "FIRE_DAMAGE")) {
                    flat_combo_dmg_boost += p->second_boost_value;
                }
            }
        }
    }

    /*printf("%d\n",flat_base_stat);
    printf("%d\n", flat_cool_down);
    printf("%d\n", flat_range);
    printf("%d\n", flat_projectile_speed);
    printf("%d\n", flat_critical_hit_chance);
    printf("%d\n", flat_critical_hit_multiplier);
    printf("%d\n", flat_duration);
    printf("%d\n", flat_combo_dmg_boost);

    printf("%f\n", percent_base_stat);
    printf("%f\n", percent_cool_down);
    printf("%f\n", percent_range);
    printf("%f\n", percent_projectile_speed);
    printf("%f\n", percent_critical_hit_chance);
    printf("%f\n", percent_critical_hit_multiplier);
    printf("%f\n", percent_duration);
    printf("%f\n", percent_combo_dmg_boost);*/

    o->base_stat = (flat_base_stat + o->base_stat) * (percent_base_stat);
    o->cool_down = (flat_cool_down + o->cool_down) * (percent_cool_down);
    o->range = (flat_range + o->range) * (percent_range);
    o->projectile_speed = (flat_projectile_speed + o->projectile_speed) * (percent_projectile_speed);
    o->critical_hit_chance = (flat_critical_hit_chance + o->critical_hit_chance) * (percent_critical_hit_chance);
    o->critical_hit_multiplier = (flat_critical_hit_multiplier + o->critical_hit_multiplier) * (percent_critical_hit_multiplier);
    o->duration = (flat_duration + o->duration) * (percent_duration);
    o->combo_dmg_boost = (flat_combo_dmg_boost + o->combo_dmg_boost) * (percent_combo_dmg_boost);

}

