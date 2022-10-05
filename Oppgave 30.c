//
//  Oppgave 30.c
//  Basics
//
//  Created by Eirik Hanasand on 05/10/2022.
//

/**
 *  Denne filen inneholder et system for å leie ut traller, se oversikt over utleide eller ledige traller, mulighet
 *  for å levere inn traller, se alle brukere og avslutte programmet.
 *
 *  @file       Oppgave 30.c
 *  @date       5. Okt 2022
 *  @version    1
 *  @author     Eirik Hanasand
 */

#include "Oppgave 30.h"             //H fil for brukte structer h filer

const int MAXTRALLER =  30;         //Max antall traller
const int STRLEN = 80;              //Maks lengde på leietakers navn
struct Tralle gTraller[MAXTRALLER]; //Struct for trallenavn, trallenr, structnr
int gAntallUtlaant   =   0;         //Antall traller utlånt

void empty(void);                   //Setter alle traller til false
void finnlaaner(void);              //Finne låner basert på navn
void innlevering(void);             //Innlevere traller
int lesTall(void);                 //Leser inn tall
char lesKommando(void);             //Leser inn en enkeltbokstav
void ledige(void);                  //Viser alle ledige traller
void meny(void);                    //Skriver meny og tar imot valg
void oversikt(void);                //Oversikt over utlånte traller
void utlaan(void);                  //Låner ut tralle til person

/**
    Hovedprogram som viser oversikt over traller, lar bruker leie ut traller, se ledige traller, innlevere traller
    og mulighet for å finne låner basert på navn.
 */
int main(){
    char valg = 0;
    empty();
    do {
        meny();
        valg = lesKommando();
        getchar();
        switch (valg) {
            case 'O': oversikt();                        break;  //Se utleide
            case 'L': ledige();                          break;  //Se ledige
            case 'U': utlaan();                          break;  //Leie ut
            case 'I': innlevering();                     break;  //Levere inn
            case 'F': finnlaaner();                      break;  //Finne låner
            case 'Q':                                    break;  //Avslutt
            default : printf("Ulovlig valg '%c'", valg); break;  //Ulovlig input
        }
    } while (valg != 'Q');
    return 0;
}

//Lese inn enkeltbokstaver
char lesKommando(){
    char valg = 0;
    valg = getchar();
    valg = toupper(valg);
    return valg;
}
//Lese inn tall
int lesTall(void){
    int trallenr = 0;
    scanf("%i", &trallenr);
    return trallenr;
}

//Viser alle utleide traller, melding om alle er ledige
void oversikt(){
    if (gAntallUtlaant == 0) {
        printf("Alle traller er ledige!\n");
    }else{
        printf("Utlånte traller:\n");
        for(int i = 0; i <= MAXTRALLER; i++){
            if (gTraller[i].utlaant == 1) {
                printf("Trallenr: %i, Leietaker: %s, Tlfnr: %i\n", i,
                       gTraller[i].navn, gTraller[i].tlfNr);
            }
        }
    }
}

//Viser alle ledige traller, melding om alle eller ingen er ledige
void ledige(){
    if(gAntallUtlaant == 0){
        printf("Alle traller er ledige!\n");
    }else if (gAntallUtlaant == 30) {
        printf("Alle trallene er utlånt!\n");
    }else{
        printf("Ledige:\n");
        for(int i = 0; i < MAXTRALLER; i++){
            if (gTraller[i+1].utlaant == 0) {
                printf("Trallenr: %i\n", i+1);
            }
        }
    }
}

/**
    Funksjon for å leie traller, feilmelding om ingen traller er ledige eller om man prøver å leie en tralle
    som allerede er utleid. Dersom alt er ok blir man spurt om trallenr, navn og tlfnr som deretter lagres
 */
void utlaan(){
    int i = 0;
    if (gAntallUtlaant == MAXTRALLER) {
        printf("Alle trallene er utlånt!\n");
    }else{
        printf("Hvilken tralle skal leies ut?\n");
        i = lesTall();
        
        if (gTraller[i].utlaant == 1) {
            printf("Denne trallen er allerede utlånt!\n");
        }else{
            gAntallUtlaant++;
            gTraller[i].utlaant = 1;
            printf("Navn på leietaker: ");
            getchar();
            fgets(gTraller[i].navn, STRLEN, stdin);
            gTraller[i].navn[strlen(gTraller[i].navn)-1] = '\0';
            printf("Leietakers tlfnr : ");
            gTraller[i].tlfNr = lesTall();
            getchar();
            printf("Trallenr %i utlånt til %s, Tlfnr: %i\n", i, gTraller[i].navn,
                   gTraller[i].tlfNr);
        }
    }
}

/**
    Innlevering av traller, feilmelding om ingen er utlånt eller den spesifiserte trallen ikke er utleid
 */
void innlevering(){
    int i = 0;
    if (gAntallUtlaant == 0) {
        printf("Ingen traller er utlånt!\n");
    }else{
        printf("Hvilken tralle skal leveres inn?\n");
        i = lesTall();
        if (gTraller[i].utlaant == 1) {
            getchar();
            gAntallUtlaant--;
            strcpy(gTraller[i].navn, "0");
            gTraller[i].utlaant = 0;
            gTraller[i].tlfNr = 0;
            printf("Trallenr %i innlevert!\n", i);
        }else{
            printf("Denne trallen er ikke utleid!\n");
            getchar();
        }
    }
}

/**
    Finn låner basert på søk på navn. Feilmelding om ingen traller er utleid eller søket ikke ga noen resultater.
    Finnes det resultater listes alle resultater opp.
 */
void finnlaaner(){
    int funn = 0;
    if (gAntallUtlaant == 0) {
        printf("Ingen traller utleid!\n");
    }else{
        char person[STRLEN];
        printf("Søk etter person:\n");
        fgets(person, STRLEN, stdin);
        person[strlen(person)-1] = '\0';
        for(int i = 0; i <= MAXTRALLER; i++){
            if (!strcmp(gTraller[i].navn, person)) {
                funn++;
            }
        }
       
        if(funn > 0){
            printf("Funn:\n");
            for(int i = 0; i <= MAXTRALLER; i++){
                if (!strcmp(gTraller[i].navn, person)) {
                    printf("Trallenr: %i, Trallenavn: %s, Tlfnr: %i\n",
                           i, gTraller[i].navn, gTraller[i].tlfNr);
                }
            }
        }else{
            printf("Denne personen leier ingen traller.\n");
        }
    }
}

//Skriver ut meny og returnerer hva brukeren ønsker å gjøre
void meny(){
    printf("Hva vil du gjøre? (O, L, U, I, F, Q)\n");
    printf("O - Oversikt\n");
    printf("L - Ledige\n");
    printf("U - Utlån\n");
    printf("I - Innlevering\n");
    printf("F - Finn låner\n");
    printf("Q - Avslutt");
}

//Funksjon som setter alle traller til ledige
void empty(){
    for (int i = 0; i < MAXTRALLER; i++) {
        gTraller[i].utlaant = 0;
    }
}
