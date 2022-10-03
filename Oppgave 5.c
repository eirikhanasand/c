//
//  Oppgave 5.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//

#include <stdio.h>                                  //Inkludert for printf

int main(){
//  Del A
    int lengde = 0;                                 //Lengen av kvadratet
    int bredde = 0;                                 //Bredden av kvadratet
    int høyde = 0;
    int resultat;                                   //Resultatet
    
    printf("Skriv inn lengde, høyde og bredde\n");  //Ber brukeren skrive inn lengde, høyde og bredde
    scanf("%i %i %i", &lengde, &bredde, &høyde);    //Tar imot lengde høyde og bredde fra brukeren
    
    resultat = lengde * bredde * høyde;             //Regner ut resultatet
    printf("%i er volumet\n", resultat);                      //Skriver ut resultatet
    
    
    
    //  Del B
    char rarvariabel[10] = "19600406";              //Rarvariabel
    for (int i = 0; i < 4; i++) {                   //Loop som går gjennom de 4 første karakterene i rarvariabel
        printf("%c", rarvariabel[i]);               //Skriver ut gjeldene skuff i rarvariabel
    }
    
    printf("\n");                                   //Starter en ny linje
    
    return 0;                                       //Avslutter programmet
}
