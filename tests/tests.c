#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>


int main() {
    unsigned int setup [10];
    unsigned int gear [5][2];
    unsigned int y = 0;
    int k = 0;
    for(int i = 0; i < 10; i++){
        if(i%2 == 0){
            y = 0;
        }else{
            y = 1;
            k++;
        }
        gear[k][y] = setup[i];

    }

    for (int i = 0; i < 10; i++){
        printf("%d ", setup[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 2; j++){
            printf("%d ", gear[i][j]);
        }
        printf("\n");
    }

    return 0;
}