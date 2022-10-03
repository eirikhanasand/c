//
//  Loops.c
//  Basics
//
//  Created by Eirik Hanasand on 13/09/2022.
//
//  Basic loops.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(){
    //While loop to calculate how many breadsticks you have after a year with a daily accumulation of 1.2 times the breadsticks value of the previous day.
    float breadsticks = .1;
    int day = 1;
    
    //Do while loop for calculating the average of your grades.
    float grade = 0;
    float average = 0;
    float numberOfTests = 0;
    float gradeEntered = 0;
    
    while (day <= 365){
        printf("You have %.2f breadstick%s on day %d\n", breadsticks, (breadsticks!=1) ? "s" : "", day);
        breadsticks*=1.2;
        day++;
    }
    
    printf("\n\nPress 0 to close program\n\n");
    do{
        printf("Test: %f     Average: %.2f\n", numberOfTests, average);
        printf("Enter grade: ");
        scanf("%f", &gradeEntered);
        grade+=gradeEntered;
        numberOfTests++;
        average = grade / numberOfTests;
    }while(gradeEntered!=0);
    
    //for loop
    int number;
    for(number=1; number<=10; number++){
        printf("%i\n", number);
    }
    
    //for loop that creates a table rows wide and columns tall
    int rows;
    int columns;
    
    for(rows=1; rows <= 10; rows++){
        for(columns=1; columns <= 10; columns++){
            printf("%d ", columns);
        }
        printf("\n");
    }
    
    //Practical example of for loop using the break and continue argument.
    int howMany;
    int a;
    int maxAmount = 100;
    printf("How many times would you like to loop? (1-100)\n");
    scanf("%i", &howMany);
    
    for(a=1; a <= maxAmount; a++){
        if (a==5 || a ==7){
            continue;
        }
        printf("%i\n", a);
        if (a==howMany){
            break;
        }
    }
    
    return 0;
}

