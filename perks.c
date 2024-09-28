#include "perks.h"
#include "menu.h"
#include "objects.h"
#define MAX_LINE_SIZE 1024

struct Perk* createPerk(char* first_boost_type,char* second_boost_type, int first_boost_value,int second_boost_value) {
    struct Perk* p = malloc(sizeof(struct Perk));
    p->first_boost_type = strdup(first_boost_type);
    p->second_boost_type = strdup(second_boost_type);
    p->first_boost_value = first_boost_value;
    p->second_boost_value = second_boost_value;
    p->is_event = false;
    return p;
}

int numberOfPerks(struct Object* o) {

}

void addPerks(struct Object* o) {
    if(o == NULL){
        return;
    }
    bool perk_choice =  true;
    bool is_event = false;
    int number_of_perks = numberOfPerks(o);
    for(int i = 0; i<number_of_perks; i++){
        while(perk_choice){
            printf("Is the perk an event perk\n");
            printf("\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("0. Don't add more perks\n");
            printf("\n");
            printf("Your choice :\n");
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
        displayAvailablePerks(perk_list, is_event);
    }
}

void displayAvailablePerks(char** perk_list, bool is_event) {
    if(perk_list == NULL){
        return;
    }
    char* perk_rarity = "" ;
    bool perk_rarity_choice = true;
    while(perk_rarity_choice){
        printf("What do you want to do\n");
        printf("------------------------\n");
        printf("1.Common\n");
        printf("2.Uncommon\n");
        printf("3.Rare\n");
        printf("4.Epic\n");
        printf("5.Legendary\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice){
            case 1:
                perk_rarity = strdup("common");
                perk_rarity_choice = false;
                break;
            case 2:
                perk_rarity = strdup("uncommon");
                perk_rarity_choice = false;
                break;
            case 3:
                perk_rarity = strdup("rare");
                perk_rarity_choice = false;
                break;
            case 4:
                perk_rarity = strdup("epic");
                perk_rarity_choice = false;
                break;
            case 5:
                perk_rarity = strdup("legendary");
                perk_rarity_choice = false;
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    if(is_event){
        char* event_perks_file_name_self = malloc(19 + strlen(perk_rarity) + 1 + strlen(perk_list[0]) + 4 + 1);
        char* event_perks_file_name_group = malloc(19 + strlen(perk_rarity) + 1 + strlen(perk_list[1]) + 4 + 1);
        if (event_perks_file_name_self == NULL || event_perks_file_name_group == NULL) {
            free(perk_rarity);
            free(event_perks_file_name_self);
            free(event_perks_file_name_group);
            return;
        }
        sprintf(event_perks_file_name_self, "../Perk_data/event_%s_%s.csv", perk_rarity, perk_list[0]);
        sprintf(event_perks_file_name_group, "../Perk_data/event_%s_%s.csv", perk_rarity, perk_list[1]);

        FILE* file = fopen(event_perks_file_name_self, "r");
        if (file == NULL) {
            printf("Error opening \"%s\", file does not exist\n", event_perks_file_name_self);
            return ;
        }
        char line[MAX_LINE_SIZE];
        if (fgets(line, sizeof(line), file) == NULL) {
            fclose(file);
            return;
        }
        char* copiedline = strdup(line);


    }else{

    }




}




char** perkLists(const struct Object* o) {
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