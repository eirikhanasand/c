//
//  findLowestHighest.c
//  Basics
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#include <stdio.h>

const int MAXNUMBERS = 20;  //Const for max numbers
int numberCount = 0;        //Amount of numbes
int lowestNum = 0;          //Lowest number
int highestNum = 0;         //Highest number
int number[MAXNUMBERS];     //Number array

//Function to find lowest or highest value
void getValue(char choice, int number[numberCount]);
char choice;    //Users choice

int main(){
    
    //Asks the users how many numbers they would like to enter
    printf("How many numbers would you like to enter? (max %i)\n", MAXNUMBERS);
    scanf("%i", &numberCount);
    
    //If input is more than max it is set to max
    if(numberCount > MAXNUMBERS){
        printf("This is more than max, setting to %i.\n", MAXNUMBERS);
        numberCount = MAXNUMBERS;
    }
    
    //Getting every number from the user
    for (int i = 0; i < numberCount; i++) {
        printf("Enter number %i:", i+1);
        scanf("%i", &number[i]);
    }
    
    //Lowest or highest number
    printf("Would you like to find the lowest or highest number? (l/H)\n");
    choice = getchar();
    choice = getchar();
    getValue(choice, number);
}

//Function to find lowest or highest value
void getValue(char choice, int number[numberCount]){
    
    //Lowest section
    if(choice == 'l'){
        lowestNum = number[0];
        for (int i = 0; i < numberCount; i++) {
            if (lowestNum > number[i]) {
                lowestNum = number[i];
            }
        }
        printf("The lowest number was: %i.\n", lowestNum);
    
    //Highest section
    }else{
        highestNum = number[0];
        for (int i = 0; i < numberCount; i++) {
            if (highestNum < number[i]) {
                highestNum = number[i];
            }
        }
        printf("The highest number was: %i.\n", highestNum);
    }
}
