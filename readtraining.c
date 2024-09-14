#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include "menu.h"
#include "objects.h"
#include "readtraining.h"
#define MAX_LINE_SIZE 1024


void readTraining(struct Object* o,char* object_name) {
    if(o == NULL || object_name == NULL){
        return;
    }
    char* training_file_name = malloc(strlen(object_name) + 17 +13 + 1);
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
                return;
            }
            printf("Wrong training input level\n");
        }else{
            break;
        }
    }

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;
    } // skip the line of information

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;
    } // get the first line of training

    copiedline = strdup(line);

    char** boost_type = malloc(sizeof(char*) * training_lvl);
    float* boost_value = malloc(sizeof(float)* training_lvl);
    int iter = 0;

    char* token = strtok(copiedline, ",");
    unsigned int level = atoi(token);
    token = strtok(NULL, ",");
    boost_value[iter] = atof(token);
    token = strtok(NULL, "\r");
    boost_type[iter] = strdup(token);

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
        boost_type[iter] = malloc(sizeof(char)*(strlen(token)+1));
        strcpy(boost_type[iter],token);
    }

    applyTraining(o,boost_type,boost_value,training_lvl);

    free(boost_type);
    free(boost_value);
    return;
}

void applyTraining(struct Object* o,char** boost_type,float* boost_value, int training_lvl) {
    if(o == NULL || boost_type == NULL || boost_value == NULL){
        return;
    }

    float p_base_stat = 1;
    float p_range = 1;
    float p_fire_dmg = 1;
    float p_cool_down = 1;
    float p_projectile_speed = 1;
    float p_crit_hit_chance = 1;
    float p_crit_hit_dmg = 1;
    float p_frost_dmg = 1;
    float p_duration = 1;
    /*float p_heal_reduction = 1;
    float p_frost = 1;
    float p_turret_rotation = 1;
    float p_healing_block = 1;
    float p_rmv_stun = 1;
    float p_rmv_frost = 1;*/ //No implementation, see a bit lower in the swich case

    int flat_base_stat = 0;
    int flat_range = 0;
    int flat_duration = 0;

    char* boost_type_cpy = "";
    float boost_value_copy = 0;
    for(int i = 0; i < training_lvl; i++){
        boost_type_cpy = strdup(boost_type[i]);
        boost_value_copy = boost_value[i];
        switch (boost_type_cpy){
            case 'BASE_STAT':
                if(boost_value_copy < 1){
                    p_base_stat += boost_value_copy;
                }else{
                    flat_base_stat += boost_value_copy;
                }
                break;
            case 'RANGE':
                if(boost_value_copy < 1){
                    p_range += boost_value_copy;
                }else{
                    flat_range += boost_value_copy;
                }
                break;
            case 'FIRE_DAMAGE':
                if(boost_value_copy < 1){
                    p_fire_dmg += boost_value_copy;
                }else{
                    printf("check training, there is a mistake either in the code or in the training dataset\n");
                    return;
                }
                break;
            case 'COOL_DOWN':
                if(boost_value_copy < 1){
                    p_cool_down += boost_value_copy;
                }else{
                    printf("check training, there is a mistake either in the code or in the training dataset\n");
                    return;
                }
                break;
            case 'PROJECTILE_SPEED':
                if(boost_value_copy < 1){
                    p_projectile_speed += boost_value_copy;
                }else{
                    printf("check training, there is a mistake either in the code or in the training dataset\n");
                    return;
                }
                break;
            case 'CRITICAL_HIT_CHANCE':
                if(boost_value_copy < 1){
                    p_crit_hit_chance += boost_value_copy;
                }else{
                    printf("check training, there is a mistake either in the code or in the training dataset\n");
                    return;
                }
                break;
            case 'CRITICAL_HIT_DAMAGE':
                if(boost_value_copy < 1){
                    p_crit_hit_dmg += boost_value_copy;
                }else{
                    printf("check training, there is a mistake either in the code or in the training dataset\n");
                    return;
                }
                break;

            case 'FROST_DAMAGE':
                if(boost_value_copy < 1){
                    p_frost_dmg += boost_value_copy;
                }else{
                    printf("check training, there is a mistake either in the code or in the training dataset\n");
                    return;
                }
                break;
            case 'DURATION':
                if(boost_value_copy < 1){
                    p_duration += boost_value_copy;
                }else{
                    flat_duration += boost_value_copy;
                }
                break;
            case 'HEALING_BLOCK':       //
                break;                  //
            case 'REMOVE_STUN':         //
                break;                  // Not implemented and won't until I find it usefull
            case 'REMOVE_FROST':        //
                break;                  //
            case 'FROST_EFFECT':        //
                break;                  //
            case 'TURET_ROTATION':      //
                break;                  //
            case 'HEALING_REDUCTION':   //
                break;                  //
            default:
                printf("The training type: %s is unknown\n", boost_type_cpy);
        }
        free(boost_type_cpy);
    }
}
