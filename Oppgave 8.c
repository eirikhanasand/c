//
//  Oppgave 8.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//

#include <stdio.h>

const int ANTALL = 17;

int main(){
    
    int tall1 = 5;
    int tall2 = 10;
    int tall3 = 15;
    int svar;
    svar = tall1 + ANTALL;
    printf("Summen av tall1 + antall er %i\n", svar);
    
    svar = tall1 - ANTALL;
    printf("Summen av tall1 - antall er %i\n", svar);
    
    svar = tall2 / ANTALL;
    printf("Summen av tall2 / antall er %i\n", svar);
    
    svar = tall3 * ANTALL;
    printf("Summen av tall3 * antall er %i\n", svar);
    
    tall1++;
    tall1++;
    tall1++;
    
    tall2--;
    tall2--;
    tall2--;
    tall2--;
    printf("Produktet av tall1 og tall2 er: %i\n", tall1 * tall2);
    printf("Dersom vi trekker fra antall er svaret: %i\n", (tall1 * tall2) - ANTALL);
    return 0;
}
