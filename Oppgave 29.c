//
//  Oppgave 29.c
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#include "Oppgave 29.h"

fractionA fracA;
fractionB fracB;
addSum sum;

void enterFraction(int i);  //User input
void writeFraction(int i);  //Prints fraction
void fracAdd(void);         //Adds fractions
void fracSub(void);         //Subs fractions
void fracM(void);           //Multiplies fractions
void fracD(void);           //Divides fractions
void writeAllFracs(void);   //Writes all fracs
void fracSum(char sign);    //Prints the sum

int main(){
    enterFraction(1);       //User inputs a fraction
    enterFraction(2);       //User inputs a fraction
    
    writeAllFracs();        //Writes inputted fractions
    fracAdd();              //Add fractions function
    fracSub();              //Subtract fractions function
    fracM();
    fracD();
    return 0;
}


//Allows the user to enter a fraction
void enterFraction(int i){
    if(i == 1){
        printf("Enter fraction numerator:\n");
        scanf("%i", &(fracA.n));
        
        do {
            printf("Enter fraction denominator: (must be positive)\n");
            scanf("%i", &fracA.d);
        } while (fracA.d < 0);
        
    }else{
        
        printf("Enter fraction 2 numerator:\n");
        scanf("%i", &(fracB.n));
        
        do {
            printf("Enter fraction 2 denominator: (must be positive)\n");
            scanf("%i", &fracB.d);
        } while (fracB.d < 0);
    }
}

//Prints fraction
void writeFraction(int i){
    if(i == 1){
        printf("%d / %d", fracA.n, fracA.d);
    }else{
        printf("%d / %d", fracB.n, fracB.d);
    }
}

//Prints all fractions
void writeAllFracs(void){
    printf("Fraction 1: %d / %d\n", fracA.n, fracA.d);
    printf("Fraction 2: %d / %d\n", fracB.n, fracB.d);
}

//Adds fractions
void fracAdd(void){
    sum.n = (fracA.n*fracB.d)+(fracA.d*fracB.n);
    sum.d = (fracA.d*fracB.d);
    fracSum('a');
}

void fracSub(void){
    sum.n = (fracA.n*fracB.d)-(fracA.d*fracB.n);
    sum.d = (fracA.d*fracB.d);
    fracSum('s');
}

void fracM(void){
    sum.n = (fracA.n*fracB.n);
    sum.d = (fracA.d*fracB.d);
    fracSum('m');
}

void fracD(void){
    sum.n = (fracA.n*fracB.d);
    sum.d = (fracA.d*fracB.n);
    fracSum('d');
}

void fracSum(char sign){
    printf("(");
    writeFraction(1);
    printf(")");
    if (sign == 'a') {
        printf(" + ");
    } else if (sign == 's') {
        printf(" - ");
    } else if (sign == 'm') {
        printf(" * ");
    }else{
        printf(" / ");
    }
    printf("(");
    writeFraction(2);
    printf(")");
    printf(" = ");
    printf("%d / %d\n", sum.n, sum.d);
}
