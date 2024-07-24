#include "ships.h"
#include "objects.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


/**
 * Creates a new Ship struct with the given parameters.
 *
 * @param ship_name The name of the ship.
 * @param speed The speed of the ship.
 * @param ship_agility The agility of the ship.
 * @param turret_agility The agility of the turret.
 * @param hit_points The hit points of the ship.
 * @param defence The defence of the ship.
 * @param gear An array of 5 integers representing the gear loadout.
 *
 * @return A pointer to the newly created Ship struct, or NULL on failure.
 */

struct Ship* createShip(char* ship_name, float speed, float ship_agility, float turret_agility, unsigned int hit_points, unsigned int defence, unsigned int gear[5]) {
    // Allocate memory for the Ship struct
    struct Ship* s = malloc(sizeof(struct Ship));
    if (s == NULL) {
        printf("Error: Memory allocation failed for Ship struct\n");
        return NULL;
    }
    // Allocate memory for the name string
    s->name = malloc(strlen(ship_name) + 1);
    if (s->name == NULL) {
        printf("Error: Memory allocation failed for name string\n");
        free(s);
        return NULL;
    }
    strcpy(s->name, ship_name);
    // Initialize the loadout array
    for (int i = 0; i < 5; i++) {
        if (gear[i] > 0) {
            s->loadout[i] = malloc(gear[i] * sizeof(struct Object*));
            if (s->loadout[i] == NULL) {
                printf("Error: Memory allocation failed for loadout array %d\n", i);
                for (int j = 0; j < i; j++) {
                    free(s->loadout[j]);
                }
                free(s->name);
                free(s);
                return NULL;
            }
        } else {
            s->loadout[i] = NULL; // Set to NULL instead of assigning NULL to the entire array
        }
    }
    // Initialize the remaining fields
    s->speed = speed;
    s->ship_agility = ship_agility;
    s->turret_agility = turret_agility;
    s->gear_score = 0;
    s->hit_points = hit_points;
    s->defence = defence;
    return s;
}

void addOject(struct Ship* s, struct Object* o){
    if(s == NULL){
        return;
    }
    if(canAddObject(s,o)){
        char* type = getObjectType(o);
        int i = 0;
        switch (type){
            case 'r':
                while(s->loadout[0][i] != NULL){
                    i++;
                }
                s->loadout[0][i] = &o;
                break;
            case 'b':
                while(s->loadout[1][i] != NULL){
                    i++;
                }
                s->loadout[1][i] = &o;
                break;
            case 'y':
                while(s->loadout[2][i] != NULL){
                    i++;
                }
                s->loadout[2][i] = &o;
                break;
            case 'g':
                while(s->loadout[3][i] != NULL){
                    i++;
                }
                s->loadout[3][i] = &o;
                break;
            case 't':
                while(s->loadout[4][i] != NULL){
                    i++;
                }
                s->loadout[4][i] = &o;
                break;
            default:
                printf("error adding object");
        }
    }
}

void removeObject(struct Ship* s, int pos) {

}

void printShipStats(struct Ship* s){

}
void printLoadout(struct Ship* s){

}

void deleteShip(struct Ship* s){

}