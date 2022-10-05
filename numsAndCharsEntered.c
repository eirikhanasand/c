//
//  numsAndCharsEntered.c
//  Basics
//
//  Created by Eirik Hanasand on 29/09/2022.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int MAXNUMBERS =       5;         //Max numbers
const int MAXLETTERS =      10;         //Max letters

int main(){
    
    char letters[MAXLETTERS] = {0};     //Letters if legal
    char tempLetters[MAXLETTERS] = {0}; //Letters before check
    int nLetters = 0;                   //Number of legal letters
    int illegal = 0;                    //Number of illegal letters
    
    int digit[MAXNUMBERS];              //Digit array
    int nDigit = 0;                     //Amount of legal letters
    
    /**
        Takes 5 numbers between 1 - 10000. Will loop until 5 satisfactory numbers have been found
     */
    do{
        printf("Enter 5 numbers between 1-10000:\n");
        for(int i = 0; i < MAXNUMBERS; i++){
            digit[i] = 0;
        }
        nDigit = 0;
        for(int i = 0; i < MAXNUMBERS; i++){
            scanf("%i", &digit[i]);
            if(digit[i] < 0 || digit[i] > 10000){
                nDigit++;
            }
        }
    }while(nDigit != 0);
    
    /**
        Outputs the numbers
     */
    printf("The %i numbers you entered were:\n", MAXNUMBERS - nDigit);
    for(int i = 0; i < MAXNUMBERS; i++){
        printf("Number %i: %i\n", i+1, digit[i]);
    }
    
    /**
        Takes 10 letters. Will loop until 10  letters have been found
     */
    
    printf("Enter 10 letters:\n");
        for(int i = 0; i < MAXLETTERS; i++){
            scanf(" %c", &tempLetters[i]);
            
            if (isalpha(tempLetters[i]) > 0){
                letters[nLetters] = tempLetters[i];
                tempLetters[i] = 0;
                letters[nLetters] = toupper(letters[nLetters]);
                nLetters++;
            }else{
                tempLetters[illegal] = tempLetters[i];
                illegal++;
            }
        }
    
    /**
        Outputs how many legal and illegal letters were found
     */
    
        printf("You entered %i legal letters:\n", nLetters);
        for(int i = 0; i < nLetters; i++){
            printf("Letter %i: %c\n", i+1, letters[i]);
        }
        if(illegal > 0){
            printf("You also entered %i illegal letters:\n", illegal);
        }
    return 0;
}
