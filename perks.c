#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "objects.h"
#include "perks.h"
#include "clear_input.h"
#define MAX_LINE_SIZE 1024

/**
 * Allocates memory for and initializes a new Perk structure with the specified boost types and values.
 *
 * @param first_boost_type A string representing the type of the first boost (e.g., "attack", "defense").
 * @param second_boost_type A string representing the type of the second boost.
 * @param first_boost_value The numeric value of the first boost.
 * @param second_boost_value The numeric value of the second boost.
 * @return A pointer to the newly created Perk structure.
 */
struct Perk* createPerk(char* first_boost_type, char* second_boost_type, float first_boost_value, float second_boost_value) {
    struct Perk* p = malloc(sizeof(struct Perk));
    p->first_boost_type = strdup(first_boost_type);
    p->second_boost_type = strdup(second_boost_type);
    p->first_boost_value = first_boost_value;
    p->second_boost_value = second_boost_value;
    p->is_event = false;
    return p;
}

/**
 * Determines the number of perks available to an Object based on its rarity and level.
 *
 * @param o A pointer to the Object structure for which the perks are being evaluated.
 * @return The number of perks the Object is eligible for based on its rarity and level.
 *         Returns 0 for unrecognized item rarity, printing an error message.
 */
int numberOfPerks(struct Object* o) {
    if(strcmp(o->rarity, "common") == 0){
        if(o->level > 20){
            return 1;
        }
        return 0;
    }
    if(strcmp(o->rarity, "uncommon") == 0){
        if(o->level > 30){
            return 2;
        } if(o->level > 10){
            return 1;
        }
        return 0;
    }
    if(strcmp(o->rarity, "rare") == 0){
        if(o->level > 20){
            return 3;
        } if(o->level > 10){
            return 2;
        }
        return 1;
    }
    if(strcmp(o->rarity, "epic") == 0){
        if(o->level > 30){
            return 4;
        } if(o->level > 10){
            return 3;
        }
        return 2;
    }
    if(strcmp(o->rarity, "legendary") == 0){
        if(o->level > 20){
            return 4;
        }
        return 3;
    }
    printf("Error handling your item, please report it to @komiko\n");
    return 0;
}

/**
 * Adds eligible perks to an Object based on its number of available perks.
 *
 * @param o A pointer to the Object structure to which perks are being added.
 *          If NULL, the function returns immediately.
 */
