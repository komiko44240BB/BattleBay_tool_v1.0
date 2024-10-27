#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "objects.h"
#include "perks.h"

/**
 * Creates a new Object instance with specified parameters and allocates memory for it.
 * Initializes the object fields with given values and default values where necessary.
 *
 * @param rarity                  A string indicating the object's rarity (e.g., "common", "rare").
 * @param name                    A string specifying the object's name.
 * @param level                   The level of the object.
 * @param base_stat               The base stat value of the object.
 * @param cool_down               Cooldown time for the object in seconds.
 * @param range                   Range value for the object.
 * @param projectile_speed        Speed of the object's projectile.
 * @param critical_hit_chance     The probability of a critical hit.
 * @param critical_hit_multiplier Multiplier applied on critical hits.
 * @param radius                  Radius of the object’s area of effect.
 * @param spread                  Spread of the object’s attack.
 * @param amount_of_projectiles   Number of projectiles the object launches.
 * @param duration                Duration of the object's effect in seconds.
 * @param slot_points             Number of slot points the object requires.
 * @param combo_dmg_boost         Damage boost percentage when in combo.
 * @return                        Pointer to the created Object struct, or NULL if memory allocation fails.
 */
struct Object* createObject(char* rarity, char* name, unsigned int level, float base_stat, float cool_down, float range, float projectile_speed, float critical_hit_chance, float critical_hit_multiplier, float radius, float spread, unsigned int amount_of_projectiles, float duration, unsigned int slot_points, float combo_dmg_boost) {
    struct Object* o = malloc(sizeof(struct Object));
    if(o == NULL) {
        return NULL;
    }
    o->name = strdup(name);
    o->rarity = strdup(rarity);
    o->type = -1;  // Initial default type value
    o->level = level;
    o->training_level = 0;
    o->base_stat = base_stat;
    o->cool_down = cool_down;
    o->range = range;
    o->projectile_speed = projectile_speed;
    o->critical_hit_chance = critical_hit_chance;
    o->critical_hit_multiplier = critical_hit_multiplier;
    o->radius = radius;
    o->spread = spread;
    o->amount_of_projectiles = amount_of_projectiles;
    o->duration = duration;
    o->combo_dmg_boost = combo_dmg_boost;
    o->slot_points = slot_points;
    for(int i = 0; i < 4; i++){
        o->perk_list[i] = NULL;  // Initialize perk slots as empty
    }
    o->next = NULL;  // Initialize next pointer for linked structure
    return o;
}

/**
 * Retrieves the type of an Object instance.
 *
 * @param o Pointer to the Object whose type is to be retrieved.
 * @return  Integer representing the object's type, or -1 if the object is NULL.
 */
int getObjectType(struct Object* o) {
    if(o == NULL){
        return -1;
    }
    return o->type;
}

/**
 * Retrieves the slot points of an Object instance.
 *
 * @param o Pointer to the Object whose slot points are to be retrieved.
 * @return  Integer value representing the object's slot points.
 */
int getObjectPoints(struct Object* o) {
    return o->slot_points;
}

/**
 * Prints the details of an Object instance, including attributes such as name, level,
 * base stat, cooldown, and others, if they are non-zero.
 *
 * @param o Pointer to the Object to be printed.
 */
void printObject(struct Object* o) {
    if (o == NULL){
        return;
    }
    if(o->level != 0){
        printf("%s %s :",o->rarity,o->name);
        printf(" level %d\n",o->level);
        if(o->base_stat != 0){
            printf("\tBase stat: %.2f\n",o->base_stat);
        }
        if(o->cool_down != 0){
            printf("\tCooldown: %.2f\n",o->cool_down);
        }
        if(o->range != 0){
            printf("\tRange :%.2f\n",o->range);
        }
        if(o->projectile_speed != 0){
            printf("\tProj speed :%.2f\n",o->projectile_speed);
        }
        if(o->critical_hit_chance != 0){
            printf("\tcrit hit chance :%.2f\n",o->critical_hit_chance);
        }
        if(o->critical_hit_multiplier != 0){
            printf("\tCrit hit mult :%.2f\n",o->critical_hit_multiplier);
        }
        if(o->radius != 0){
            printf("\tRadius :%.2f\n",o->radius);
        }
        if(o->spread != 0){
            printf("\tSpread :%.2f\n",o->spread);
        }
        if(o->amount_of_projectiles > 1){
            printf("\tAmnt of proj :%d\n",o->amount_of_projectiles);
        }
        if(o->duration != 0){
            printf("\tDuration :%.2f\n",o->duration);
        }
        for(int i = 0; i< o->amount_of_perks; i++){
            displayPerk(o->perk_list[i]);
        }
    }
}

/**
 * Frees the memory allocated for an Object instance, including dynamic strings.
 *
 * @param o Pointer to the Object to be deleted.
 */
void deleteObject(struct Object* o) {
    if (o) {
        // Free dynamically allocated memory for rarity and name
        free(o->rarity);
        free(o->name);
        // Free each Perk in the perk_list
        for (unsigned int i = 0; i < o->amount_of_perks; i++) {
            deletePerk(o->perk_list[i]);
        }
        // Free the object itself
        free(o);
    }
}

/**
 * Edits the type field of an Object instance.
 *
 * @param o    Pointer to the Object whose type is to be modified.
 * @param type New type value to assign, decremented by 1 for internal usage.
 */
void editObjectType(struct Object* o, unsigned int type) {
    type--;
    o->type = type;
}

/**
 * Adds a Perk to an Object’s perk list if there is available space.
 * If successfully added, prints a confirmation message.
 *
 * @param p Pointer to the Perk to be added.
 * @param o Pointer to the Object to which the Perk will be added.
 */
void addPerk(struct Perk* p, struct Object* o) {
    if(o == NULL || p == NULL){
        return;
    }
    for(int i = 0; i < 4; i++){
        if(o->perk_list[i] == NULL){
            o->perk_list[i] = p;
            printf("Perk was added successfully\n");
            return;
        }
    }
    printf("Perk could not be added, maximum perks reached.\n");
}

/**
 * @brief Deletes all Objects in a linked list contained within a Slots structure.
 *
 * This function traverses the linked list of Objects pointed to by the head
 * of the provided Slots structure. It frees each Object in the list and
 * finally frees the Slots structure itself.
 *
 * @param slots A pointer to the Slots structure that contains the linked list
 *              of Objects. If NULL, the function returns immediately.
 */
void deleteSlots(struct Slots* slots) {
    if (slots == NULL) {
        return; // Nothing to delete
    }

    struct Object* current = slots->head; // Pointer to the current Object in the list
    struct Object* next; // Pointer to the next Object to be deleted

    // Iterate through the linked list of Objects and free each one
    while (current != NULL) {
        next = current->next; // Store the next object to process
        deleteObject(current); // Free the current object from memory
        current = next; // Move to the next object in the list
    }

    free(slots); // Free the Slots structure itself to avoid memory leaks
}
