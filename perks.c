#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "objects.h"
#include "perks.h"
#include "clear_input.h"
#define MAX_LINE_SIZE 1024

struct Perk* createPerk(char* first_boost_type,char* second_boost_type, float first_boost_value,float second_boost_value) {
    struct Perk* p = malloc(sizeof(struct Perk));
    p->first_boost_type = strdup(first_boost_type);
    p->second_boost_type = strdup(second_boost_type);
    p->first_boost_value = first_boost_value;
    p->second_boost_value = second_boost_value;
    p->is_event = false;
    return p;
}

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
    printf("Error handeling your item, please report it to @komiko\n");
    return 0;
}

void addPerks(struct Object* o) {
    if(o == NULL){
        return;
    }
    bool perk_choice =  true;
    bool is_event = true;
    int number_of_perks = numberOfPerks(o);
    for(int i = 0; i<number_of_perks; i++){
        while(perk_choice){
            printf("Is the perk an event perk\n");
            printf("------------------------\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("0. Don't add more perks\n");
            printf("------------------------\n");
            printf("Your choice : ");
            int choice = 0;
            scanf("%d",&choice);
            clearInputBuffer();
            switch (choice){
            case 1 :
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
        char** perk_list = perkLists(o);
        o->perk_list[i] = displayAndChooseAvailablePerks(perk_list, is_event);
        perk_choice =  true;
    }
    return;
}

struct Perk* displayAndChooseAvailablePerks(char** perk_list, bool is_event) {
    if (perk_list == NULL) {
        printf("Error: perk_list is NULL\n");
        return NULL;
    }

    char* perk_rarity = NULL;
    bool perk_rarity_choice = true;
    while (perk_rarity_choice) {
        printf("What do you want to do\n");
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

    if (is_event) {
        // Allocate memory for event perk file paths
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
        // Allocate memory for normal perk file paths
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

    printf("What do you want to do\n");
    printf("------------------------\n");
    for (int i = 0; i < num_files; i++) {
        FILE* file = fopen(perks_full_path[i], "r");
        if (file == NULL) {
            printf("Error opening \"%s\", file does not exist\n", perks_full_path[i]);
            continue;
        }

        /*if (fgets(line, sizeof(line), file) == NULL) {
            printf("Error reading first line from file \"%s\"\n", perks_full_path[i]);
            fclose(file);
            file = NULL;
            continue;
        }*/

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

        if (i > 0) {
            perk_choice[i] = perk_iter - perk_choice[i - 1]; // Calculate the number of perks in the current file
        } else {
            perk_choice[i] = perk_iter;
        }
        if(file!= NULL){
            fclose(file); // Close the file after reading
        }
        printf("\n");
    }
    printf("------------------------\n");
    printf("Your choice: ");
    int choice_perk = 2;
    scanf("%d", &choice_perk);
    clearInputBuffer();
    int file_number = -1;
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

    /*if (fgets(line, sizeof(line), file) == NULL) {
        printf("Error reading first line from file \"%s\"\n", perks_full_path[file_number]);
        fclose(file);
        return NULL;
    }*/

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
    printf("\n %s \n",line);

    char* copiedline = strdup(line);
    char* token = strtok(copiedline, ",");
    float first_boost_value = atof(token);
    token = strtok(NULL, ",");
    char* first_boost_type = strdup(token);
    token = strtok(NULL, ",");
    float second_boost_value = atof(token);
    token = strtok(NULL, "\r");
    char* second_boost_type = strdup(token);
    free(copiedline); // Free the copied line

    struct Perk* p = createPerk(first_boost_type, second_boost_type, first_boost_value, second_boost_value);
    updateEvent(p, is_event);
    fclose(file); // Close the file after reading

    // Free the memory allocated for perk_rarity and perks_full_path
    free(perk_rarity);
    for (int i = 0; i < num_files; i++) {
        free(perks_full_path[i]);
    }
    //displayPerk(*p);
    return p;
}

void updateEvent(struct Perk* p,bool is_event) {
    p->is_event = is_event;
}

char** perkLists(struct Object* o) {
    char** files_names = malloc(sizeof(char*) * 2);
    if (files_names == NULL) {
        return NULL;
    }
    if(o->type == 0){
        if(strcmp(o->name, "standard_cannon") == 0 || strcmp(o->name, "blast_cannon") == 0 ||strcmp(o->name, "sniper_cannon") == 0 || strcmp(o->name, "explosive_cannon") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_cannons");
        } else if(strcmp(o->name, "galting_gun") == 0 || strcmp(o->name, "carronade") == 0 ||strcmp(o->name, "grenade_launcher") == 0 || strcmp(o->name, "railgun") == 0 || strcmp(o->name, "mine") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
        } else if(strcmp(o->name, "standard_mortar") == 0 || strcmp(o->name, "long_range_mortar") == 0 ||strcmp(o->name, "ballpark_mortar") == 0 || strcmp(o->name, "big_berta") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_mortars");
        } else if(strcmp(o->name, "standard_torpedo") == 0 || strcmp(o->name, "big_torpedo") == 0 ||strcmp(o->name, "swift_torpedo") == 0 || strcmp(o->name, "triple_torpedo") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_torpedoes");
        } else if(strcmp(o->name, "missile_launcher") == 0 || strcmp(o->name, "multi_missile") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_missiles");
        } else if(strcmp(o->name, "flare_gun") == 0 || strcmp(o->name, "napalm_launcher") == 0 ||strcmp(o->name, "fire_bomb") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_fire");
        } else {
            free(files_names);
            return NULL;
        }
    } else if(o->type == 1){
        if(strcmp(o->name, "standard_shield") == 0 || strcmp(o->name, "big_shield") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_shields");
        } else if(strcmp(o->name, "turbo") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
        } else if(strcmp(o->name, "bandage") == 0 || strcmp(o->name, "big_bandage") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
        }
    }
    else if(o->type == 2) {
        if(strcmp(o->name, "overboost") == 0 || strcmp(o->name, "nitro") == 0 || strcmp(o->name, "tesla_bolt") == 0 || strcmp(o->name, "tesla_shield") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
        } else if(strcmp(o->name, "frost_blaster") == 0 || strcmp(o->name, "frost_launcher") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_frost");
        } else {
            free(files_names);
            return NULL;
        }
    }
    else if(o->type == 3) {
        if(strcmp(o->name, "repair_box_launcher") == 0 || strcmp(o->name, "repair_pulse") == 0 || strcmp(o->name, "duct_tape") == 0 || strcmp(o->name, "repair_bolt") == 0 || strcmp(o->name, "repair_plasma") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
           } else {
               free(files_names);
               return NULL;
           }
    }
    else if(o->type == 4) {
        if(strcmp(o->name, "defence_wall") == 0 || strcmp(o->name, "defence_aura") == 0 || strcmp(o->name, "bloster_armor") == 0 || strcmp(o->name, "cleanse_pulse") == 0) {
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
           } else {
               free(files_names);
               return NULL;
           }
    }
    return files_names;
}


void displayPerk(struct Perk p ) {
    printf("Is Event: %s\n", p.is_event ? "True" : "False");
    printf("First Boost Value: %.2f\n", p.first_boost_value);
    printf("First Boost Type: %s\n", p.first_boost_type);
    printf("Second Boost Value: %.2f\n", p.second_boost_value);
    printf("Second Boost Type: %s\n", p.second_boost_type);
}