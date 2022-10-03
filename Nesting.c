//
//  Nesting.c
//  Basic
//
//  Created by Eirik Hanasand on 28/08/2022.
//
//  Using integers to compare things and check if they are more, less or equal to each other.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int a, b, c, e;
char feet[50] = "I like feet (not really I hate feet tbh.)\n";



int main(){
    
    printf("Enter value of a\n");
    scanf(" %d", &a);
    
    printf("Enter value of b\n");
    scanf(" %d", &b);
    
    printf("Enter value of c\n");
    scanf("%d", &c);
    
    if(a < b && c > b){
        printf("%d is larger than %d, but not larger than %d.\n", b, a, c);
        e = 2;
    }else if(a == b){
        printf("%d is equal to %d\n", a, b);
        e = 3;
    }else{
        printf("%d is more than %d\n", a, b);
        e = 4;
    }
    char answer;
    printf("Do you like this program?\n");
    scanf(" %c", &answer);
    if ((answer == 'y')||(answer == 'n')){
        printf("Thank you for your feedback!\n");
    }else{return 0;}
    
    printf("%s", feet);
    return e;
}
