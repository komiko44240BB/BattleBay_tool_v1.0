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
        int choice = 0;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            valid3 = false;
            break;
        case 2:
            valid3 = false;
            break;
        case 3:
            valid3 = false;
            break;
        case 4:
            valid3 = false;
            break;
        case 5:
            valid3 = false;
            break;
        case 6:
            valid3 = false;
            break;
        case 7:
            valid3 = false;
            break;
        case 8:
            valid3 = false;
            break;
        case 9:
            valid3 = false;
            break;
        default:
            printf("Invalid choice, please try again\n");
            clearInputBuffer();
        }
    }
    addObject();
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
        return;
    }
    printf("\nFile \"%s\" read successfully!\n\n", filename);
    bool valid2 = true;  // Indicateur de boucle pour le sous-menu après lecture du fichier

    while (valid2){
        printf("What do you want to do\n");
        printf("------------------------\n");
        printf("1. Change an object stats\n");
        printf("2. Change ship type\n");
        printf("3. Change an object\n");
        printf("4. Save modifications (will overwrite current file)\n");
        printf("5. Save under a new name (will generate a second file)\n");
        printf("6. Go back to principal menu\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice){
            case 1:
                changeObjectStats();
                break;
            case 2:
                changeShipType();
                break;
            case 3:
                changeObject();
                break;
            case 4:
                editCurentShip(s);
                break;
            case 5:
                saveShipAs();
                break;
            case 6:
                valid2 = false;
                break;
            default:
                printf("Invalid choice, please try again\n");
                clearInputBuffer();
        }
    }
}