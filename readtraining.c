#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include "menu.h"
#include "objects.h"
#include "readtraining.h"
#define MAX_LINE_SIZE 1024

/**
 * Allocates memory for a Training struct and its components based on the provided training level.
 *
 * @param training_lvl The number of training types/values to allocate space for.
 * @return A pointer to the newly created Training struct, or NULL if memory allocation fails.
 */
struct Training* createTraining(unsigned int training_lvl) {
    // Allocate memory for the Training struct
    struct Training* t = malloc(sizeof(struct Training));
    // Check if memory allocation for the struct failed
    if (t == NULL) {
        return NULL;
    }
    // Allocate memory for the 'type' array, which holds 'training_lvl' number of char pointers
    t->type = malloc(sizeof(char*) * training_lvl);
    // If memory allocation for 'type' fails, free the allocated Training struct and return NULL
    if (t->type == NULL) {
        free(t);
        return NULL;
    }
    // Allocate memory for the 'value' array, which holds 'training_lvl' number of floats
    t->value = malloc(sizeof(float) * training_lvl);
    // If memory allocation for 'value' fails, free previously allocated memory for 'type' and the Training struct
    if (t->value == NULL) {
        free(t->type);
        free(t);
        return NULL;
    }
    // Set the 'size' field of the Training struct to the provided training level
    t->size = training_lvl;
    // Return the pointer to the successfully created and initialized Training struct
    return t;
}

/**
 * Reads training data from a CSV file for a specified object and returns a Training struct.
 *
 * @param o The object whose training data is being requested.
 * @param object_name The name of the object to locate its training data file.
 * @return A pointer to a Training struct, or NULL if an error occurs (e.g., object or file is not found).
 */
struct Training* readTraining(struct Object* o, char* object_name) {
    // Check if object or object name is null, return NULL in case of invalid input
    if (o == NULL || object_name == NULL) {
        return NULL;
    }
    // Allocate memory for the training file name string, including the base path, object name, and extension
    char* training_file_name = malloc(strlen(object_name) + 17 + 13 + 1);
    if (training_file_name == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }
    // Construct the full path to the training file
    sprintf(training_file_name, "../Training_data/%s_training.csv", object_name);
    // Attempt to open the training file
    FILE* file = fopen(training_file_name, "r");
    if (file == NULL) {
        printf("Error opening \"%s\", file does not exist\n", training_file_name);
        free(training_file_name); // Free memory for training file name
        return NULL; // Return NULL if file does not exist
    }
    free(training_file_name); // Free memory for training file name after opening the file
    char line[MAX_LINE_SIZE]; // Buffer to hold lines read from the file
    // Read the first line to get the maximum training level
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file); // Close file if reading fails
        return NULL;
    }
    // Convert the first line to an unsigned integer for the max training level
    unsigned int max_training_lvl = atoi(line);
    int training_lvl = 0;
    // Prompt the user to input a valid training level
    while (true) {
        printf("------------------------\n");
        printf("What is the level of training of your object?\n");
        printf("(between 0 and %d)\n", max_training_lvl);
        printf("------------------------\n");
        printf("Your choice: \n");
        scanf("%d", &training_lvl);
        clearInputBuffer(); // Clear any remaining input from the buffer
        // Validate the entered training level
        if (training_lvl <= 0 || training_lvl > max_training_lvl) {
            if (training_lvl == 0) {
                fclose(file); // Close file if the user chooses level 0
                struct Training* t0 = createTraining(0); // Create a training struct with level 0
                return t0;
            }
            printf("Wrong training input level\n"); // Inform the user of invalid input
        } else {
            break; // Valid input, exit loop
        }
    }
    // Skip the next line of information in the file
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file); // Close file if reading fails
        return NULL;
    }
    // Read the first line of training data
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file); // Close file if reading fails
        return NULL;
    }
    // Duplicate the line for further processing
    char* copiedline = strdup(line);
    // Create a new Training struct with the specified level
    struct Training* t = createTraining(training_lvl);
    if (t == NULL) {
        fclose(file); // Close file if creating the Training struct fails
        free(copiedline); // Free copied line
        return NULL;
    }
    int iter = 0; // Initialize iteration count for training data processing
    // Parse the first line of training data
    char* token = strtok(copiedline, ",");
    unsigned int level = atoi(token); // Get the training level from the first token
    token = strtok(NULL, ",");
    t->value[iter] = atof(token); // Get the value and store it in the struct
    token = strtok(NULL, "\r");
    t->type[iter] = strdup(token); // Get the type and store it in the struct
    free(copiedline); // Free the copied line after processing
    // Continue reading and parsing lines until the desired training level is reached
    while (level < training_lvl) {
        if (fgets(line, sizeof(line), file) == NULL) {
            fclose(file); // Close file if reading fails
            return NULL;
        }
        iter++; // Increment iteration count
        copiedline = strdup(line); // Duplicate the current line
        token = strtok(copiedline, ",");
        level = atoi(token); // Get the training level from the first token
        token = strtok(NULL, ",");
        t->value[iter] = atof(token); // Get the value and store it in the struct
        token = strtok(NULL, "\r");
        t->type[iter] = strdup(token); // Get the type and store it in the struct
        free(copiedline); // Free the copied line after processing
    }
    fclose(file); // Close the file once training data is successfully read
    return t; // Return the populated Training struct
}