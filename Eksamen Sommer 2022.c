/**
 *   Skjelett kontinuasjonseksamen i GrProg (i C), august 2022, oppgave 2.
 *
 *   Programmet holder orden på ulike ting/produkt/saker som
 *   må handles/er handlet inn ifm oppussing (i et hus/leilighet/hybel).
 *
 *   @file     EX_S22_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen, strstr
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXTING        100     ///<  Max. antall ting/produkt som trengs.
const int STRLEN  =       80;    ///<  Max. tekstlengde.


/**
 *  Enhet (ugyldig/udefinert, centimeter, meter, kvadratmeter, stykk, liter).
 */
enum Enhet { ugyldig, cm, m, kvm, stk, l};


/**
 *  Ting (med navn, antall, pris og enhetsmål).
 */
struct Ting {
  char* navn;                    //  Tingens:  - navn
  float antall,                  //            - antallet av tingen
        pris;                    //            - pris pr.enhet
  enum  Enhet enhet;             //            - enhetsmål
};


char  charFraEnum(const enum Enhet enhet);                     //  |
enum  Enhet enumFraChar(const char tegn);                      //  | Ferdig-
char  lesEnhetsBokstav();                                      //  | laget.
void  skrivMeny();                                             //  |
void  nyTing();                                                //  Oppgave 2A
void  tingLesData(struct Ting* ting);                          //  Oppgave 2A
void  skrivAlleTingene();                                      //  Oppgave 2B
void  tingSkrivData(const struct Ting* ting);                  //  Oppgave 2B
void  endrePris();                                             //  Oppgave 2C
void  tingEndrePris(struct Ting* ting);                        //  Oppgave 2C
void  skrivAlleMedTekst();                                     //  Oppgave 2D
bool tingMedTekst(const struct Ting* ting, const char tekst[]);//  Oppgave 2D
void  totalKostnad();                                          //  Oppgave 2E
float tingHentKostnad(const struct Ting* ting);                //  Oppgave 2E
void  skrivTilFil();                                           //  Oppgave 2F
void  tingSkrivTilFil(FILE* ut, const struct Ting* ting);      //  Oppgave 2F
void  lesFraFil();                                             //  Oppgave 2G
void  tingLesFraFil(FILE* inn, struct Ting* ting);             //  Oppgave 2G


int    gAntallTing;                     ///<  Antall ting hittil registrert.
struct Ting* gTing[MAXTING];            ///<  Alle tingene.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                             //  Oppgave 2G

    skrivMeny();
    kommando = lesChar("\nØnske");

    while (kommando != 'Q') {
        switch (kommando) {
          case 'N':  nyTing();                     break;    //  Oppgave 2A
          case 'A':  skrivAlleTingene();           break;    //  Oppgave 2B
          case 'E':  endrePris();                  break;    //  Oppgave 2C
          case 'I':  skrivAlleMedTekst();          break;    //  Oppgave 2D
          case 'T':  totalKostnad();               break;    //  Oppgave 2E
          default:   skrivMeny();                  break;
        }
        kommando = lesChar("\nØnske");
    }

    skrivTilFil();                                           //  Oppgave 2F

    return 0;
}


/**
 *  Gjør om en lovlig enum-verdi til ett tegn/bokstav.
 *
 *  @param    enhet  -  Enum-verdi som skal konverteres til bokstav/tegn
 *  @return   En bokstav (C, M, K, S, L) ut fra en enum-verdi
 */
char charFraEnum(const enum Enhet enhet)  {
  switch (enhet)  {                      //  Ut fra enum-verdi returneres
    case  cm:   return 'C';              //    aktuell bokstav:
    case   m:   return 'M';
    case kvm:   return 'K';
    case stk:   return 'S';
    case   l:   return 'L';
  }
}


/**
 *  Gjør om en (lovlig) bokstav til en aktuell enum-verdi.
 *
 *  @param    tegn  -  Bokstav/tegn som skal konverteres til enum-verdi
 *  @return   Enum-verdi ut fra en bokstav/tegn
 */
enum Enhet enumFraChar(const char tegn)  {
  switch (tegn)  {
    case 'C':  return  cm;               //  Ut fra bokstav returneres
    case 'M':  return   m;               //    aktuell enum-verdi:
    case 'K':  return kvm;
    case 'S':  return stk;
    case 'L':  return   l;
    default:   printf("\n\tUgyldig bokstav for Enhet!\n\n");
               return ugyldig;
  }
}


