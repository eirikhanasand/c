//
//  User input.c
//  Basic
//
//  Created by Eirik Hanasand on 28/08/2022.
//
//  Basic program that takes input.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

char firstName[20];
char lastName[20];
char school[20];
int age;
int inputs;

int main(void){
    
    printf("What is your first name?\n");
    scanf("%s", firstName);
    inputs++;
    
    printf("What is your last name?\n");
    scanf("%s", lastName);
    inputs++;

    printf("What school do you go to?\n");
    scanf("%s", school);
    inputs++;

    printf("What is your age?\n");
    scanf("%d", &age);
    inputs++;

    printf("You are %s %s age %d going to school %s.\n", firstName, lastName, age, school);
    printf("This program needs user input %d times.\n", inputs);
    printf("Program finished\n");
    
    return 0;
    
}
