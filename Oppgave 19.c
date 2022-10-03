//
//  Oppgave 19.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

const int MAXNUMBERS = 20;

int main(){
    int input;
    int number[MAXNUMBERS];
    int numberCount =   0;
    int under20 =       0;
    int under40 =       0;
    int under60 =       0;
    int under80 =       0;
    int under100 =      0;
    
    do{
        
        for (int i = 0; i < MAXNUMBERS; i++) {
            printf("Enter %i numbers: (numbers entered: %i)\n", MAXNUMBERS, numberCount);
            scanf("%i", &input);
            
            if (input > 0 && input <= 100) {
                number[i] = input;
                numberCount++;
            }else{
                printf("Number must be between 1 - 100!\n");
                do {
                    printf("Try again, between 1 - 100:\n");
                    scanf("%i", &input);
                } while (input < 0 && input > 100);
                numberCount++;
            }
            
            if (input > 0 && input <= 20) {
                under20++;
            }else if (input > 20 && input <= 40) {
                under40++;
            }else if (input > 40 && input <= 60) {
                under60++;
            }else if (input > 60 && input <= 80) {
                under80++;
            }else{
                under100++;
            }
            
        }
        
    }while(numberCount != MAXNUMBERS);
        
    printf("You entered %i numbers!\n", numberCount);
    
    printf("%i numbers below 20!\n", under20);
    printf("%i numbers below 40!\n", under40);
    printf("%i numbers below 60!\n", under60);
    printf("%i numbers below 80!\n", under80);
    printf("%i numbers below 100!\n", under100);
    
    return 0;
}
