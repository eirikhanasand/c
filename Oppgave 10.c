//
//  Oppgave 10.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//

#include <stdio.h>
const int LENGDE = 80;

int main(){
    char tegn1 = 'F';
    char tegn2 = 'H';
    char b = 'b';
    float flyt1 = 17.52;
    float flyt2 = 451.87;
    
    printf("%f\n%f\n%c\n%c\n", flyt2, flyt1, tegn2, tegn1);
    printf("%e\n", flyt2);
    printf("%i\n", (int)flyt1);
    printf("%i\n", (int)flyt2);
    printf("%i\n", (int)tegn1);
    printf("%i\n", (int)b);
}
