//
//  logicoperators.c
//  Basics
//
//  Created by Eirik Hanasand on 13/09/2022.
//
//  Basic math operators. 
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    
    float number1 = 0;
    float number2;
    float answer;
    
    printf("What would you like to divide? (number 1 / number 2\n");
    printf("Number 1:\n");
    scanf("%f", &number1);
    printf("Number 2:\n");
    scanf("%f", &number2);
    
    while (number1 <= 0 || number2 <= 0) {
        if(number1 <= 0){
            printf("You wrote 0 for number 1, choose a new number 1:\n");
            scanf("%f", &number1);
        }else if (number2 <= 0){
            printf("You wrote 0 for number 2, choose a new number 2:\n");
            scanf("%f", &number2
                  );
        }else{return 1;}
    }
    answer = answer1 / answer2;
    printf("%.2f / %.2f = %.2f\n", number1, number2, answer);
    
    return 0;
}
