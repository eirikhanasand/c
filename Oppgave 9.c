//
//  Oppgave 9.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//

#include <stdio.h>

int main(){
    int totaltSekunder;
    int sekunder;
    int minutter;
    int timer;
    
    printf("Skriv inn sekunder\n");
    scanf("%i", &totaltSekunder);
    timer = totaltSekunder / 3600;
    minutter = (totaltSekunder % 3600) / 60;
    sekunder = (totaltSekunder % 3600) % 60;
    printf("%i sekunder er %i timer, %i minutt, %i sekund\n", totaltSekunder, timer, minutter, sekunder);
    
}
