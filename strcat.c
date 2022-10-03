//
//  strcat.c
//  Basic
//
//  Created by Eirik Hanasand on 30/08/2022.
//
//  How to round numbers up and down.
//
//  How to ignore spaces in scanf = scanf("%[^\n]s", char);
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
//    float val1 = 3.01;
//    float val2 = 6.278485995;
//
//    printf("Value 1: %.2f   Value 2: %.2f\n", floor(val1), floor(val2));
//
//    printf("Value 1: %.2f   Value 2: %.2f", ceil(val1), ceil(val2));
//
    
    char name[30];
    puts("What is your name?");
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Hello %s!\n", name);

//    char boo[100] = "\t\tHey\n";
//
//    strcat(boo, ", how are you");
//    strcat(boo, " today?\n");
//    printf("%s", boo);
//
//    strcpy(boo, "Replaced lol\n");
//    printf("%s", boo);
    
    return 0;
}
