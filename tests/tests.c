void addObjects(struct Ship* s) {
    clearInputBuffer();
    bool add_objects = true;
    
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
        printf("7. Cancel adding an object\n");
        printf("------------------------\n");
        printf("Your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            redWeaponKind(s);
            break;
        case 2:
            blueObjects(s);
            break;
        case 3:
            yellowObjects(s);
            break;
        case 4:
            greenObjects(s);
            break;
        case 5:
            tealObjects(s);
            break;
        case 6:
            saveShipAs(s);
        case 7:
            deleteShip(s);
            return;
        default:
            printf("Invalid choice, please try again\n");
            clearInputBuffer();
        }
    }
    
}





bool read_file = false;
    char* object_name = "";
    char* rarity = "";
    int object_type = -1;


case 1:
            object_name = strdup(chooseWeapon(s));
            rarity = strdup(chooseRarity());
            object_type = 0;
            
            read_file = true;
            break;
        case 2:
            object_name = strdup(choosePasive(s));
            rarity = strdup(chooseRarity());
            object_type = 1;
            
            read_file = true;
            break;
        case 3:
            object_name = strdup(chooseUtility(s));
            rarity = strdup(chooseRarity());
            object_type = 2;
           
            read_file = true;
            break;
        case 4:
            object_name = strdup(chooseHealing(s));
            rarity = strdup(chooseRarity());
            object_type = 3;
            
            read_file = true;
            break;
        case 5:
            object_name = strdup(chooseTeal(s));
            rarity = strdup(chooseRarity());
            object_type = 4;
            
            read_file = true;
            break;
            
            
            
            
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