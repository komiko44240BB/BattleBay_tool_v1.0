#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include "ships.h"
#include "menu.h"
#include "readobjects.h"
#include "readtraining.h"

#define FILENAME_SIZE 40



void start(){
    printf("████████ ██   ██ ███████     ██████   █████  ████████ ████████ ██      ███████     ██████   █████  ██    ██     ████████  ██████   ██████  ██      \n");
    printf("   ██    ██   ██ ██          ██   ██ ██   ██    ██       ██    ██      ██          ██   ██ ██   ██  ██  ██         ██    ██    ██ ██    ██ ██      \n");
    printf("   ██    ███████ █████       ██████  ███████    ██       ██    ██      █████       ██████  ███████   ████          ██    ██    ██ ██    ██ ██      \n");
    printf("   ██    ██   ██ ██          ██   ██ ██   ██    ██       ██    ██      ██          ██   ██ ██   ██    ██           ██    ██    ██ ██    ██ ██      \n");
    printf("   ██    ██   ██ ███████     ██████  ██   ██    ██       ██    ███████ ███████     ██████  ██   ██    ██           ██     ██████   ██████  ███████ \n");
    printf("\n");
    printf("                                                       ██    ██      ██     ██████                                                                 \n");
    printf("                                                       ██    ██     ███    ██  ████                                                                \n");
    printf("                                             █████     ██    ██      ██    ██ ██ ██     █████                                                      \n");
    printf("                                                        ██  ██       ██    ████  ██                                                                \n");
    printf("                                                         ████        ██ ██  ██████                                                                 \n");
    printf("                             ______                              _                              _                                                  \n");
    printf("                            / _____)                            (_)_                           | |                                                 \n");
    printf("                           | /      ___  ____  ____  _   _ ____  _| |_ _   _    ____   ____  _ | | ____                                            \n");
    printf("                           | |     / _ \\|    \\|    \\| | | |  _ \\| |  _) | | |  |    \\ / _  |/ || |/ _  )                                      \n");
    printf("                           | \\____| |_| | | | | | | | |_| | | | | | |_| |_| |  | | | ( ( | ( (_| ( (/ /                                           \n");
    printf("                            \\______)___/|_|_|_|_|_|_|\\____|_| |_|_|\\___)__  |  |_|_|_|\\_||_|\\____|\\____)                                     \n");
    printf("                                                                      (____/                                                                       \n");
    printf("Made by #VWHSGMZR aka komiko44240\n");
    printf("Special thanks to #FGZNGMWK aka TheregoesURboat\n");
    sleep(1);
    startMenu();
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void startMenu() {
    bool valid1 = true;
    while (valid1){
        printf("What do you want to do\n");
        printf("------------------------\n");
        printf("1. Start a new ship\n");
        //printf("2. Read a ship file");
        printf("0. Exit program\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int exitOrRead = 0;
        scanf("%d", &exitOrRead);
        clearInputBuffer();
        switch (exitOrRead){
            case 1:
                creatingShip();
                break;
            /*case 2:
                editingShip();
                break;*/
            case 0:
                valid1 = false;  // Quitter l'application
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    printf("\nExited successfully...\n");
}

void creatingShip() {
    bool createShip = true;
    char* ship_name = "";
    float speed = 0;
    int ship_agility = 0;
    int turret_agility = 0;
    unsigned int hit_points = 0;
    unsigned int defence = 0;
    unsigned int gear [5][2] = {0};
    unsigned int k = 0;
    unsigned int y;
    while (createShip){
        printf("what ship do you want to use ?\n");
        printf("------------------------\n");
        printf("1. Shooter\n");
        printf("2. Defender\n");
        printf("3. Speeder\n");
        printf("4. Enfoncer\n");
        printf("5. Fixer\n");
        printf("6. Interceptor\n");
        printf("7. Reaper\n");
        printf("8. Guardian\n");
        printf("9. Striker\n");
        printf("0. Cancel\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice){
        case 1:
            ship_name = "Shooter";
            speed = 0.92;
            ship_agility = 60;
            turret_agility = 70;
            hit_points = 1950;
            defence = 10;
            unsigned int shooter_setup[10] = {5,8,3,4,0,0,0,0,0,0};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = shooter_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 2:
            ship_name = "Defender";
            speed = 0.92;
            ship_agility = 50;
            turret_agility = 60;
            hit_points = 2700;
            defence = 20;
            unsigned int defender_setup[10] = {3,5,4,6,0,0,0,0,1,1};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = defender_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 3:
            ship_name = "Speeder";
            speed = 1.21;
            ship_agility = 80;
            turret_agility = 90;
            hit_points = 1650;
            defence = 0;
            unsigned int speeder_setup[10] = {2,3,3,4,3,4,0,0,0,0};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = speeder_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 4:
            ship_name = "Enfoncer";
            speed = 1.03;
            ship_agility = 100;
            turret_agility = 110;
            hit_points = 2300;
            defence = 5;
            unsigned int enfoncer_setup[10] = {3,3,2,3,3,5,0,0,0,0};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = enfoncer_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 5:
            ship_name = "Fixer";
            speed = 0.98;
            ship_agility = 70;
            turret_agility = 90;
            hit_points = 2250;
            defence = 0;
            unsigned int fixer_setup[10] = {2,3,2,2,1,1,3,5,0,0};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = fixer_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 6:
            ship_name = "Interceptor";
            speed = 0.99;
            ship_agility = 80;
            turret_agility = 90;
            hit_points = 2100;
            defence = 5;
            unsigned int interceptor_setup[10] = {4,6,3,4,1,1,0,0,0,0};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = interceptor_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 7:
            ship_name = "Reaper";
            speed = 1;
            ship_agility = 85;
            turret_agility = 100;
            hit_points = 2150;
            defence = 0;
            unsigned int reaper_setup[10] = {2,4,2,2,2,2,2,3,0,0};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = reaper_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 8:
            ship_name = "Guardian";
            speed = 1;
            ship_agility = 60;
            turret_agility = 75;
            hit_points = 2700;
            defence = 10;
            unsigned int guardian_setup[10] = {2,3,3,4,0,0,0,0,3,4};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = guardian_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 9:
            ship_name = "Striker";
            speed = 1.01;
            ship_agility = 90;
            turret_agility = 100;
            hit_points = 2000;
            defence = 5;
            unsigned int striker_setup[10] = {3,4,3,4,2,3,0,0,0,0};
            for(int i = 0; i < 10; i++){
                if(i%2 == 1){
                    y = 1;
                    k--;
                }else{
                    y = 0;
                }
                gear[k][y] = striker_setup[i];
                k++;
            }
            createShip = false;
            break;
        case 0:
            return;
        default:
            printf("Invalid choice, please try again\n");
            clearInputBuffer();
        }
    }
    struct Ship* s = initialiseShip(ship_name,speed,ship_agility,turret_agility,hit_points,defence);
    setUpShip(s,gear);
    addObjects(s);
    return;
}

void addObjects(struct Ship* s) {
    for(int i = 0; i <= 8 ; i++){
        bool add_objects = true;
        bool read_file = false;
        char* object_name = "";
        char* rarity = "";
        unsigned int object_type = 0;
        if(i == 8){
            printf("You can only save the ship, all slots are full\n");
            i--;
        }
        while(add_objects){
            printf("It doesn't matter which type of object you add first\n");
            printf("What type of object do you want to add ?\n");
            printf("------------------------\n");
            printf("1. Red (weapons)\n");
            printf("2. Blue (passives)\n");
            printf("3. Yellow (utility)\n");
            printf("4. Green (healing)\n");
            printf("5. Teal (guardian's type)\n");
            printf("6. Save ship\n");
            printf("7. Display ship\n");
            printf("0. Cancel ship\n");
            printf("------------------------\n");
            printf("Your choice: ");
            object_type = 0;
            scanf("%d", &object_type);
            clearInputBuffer();
            switch (object_type){
            case 1:
                object_name = strdup(chooseWeapon());
                if(strcmp(object_name,"cancel") != 0){
                    rarity = strdup(chooseRarity());
                    add_objects = false;
                }else{
                    i--;
                }
                read_file = true;
                break;
            case 2:
                object_name = strdup(choosePasive());
                if(strcmp(object_name,"cancel") != 0){
                    rarity = strdup(chooseRarity());
                    add_objects = false;
                }else{
                    i--;
                }
                read_file = true;
                break;
            case 3:
                object_name = strdup(chooseUtility());
                if(strcmp(object_name,"cancel") != 0){
                    rarity = strdup(chooseRarity());
                    add_objects = false;
                }else{
                    i--;
                }
                read_file = true;
                break;
            case 4:
                object_name = strdup(chooseHealing());
                if(strcmp(object_name,"cancel") != 0){
                    rarity = strdup(chooseRarity());
                    add_objects = false;
                }else{
                    i--;
                }
                read_file = true;
                break;
            case 5:
                object_name = strdup(chooseTeal());
                if(strcmp(object_name,"cancel") != 0){
                    rarity = strdup(chooseRarity());
                    add_objects = false;
                }else{
                    i--;
                }
                read_file = true;
                break;
            case 6:
                //saveShipAs(s);
                read_file = false;
                return;
            case 7:
                printShipStats(s);
                printLoadout(s);
                add_objects = true;
                read_file = false;
                break;
            case 0:
                deleteShip(s);
                read_file = false;
                return;
            default:
                printf("Invalid choice, please try again\n");
                read_file = false;
            }
        }
        if(read_file){
            struct Object* o = readObjectFile(object_type,object_name,rarity);
            bool isAdded = addOject(s,o);
            if(!isAdded){
                printf("Could not add object, not enought slot points or slots\n");
                i--;
            }else{
                printf("Object has been added\n");
                struct Training* t = readTraining(o,object_name);
                addPerks(o);
            }
        }
    }
}

char* chooseWeapon() {
    while(true){
        printf("What weapon do you want to add ?\n");
        printf("------------------------\n");
        printf("1.standard cannon\t2.blast cannon\n");
        printf("3.sniper cannon\t\t4.explosive cannon\n");
        printf("5.galting gun\t\t6.carronade\n");
        printf("7.grenade launcher\t8.standard mortar\n");
        printf("9.long range mortar\t10.ballpark mortar\n");
        printf("11.big berta\t\t12.standard torpedo\n");
        printf("13.big torpedo\t\t14.swift torpedo\n");
        printf("15.triple torpedo\t16.railgun\n");
        printf("17.missile launcher\t18.multi missile\n");
        printf("19.mine\t\t\t20.flare gun\n");
        printf("21.napalm launcher\t22.fire bomb\n");
        printf("0.Cancel, change item type\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:return "standard_cannon";
            case 2:return "blast_cannon";
            case 3:return "sniper_cannon";
            case 4:return "explosive_cannon";
            case 5:return "galting_gun";
            case 6:return "carronade";
            case 7:return "grenade_launcher";
            case 8:return "standard_mortar";
            case 9:return "long_range_mortar";
            case 10:return "ballpark_mortar";
            case 11:return "big_berta";
            case 12:return "standard_torpedo";
            case 13:return "big_torpedo";
            case 14:return "swift_torpedo";
            case 15:return "triple_torpedo";
            case 16:return "railgun";
            case 17:return "missile_launcher";
            case 18:return "multi_missile";
            case 19:return "mine";
            case 20:return "flare_gun";
            case 21:return "napalm_launcher";
            case 22:return "fire_bomb";
            case 0: return "cancel";
            default:
                printf("Invalid choice, please try again\n");
        }
    }
}

char* choosePasive() {
    while(true){
        printf("What passive object do you want to add ?\n");
        printf("------------------------\n");
        printf("1.standard shield\n");
        printf("2.big shield\n");
        printf("3.turbo\n");
        printf("4.bandage\n");
        printf("5.big bandage\n");
        printf("0.Cancel, change item type\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice){
        case 1: return "standard_shield";
        case 2: return "big_shield";
        case 3: return "turbo";
        case 4: return "bandage";
        case 5: return "big_bandage";
        case 0: return "cancel";
        default:
            printf("Invalid choice, please try again\n");
        }
    }
}

char* chooseUtility() {
    while(true){
        printf("What utility object do you want to add ?\n");
        printf("------------------------\n");
        printf("1.overboost\n");
        printf("2.nitro\n");
        printf("3.tesla bolt\n");
        printf("4.tesla shield\n");
        printf("5.frost blaster\n");
        printf("6.frost launcher\n");
        printf("0.Cancel, change item type\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice){
        case 1: return "overboost";
        case 2: return "nitro";
        case 3: return "tesla bolt";
        case 4: return "tesla shield";
        case 5: return "frost blaster";
        case 6: return "frost launcher";
        case 0: return "cancel";
        default:
            printf("Invalid choice, please try again\n");
        }
    }
}

char* chooseHealing() {
    while(true){
        printf("What repair object do you want to add ?\n");
        printf("------------------------\n");
        printf("1.repair box launcher\n");
        printf("2.repair pulse\n");
        printf("3.duct tape\n");
        printf("4.repair bolt\n");
        printf("5.repair plasma\n");
        printf("0.Cancel, change item type\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice){
        case 1: return "repair_box_launcher";
        case 2: return "repair_pulse";
        case 3: return "duct_tape";
        case 4: return "repair_bolt";
        case 5: return "repair_plasma";
        case 0: return "cancel";
        default:
            printf("Invalid choice, please try again\n");
        }
    }
}

char* chooseTeal() {
    while(true){
        printf("What teal object item do you want to add ?\n");
        printf("------------------------\n");
        printf("1.defence wall\n");
        printf("2.defence aura\n");
        printf("3.bloster armor\n");
        printf("4.cleanse pulse\n");
        printf("0.Cancel, change item type\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice){
        case 1: return "defence_wall";
        case 2: return "defence_aura";
        case 3: return "bloster_armor";
        case 4: return "cleanse_pulse";
        case 0: return "cancel";
        default:
            printf("Invalid choice, please try again\n");
        }
    }
}

char* chooseRarity() {
    while(true){
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
        case 1: return "common";
        case 2: return "uncommon";
        case 3: return "rare";
        case 4: return "epic";
        case 5: return "legendary";
        default:
            printf("Invalid choice, please try again\n");
        }
    }
}

/*
void editingShip() {
    clearInputBuffer();
    printf("\nRead CSV file\n");
    printf("------------------------\n");
    printf("Enter CSV file name (without the \".csv\"): ");
    clearInputBuffer();
    char filename[FILENAME_SIZE] = "";
    fgets(filename, FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;
    struct Ship* s = readShipFile();
    if(s == NULL){
        printf("Ship fille is empty or there was an error reading the file\n");
        printf("If this message is persistent please inform me on the Battle Bay discord server\n");
        return;
    }
    printf("\nFile \"%s\" read successfully!\n\n", filename);
    bool valid2 = true;  // Indicateur de boucle pour le sous-menu après lecture du fichier

    while (valid2){
        printf("What do you want to do\n");
        printf("------------------------\n");
        printf("1. Change an object stats\n");
        printf("2. Change an object\n");
        printf("3. Save modifications (will overwrite current file)\n");
        printf("4. Save under a new name (will generate a second file)\n");
        printf("5. Go back to main menu\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice){
            case 1:
                changeObjectStats();
                break;
            case 2:
                changeObject();
                break;
            case 3:
                saveShip(s);
                break;
            case 4:
                saveShipAs();
                break;
            case 5:
                valid2 = false;
                break;
            default:
                printf("Invalid choice, please try again\n");
                clearInputBuffer();
        }
    }
}*/