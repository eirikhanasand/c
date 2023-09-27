/**
 *   Skjelett for kontinuasjonseksamen i GrProg (i C), august 2020, oppgave 2.
 *
 *   Programmet holder orden på hvilke episoder en person
 *   har sett i de ulike sesongene av en lang, lang serie.
 *
 *   @file     EX_S20_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcpy, strlen, strstr
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXSESONG    100       ///<  Max. antall sesonger.
#define   MAXEPISODE    20       ///<  Max. antall episoder EN sesong.
const int STRLEN = 60;           ///<  Max. tekstlengde.


/**
 *  Sesong (med tittel, antall episoder og hvilke som er sett).
 */
struct Sesong {
    char* tittel;                //  Sesongens tittel/emne.
    int   antallEpisoder;        //  Antall episoder i vedkommende sesong.
    bool  sett[MAXEPISODE];      //  Sett episode eller ei.
};


void skrivMeny();
void nySesong();                                           //  Oppgave 2A
void sesongLesData(struct Sesong* s);                      //  Oppgave 2A
void skrivAlleSesongene();                                 //  Oppgave 2B
void sesongSkrivData(const struct Sesong* s);              //  Oppgave 2B
void settEnEpisode();                                      //  Oppgave 2C
void sesongSettEpisode(struct Sesong* s);                  //  Oppgave 2C
void skrivEnNavngittSesong();                              //  Oppgave 2D
void sesongerProsentvisSett();                             //  Oppgave 2E
void skrivTilFil();                                        //  Oppgave 2F
void sesongSkrivTilFil(FILE* ut, const struct Sesong* s);  //  Oppgave 2F
void lesFraFil();                                          //  Oppgave 2G
void sesongLesFraFil(FILE* inn, struct Sesong* s);         //  Oppgave 2G


