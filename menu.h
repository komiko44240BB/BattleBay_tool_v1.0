
#ifndef MENU_H
#define MENU_H
void start();
void clearInputBuffer();
void startMenu();
void creatingShip();
void editingShip();
void changeObjectStats();
void changeShipType();
void changeObject();
void saveShipAs();
void saveShip(struct Ship* s);
void addObjects(struct Ship* s);
char* chooseWeapon();
char* choosePasive();
char* chooseUtility();
char* chooseHealing();
char* chooseTeal();
char* chooseRarity();








#endif