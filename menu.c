#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include "ships.h"
#include "menu.h"

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
    printf("Made by #VWHSGMZR aka Komiko44240");
    printf("Special thanks to #FGZNGMWK aka TheregoesURboat\n");
    sleep(5);
    startMenu();
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void startMenu() {
    clearInputBuffer();
    bool valid1 = true;
    while (valid1){
        printf("What do you want to do\n");
        printf("------------------------\n");
        printf("1. Start a new ship\n");
        printf("2. Read a ship file");
        printf("3. Exit program\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int exitOrRead = 0;
        scanf("%d", &exitOrRead);
        switch (exitOrRead){
            case 1:
                creatingShip();
                break;
            case 2:
                editingShip();
                break;
            case 3:
                valid1 = false;  // Quitter l'application
                break;
            default:
                printf("Invalid choice, please try again\n");
                clearInputBuffer();
                break;
        }
    }
    printf("\nExited successfully...\n");
}

void creatingShip() {
    clearInputBuffer();
    bool valid3 = true;
    char* ship_name = "";
    float speed = 0;
    float ship_agility = 0;
    float turret_agility = 0;
    unsigned int hit_points = 0;
    unsigned int defence = 0;
    while (valid3){
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
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            ship_name = "Shooter";
            speed = 0.92;
            ship_agility = 60;
            turret_agility = 70;
            hit_points = 1950;
            defence = 10;
            valid3 = false;
            break;
        case 2:
            ship_name = "Defender";
            speed = 0.92;
            ship_agility = 50;
            turret_agility = 60;
            hit_points = 2700;
            defence = 20;
            valid3 = false;
            break;
        case 3:
            ship_name = "Speeder";
            speed = 1.21;
            ship_agility = 80;
            turret_agility = 90;
            hit_points = 1650;
            defence = 0;
            valid3 = false;
            break;
        case 4:
            ship_name = "Enfoncer";
            speed = 1.03;
            ship_agility = 100;
            turret_agility = 110;
            hit_points = 2300;
            defence = 5;
            valid3 = false;
            break;
        case 5:
            ship_name = "Fixer";
            speed = 0.98;
            ship_agility = 70;
            turret_agility = 90;
            hit_points = 2250;
            defence = 0;
            valid3 = false;
            break;
        case 6:
            ship_name = "Interceptor";
            speed = 0.99;
            ship_agility = 80;
            turret_agility = 90;
            hit_points = ;
            defence = 5;
            valid3 = false;
            break;
        case 7:
            ship_name = "Reaper";
            speed = 1;
            ship_agility = 85;
            turret_agility = 100;
            hit_points = ;
            defence = 0;
            valid3 = false;
            break;
        case 8:
            ship_name = "Guardian";
            speed = 1;
            ship_agility = 60;
            turret_agility = 75;
            hit_points = 2700;
            defence = 10;
            valid3 = false;
            break;
        case 9:
            ship_name = "Striker";
            speed = 1.01;
            ship_agility = 90;
            turret_agility = 100;
            hit_points = 1944;
            defence = 5;
            valid3 = false;
            break;
        default:
            printf("Invalid choice, please try again\n");
            clearInputBuffer();
        }
    }
    struct Ship* s = initialiseShip(ship_name,speed,ship_agility,turret_agility,hit_points,defence);
    setUpShip(s,gear);
    addObjects(s);// il faut ajouter un menu avant de faire rajouter les objets
}

void addObjects(struct Ship* s) {
    bool add_objects = true;
    bool read_file = false;
    char* object_name = "";
    char* rarity = "";
    while(add_objects){
        printf("It doesn't matter which type of object you add first\n");
        printf("What type of object do you want to add ?\n");
        printf("------------------------\n");
        printf("1. Red (weapons)\n");
        printf("2. Blue (passives)\n");
        printf("3. Yellow (utility)\n");
        printf("4. Green (healing)\n");
        printf("5. Teal (guardian's type)\n");
        printf("6. Cancel adding an object\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            object_name = strdup(chooseWeapon(s));
            rarity = strdup(chooseRarity());
            add_objects = false;
            read_file = true;
            break;
        case 2:
            object_name = strdup(choosePasive(s));
            rarity = strdup(chooseRarity());
            add_objects = false;
            read_file = true;
            break;
        case 3:
            object_name = strdup(chooseUtility(s));
            rarity = strdup(chooseRarity());
            add_objects = false;
            read_file = true;
            break;
        case 4:
            object_name = strdup(chooseHealing(s));
            rarity = strdup(chooseRarity());
            add_objects = false;
            read_file = true;
            break;
        case 5:
            object_name = strdup(chooseTeal(s));
            rarity = strdup(chooseRarity());
            add_objects = false;
            read_file = true;
            break;
        case 6:
            add_objects = false;
            read_file = false;
        default:
            printf("Invalid choice, please try again\n");
            clearInputBuffer();
        }
    }
    if(read_file){
        char* object_file_name = malloc(strlen(object_name) + strlen(rarity) + 5 + 1);
        sprintf(object_file_name, "%s_%s.csv", object_name, rarity);
        struct Object* o = readWeaponFile(object_file_name);

        printf("------------------------\n");
        printf("What is the level of training of your object ?\n");
        printf("------------------------\n");
        printf("Your choice: ");
        clearInputBuffer();
        int choice = 0;
        scanf("%d", &choice);
        if(choice > 0){
            char* training_file_name = malloc(strlen(object_name) + 8 + 5 + 1);
            sprintf(training_file_name, "%s_training.csv", object_name);
            readAndApplyTraining(o,training_file_name, choice);
        }
    }
}



void editingShip() {
    clearInputBuffer();
    printf("\nRead CSV file\n");
    printf("------------------------\n");
    printf("Enter CSV file name: ");
    clearInputBuffer();
    char filename[FILENAME_SIZE] = "";
    fgets(filename, FILENAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;
    struct Ship* s = readShipFile();
    if(s == NULL){
        printf("Ship fille is empty or there was an error reading the file\n");
        printf("If this message is persistent please make inform me on the Battle Bay discort server\n");
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
        printf("5. Go back to principal menu\n");
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
                editCurentShip(s);
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
}