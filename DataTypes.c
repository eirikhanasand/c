//
//  DataTypes.c
//  Basic
//
//  This program takes on different data types and header file. 
//
//  Created by Eirik Hanasand on 26/08/2022.
//
//  This program plays around with different data types.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    const MYNAME;
    const AGE;
    printf("My name is %s and my age is %d\n", MYNAME, AGE);
    //For loop finding the 300th rectangular number
    int n, rgN;
    rgN = 0;
    for (n = 1; n <= 300; n = n+1)
        rgN = rgN + n;
        printf("The 300th rectangular number is %i\n", rgN);
    //Declaring various variables
    int integerVar = 100;
    float floatingVar = 331.79;
    double doubleVar = 8.44e+11;
    char charVar = 'W';
    _Bool boolVar = 0;
    
    //Playing with integers
    int a = 100;
    int b = 75;
    int c = 50;
    int d = 25;
    
    //Playing with floats
    float f1 = 10;
    float f2 = 7;
    float f3 = 5;
    float f4 = 2;
    
    //Playing with chars
    char c1 = 'w';
    char c2 = 'x';
    char c3 = 'y';
    char c4 = 'z';
    
    int result;

    //Testing different data types
    printf("Printing various data types\n");
    printf("integerVar = %i\n", integerVar);
    printf("floatingVar = %f\n", floatingVar);
    printf("doubleVar = %e\n", doubleVar);
    printf("doubleVar = %g\n", doubleVar);
    printf("charVar = %c\n", charVar);
    printf("boolVar = %i\n", boolVar);
    
    //Printing different results
    printf("\nPrinting different results\n");
    
    //Subtraction
    result = a-b;
    printf("a-b = %i\n", result);
    
    //Division
    result = b/a;
    printf("b/a = %i\n", result);
    
    //Subtraction with negative result
    result = c-a;
    printf("c-a = %i\n", result);
    
    //Addition
    result = d+a;
    printf("d+a = %i\n", result);
    
    //Precedence
    result = a-b*c;
    printf("a-b*c = %i\n", result);
    
    //Multiplication
    result = a*b*c*d;
    printf("a*b*c*d = %i\n", result);
    
    //Printing a,b,c,d on the same line
    printf("a=%i b=%i c=%i d=%i\n", a, b, c, d);
    
    //Converting between integers and floats
    //a = f1;
    printf("\na turned into f1 = %i\n", a);
    b = c2;
    printf("b turned into c2 = %c\n", b);
    c = (float) a/10;
    printf("(Float) %i when a is divided by 10 = %i", a, c);
    
    //Checking if the program got to the last line
    printf("\nProgram completed\n");
    return 0;
}
