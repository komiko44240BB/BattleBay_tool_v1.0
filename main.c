#include "menu.h"

// Formula to calculate stat and combo stat : ( base stat + flat train stat + flat perk stat ) * ( 1 + % perk stat + % train stat ) * ( 1 + % combo train stat + % combo perk stat )

int main() {
    /*
    int gear[5][2] = {{5,8},{3,4},{0,0},{0,0},{0,0}};
    struct Ship* s = initialiseShip("defender",1.2,0.9,0.5,1596,5);
    setUpShip(s,gear);
    char* object_name= "swift_torpedo";
    char* rarity = "legendary";
    struct Object* o = readObjectFile(1,object_name,rarity);
    bool isAdded = addOject(s,o);
    if(!isAdded){
        printf("Could not add objects, not enought slot points or slots\n");
    }else{
        printf("Object added sucesfuly\n");
    }
    struct Training* t = readTraining(o,object_name);
    for(int i = 0; i < t->size; i++){
        int y = i+1;
        printf("%d, %.2f, %s\n", y, t->value[i], t->type[i]);
    }
    printf("\n");
    printLoadout(s);
    printObject(o);*/
    start();
    return 0;
}