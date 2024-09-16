#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>

#include "menu.h"
#include "readobjects.h"
#include "ships.h"
#include "objects.h"
//#include "readtraining.h"

// Formula to calculate dmg and combo dmg : ( base dmg + flat train dmg + flat perk dmg ) * ( 1 + % perk dmg + % train dmg ) * ( 1 + % fire train dmg + % fire perk dmg )

int main() {
    /*int gear[5][2] = {{5,8},{3,4},{0,0},{0,0},{0,0}};
    struct Ship* s = initialiseShip("shooter",1.2,0.9,0.5,1596,5);
    setUpShip(s,gear);
    for (int i = 0 ; i < 5; i++){
        char* object_name= "standard_cannon";
        char* rarity = "legendary";
        struct Object* o = readObjectFile(1,object_name,rarity);
        bool isAdded = addOject(s,o);
        if(!isAdded){
            printf("Could not add objects, not enought slot points or slots\n");
            i++;
        }else{
            printf("Object added sucesfuly\n");
        }
        //readTraining(o,object_name);
    }
    for (int i = 0 ; i < 3; i++){
        char* object_name= "standard_shield";
        char* rarity = "legendary";
        struct Object* o = readObjectFile(2,object_name,rarity);
        bool isAdded = addOject(s,o);
        if(!isAdded){
            printf("Could not add objects, not enought slot points or slots\n");
            i++;
        }else{
            printf("Object added sucesfuly\n");
        }
        //readTraining(o,object_name);
    }
    printf("\n");
    printLoadout(s);
    printObject(o);*/
    start();
    return 0;
}
