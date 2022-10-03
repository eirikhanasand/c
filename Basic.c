//
//  Basic.c
//  Basic
//
//  Created by Eirik Hanasand on 24/08/2022.
//
//  First program in Basic folder, area of triangle
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    //Declaring integers
    int value1, value2, mvalue, sum;
    //Setting values for the ints
    value1 = 4;
    value2 = 3;
    //Calculating the combind value of value 1 and value 2
    mvalue = value1 * value2;
    //Dividing the answer by 2 since its a rectangle and not a square
    sum = mvalue/2;
    //Printing the result
    printf("Arealet av trekanten med grunnlinje %i og høyde %i er %i.\n",value1, value2, sum);
    //Playing with line breaks
    printf("Tester...\n1...\n2...\n3...\n4...\n5...\nTest utført.\n");
    //Checking that the result is still the same
    printf("Arealet av trekanten er fortsatt %i.\n", sum);
    //Closing the program
    return 0;
}
