//
//  test.c
//  C-Project
//
//  Created by Eirik Hanasand on 24/11/2022.
//

#include <stdio.h>
#include <string.h>


int forekomstAvBokstaver(const char tekst[], const char bokstaver[],
                         const int tekstlengde, const int bokstavlengde);

int forekomstAvBokstaver(const char tekst[], const char bokstaver[],
                         const int tekstlengde, const int bokstavlengde){
    
    int antall = 0; //Brukes for å telle opp antall
    for(int i = 0; i < bokstavlengde; i++) {
        for(int j = 0; j < tekstlengde; j++) {
            if(tekst[j] == bokstaver[i]) {
                antall++;
            }
        }
    }
    return antall;
}


