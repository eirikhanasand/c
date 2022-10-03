//
//  frame.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//
//  This program takes input length*height and makes a frame using these parameters.
//  (Task 22)
//

#include <stdio.h>

int main(){
    
    int height = 0;
    int width = 0;
    
    printf("What height and width would you like the frame to be?\n");
    scanf("%i %i", &height, &width);
    
    for(int i = 0; i < width; i++){
        printf("*");
    }
    printf("\n");
    
    for(int i = 0; i < height-2; i++){
        printf("*");
            for (int j = 0; j < width-2; j++) {
                printf(" ");
            }
            printf("*\n");
    }
    
    for(int i = 0; i < width; i++){
        printf("*");
    }
    printf("\n");
    return 0;
}
