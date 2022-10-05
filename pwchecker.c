//
//  pwchecker.c
//  Basics
//
//  Created by Eirik Hanasand on 30/08/2022.
//
//  This program checks if a password is longer than 8 characters, includes both upper and lower case letters, a number and a symbol. It will then set the password, or print whats wrong together with an error code to directly see in the code what was wrong.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    //Declaring variables 33 on password because 32 is the max length accepted
    char password[33];
    int spot = 0;
    int hasupper = 0;
    int haslower = 0;
    int hasdigit = 0;
    int haspunct = 0;
    int combo;
    
    //User enters their desired password
    printf("Enter password: ");
    scanf("%s", password);
    
    //Checking if the password includes every criteria and giving points for criteria met
    for (spot; spot <= sizeof(password); spot++) {
            if(isupper(password[spot])){
                    hasupper++;
            }else if(islower(password[spot])){
                    haslower++;
            }else if(isdigit(password[spot])){
                    hasdigit++;
            }else if(ispunct(password[spot])){
                    haspunct++;
            }else{
                continue;
            }
    }
    //Making a variable for the length of the password
    combo = hasupper + haslower + hasdigit + haspunct;
    
    /**
     Checking if any points equal 0 (this means its not included in the password)
     */
    if(combo < 8){
        printf("Password is only %i/8 characters long.\n", combo);
        return 1;
    }else if(hasupper == 0){
        printf("Your password does not contain a upper case letter.\n");
        return 2;
    }else if (haslower == 0){
        printf("Your password does not contain a lower case letter.\n");
        return 3;
    }else if (hasdigit == 0){
        printf("Your password does not contain a number.\n");
        return 4;
    }else if (haspunct == 0){
        printf("Your password does not contain a special character\n");
        return 5;
    }else{
        printf("Password set!\n");
        return 0;
    }
}
