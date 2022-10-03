//
//  Oppgave 7.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//
/**
 inneholder heltallene tall1, tall2, tall3, sum, kvadratSum
 • inneholder flyttallene flyt1, flyt2, gjsnittSum, gjsnittKvadrat
 • initierer/setter de tre første heltallene og de to første flyttallene til noen selvvalgte/
 ønskelig verdier
 • lar sum bli inneholdende summen av de tre første heltallene, og skriver ut alle tallene
 som har vært involvert i regnestykket (tall1, tall2, tall3 og sum)
 • lar gjsnittSum bli inneholdende gjennomsnittet for de tre tallene i sum, og skriver
 ut dette svaret/tallet. Hvorfor må du huske å dele/dividere med 3.0 ?
 • lar kvadratSum bli inneholdende summen av de tre første heltallene kvadrert
 (ganget med seg selv), og skriver ut dette svaret/tallet
 • lar gjsnittKvadrat bli inneholdende gjennomsnittet for summen av de tre
 kvadratene i kvadratSum, og skriver ut dette svaret/tallet. Del også her med 3.0.
 • skriver ut gjennomsnittet av flyt1 og flyt2, uten å bruke en hjelpevariabel.
 Hvorfor er det strengt tatt ikke påkrevd å dele med 2.0 her?
 */
#include <stdio.h>

int main(){
    int tall1 = 2;
    int tall2 = 4;
    int tall3 = 6;
    int sum;
    int kvadratSum;
    
    float f1 = 8;
    float f2 = 10;
    float gjennomsnitt;
    float gjKvadrat;
    
    sum = tall1 + tall2 + tall3;
    printf("Tall1:                    %i\n", tall1);
    printf("Tall2:                    %i\n", tall2);
    printf("Tall3:                    %i\n", tall3);
    printf("Sum:                      %i\n", sum);
    
    kvadratSum = tall1 * tall2 * tall3;
    printf("Kvadratsum:               %i\n", kvadratSum);
    
    gjennomsnitt = ((tall1 + tall2 + tall3) / 3);
    printf("Gjennomsnittet:           %.2f\n", gjennomsnitt);
    
    gjKvadrat = f1 * f2;
    printf("Gj Kvadrat:               %.2f\n", gjKvadrat);
    
    printf("Summen av tall1 og tall2: %i\n", (tall1+tall2/2));
    
    return 0;
}
