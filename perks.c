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
    
}