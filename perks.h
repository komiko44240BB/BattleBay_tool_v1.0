#ifndef PERKS_H
#define PERKS_H
#include<stdbool.h>


struct Perk {
    bool is_event;
    float first_boost_value;
    char* first_boost_type;
    float second_boost_value;
    char* second_boost_type;
};

struct Perk* createPerk(char* first_boost_type,char* second_boost_type, float first_boost_value,float second_boost_value);

int numberOfPerks(struct Object* o);
void addPerks(struct Object* o);
char** perkLists(struct Object* o);
struct Perk* displayAndChooseAvailablePerks(char** perk_list, bool is_event, struct Object* o);
bool perk_already_fited(bool is_event, struct Object* o, char* line);
char* perk_to_string(struct Perk* p);
void updateEvent(struct Perk* p,bool is_event);
void displayPerk(struct Perk p );
#endif
