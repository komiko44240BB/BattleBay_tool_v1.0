#include "perks.h"

#include "objects.h"


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
    }
}

char** perkLists(struct Object* o) {
    char** files_names = malloc(sizeof(char*) * 2);
    if(o->type == 0){
        if(strcmp(o->name, "standard_cannon") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_cannons");
            return files_names;
        }
        if(strcmp(o->name, "blast_cannon") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_cannons");
            return files_names;
        }
        if(strcmp(o->name, "sniper_cannon") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_cannons");
            return files_names;
        }
        if(strcmp(o->name, "explosive_canon") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_cannons");
            return files_names;
        }
        if(strcmp(o->name, "galting_gun") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "carronade") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "grenade_launcher") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "standard_mortar") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_mortars");
            return files_names;
        }
        if(strcmp(o->name, "long_range_mortar") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_mortars");
            return files_names;
        }
        if(strcmp(o->name, "ballpark_mortar") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_mortars");
            return files_names;
        }
        if(strcmp(o->name, "big_berta") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_mortars");
            return files_names;
        }
        if(strcmp(o->name, "standard_torpedo") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_torpedoes");
            return files_names;
        }
        if(strcmp(o->name, "big_torpedo") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_torpedoes");
            return files_names;
        }
        if(strcmp(o->name, "swift_torpedo") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_torpedoes");
            return files_names;
        }
        if(strcmp(o->name, "triple_torpedo") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_torpedoes");
            return files_names;
        }
        if(strcmp(o->name, "railgun") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "missile_launcher") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_missiles");
            return files_names;
        }
        if(strcmp(o->name, "multi_missile") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_missiles");
            return files_names;
        }
        if(strcmp(o->name, "mine") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "flare_gun") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_fire");
            return files_names;
        }
        if(strcmp(o->name, "napalm_launcher") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_fire");
            return files_names;
        }
        if(strcmp(o->name, "fire_bomb") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_fire");
            return files_names;
        }
    }
    if(o->type == 1){
        if(strcmp(o->name, "standard_shield") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_shields");
            return files_names;
        }
        if(strcmp(o->name, "big_shield") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_shields");
            return files_names;
        }
        if(strcmp(o->name, "turbo") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "bandage") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
            return files_names;
        }
        if(strcmp(o->name, "big_bandage") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
            return files_names;
        }
    }
    if(o->type == 2){
        if(strcmp(o->name, "overboost") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "nitro") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "tesla_bolt") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "tesla_shield") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "frost_blaster") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_forst");
            return files_names;
        }
        if(strcmp(o->name, "frost_launcher") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_forst");
            return files_names;
        }
    }
    if(o->type == 3){
        if(strcmp(o->name, "repair_box_launcher") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
            return files_names;
        }
        if(strcmp(o->name, "repair_pulse") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
            return files_names;
        }
        if(strcmp(o->name, "duct_tape") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
            return files_names;
        }
        if(strcmp(o->name, "repair_bolt") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
            return files_names;
        }
        if(strcmp(o->name, "repair_plasma") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("all_healing");
            return files_names;
        }
    }
    if(o->type == 4){
        if(strcmp(o->name, "defence_wall") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "defence_aura") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "bloster_armor") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
        if(strcmp(o->name, "cleanse_pulse") == 0){
            files_names[0] = strdup(o->name);
            files_names[1] = strdup("none");
            return files_names;
        }
    }
    return files_names;
}