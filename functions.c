//
//  functions.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

void frame(int height, int width);

int main(){
    int desiredHeight = 0;
    int desiredWidth = 0;
    
    printf("What height and width would you like the frame to be?\n");
    scanf("%i %i", &desiredHeight, &desiredWidth);
    
    frame(desiredHeight, desiredWidth);
    
    return 0;
    }


void frame(int height, int width){
    
    int i = 0;
    int j = 0;

    for(i = 0; i < width; i++){
        printf("*");
    }
    printf("\n");

    for(i = 0; i < height-2; i++){
        printf("*");
            for (j = 0; j < width-2; j++) {
                printf(" ");
            }
            printf("*\n");
    }

    for(int i = 0; i < width; i++){
        printf("*");
    }
    printf("\n");
}

