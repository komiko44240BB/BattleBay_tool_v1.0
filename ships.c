#include "ships.h"
#include "objects.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define OBJECT_TYPES "rbygt"

/**
 * Creates a new Ship struct with the given parameters.
 *
 * @param ship_name The name of the ship.
 * @param speed The speed of the ship.
 * @param ship_agility The agility of the ship.
 * @param turret_agility The agility of the turret.
 * @param hit_points The base_hit points of the ship.
 * @param defence The defence of the ship.
 *
 * @return A pointer to the newly created Ship struct, or NULL on failure.
 */

struct Ship* initialiseShip(char* ship_name, float speed, float ship_agility, float turret_agility, unsigned int hit_points, unsigned int defence) {
    // Allocate memory for the Ship struct
    struct Ship* ship = malloc(sizeof(struct Ship));
    if (ship == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    // Initialize the Ship struct fields
    ship->name = strdup(ship_name); // Duplicate the string to avoid memory issues
    ship->speed = speed;
    ship->ship_agility = ship_agility;
    ship->turret_agility = turret_agility;
    ship->gear_score = 0; // Initialize gear score to 0
    ship->hit_points = hit_points;
    ship->defence = defence;

    return ship;
}

void setUpShip(struct Ship* s, unsigned int gear[5][2]) {
    if(s == NULL){
        return;
    }
    for (int i = 0; i < 5; i++){
        s->loadout[i] = malloc(sizeof(struct Slots));
        if (s->loadout[i] == NULL) {
            printf("Error: Memory allocation failed\n");
            return;
        }
        s->loadout[i]->type = OBJECT_TYPES[i];
        s->loadout[i]->slot_amount = gear[i][0];
        s->loadout[i]->occipied_slots = 0;
        s->loadout[i]->slot_points = gear[i][1];
        s->loadout[i]->used_points = 0;
        s->loadout[i]->head = NULL;
    }
}


void addOject(struct Ship* s, struct Object* o){
    if(s == NULL){
        return;
    }
    if(canAddObject(s,o)){
        int type = getObjectType(o);
        struct Object* iter = s->loadout[type]->head;
        while(iter->next != NULL){
            iter = iter->next;
        }
            iter->next = o;
    }
}

void removeObject(struct Ship* s, int pos) {
    if( s != NULL ){
       int count = 0;
        for (int i = 0; i < 5; i++) {
            struct Object* iter = s->loadout[i]->head;
            struct Object* prev = NULL;
            while (iter != NULL) {
                if (count == pos) {
                    if (prev == NULL) {
                        s->loadout[i]->head = iter->next;
                    } else {
                        prev->next = iter->next;
                    }
                    deleteObject(iter);
                    return;
                }
                prev = iter;
                iter = iter->next;
                count++;
            }
        }
    }
}

void printShipStats(struct Ship* s){
    if(s == NULL){
        return;
    }
    printShipName(s);
    printf("Gear score :    unsuported    Health :    %d\n",s->hit_points);
    printf("Turret agility :    %.2f      Speed :     %.2f\n",s->turret_agility,s->speed);
    printf("Ship agility :      %.2f      Defense :   %d\n",s->ship_agility,s->defence);
}
void printLoadout(struct Ship* s){
    if(s == NULL){
        return;
    }
    int count = 0;
    for(int i = 0; i < 5; i++){
        struct Object* iter = s->loadout[i]->head;
        while (iter->next != NULL){
            printObject(iter);
            if(count%4 == 0){
                printf("\n");
            }
        }
    }
}

void printShipName(struct Ship* s) {
    if(s == NULL){
        return;
    }
    if(strcmp(s->name,"shooter") == 0){

    }
    if(strcmp(s->name,"defender") == 0){

    }
    if(strcmp(s->name,"speeder") == 0){

    }
    if(strcmp(s->name,"enfoncer") == 0){

    }
    if(strcmp(s->name,"fixer") == 0){

    }
    if(strcmp(s->name,"interceptor") == 0){

    }
    if(strcmp(s->name,"reaper") == 0){

    }
    if(strcmp(s->name,"guardian") == 0){

    }
    if(strcmp(s->name,"strikergi") == 0){

    }

}

void deleteShip(struct Ship* s){

}