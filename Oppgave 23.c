//
//  Oppgave 23.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>
#include <math.h>

void summerKvadrater(int tall,int tall2,int tall3);
int inputNumber1 = 0;
int inputNumber2 = 0;
int inputNumber3 = 0;
int sum = 0;

int main(){
    printf("Skriv inn tre tall\n");
    scanf("%i %i %i", &inputNumber1, &inputNumber2, &inputNumber3);
    summerKvadrater(inputNumber1, inputNumber2, inputNumber3);
    
    return 0;
}

void summerKvadrater(int tall,int tall2,int tall3){
    tall = sqrt(inputNumber1);
    tall2 = sqrt(inputNumber2);
    tall3 = sqrt(inputNumber3);
    sum = tall + tall2 + tall3;
    printf("Kvadratroten av tall 1: %i\n", tall);
    printf("Kvadratroten av tall 2: %i\n", tall2);
    printf("Kvadratroten av tall 3: %i\n", tall3);
    printf("Dette gir summen %i\n", sum);
}

