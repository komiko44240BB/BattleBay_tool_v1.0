#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include "menu.h"
#include "objects.h"
#include "readtraining.h"
#define MAX_LINE_SIZE 1024


struct Training* createTraining(unsigned int training_lvl) {
    struct Training* t = malloc(sizeof(struct Training));
    if (t == NULL) {
        return NULL;
    }

    t->type = malloc(sizeof(char*) * training_lvl);
    if (t->type == NULL) {
        free(t);
        return NULL;
    }

    t->value = malloc(sizeof(float) * training_lvl);
    if (t->value == NULL) {
        free(t->type);
        free(t);
        return NULL;
    }

    return t;
}


struct Training* readTraining(struct Object* o,char* object_name) {
    if(o == NULL || object_name == NULL){
        return NULL;
    }
    char* training_file_name = malloc(strlen(object_name) + 17 +13 + 1);
    sprintf(training_file_name, "../Training_data/%s_training.csv", object_name);

    FILE* file = fopen(training_file_name, "r");
    if (file == NULL) {
        printf("Error opening \" %s \", file does not exist\n", training_file_name);
        return NULL;
    }

    char line[MAX_LINE_SIZE];
    char* copiedline = NULL;

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return NULL;
    }

    copiedline = strdup(line);
    unsigned int max_training_lvl = atoi(copiedline);
    free(copiedline);

    int training_lvl = 0;
    while(true){
        printf("------------------------\n");
        printf("What is the level of training of your object ?\n");
        printf("(between 0 and %d\n", max_training_lvl);
        printf("------------------------\n");
        printf("Your choice: \n");
        scanf("%d", &training_lvl);
        clearInputBuffer();
        if(training_lvl<= 0 || training_lvl > max_training_lvl){
            if(training_lvl == 0){
                fclose(file);
                struct Training* t0 = createTraining(0);
                return t0;
            }
            printf("Wrong training input level\n");
        }else{
            break;
        }
    }

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return NULL;
    } // skip the line of information

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return NULL;
    } // get the first line of training

    copiedline = strdup(line);

    struct Training* t = createTraining(training_lvl);
    int iter = 0;

    char* token = strtok(copiedline, ",");
    unsigned int level = atoi(token);
    token = strtok(NULL, ",");
    t->value[iter] = atof(token);
    token = strtok(NULL, "\r");
    t->type[iter] = strdup(token);

    free(copiedline);

    while(level < training_lvl){
        if (fgets(line, sizeof(line), file) == NULL) {
            fclose(file);
            return NULL;
        }
        iter++;
        copiedline = strdup(line);
        token = strtok(copiedline, ",");
        level = atoi(token);
        token = strtok(NULL, ",");
        t->value[iter] = atof(token);
        token = strtok(NULL, "\r");
        t->type[iter] = strdup(token);

        free(copiedline);
    }

    fclose(file);
    return t;
}