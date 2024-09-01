
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
char* chooseWeapon(struct Ship* s);
char* choosePasive(struct Ship* s);
char* chooseUtility(struct Ship* s);
char* chooseHealing(struct Ship* s);
char* chooseTeal(struct Ship* s);
char* chooseRarity();








#endif