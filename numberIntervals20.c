//
//  numberIntervals20.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>          //Included for printf

const int MAXNUMBERS = 20;  //Const max numbers

int main(){
    int input;              //User input
    int number[MAXNUMBERS]; //Number array
    int numberCount =   0;  //Amount of numbers
    int under20 =       0;  //Numbers between 1 - 20
    int under40 =       0;  //Numbers between 21 - 40
    int under60 =       0;  //Numbers between 41 - 60
    int under80 =       0;  //Numbers between 61 - 80
    int under100 =      0;  //Numbers between 81 - 100
    
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
            
            //Checks if number is between 1-20
            if (input > 0 && input <= 20) {
                under20++;
            
            //Checks if number is between 21-40
            }else if (input > 20 && input <= 40) {
                under40++;
            
            //Checks if number is between 41-60
            }else if (input > 40 && input <= 60) {
                under60++;
                
            //Checks if number is between 61-80
            }else if (input > 60 && input <= 80) {
                under80++;
                
            //Checks if number is between 81-100
            }else{
                under100++;
            }
            
        }
        
    }while(numberCount != MAXNUMBERS);
        
    printf("You entered %i numbers!\n", numberCount);
    
    printf("%i numbers between 1-20!\n", under20);       //Prints numbers between 1-20
    printf("%i numbers between 21-40!\n", under40);      //Prints numbers between 21-40
    printf("%i numbers between 41-60!\n", under60);      //Prints numbers between 41-60
    printf("%i numbers between 61-80!\n", under80);      //Prints numbers between 61-80
    printf("%i numbers between 81-100!\n", under100);    //Prints numbers between 81-100
    
    return 0;
}
