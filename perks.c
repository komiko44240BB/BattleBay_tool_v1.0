#include "perks.h"

#include "objects.h"


struct Perk* createPerk(char* first_boost_type,char* second_boost_type, int first_boost_value,int second_boost_value) {
    struct Perk* p = malloc(sizeof(struct Perk));
    p->first_boost_type = strdup(first_boost_type);
    p->second_boost_type = strdup(second_boost_type);
    p->first_boost_value = first_boost_value;
    p->second_boost_value = second_boost_value;
    return p;
}

void addPerks(struct Object* o) {
    if(o == NULL){
        return;
    }
    char** perk_files_names = displayPerks(o);
}

char** displayPerks(struct Object* o) {
    char** files_names = malloc(sizeof(char*) * 2);
    if(strcmp(o->name, "big_berta")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_mortars");
        return files_names;
    }
    if(strcmp(o->name, "standard_mortar")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_mortars");
        return files_names;
    }
    if(strcmp(o->name, "long_range_mortar")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_mortars");
        return files_names;
    }
    if(strcmp(o->name, "ballpark_mortar")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_mortars");
        return files_names;
    }
    if(strcmp(o->name, "flare_gun")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_incendiary_items");
        return files_names;
    }
    if(strcmp(o->name, "swift_torpedo")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_torpedoes");
        return files_names;
    }
    if(strcmp(o->name, "triple_torpedo")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_torpedoes");
        return files_names;
    }
    if(strcmp(o->name, "big_torpedo")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_torpedoes");
        return files_names;
    }
    if(strcmp(o->name, "blast_cannon")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_cannons");
        return files_names;
    }
    if(strcmp(o->name, "sniper_cannon")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_cannons");
        return files_names;
    }
    if(strcmp(o->name, "standard_torpedo")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_torpedoes");
        return files_names;
    }
    if(strcmp(o->name, "explosive_cannon")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_cannons");
        return files_names;
    }
    if(strcmp(o->name, "napalm")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_incendiary_items");
        return files_names;
    }
    if(strcmp(o->name, "fire_bomb")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_incendiary_items");
        return files_names;
    }
    if(strcmp(o->name, "standard_cannon")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_cannons");
        return files_names;
    }
    if(strcmp(o->name, "missile_launcher")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_missiles");
        return files_names;
    }
    if(strcmp(o->name, "multi_missile")){
        files_names[0] = strdup("all_missiles");
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "mines")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "grenades")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "carronade")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "gatling_gun")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "railguns")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "tesla_shield")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "tesla_bolt")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "frost_launcher")){
        files_names[0] = strdup("all_frost");
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "frost_blaster")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_frost");
        return files_names;
    }
    if(strcmp(o->name, "big_bandage")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "turbo")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("none");
        return files_names;
    }
    if(strcmp(o->name, "small_shield")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_shields");
        return files_names;
    }
    if(strcmp(o->name, "bid_shield")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_shields");
        return files_names;
    }
    if(strcmp(o->name, "repair_bolt")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_repair_items");
        return files_names;
    }
    if(strcmp(o->name, "repair_box")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_repair_items");
        return files_names;
    }
    if(strcmp(o->name, "repair_plasma")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_repair_items");
        return files_names;
    }
    if(strcmp(o->name, "duct_tape")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_repair_items");
        return files_names;
    }
    if(strcmp(o->name, "repair_pulse")){
        files_names[0] = strdup(o->name);
        files_names[1] = strdup("all_repair_items");
        return files_names;
    }
}