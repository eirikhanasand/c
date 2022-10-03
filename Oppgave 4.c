//
//  Oppgave 4.c
//  Basic
//
//  Created by Eirik Hanasand on 26/09/2022.
//

#include <stdio.h>

const int lengde = 20;
int main(){
    
    char navn[lengde] = "Eirik";
    char adresse[lengde] = "Berghusvegen 10";
    char sted[lengde] = "Gjøvik";
    int mobilnr = 95996971;
    int alder = 18;

    printf("Navn:    %s\n", navn);
    printf("Adresse: %s\n", adresse);
    printf("Sted:    %s\n", sted);
    printf("Mobilnr: %i\n", mobilnr);
    printf("Alder:   %i\n", alder);

    
    return 0;
}
