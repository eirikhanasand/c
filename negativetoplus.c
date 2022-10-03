//
//  negativetoplus.c
//  Basics
//
//  Created by Eirik Hanasand on 30/08/2022.
//
//  This program converts negative numbers to positive.
//
//  This program also shows basic examples of using the pow(power) and sqrt(squareroot) keywords.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    //Basic example of the pow keyword
    printf("%f\n", pow(5, 3));
    
    //Basic example of the sqrt keyword
    printf("%.2f\n", sqrt(16));
    
    int year1;
    int year2;
    int diff;
    
    printf("Enter a year: \n");
    scanf("%d", &year1);
    
    printf("Enter another year:  \n");
    scanf("%d", &year2);
    
    diff = year1 - year2;
    printf("%d\n", diff);
    
//  The abs function converts negative numbers to positive
    diff = abs(diff);
    printf("%d\n", diff);
    
    return 0;
}
