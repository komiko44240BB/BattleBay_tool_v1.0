#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include "readtraining.h"
#include "menu.h"
#define MAX_LINE_SIZE 4096


void readAndApplyTraining(struct Object* o,char* object_name) {
    if(o == NULL || object_name == NULL){
        return;
    }
    char* training_file_name = malloc(strlen(object_name) + 16 +8 + 5 + 1);
    sprintf(training_file_name, "../Training_data/%s_training.csv", object_name);

    FILE* file = fopen(training_file_name, "r");
    if (file == NULL) {
        printf("Error opening \" %s \", file does not exist\n", training_file_name);
        return ;
    }

    char line[MAX_LINE_SIZE];
    char* copiedline = NULL;

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return ;
    }
    copiedline = malloc(strlen(line) + 1);
    if (copiedline == NULL) {
        fclose(file);
        printf("Malloc copied line failed\n");
        return ;
    }
    strcpy(copiedline, line);
    unsigned int max_training_lvl = atoi(copiedline);
    free(copiedline);
    int training_lvl = 0;
    while(true){
        printf("------------------------\n");
        printf("What is the level of training of your object ?\n");
        printf("(between 0 and %d", max_training_lvl);
        printf("------------------------\n");
        printf("Your choice: \n");
        clearInputBuffer();
        scanf("%d", &training_lvl);
        if(training_lvl >= 0 || training_lvl > max_training_lvl){
            printf("Wrong training input level\n");
        }else{
            break;
        }
    }
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;
    }

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;
    }

    copiedline = malloc(strlen(line) + 1);
    if (copiedline == NULL) {
        printf("Malloc copied line failed(2)\n");
        fclose(file);
        return ;
    }

    char** boost_type = malloc(sizeof(char*) * training_lvl);
    float* boost_value = malloc(sizeof(float)* training_lvl);
    int iter = 0;
    strcpy(copiedline, line);
    char* token = strtok(copiedline, ",");
    unsigned int level = atoi(token);
    token = strtok(NULL, ",");
    boost_value[iter] = atof(token);
    token = strtok(NULL, "\r");
    boost_type[iter] = token;

    while(level < training_lvl){
        if (fgets(line, sizeof(line), file) == NULL) {
            fclose(file);
            return;
        }
        copiedline = malloc(strlen(line) + 1);
        if (copiedline == NULL) {
            printf("Malloc copied line failed(2)\n");
            fclose(file);
            return;
        }
        strcpy(copiedline, line);
        iter++;
        token = strtok(copiedline, ",");
        level = atoi(token);
        token = strtok(NULL, ",");
        boost_value[iter] = atof(token);
        token = strtok(NULL, "\r");
        boost_type[iter] = token;
    }


}
