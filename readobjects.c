    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<stdbool.h>
    #include <unistd.h>
    #include "readobjects.h"
    #include "menu.h"
    #include "objects.h"

    #define MAX_LINE_SIZE 4096
/**
 * Reads object data from a CSV file based on the provided object type, name, and rarity.
 *
 * The function prompts the user for the object's level and retrieves data from a file formatted
 * as "<object_name>_<rarity>.csv". It then extracts and processes the object's properties
 * corresponding to the specified level.
 *
 * @param object_type   The type/category of the object (used to store it in the ship acordingly).
 * @param object_name   The name of the object (used to form the filename).
 * @param rarity        The rarity of the object (used to form the filename).
 * @return              A pointer to a dynamically allocated Object structure containing the
 *                      object's properties, or NULL if an error occurs.
 */
struct Object* readObjectFile(unsigned int object_type, char* object_name, char* rarity) {
    // Loop to prompt user for object level until a valid input is provided
    while (true){
        printf("What level is the object ?\n");
        printf("(Between 1 and 50)\n");
        printf("------------------------\n");
        printf("Your choice: ");
        clearInputBuffer();  // Clear any leftover input from previous user inputs
        int object_lvl = 0;
        scanf(" %d", &object_lvl);  // Get user input for object level
        // Validate the level input
        if(object_lvl < 0 || object_lvl > 50){
            printf("Invalid choice, please try again\n");
        }else{
             // Allocate memory for the filename using object name and rarity
            char* object_file_name = malloc(strlen(object_name) + strlen(rarity) + 16 + 5 + 1);
            if(object_file_name == NULL){
                printf("error malloc object_file_name\n");
                return NULL;
            }
            sprintf(object_file_name, "../Weapons_data/%s_%s.csv", object_name, rarity);  // Create filename in the format: "<object_name>_<rarity>.csv"

            // Try to open the CSV file for reading
            FILE* file = fopen(object_file_name, "r");
            if (file == NULL) {
                printf("Error opening \"%s\", file does not exist\n", object_file_name);
                return NULL;  // Return NULL if the file cannot be opened
            }

            char line[MAX_LINE_SIZE];
            char* copiedline = NULL;

            // Read the first line to get the slot points, if file is not empty
            if (fgets(line, sizeof(line), file) == NULL) {
                fclose(file);
                return NULL;  // Return NULL if there's an issue reading the file
            }
            copiedline = malloc(strlen(line) + 1);
            if (copiedline == NULL) {
                fclose(file);
                printf("Malloc copied line failed\n");
                return NULL;  // Return NULL if memory allocation fails
            }
            strcpy(copiedline, line);  // Copy the line
            unsigned int slot_points = atoi(copiedline);  // Convert the line to an integer for slot points
            free(copiedline);  // Free allocated memory after use

            // Skip lines to reach the desired object level
            for(int i = 0; i < object_lvl; i++){
                if (fgets(line, sizeof(line), file) == NULL) {
                    fclose(file);
                    return NULL;  // Return NULL if reading the next line fails
                }
            }

            // Process the line containing the object's attributes for the specified level
            copiedline = malloc(strlen(line) + 1);
            if (copiedline == NULL) {
                printf("Malloc copied line failed(2)\n");
                fclose(file);
                return NULL;  // Return NULL if memory allocation fails
            }
            strcpy(copiedline, line);  // Copy the line
            // Parse the CSV line, using semicolon ';' as the delimiter
            char* token = strtok(copiedline, ";");
            unsigned int level = atoi(token);  // Object level
            token = strtok(NULL, ";");
            float base_stat = atof(token);  // Base stat of the object
            token = strtok(NULL, ";");
            float cool_down = atof(token);  // Cooldown time
            token = strtok(NULL, ";");
            float range = atof(token);  // Object's range
            token = strtok(NULL, ";");
            float projectile_speed = atof(token);  // Speed of the projectile
            token = strtok(NULL, ";");
            float critical_hit_chance= atof(token);  // Critical hit chance percentage
            token = strtok(NULL, ";");
            float critcal_hit_multiplier=1;// atof(token);  // Critical hit damage multiplier
            //token = strtok(NULL, ";");
            float radius = atof(token);  // Radius of effect
            token = strtok(NULL, ";");
            float spread = atof(token);  // Spread of the projectiles
            token = strtok(NULL, ";");
            float amount_of_projectiles = atof(token);  // Number of projectiles
            printf("test2\n");
            token = strtok(NULL, "\r");
            float duration= atof(token);  // Duration of the effect
            printf("test3\n");
            // Create a new Object instance using the parsed data
            struct Object* o = createObject(rarity,object_name,level,base_stat,cool_down,range,projectile_speed,critical_hit_chance,critcal_hit_multiplier,radius,spread,amount_of_projectiles,duration,slot_points,1);

            // Edit the object's type based on the provided object_type parameter
            editObjectType(o,object_type);

            // Return the newly created object
            return o;
        }
    }
}