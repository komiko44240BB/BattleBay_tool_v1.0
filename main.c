#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "ships.h"

#define OBJECT_TYPES {'r','b','y','g','t'}

int main (){
    unsigned int gear[5][2]= {{4,6},{3,4},{1,1},{0,0},{0,0}};
    struct Ship* s = initialiseShip("reaper", 1.2,0.95,0.5,3000,9);
    setUpShip(s,gear);
    printShipStats(s);
    return 0;
}
