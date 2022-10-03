//
//  Switches.c
//  Basics
//
//  Created by Eirik Hanasand on 29/08/2022.
//
//  How to use switches
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    char grade = 'C';
//    if(isalpha(grade)){
//        printf("Yes %c is a letter\n", grade);
//    }else if(isdigit(grade)){
//        printf("Yes %c is a letter\n", grade);
//    }else{printf("wtf is %c, Ive never seen that before :(", grade);
//    }

    printf("What grade did you get?\n");
    scanf("%c", &grade);
    
    switch(toupper(grade)){
        case 'A': printf("Well done!\n");
            break;
        case 'B': printf("Great!\n");
            break;
        case 'C': printf("%c is okay!\n", toupper(grade));
            break;
        case 'D': printf("Not too bad bro\n");
            break;
        case 'E': printf("Well hey! At least you didnt fail\n");
            break;
        case 'F': printf("Maybe you should study more...\n");
            break;
        default: printf("%c is not a grade bro..\n", toupper(grade));
    }
}