void addPerks(struct Object* o) {
    if(o == NULL){
        return;
    }

    bool perk_choice = true;  // Indicates if the user has chosen to add a perk.
    bool is_event = true;     // Indicates if the current perk is an event perk.
    int number_of_perks = numberOfPerks(o);  // Number of perks to add to the Object.
    o->amount_of_perks = number_of_perks;
    for(int i = 0; i < number_of_perks; i++){
        while(perk_choice){
            printf("Is the perk an event perk ?\n");
            printf("------------------------\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("0. Don't add more perks\n");
            printf("------------------------\n");
            printf("Your choice : ");

            int choice = 0;
            scanf("%d", &choice);
            clearInputBuffer();

            switch (choice){
            case 1:
                is_event = true;
                perk_choice = false;
                break;
            case 2:
                is_event = false;
                perk_choice = false;
                break;
            case 0:
                return;
            default:
                printf("Wrong input\n");
            }
        }

        char** perk_list = perkLists(o);  // Retrieves the list of available perks for the Object.
        o->perk_list[i] = displayAndChooseAvailablePerks(perk_list, is_event, o);  // Prompts user to choose a perk.
        perk_choice = true;  // Reset choice for next iteration.
        free(perk_list);     // Free allocated memory for the perk list.
    }
    return;
}


/**
 * Displays available perks based on specified rarity and allows the user to choose one.
 * Allocates memory for file paths, handles user input for perk rarity, reads files
 * to display available perks, and creates the selected Perk struct for the specified object.
 *
 * @param perk_list Array of perk names as strings to determine perk file paths
 * @param is_event Boolean indicating if the perk is event-based or regular
 * @param o Pointer to the Object struct for which the perk is selected
 * @return Pointer to the created Perk struct, or NULL if an error occurs
 */
struct Perk* displayAndChooseAvailablePerks(char** perk_list, bool is_event, struct Object* o) {
    if (perk_list == NULL) {
        printf("Error: perk_list is NULL\n");
        return NULL;
    }

    char* perk_rarity = NULL;
    bool perk_rarity_choice = true;

    // Prompt user to select perk rarity
    while (perk_rarity_choice) {
        printf("What rarity is your perk ?\n");
        printf("------------------------\n");
        printf("1.Uncommon\n");
        printf("2.Rare\n");
        printf("3.Epic\n");
        printf("4.Legendary\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                perk_rarity = strdup("uncommon");
                perk_rarity_choice = false;
                break;
            case 2:
                perk_rarity = strdup("rare");
                perk_rarity_choice = false;
                break;
            case 3:
                perk_rarity = strdup("epic");
                perk_rarity_choice = false;
                break;
            case 4:
                perk_rarity = strdup("legendary");
                perk_rarity_choice = false;
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    char* perks_full_path[3] = {NULL, NULL, NULL}; // Array to store file paths
    int num_files = 0;

    // Allocate and build file paths based on event status and selected rarity
    if (is_event) {
        perks_full_path[0] = malloc(19 + strlen(perk_rarity) + 1 + strlen(perk_list[0]) + 4 + 1);
        perks_full_path[1] = malloc(19 + strlen(perk_rarity) + 1 + strlen(perk_list[1]) + 4 + 1);
        if (perks_full_path[0] == NULL || perks_full_path[1] == NULL) {
            free(perk_rarity);
            free(perks_full_path[0]);
            free(perks_full_path[1]);
            printf("Error allocating memory for event perk file paths\n");
            return NULL; // Return NULL if memory allocation fails
        }
        sprintf(perks_full_path[0], "../Perk_data/event_%s_%s.csv", perk_rarity, perk_list[0]);
        sprintf(perks_full_path[1], "../Perk_data/event_%s_%s.csv", perk_rarity, perk_list[1]);
        num_files = 2;
    } else {
        perks_full_path[0] = malloc(20 + strlen(perk_rarity) + 1 + strlen(perk_list[0]) + 4 + 1);
        perks_full_path[1] = malloc(20 + strlen(perk_rarity) + 1 + strlen(perk_list[1]) + 4 + 1);
        perks_full_path[2] = malloc(20 + strlen(perk_rarity) + 14 + 1);
        if (perks_full_path[0] == NULL || perks_full_path[1] == NULL || perks_full_path[2] == NULL) {
            free(perk_rarity);
            free(perks_full_path[0]);
            free(perks_full_path[1]);
            free(perks_full_path[2]);
            printf("Error allocating memory for normal perk file paths\n");
            return NULL; // Return NULL if memory allocation fails
        }
        sprintf(perks_full_path[0], "../Perk_data/normal_%s_%s.csv", perk_rarity, perk_list[0]);
        sprintf(perks_full_path[1], "../Perk_data/normal_%s_%s.csv", perk_rarity, perk_list[1]);
        sprintf(perks_full_path[2], "../Perk_data/normal_%s_all_items.csv", perk_rarity);
        num_files = 3;
    }

    char line[MAX_LINE_SIZE];
    int perk_iter = 0;
    int perk_choice[3] = {0}; // Array to store the number of perks in each file

    // Display available perks from files
    printf("Available perks for your object\n");
    printf("------------------------\n");
    for (int i = 0; i < num_files; i++) {
        FILE* file = fopen(perks_full_path[i], "r");
        if (file == NULL) {
            printf("Error opening \"%s\", file does not exist\n", perks_full_path[i]);
            continue;
        }

        // Read perks line by line
        while (!feof(file)) {
            if (fgets(line, sizeof(line), file) == NULL) {
                printf("Error reading line from file \"%s\"\n", perks_full_path[i]);
                fclose(file);
                file = NULL;
                break;
            }
            char* copiedline = strdup(line);
            perk_iter++;
            printf("%d. %s", perk_iter, copiedline);
            free(copiedline); // Free the copied line
        }

        // Calculate perks count per file
        if (i > 0) {
            perk_choice[i] = perk_iter - perk_choice[i - 1];
        } else {
            perk_choice[i] = perk_iter;
        }
        if (file != NULL) {
            fclose(file); // Close file after reading
        }
        printf("\n");
    }
    printf("------------------------\n");
    printf("Your choice: ");
    int choice_perk = 0;
    scanf("%d", &choice_perk);
    clearInputBuffer();
    int file_number = -1;

    // Determine which file contains the selected perk based on user input
    if (choice_perk <= perk_choice[0]) {
        file_number = 0;
        choice_perk = choice_perk - 1;
    } else if (choice_perk <= (perk_choice[0] + perk_choice[1])) {
        file_number = 1;
        choice_perk = choice_perk - perk_choice[0] - 1;
    } else {
        file_number = 2;
        choice_perk = choice_perk - (perk_choice[0] + perk_choice[1]) - 1;
    }

    FILE* file = fopen(perks_full_path[file_number], "r");
    if (file == NULL) {
        printf("Error opening \"%s\", file does not exist\n", perks_full_path[file_number]);
        return NULL;
    }

    // Find and read the selected perk line in the chosen file
    perk_iter = 0;
    while (choice_perk > perk_iter) {
        if (fgets(line, sizeof(line), file) == NULL) {
            printf("Error reading line from file \"%s\"\n", perks_full_path[file_number]);
            fclose(file);
            return NULL;
        }
        perk_iter++;
    }
    fgets(line, sizeof(line), file);

    if (line == NULL) {
        printf("Error reading chosen perk line from file \"%s\"\n", perks_full_path[file_number]);
        fclose(file);
        return NULL;
    }
    char* copiedline = strdup(line);
    struct Perk* p = NULL;

    // Parse perk values and types from the selected line
    char* token = strtok(copiedline, ",");
    float first_boost_value = atof(token);
    token = strtok(NULL, ",");
    char* first_boost_type = strdup(token);
    token = strtok(NULL, ",");
    float second_boost_value = atof(token);
    token = strtok(NULL, "\r");
    char* second_boost_type = strdup(token);

    free(copiedline); // Free copied line memory
    fclose(file); // Close file after reading

    char* selected_perk = malloc((strlen(first_boost_type) + strlen(second_boost_type)) * sizeof(char));
    snprintf(selected_perk, strlen(first_boost_type) + strlen(second_boost_type), "%s,%s", first_boost_type, second_boost_type);

    // Check if selected perk is already applied; if not, create and update it
    if (perk_already_fited(is_event, o, selected_perk) == false) {
        p = createPerk(first_boost_type, second_boost_type, first_boost_value, second_boost_value);
        updateEvent(p, is_event);
    } else {
        printf("You can't have multiple of the same event perks on an object");
        p = displayAndChooseAvailablePerks(perk_list, is_event, o);
    }
    free(selected_perk);

    // Free memory allocated for perk_rarity and perks_full_path
    free(perk_rarity);
    for (int i = 0; i < num_files; i++) {
        free(perks_full_path[i]);
    }
    return p;
}

/**
 * Updates the event status of a perk.
 *
 * @param p Pointer to a Perk struct, representing the perk to be updated.
 * @param is_event Boolean indicating whether the perk is part of an event.
 */
void updateEvent(struct Perk* p, bool is_event) {
    p->is_event = is_event;
}

/**
 * Generates a list of perk files based on the object type and name.
 *
 * Allocates memory for an array of strings with two elements.
 * If the object name matches certain predefined values, the function assigns
 * the corresponding filenames and category. Otherwise, returns NULL if
 * allocation fails or the object name is invalid.
 *
 * @param o Pointer to an Object struct, representing the object for which the perk list is generated.
 * @return A dynamically allocated array of strings containing the object name and category,
 *         or NULL if allocation fails or the name is unrecognized.
 */
char** perkLists(struct Object* o) {
    char** files_names = malloc(sizeof(char*) * 2);
    if (files_names == NULL) {
        return NULL;
    }
    if(o->type == 0) {
        if(strcmp(o->name, "standard_cannon") == 0 || strcmp(o->name, "blast_cannon") == 0 ||
           strcmp(o->name, "sniper_cannon") == 0 || strcmp(o->name, "explosive_cannon") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_cannons");
        } else if(strcmp(o->name, "galting_gun") == 0 || strcmp(o->name, "carronade") == 0 ||
                  strcmp(o->name, "grenade_launcher") == 0 || strcmp(o->name, "railgun") == 0 || strcmp(o->name, "mine") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
        } else if(strcmp(o->name, "standard_mortar") == 0 || strcmp(o->name, "long_range_mortar") == 0 ||
                  strcmp(o->name, "ballpark_mortar") == 0 || strcmp(o->name, "big_berta") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_mortars");
        } else if(strcmp(o->name, "standard_torpedo") == 0 || strcmp(o->name, "big_torpedo") == 0 ||
                  strcmp(o->name, "swift_torpedo") == 0 || strcmp(o->name, "triple_torpedo") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_torpedoes");
        } else if(strcmp(o->name, "missile_launcher") == 0 || strcmp(o->name, "multi_missile") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_missiles");
        } else if(strcmp(o->name, "flare_gun") == 0 || strcmp(o->name, "napalm_launcher") == 0 ||
                  strcmp(o->name, "fire_bomb") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_fire");
        } else {
            free(files_names);
            return NULL;
        }
    } else if(o->type == 1) {
        if(strcmp(o->name, "standard_shield") == 0 || strcmp(o->name, "big_shield") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_shields");
        } else if(strcmp(o->name, "turbo") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
        } else if(strcmp(o->name, "bandage") == 0 || strcmp(o->name, "big_bandage") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
        } else {
            free(files_names);
            return NULL;
        }
    } else if(o->type == 2) {
        if(strcmp(o->name, "overboost") == 0 || strcmp(o->name, "nitro") == 0 || strcmp(o->name, "tesla_bolt") == 0 ||
           strcmp(o->name, "tesla_shield") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
        } else if(strcmp(o->name, "frost_blaster") == 0 || strcmp(o->name, "frost_launcher") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_frost");
        } else {
            free(files_names);
            return NULL;
        }
    } else if(o->type == 3) {
        if(strcmp(o->name, "repair_box_launcher") == 0 || strcmp(o->name, "repair_pulse") == 0 ||
           strcmp(o->name, "duct_tape") == 0 || strcmp(o->name, "repair_bolt") == 0 || strcmp(o->name, "repair_plasma") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
        } else {
            free(files_names);
            return NULL;
        }
    } else if(o->type == 4) {
        if(strcmp(o->name, "defence_wall") == 0 || strcmp(o->name, "defence_aura") == 0 ||
           strcmp(o->name, "bloster_armor") == 0 || strcmp(o->name, "cleanse_pulse") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
        } else {
            free(files_names);
            return NULL;
        }
    }
    return files_names;
}

/**
 * Checks if a perk is already fitted to the object based on the event type.
 *
 * Iterates through the object's perk list, comparing each perk to the selected perk
 * (case-insensitive). Returns true if a matching perk is found, otherwise false.
 *
 * @param is_event Boolean indicating if the object is event-based.
 * @param o Pointer to an Object struct containing the perk list.
 * @param selected_perk String representing the name of the perk to check.
 * @return True if the selected perk is already fitted, false otherwise.
 */
bool perk_already_fited(bool is_event, struct Object* o, char* selected_perk) {
    bool is_fited = false;
    if(is_event) {
        for(int i = 0; i < 4; i++) {
            if(o->perk_list[i] != NULL) {
                char* perk = perk_to_string(o->perk_list[i]);
                if(strcasecmp(perk, selected_perk) == 0) {
                    is_fited = true;
                }
                free(perk);
            }
        }
    }
    return is_fited;
}

/**
 * Converts the boost types of a perk into a comma-separated string format.
 *
 * Allocates memory for a string containing the first and second boost types,
 * separated by a comma. Returns NULL if allocation fails.
 *
 * @param p Pointer to a Perk struct, representing the perk to convert.
 * @return A dynamically allocated string of the perk's boost types in "type1,type2" format, or NULL if allocation fails.
 */
char* perk_to_string(struct Perk* p) {
    char* perk = malloc((strlen(p->first_boost_type) + strlen(p->second_boost_type)) * sizeof(char));
    if (perk == NULL) {
        return NULL;
    }
    snprintf(perk, strlen(p->first_boost_type) + strlen(p->second_boost_type), "%s,%s", p->first_boost_type, p->second_boost_type);
    return perk;
}

/**
 * Displays the details of a given perk.
 *
 * Prints the event status, first and second boost values, and boost types
 * of the perk to standard output.
 *
 * @param p Perk struct containing the details to be displayed.
 */
void displayPerk(struct Perk* p) {
    if(p != NULL){
        printf("Is Event: %s\n", p->is_event ? "True" : "False");
        printf("First Boost Value: %.2f\n", p->first_boost_value);
        printf("First Boost Type: %s\n", p->first_boost_type);
        printf("Second Boost Value: %.2f\n", p->second_boost_value);
        printf("Second Boost Type: %s\n", p->second_boost_type);
    }
}

/**
 * Frees memory allocated for a Perk struct and its members.
 *
 * @param p Pointer to the Perk struct to be deleted. If p is NULL,
 *          the function does nothing. Otherwise, it frees memory
 *          for each allocated member before freeing the Perk itself.
 */
void deletePerk(struct Perk* p) {
    if (p == NULL) { // Check if the pointer is NULL to avoid unnecessary operations.
        return;
    }
    if (p->first_boost_type != NULL) { // Free first_boost_type if it has been allocated.
        free(p->first_boost_type);
        p->first_boost_type = NULL; // Set pointer to NULL to avoid dangling pointers.
    }
    if (p->second_boost_type != NULL) { // Free second_boost_type if it has been allocated.
        free(p->second_boost_type);
        p->second_boost_type = NULL; // Set pointer to NULL to avoid dangling pointers.
    }
    free(p); // Free the Perk struct itself.
}

