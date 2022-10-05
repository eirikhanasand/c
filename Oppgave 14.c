//
//  Oppgave 14.c
//  Basics
//
//  Created by Eirik Hanasand on 27/09/2022.
//

#include <stdio.h>

int main(){
    int tall;
    int innlesteTall = 0;
    int totalSum = 0;
    int gjennomsnitt = 0;
    
    while (tall > 0) {
            printf("Skriv inn et positivt heltall:\n");
            scanf("%i", &tall);
            printf("Du skrev inn: %i\n", tall);
        
        if (tall > 0) {
            innlesteTall++;
            totalSum += tall;
            gjennomsnitt = totalSum / innlesteTall;
        }
    }
    if (totalSum > 0){
        printf("Antall tall innlest:    %i\n", innlesteTall);
        printf("Summen av alle tallene: %i\n", totalSum);
        printf("Gjennomsnitt:           %i\n", gjennomsnitt);
        printf("Programmmet ble avsluttet.\n");
    }
    return 0;
}
