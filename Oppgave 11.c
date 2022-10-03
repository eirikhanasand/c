//
//  Task11.c
//  Basics
//
//  Created by Eirik Hanasand on 19/09/2022.
//
//  Task using different parts of strings and integers to play around
//

#include <stdio.h>

int main(){
    int number[5];
    int number2[] = {6, 2, 10, 12, 19, 3, 7};
    char text[5];
    char name[12] = "Lars Hansen";
    char address[13] = "Ringgata 111";
    
    number[0] = 13;
    number[1] = 67;
    number[2] = number2[0] + number[1];
    
    number[3] = number2[0] + number2[1] + number2[2] + number2[3];
    number[4] = number2[4] + number2[5] + number2[6];
    
    printf("The sum of number and number2 is: %i\n", number[2]);
    printf("Number3 / 2 is: %i\n", number[2]/2);
    printf("The sum of the four first numbers in number two is: %i\n", number[3]);
    printf("The sum of the three last numbers in number two is: %i\n", number[4]);
    printf("House number %c%c%c\n", address[9], address[10], address[11]);
    
    printf("Number before being increased: %i\n", number[2]);
    for(int i; i<=4; i++){
        tall[2]++;
    }
    printf("Increased value of number: %i\n", number[2]);
    
}
