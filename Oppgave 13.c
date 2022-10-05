//
//  Oppgave 13.c
//  Basics
//
//  Created by Eirik Hanasand on 27/09/2022.
//

#include <stdio.h>

const float HOYDE = 4;
const float PI = 3.1415;

int main(){
    int radius;
    float volum;
    while (radius > 20) {
        printf("Velg ønsket radius: (1-20)\n");
        scanf("%i", &radius);
    }
    
    for (int i = 1; i <= radius; i++) {
        volum = PI*(i*i)*HOYDE;
        printf("Volumet er: %10.2fm^3\n", volum);
    }
}
