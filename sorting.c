//
//  sorting.c
//  Basics
//
//  Created by Eirik Hanasand on 31/08/2022.
//
//  This is a program that sorts items in a list from the lowest to the highest value
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

const int MAXNUMBERS = 20;
int main(){
    
    int i, temp, swapped;       //Loop temporary and swapped number
    int numbers[MAXNUMBERS];    //Array for storing the numbers
    int howMany = 0;            //Howmany numbers were entered
    
    for (int i = 0; i < MAXNUMBERS; i++) {
        numbers[i] = 0;
    }
    /**
     Asks the user how many 
     */
    printf("How many numbers would you like to sort? (max 20)\n");
    scanf("%i", &howMany);
    
    if (howMany > MAXNUMBERS) {
        howMany = MAXNUMBERS;
    }
    
    for (int i = 0; i < howMany; i++) {
        printf("Number %i: ", i+1);
        scanf("%i", &numbers[i]);
    }
    
    printf("\nOriginal list:\t (%i nums)\n", howMany);
    for(i=0; i < howMany; i++){
        printf("%d\n", numbers[i]);
    }
    
    while(1){
        swapped = 0;
        
        for(i = 0; i < howMany-1; i++){
            if(numbers[i] > numbers[i+1]){
                temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                swapped = 1;
            }
        }
        if(swapped==0){
            break;
            
        }
    }
    
    /**
      Prints the sorted list
     */
    printf("\nSorted list:\t (%i nums)\n", howMany);
    for(i=0; i < howMany; i++){
        printf("%d\n", numbers[i]);
    }
    printf("\n");
    return 0;
}
