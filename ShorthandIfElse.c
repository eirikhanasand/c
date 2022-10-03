//
//  ShorthandIfElse.c
//  Basic
//
//  Created by Eirik Hanasand on 29/08/2022.
//
//  This program takes on a shorthand version of writing if else statements.
//  Plus a practical example of when this can be used.
//
//  NOTE: Should only be used for single lines of code because it is harder to read and introduces more posibilites for confusion and error.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    char lastName[20];
    int dollar;
    
    printf("What is your last name?\n");
    scanf("%s", lastName);
    
    printf("Your last name is %s\n", lastName);
    (lastName[0] < 'M') ? printf("%s you will be on TEAM RED\n", lastName) : printf("%s you will be on TEAM BLUE\n", lastName);
    
    printf("How much money do you have?\n");
    scanf("%d", &dollar);
    printf("%s has %d dollar%s\n", lastName, dollar, (dollar!=1) ? "s" : "");
    
    return 0;
}
