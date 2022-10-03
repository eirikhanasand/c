//
//  structures.c
//  Basics
//
//  Created by Eirik Hanasand on 02/09/2022.
//
//  Basic Calculator
//

#include <stdio.h>
#include <string.h>

int main(){
    int number1 = 0;
    int number2 = 0;
    int result;
    char multiply[10] = "multiply";
    char divide[10] = "divide";
    char plus[10] = "plus";
    char minus[10] = "minus";
    char null[10] = "0";
    char choice[10];
    
    do{
        printf("What would you like to do? (multiply, divide, plus or minus)\Write 0 end the program\n");
        scanf("%s", choice);
        
        int mresult = strcmp(multiply, choice);
    //      printf("strcmp(multiply, choice) = %d\n", mresult);
        int dresult = strcmp(divide, choice);
    //      printf("strcmp(divide, choice) = %d\n", dresult);
        int presult = strcmp(plus, choice);
    //      printf("strcmp(plus, choice) = %d\n", presult);
        int miresult = strcmp(minus, choice);
    //      printf("strcmp(minus, choice) = %d\n", miresult);
        int nullresult = strcmp(null, choice);
        
        if(mresult == 0){
            printf("What would you like to multiply?\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 * number2;
            printf("%d * %d = %d\n", number1, number2, result);
        }
        else if(dresult == 0){
            printf("What would you like to divide?\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 / number2;
            printf("%d / %d = %d\n", number1, number2, result);
        }else if(presult == 0){
            printf("What would you like to plus\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
        }else if(miresult == 0){
            printf("What would you like to subtract?\n");
            printf("Number 1:\n");
            scanf("%d", &number1);
            printf("Number 2:\n");
            scanf("%d", &number2);
            result = number1 - number2;
            printf("%d - %d = %d\n", number1, number2, result);
        }else if(number1 != 0 && number2 != 0 && nullresult != 0){
            printf("You wrote %s, and the program was terminated.\n", choice);
            return 2;
        }else{
            printf("You wrote %s, and the program was terminated.\n", choice);
            return 1;
        }
    }while(number1 != 0 && number2 != 0);
    
    printf("You wrote 0, and the program was terminated.\n");
    
    return 0;
}
