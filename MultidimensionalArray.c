//
//  MultidimensionalArray.c
//  Basics
//
//  Created by Eirik Hanasand on 20/09/2022.
//
//  Multidimensional arrays of numbers and characters
//
/**
 * This program shows exmples of multidimensional arrays of both numbers and characters. 
 */

#include <stdio.h>

int main(){
    int i, j;
    int sum = 0;
    
    int tall[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12} };
    
    printf("%i\n", tall[0][0]);
    printf("%i\n", tall[0][3]);
    printf("%i\n", tall[1][3]);
    printf("%i\n", tall[2][3]);

    for(i = 0; i < 3; i++){
        for (j = 0; j < 4; j++) {
            printf("%5i", tall[i][j]);
        }
        printf("\n");
    }
    
    char ukedager[7][5] = {
        "Man", "Tirs", "Ons", "Tors", "Fre", "Lør", "Søn"};
    
    for(i = 0; i < 7; i++){
        for(j = 0; j < 5; j++){
            printf("%c", ukedager[i][j]);
        }
        printf("dag\n");
    }
    
    int skip;
    char dager[7][5] = {
        "Man", "Tirs", "Ons", "Tors", "Fre", "Lør", "Søn"};
    
    for(i=0; i<7; i++){
        for(j=0; j<5; j++){
//            printf("%c", dager[i][j]);
        }
        printf("dag\n");
//        scanf("");
    }
    
    return 0;
}