/**
 *  Leser korrekt en lovlig bokstav for en Enhet, og returnerer denne.
 *
 *  @return   En bokstav (C, M, K, S, L) som står for en enhetsbetegnelse
 */
char lesEnhetsBokstav()  {
  char tegn;
  do  {                                     //  Sikrer LOVLIG bokstav-verdi:
    tegn = lesChar("\tEnhetstype (C(m), M, K(vm), S(tk), L)");
  } while (tegn != 'C' && tegn != 'M' &&
           tegn != 'K' && tegn != 'S' && tegn != 'L');
  return tegn;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
  printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
  printf("\tN   = Ny ting som skal kjøpes\n");
  printf("\tA   = skriv Alle tingene som er kjøpt/skal kjøpes\n");
  printf("\tE   = Endre/legge inn prisen for en ting\n");
  printf("\tI   = skriv alle tingene som Inneholder en tekst i navnet\n");
  printf("\tT   = Totalkostnad (så langt) for alt handlet/oppussingen\n");
  printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny ting i datastrukturen.
 *
 *  @see   tingLesData(...)
 */
void  nyTing()  {
    if(gAntallTing < MAXTING){
        printf("Legger inn ting %i", gAntallTing);
        gTing[gAntallTing] = (stuct Ting*) malloc(sizeof(struct Ting));
        tingLesData(gTing[i]);
        gAntallTing++;
    }else{
        printf("Beklager, det er ikke plass til flere ting.\n");
    }
}


/**
 *  Oppgave 2A - Leser inn ALLE datamedlemmer i EN ting.
 *
 *  @param   ting -  Tingen som får innlest sine data
 *  @see     enumFraChar(...)
 */
void  tingLesData(struct Ting* ting)  {
    char enhet;
    ting->navn = lagOgLesText("Navn på tingen:\n");
    ting->antall = lesFloat("Antall av tingen:\n", 1, 1000);
    ting->pris = lesFloat("Pris på tingen:\n", 1, 10000);
    do(
        enhet = lesChar("Skriv inn enhetsmål:\n");
    )while{charFraEnum(enhet) == ugyldig}
    ting->enhet = enhet;
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE tingene.
 *
 *  @see   tingSkrivData(...)
 */
void  skrivAlleTingene()  {

    if(gAntallTing > 0){
        for(int i = 0; i < gAntallTing; i++){
            printf("Skriver ting %i", i);
            tingSkrivData(gTing[i]);
        }
    }else{
        printf("Vennligst legg inn ting først.\n");
    }

}


/**
 *  Oppgave 2B - Skriver ALT om EN ting ut på skjermen.
 *
 *  @param   ting  -  Tingen som skrives ut
 *  @see     charFraEnum(...)
 */
void  tingSkrivData(const struct Ting* ting)  {

    printf("Navn: %s\t Antall: %f\t Pris: %f\t Enhet: %s\n", 
    ting->navn, ting->antall, ting->pris, charFraEnum(ting->enhet));
    
}


/**
 *  Oppgave 2C - Endre en tings pris.
 *
 *  @see   tingEndrePris(...)
 */
void  endrePris()  {
    int aktuellTing;
    if(gAntallTing > 0){
        aktuellTing = lesInt("Hvilken ting vil du endre pris for?", 1, gAntallTing);
        tingEndrePris(gTing[aktuellTing-1]);
    }else{
        printf("Vennligst legg inn ting først.\n");
    }

}


/**
 *  Oppgave 2C - Leser inn EN tings nye pris.
 *
 *  @param    ting  -  Tingen som får endret sin pris
 */
void  tingEndrePris(struct Ting* ting)  {

    printf("Nåværende pris: %f\n", ting->pris);
    ting->pris = lesFloat("Skriv inn ønsket pris:", 1, 10000);
    printf("Endret pris til %f\n", ting->pris);
}


/**
 *  Oppgave 2D - Skriver ALLE tingene som har en gitt (sub)tekst i 'navn'.
 *
 *  @see   tingMedTekst(...)
 *  @see   tingSkrivData(...)
 */
void  skrivAlleMedTekst()  {
    char valgtNavn; 
    bool funn = false;
    if(gAntallTing > 0){
        valgtNavn = lagOgLesText("Søk:\n");

        for(int i = 0; i < gAntallTing; i++){
            funn = tingMedTekst(gTing[i], valgtNavn);
            if(funn){
                tingSkrivData(gTing[i]);
            }
        }

    }else{
        printf("Beklager, det finnes ingen ting.\n");
    }

}


/**
 *  Oppgave 2D - Returnerer om en ting har en gitt tekst i 'navn' eller ei.
 *
 *  @param    ting   -  Tingen som skal sjekkes for om inneholder 'tekst'
 *  @param    tekst  -  Teksten det sjekkes for om er i tingens 'navn'
 *  @return   Om tingens 'navn' inneholder 'tekst' eller ei
 */
bool tingMedTekst(const struct Ting* ting, const char tekst[])  {
    
    if(strstr(ting->navn, tekst)){
        return true;
    }else{
        return false;
    }
}


/**
 *  Oppgave 2E - Beregner og skriver TOTALkostand for ALLE tingene HITTIL.
 *
 *  @see   tingHentKostnad((...)
 */
void  totalKostnad()  {
    float totalPris;
    int antallTing;
    int manglerPris;
    if(gAntallTing > 0){
        for(int i = 0; i < gAntallTing; i++){
            if(gTing[i]->pris > 0 && gTing[i]->antall > 0){
                totalPris += tingHentKostnad(gTing[i]);
                antallTing++;
            }else{manglerPris++;}
        }
        printf("Totalpris: %f\t Antall ting: %i\t Ting uten pris: %i\n", 
                totalPris, antallTing, manglerPris);
    }else{
        printf("Vennligst legg inn ting først.\n");
    }

}


/**
 *  Oppgave 2E - Regner ut og returnerer EN tings TOTALE kostnad/pris.
 *
 *  @param    ting  -  Tingen som får sin totalkostnad beregnet
 *  @return   Tingens totale kostnad
 */
float tingHentKostnad(const struct Ting* ting)  {
    return(gTing[i]->pris * gTing[i]->antall);
}


/**
 *  Oppgave 2F - Skriver ALLE tingene til fil.
 *
 *  @see   tingSkrivTilFil(...)
 */
void skrivTilFil() {
    FILE* utfil = fopen("TING.DTA", "w");
    
    if(utfil){
        fprintf(utfil, "%i\n", gAntallTing);

        for(int i = 0; i < gAntallTing; i++){
            tingSkrivTilFil(gTing[i]);
        }
    }else{
        printf("Kunne ikke skrive til fil TING.DTA\n");
    }

    fclose(utfil);
}


/**
 *  Oppgave 2F - Alle EN tings data skrives ut på fil.
 *
 *  @param   ut    -  Filen det skal skrives til
 *  @param   ting  -  Tingen som skrives til fil
 *  @see     charFraEnum(...)
 */
 void  tingSkrivTilFil(FILE* ut, const struct Ting* ting)  {

   fprintf(ut, "%s %f %f %c\n", ting->navn, ting->antall, ting->pris, charFraEnum(ting->enhet));

}

/**
 *  Oppgave 2G - Leser ALLE tingene fra fil.
 *
 *  @see   tingLesFraFil(...)
 */
void  lesFraFil()  {

    FILE* innfil = fopen("TING.DTA", "r");

    if(innfil){
        fscanf(innfil, "%i", &gAntallTing);
        getc(innfil);
        for(int i = 0; i < gAntallTing; i++){
            gTing[i] = (struct Ting*) malloc(sizeof(struct Ting));
            tingLesFraFil(innfil, gTing[i]);
        }
        printf("%i ting innlest fra TING.DTA\n", gAntallTing);
    }else{
        printf("Kunne ikke åpne TING.DTA\n");
    }

}


/**
 *  Oppgave 2G - Leser ALT om EN ting fra fil.
 *
 *  @param   inn   -  Filen det skal leses fra
 *  @param   ting  -  Tingen som får innlest sine data
 *  @see     enumFraChar(...)
 */
void  tingLesFraFil(FILE* inn, struct Ting* ting)  {
    char buffer[STRLEN];    
    
    fgets(buffer, STRLEN, inn);     buffer[strlen(buffer)-1] = '\0';
    ting->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(ting->navn, buffer);
    fgetc(inn);

    fscanf(inn, "%f", &ting->antall);
    fgetc(inn);

    fscanf(inn, "%f", &ting->pris);
    fgetc(inn);

    s->enhet = enumFraChar(fgetc(inn));
    fgetc(inn); //Fanger avsluttende line break
}