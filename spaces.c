//
//  spaces.c
//  Basics
//
//  Created by Eirik Hanasand on 29/09/2022.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int MAXUSERS = 20;
const int STRLEN = 80;
int main(){
    char userName[MAXUSERS][STRLEN]; //Array for users
    char userPass[MAXUSERS][STRLEN]; //Array for password
    
    int hasSpaces = 0;
    int userNumber = 0;
    
    do{
        hasSpaces = 0;
        printf("Enter Username:\n");       //Asking for username
        gets(userName[userNumber]);        //Getting username
            if (strchr(userName[userNumber], ' ') != 0){
                printf("Username contains spaces\n");
                hasSpaces++;
            }
        }while(hasSpaces > 0);

    do{
        hasSpaces = 0;
        printf("Enter Password:\n");       //Asking for username
        gets(userPass[userNumber]);        //Getting username

            if (strchr(userPass[userNumber], ' ') != 0){
                printf("Password contains spaces\n");
                hasSpaces++;
            }
    }while(hasSpaces > 0);
    
    printf("Everything worked!\n");
    return 0;
}