int    gAntallSesonger;               ///<  Antall sesonger hittil registrert.
struct Sesong* gSesonger[MAXSESONG];  ///<  Alle sesongene.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                            //  Oppgave 2G
    skrivMeny();
    kommando = lesChar("Ønske");

    while (kommando != 'Q') {
        switch(kommando) {
           case 'N': nySesong();                     break;  //  Oppgave 2A
           case 'A': skrivAlleSesongene();           break;  //  Oppgave 2B
           case 'E': settEnEpisode();                break;  //  Oppgave 2C
           case 'S': skrivEnNavngittSesong();        break;  //  Oppgave 2D
           case 'P': sesongerProsentvisSett();       break;  //  Oppgave 2E
           default:  skrivMeny();                    break;
        }
        kommando = lesChar("Ønske");
    }

    skrivTilFil();                                          //  Oppgave 2F
    printf("\n\n");
    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN   = Ny sesong\n");
    printf("\tA   = skriv Alle sesongene\n");
    printf("\tE   = sett en ny Episode\n");
    printf("\tS   = skriv en navngitt Sesong\n");
    printf("\tP   = sesonger Prosentvis sett\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny sesong i datastrukturen.
 *
 *  @see   sesongLesData(...)
 */
void nySesong() {

    if(gAntallSesonger < MAXSESONG){
        printf("Legger inn sesong %i", gAntallSesonger+1);

        gSesonger[gAntallSesonger] = (struct Sesong*) malloc(sizeof(struct Sesong));

        sesongLesData(gSesonger[gAntallSesonger]);
        gAntallSesonger++;
	}else{
		printf("Beklager, det er ikke plass til flere sesonger\n");
	}
}


/**
 *  Oppgave 2A - Leser inn relevante data og nullstiller andre.
 *
 *  @param  s -  Sesongen som får innlest/initiert sine data
 */
void sesongLesData(struct Sesong* s) {

    s->tittel = lagOgLesText("Hva heter sesongen?\n");
    s->antallEpisoder = lesInt("Hvor mange episoder?\n", 0, MAXEPISODE);
    for(int i = 0; i < s->antallEpisoder; i++){
        s->sett[i] = false;
    }
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE sesonger.
 *
 *  @see   sesongSkrivData(...)
 */
void skrivAlleSesongene() {
    for(int i = 0; i < gAntallSesonger; i++){
        sesongSkrivData(gSesonger[i]);
    }
}


/**
 *  Oppgave 2B - Skriver ALT om EN sesong ut på skjermen.
 *
 *  @param  s - Sesongen som skrives ut
 */
void sesongSkrivData(const struct Sesong* s)  {

    printf("Tittel: %s \t Antall episoder: %i \t Sett:\n", s->tittel, s->antallEpisoder);

    for(int i = 0; i < s->antallEpisoder; i++){
        printf("%2i ", i);
    }
    printf("\n");

    for(int i = 0; i < s->antallEpisoder; i++){
        if(s->sett[i]){
            printf(" X ");
        }else{
            printf(" - ");
        }
    }
    printf("\n");

}


/**
 *  Oppgave 2C - Sett EN episode en gitt sesong.
 *
 *  @see   sesongSettEpisode(...)
 */
void settEnEpisode() {
    int valgtSesong = 0;

    valgtSesong = lesInt("Velg sesong:\n", 0, gAntallSesonger);

    sesongSettEpisode(gSesonger[valgtSesong]);

}


/**
 *  Oppgave 2C - Registrerer (om mulig) at EN episode er sett.
 *
 *  @param  s - Sesongen det er sett EN ny episode
 */
void sesongSettEpisode(struct Sesong* s) {
    int valgtEpisode = 0;
    valgtEpisode = lesInt("Velg episode: \n", 0, s->antallEpisoder);

    if(!s->sett[valgtEpisode]){
        s->sett[valgtEpisode] = true;
        printf("Registrerte episode %i som sett.\n", valgtEpisode);
    }else{
        printf("Denne episoden er allerede registrert som sett\n");
    }
}


/**
 *  Oppgave 2D - Skriver navngitt(e) sesong(er).
 *  @see sesongSkrivData(...)
 */
void skrivEnNavngittSesong() {
    char* valg;
    char* resultat;
    int funn = 0;
    valg = lagOgLesText("Skriv inn tittel:\n");

    if(gAntallSesonger > 0){
        for(int i = 0; i < gAntallSesonger; i++) {
            resultat = strstr(gSesonger[i]->tittel ,valg);
            if(resultat != NULL){
                funn++;
                sesongSkrivData(gSesonger[i]);
            }
        }

    if(funn > 0) {
        printf("Skrev ut all informasjon om %i matchende sesonger\n");
    }else{
        printf("Fant ingen matchende sesonger.\n");
    }

    }else{
        printf("Det finnes ingen sesonger.\n");
    }
    
}


/**
 *  Oppgave 2E - Skriver % sett av hver sesong, og den mest sette sesongen.
 *  @see finnProsent(...)
 */
void sesongerProsentvisSett() {
    int hoyesteProsent = 0;
    int mestSett = 0;

    if(gAntallSesonger > 0){
        for(int i = 0; i < gAntallSesonger; i++){
            printf("Prosent sett av sesong:");
            printf("%i: %i", i, finnProsent(gSesonger[i]));

            if(finnProsent(gSesonger[i]) > hoyesteProsent){
                hoyesteProsent = finnProsent(gSesonger[i]);
                mestSett = i;
            }
        }

        printf("Du har sett mest av sesong %i (%s) - %i%% sett.", mestSett, gSesonger[mestSett->tittel], hoyesteProsent);

    }else{
        printf("Beklager, det finnes ingen sesonger å skrive ut.\n");
    }

}

/**
 *  Oppgave 2E - Henter % sett for hver sesong
 */
int finnProsent(struct Sesong* s) {
    int sett = 0;
    int prosent = 0;
    for(int i = 0; i < s->antallEpisoder; i++){
        if(s->sett[i]){sett++;}
    }

    prosent = (sett/s->antallEpisoder*100);

    return prosent;
}

/**
 *  Oppgave 2F - Skriver ALLE sesongene til fil.
 *
 *  @see   sesongSkrivTilFil(...)
 */
void skrivTilFil() {
    FILE* utfil = fopen('SESONGER.DTA');

    if(utfil){
        fprintf("%i\n", gAntallSesonger);
        for(int i = 0; i < gAntallSesonger; i++){
        sesongSkrivTilFil(utfil, gSesonger[i]);
        }
    }else{
        printf("Kunne ikke skrive til SESONGER.DTA filen.\n");
    }
    
    fclose(utfil);
}

/**
 *  Oppgave 2F - Alle EN sesongs data skrives ut på fil.
 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   s   - Sesongen som skrives til fil
 */
void sesongSkrivTilFil(FILE* ut, const struct Sesong* s) {

    fprintf(ut, "%s %i\n", s->tittel, s->antallEpisoder);
    for(int i = 0; i < s->antallEpisoder; i++){
        fprintf(ut, "%i ", s->sett[i]);
    }

    fprintf(ut, "\n");
}


/**
 *  Oppgave 2G - Leser ALLE sesongene fra fil.
 *
 *  @see     sesongLesFraFil(...)
 */
void lesFraFil() {

    FILE* innfil = fopen('SESONGER.DTA');

    if(innfil){
        fscanf(innfil, "%i", &gAntallSesonger);
        getc(innfil);

        for(int i = 0; i < gAntallSesonger; i++) {
            gSesonger[i] = (struct Sesong*) malloc(sizeof(struct Sesong));
            sesongLesFraFil(innfil, gSesonger[i]);
        }
        printf("Sesonger innlest fra SESONGER.DTA\n");
    }else{
        printf("Kunne ikke lese inn fra SESONGER.DTA filen\n");
    }
    
}


/**
 *  Oppgave 2G - Leser ALT om EN sesong fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  s   - Sesongen som får innlest sine data
 */
void sesongLesFraFil(FILE* inn, struct Sesong* s) {
    char buffer[STRLEN];

    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    s->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(s->navn, buffer);
    fgetc(inn);

    fscanf(inn, "%i", &s->antallEpisoder);
    fgetc(inn);

    for(int i = 0; i < antallEpisoder; i++){
       fscanf(inn, "%i", &s->sett[i]); 
       fgetc(innfil);
    }
}
