#include "ships.h"
#include "objects.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OBJECT_TYPES "rbygt"

/**
* Initializes a Ship struct with the given parameters.
* Allocates memory for the Ship struct and duplicates the ship name.
* Initializes all the fields of the Ship struct.
*
* @param ship_name The name of the ship
* @param speed The speed of the ship
* @param ship_agility The agility of the ship
* @param turret_agility The agility of the ship's turrets
* @param hit_points The hit points (health) of the ship
* @param defence The defence points of the ship
* @return Pointer to the initialized Ship struct or NULL if memory allocation fails
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

/**
* Sets up the loadout slots for a given Ship struct with the provided gear specifications.
* Allocates memory for each Slot and initializes its fields.
*
* @param s Pointer to the Ship struct
* @param gear A 2D array where each row contains the slot amount and slot points for a specific type of slot
*/
void setUpShip(struct Ship* s, unsigned int gear[5][2]) {
    if(s == NULL){
        return;
    }
    for (int i = 0; i < 5; i++){
        s->loadout[i] = malloc(sizeof(struct Slots));    // Allocate memory for each Slot
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

/**
* Adds an Object to the appropriate Slot in the Ship's loadout if it can be added.
*
* @param s Pointer to the Ship struct
* @param o Pointer to the Object to be added
*/
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

/**
* Removes an Object from the Ship's loadout based on its position.
* Frees the memory allocated for the Object.
*
* @param s Pointer to the Ship struct
* @param pos The position of the Object to be removed
*/
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

/**
* Prints the statistics of the Ship including gear score, health, turret agility, speed, ship agility, and defense.
*
* @param s Pointer to the Ship struct
*/
void printShipStats(struct Ship* s){
    if(s == NULL){
        return;
    }
    printShipName(s);
    printf("Gear score :    unsuported    Health :    %d\n",s->hit_points);
    printf("Turret agility :    %.2f      Speed :     %.2f\n",s->turret_agility,s->speed);
    printf("Ship agility :      %.2f      Defense :   %d\n",s->ship_agility,s->defence);
}

/**
* Prints the loadout of the Ship including all the Objects in each Slot.
*
* @param s Pointer to the Ship struct
*/
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

/**
* Prints the name of the Ship in a stylized ASCII art format based on the ship's name.
*
* @param s Pointer to the Ship struct
*/
void printShipName(struct Ship* s) {
    if(s == NULL){
        return;
    }
    if(strcmp(s->name,"shooter") == 0){
        printf("    ____  _                 _            \n");
        printf("   / ___|| |__   ___   ___ | |_ ___ _ __ \n");
        printf("   \\___ \\| '_ \\ / _ \\ / _ \\| __/ _ \\ '__|\n");
        printf("    ___) | | | | (_) | (_) | ||  __/ |   \n");
        printf("   |____/|_| |_|\\___/ \\___/ \\__\\___|_|   \n");
    }
    if(strcmp(s->name,"defender") == 0){
        printf(" ____        __                _           \n");
        printf("|  _ \\  ___ / _| ___ _ __   __| | ___ _ __ \n");
        printf("| | | |/ _ \\ |_ / _ \\ '_ \\ / _` |/ _ \\ '__|\n");
        printf("| |_| |  __/  _|  __/ | | | (_| |  __/ |   \n");
        printf("|____/ \\___|_|  \\___|_| |_|\\__,_|\\___|_|   \n");
    }
    if(strcmp(s->name,"speeder") == 0){
        printf("    ____                      _           \n");
        printf("  / ___| _ __   ___  ___  __| | ___ _ __ \n");
        printf("  \\___ \\| '_ \\ / _ \\/ _ \\/ _` |/ _ \\ '__|\n");
        printf("  ___) | |_) |  __/  __/ (_| |  __/ |   \n");
        printf(" |____/| .__/ \\___|\\___|\\__,_|\\___|_|   \n");
        printf("      |_|                              \n");
    }
    if(strcmp(s->name,"enfoncer") == 0){
        printf(" _____        __                           \n");
        printf("| ____|_ __  / _| ___  _ __   ___ ___ _ __ \n");
        printf("|  _| | '_ \\| |_ / _ \\| '_ \\ / __/ _ \\ '__|\n");
        printf("| |___| | | |  _| (_) | | | | (_|  __/ |   \n");
        printf("|_____|_| |_|_|  \\___/|_| |_|\\___\\___|_|   \n");
    }
    if(strcmp(s->name,"fixer") == 0){
       printf(" _____ _               \n");
       printf("|  ___(_)_  _____ _ __ \n");
       printf("| |_  | \\ \\/ / _ \\ '__|\n");
       printf("|  _| | |>  <  __/ |   \n");
       printf("|_|   |_/_/\\_\\___|_|   \n");
    }
    if(strcmp(s->name,"interceptor") == 0){
       printf(" ___       _                          _             \n");
       printf("|_ _|_ __ | |_ ___ _ __ ___ ___ _ __ | |_ ___  _ __ \n");
       printf(" | || '_ \\| __/ _ \\ '__/ __/ _ \\ '_ \\| __/ _ \\| '__|\n");
       printf(" | || | | | ||  __/ | | (_|  __/ |_) | || (_) | |   \n");
       printf("|___|_| |_|\\__\\___|_|  \\___\\___| .__/ \\__\\___/|_|   \n");
       printf("                               |_|                  \n");
    }
    if(strcmp(s->name,"reaper") == 0){
       printf(" ____                            \n");
       printf("|  _ \\ ___  __ _ _ __   ___ _ __ \n");
       printf("| |_) / _ \\/ _` | '_ \\ / _ \\ '__|\n");
       printf("|  _ <  __/ (_| | |_) |  __/ |   \n");
       printf("|_| \\_\\___|\\__,_| .__/ \\___|_|   \n");
       printf("                |_|              \n");
    }
    if(strcmp(s->name,"guardian") == 0){
      printf("  ____                     _ _             \n");
      printf(" / ___|_   _  __ _ _ __ __| (_) __ _ _ __  \n");
      printf("| |  _| | | |/ _` | '__/ _` | |/ _` | '_ \\ \n");
      printf("| |_| | |_| | (_| | | | (_| | | (_| | | | |\n");
      printf(" \\____|\\__,_|\\__,_|_|  \\__,_|_|\\__,_|_| |_|\n");
    }
    if(strcmp(s->name,"striker") == 0){
       printf(" ____  _        _ _             \n");
       printf("/ ___|| |_ _ __(_) | _____ _ __ \n");
       printf("\\___ \\| __| '__| | |/ / _ \\ '__|\n");
       printf(" ___) | |_| |  | |   <  __/ |   \n");
       printf("|____/ \\__|_|  |_|_|\\_\\___|_|   \n");
    }

}

/**
* Frees the memory allocated for a Ship struct and its associated fields.
*
* @param s Pointer to the Ship struct to be deleted
*/
void deleteShip(struct Ship* s){
    if (s == NULL) {
        return;
    }
    // Free the ship's name
    free(s->name);
    // Free each slot's objects and the slot itself
    for (int i = 0; i < 5; i++) {
        struct Object* iter = s->loadout[i]->head;
        while (iter != NULL) {
            struct Object* next = iter->next;
            deleteObject(iter);
            iter = next;
        }
        free(s->loadout[i]);
    }
    // Free the ship struct itself
    free(s);
}