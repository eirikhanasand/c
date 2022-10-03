/**
 * Denne filen innhenter informasjon om navn, timelønn og antall ferieuker fra 2 personer.
 *
 * Deretter beregnes ukelønn, månedslønn, årslønn og om begge personene
 * har likt navn eller samme lønn. Til slutt skrives denne informasjonen ut igjen til brukeren.
 *
 * @file      PROG1001oblig1.c
 * @date      7. September 2022
 * @version   1
 * @author    Eirik Hanasand
 */

#include <stdio.h>          //Inkluderes for print funksjonen
#include <string.h>         //Inkluderes for strcmp funksjonen
#include <stdbool.h>        //Inkluderes for bool funksjonen

int main(){
    char navn1[20];         //Navn person 1
    float timelonn1;        //Timelønn person 1
    float ferieuker1;       //Antall ferieuker person 1
    float ukelonn1;         //Ukelønn person 1
    float maanedslonn1;     //Månedslønn person 1
    float aarslonn1;        //Årslønn person 1
    
    char navn2[20];         //Navn person 2
    float timelonn2;        //Timelønn person 2
    float ferieuker2;       //Antall ferieuker person 2
    float ukelonn2;         //Ukelønn person 2
    float maanedslonn2;     //Månedslønn person 2
    float aarslonn2;        //Årslønn person 2
    
    bool liktNavn = false;  //Angir om person 1 og 2 har samme navn
    bool likLonn = false;   //Angir om person 1 og 2 har lik lønn
    
//  Innhenter navn, timelønn og ferieuker fra person 1
    printf("Navn på person 1:\n");
    scanf("%s", navn1);
    printf("Timelonn person 1:\n");
    scanf("%f", &timelonn1);
    printf("Antall ferieuker person 1:\n");
    scanf("%f", &ferieuker1);
    
//  Innhenter navn, timelønn og ferieuker fra person 2
    printf("Navn på person 2:\n");
    scanf("%s", navn2);
    printf("Timelonn person 2:\n");
    scanf("%f", &timelonn2);
    printf("Antall ferieuker person 2:\n");
    scanf("%f", &ferieuker2);
    
    ukelonn1 = timelonn1*8*5;               //Beregner ukelønn person 1
    maanedslonn1 = ukelonn1*4.33;           //Beregner månedslønn person 1
    aarslonn1 = (52-ferieuker1)*ukelonn1;   //Beregner årslønn person 1
    
    ukelonn2 = timelonn2*8*5;               //Beregner ukelønn person 2
    maanedslonn2 = ukelonn2*4.33;           //Beregner månedslønn person 2
    aarslonn2 = (52-ferieuker2)*ukelonn2;   //Beregner årslønn person 2
    
//  Skriver ut all informasjon om person 1
    printf("Navn 1: %s (lengde: %lu)\n", navn1, strlen(navn1));
    printf("Timelonn %.2f\n", timelonn1);
    printf("Ferieuker: %.1f\n", ferieuker1);
    printf("Ukelonn: %.2f\n", ukelonn1);
    printf("Maanedslonn: %.2f\n", maanedslonn1);
    printf("Aarslonn: %.2f\n\n", aarslonn1);
    
//  Skriver ut all informasjon om person 2
    printf("Navn 2: %s (lengde: %lu)\n", navn2, strlen(navn2));
    printf("Timelonn %.2f\n", timelonn2);
    printf("Ferieuker: %.1f\n", ferieuker2);
    printf("Ukelonn: %.2f\n", ukelonn2);
    printf("Maanedslonn: %.2f\n", maanedslonn2);
    printf("Aarslonn: %.2f\n\n", aarslonn2);
    
    liktNavn = !strcmp(navn1, navn2);       //Sjekker om navnene er like
    likLonn = (timelonn1 == timelonn2);     //Sjekker om lønnen er lik
    
    printf("Likt navn = %d\n", liktNavn);   //Skriver ut om navnene er like
    printf("Lik lonn = %d\n", likLonn);     //Skriver ut om lønnen er lik
    
    return 0;
}
