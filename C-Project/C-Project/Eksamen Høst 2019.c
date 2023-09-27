/**
 *   Skjelett for eksamen i GrProg (i C), november 2019, oppgave 2.
 *
 *   Programmet holder orden på ansatte på en arbeidsplass, hvilke dager
 *   de (ikke) skal arbeide, og om de har møtt opp eller ei til arbeidet.
 *
 *   @file     Eksamen Høst 2019.c
 *   @author   Eirik Hanasand
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcpy, strlen
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data

#define   MAXDAG        31       ///<  Max. antall dager i en måned.
#define   MAXANSATTE   100       ///<  Max. antall ansatte.
const int STRLEN    =   80;      ///<  Max. tekstlengde.


/**
 *  Ansatt (med navn, mailadresse, mobiltlf og hvordan jobber DENNE måneden).
 */
struct Ansatt {
    char* navn,                  //  Ansattes navn.
        * mail;                  //  Mailadresse.
    int   mobil;                 //  Mobiltelefonnummer.
    char  jobbing[MAXDAG];       //  Jobbingen i løpet av måneden
};                               //    ('-'= nei,  'J'= jobbe,  'M'= møtt)


void skrivMeny(void);
void nyAnsatt(void);                                       //  Oppgave 2A
void ansattLesOgSettData(struct Ansatt* a);                //  Oppgave 2A
void kommerPaaJobb(void);                                  //  (Oppgave 2B)
void ansattAnkommerJobb(struct Ansatt* a);                 //  Oppgave 2B
void oversiktAnsattesJobbing(void);                        //  Oppgave 2C
void ansattSkrivJobbing(const struct Ansatt* a);           //  Oppgave 2C
void endreEnsJobbingEnDag(void);                           //  (Oppgave 2D)
void ansattEndreJobbing(struct Ansatt* a);                 //  Oppgave 2D
void lesJobbingFraFil(const bool lesAlt);                  //  Oppgave 2E
void ansattLesJobbingFraFil(FILE* inn, struct Ansatt* a);  //  Oppgave 2E
void jobbStatistikk(void);                                 //  Oppgave 2F
void lesAnsatteFraFil(void);                               //  Oppgave 2G
void ansattLesFraFil(FILE* inn, struct Ansatt* a);         //  Oppgave 2G


int gAntallAnsatte,                   ///<  Antall ansatte i bruk i 'gAnsatte'.
    gDagNr,                           ///<  Dagens dato.
    gSisteDag;                        ///<  Aktuell måneds dagantall (28-31).
struct Ansatt* gAnsatte[MAXANSATTE];  ///<  Alle de ansatte.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesAnsatteFraFil();                //  Oppgave 2G
    lesJobbingFraFil(false);           //  Oppgave 2E - Henter KUN 'gSisteDag'.
    gDagNr = lesInt("Dato", 1, gSisteDag);  //  Leser dagens dato (1-gSisteDag).

    skrivMeny();
    kommando = lesChar("Ønske");
    kommando = 'F';
    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N': nyAnsatt();                     break;  //  Oppgave 2A
          case 'K': kommerPaaJobb();                break;  //  Oppgave 2B
          case 'O': oversiktAnsattesJobbing();      break;  //  Oppgave 2C
          case 'E': endreEnsJobbingEnDag();         break;  //  Oppgave 2D
          case 'M': lesJobbingFraFil(true);         break;  //  Oppgave 2E
          case 'S': jobbStatistikk();               break;  //  Oppgave 2F
          default:  skrivMeny();                    break;
        }
        kommando = lesChar("Ønske");
    }
//    skrivAnsatteTilFil();       //  Skriver ALLE ansatte tilbake til fil.
    printf("\n\n");
    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN   = Ny ansatt\n");
    printf("\tK   = ansatt Kommer på jobb\n");
    printf("\tO   = Oversikt over alle ansattes jobbing\n");
    printf("\tE   = Endre jobbing for en ansatt på en dag\n");
    printf("\tM   = Månedsskifte (ny jobbplan)\n");
    printf("\tS   = Statistikk over antall dager jobbet/ikke møtt\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny ansatt i datastrukturen.
 *
 *  @see   ansattLesOgSettData(...)
 */
void nyAnsatt() {

    if(gAntallAnsatte < MAXANSATTE) {
    printf("Lager ansatt nr %i", gAntallAnsatte+1);
    gAnsatte[gAntallAnsatte] = (struct Ansatt*) malloc(sizeof(struct Ansatt));
        ansattLesOgSettData(gAnsatte[gAntallAnsatte]);
        gAntallAnsatte++;
    }else{
    printf("Det er ikke plass til flere ansatte! (%i/%i)", gAntallAnsatte,
                MAXANSATTE);
    }

}


/**
 *  Oppgave 2A - Leser inn og initierer data om EN ansatt.
 *
 *  @param  a - Den ansatte som får innlest/initiert sine data
 */
void ansattLesOgSettData(struct Ansatt* a) {

    for(int i = 0; i < gDagNr-2; i++) {
        a->jobbing[i] = '-' ;
    }
    
    for(int i = gDagNr-1; i < gSisteDag-1; i++) {
    printf("Skal den ansatte jobbe den %i. ? (J / -)", i);
        a->jobbing[i] = lesChar("");
    }

}


/**
 *  Oppgave 2B - Ansatt har kommet på jobb.
 *
 *  @see   ansattAnkommerJobb(...)
 */
void kommerPaaJobb()  {

    int nr = lesInt("Ansattnr", 1, gAntallAnsatte);  //  Leser aktuelt ansnr.
    ansattAnkommerJobb(gAnsatte[nr - 1]);

}


/**
 *  Oppgave 2B - Registrerer (om mulig) at en ansatt har møtt på jobb.
 *
 *  @param  a - Den ansatte som får registrert at har møtt på jobb
 */
void ansattAnkommerJobb(struct Ansatt* a) {

    if(a->jobbing[gDagNr-1] == 'J'){
    a->jobbing[gDagNr-1] = 'M';
    printf("Oppmøte registrert\n");
    }else if(a->jobbing[gDagNr-1] == '-'){
    printf("Du skal ikke jobbe i dag\n");
    }else if(a->jobbing[gDagNr-1] == 'M'){
        printf("Oppmøte allerede registrert");
    }else{
    printf("Feil! Ulovlig element %c funnet i \"a->jobbing[gDagNr-1]\"",
               a->jobbing[gDagNr-1]);
    }

}


/**
 *  Oppgave 2C - Skriver ALLE de ansattes jobbstatus.
 *
 *  @see   ansattSkrivJobbing(...)
 */
void oversiktAnsattesJobbing()  {

    for(int i = 0; i < gSisteDag; i++) {
    if(i < 10) {
         printf("%i  ", i);
    }else{
         printf("%i ", i);
    }
    }

    for (int i = 0; i < gAntallAnsatte; i++) {
        ansattSkrivJobbing(gAnsatte[i]);
    }
    printf("\n");


}


/**
 *  Oppgave 2C - Skriver EN ansatts navn og jobbestatus.
 *
 *  @param  a - Den ene ansatte som jobbstatus skrives for
 */
void ansattSkrivJobbing(const struct Ansatt* a) {

    printf("\n");
    
    for(int i = 0; i < gSisteDag; i++) {
        printf("%c  ", a->jobbing[i]);
    }
    
    printf("%s", a->navn);

}


/**
 *  Oppgave 2D - Endre en ansatts jobbing.
 *
 *  @see   ansattEndreJobbing(...)
 */
void endreEnsJobbingEnDag() {
    int nr = lesInt("Ansattnr", 1, gAntallAnsatte);   //  Leser aktuelt ansnr.
    ansattEndreJobbing(gAnsatte[nr - 1]);
}


/**
 *  Oppgave 2D - Endrer (om mulig) status for jobbing.
 *
 *  @param  a - Den ansatte som får endret sin jobbing
 */
void ansattEndreJobbing(struct Ansatt* a) {

    int aktuellDag = 0; //Dagen brukeren ønsker å endre på

    printf("Hvilken dag vil du endre? (%i - %i)", gDagNr, gSisteDag);
    aktuellDag = lesInt("", gDagNr, gSisteDag);

    printf("Status for dag %i: %c", aktuellDag, a->jobbing[aktuellDag]);
    
    if(aktuellDag == gDagNr) {
    do{
        a->jobbing[aktuellDag] =
            lesChar("Hva vil du endre til? (J / M / -)");
        }while(
        a->jobbing[aktuellDag] == 'J' || a->jobbing[aktuellDag] == 'M' ||
        a->jobbing[aktuellDag] == '-'
        );
    }else{
        do{
        a->jobbing[aktuellDag] = lesChar("Hva vil du endre til? (J / -)");
        }while(
               a->jobbing[aktuellDag] == 'J' ||  a->jobbing[aktuellDag] == '-'
        );
       
        printf("Jobbstatus for dag %i endret til %c", aktuellDag,
                a->jobbing[aktuellDag]);
    }
}


/**
 *  Oppgave 2E - Jobbingen for NESTE måned leses inn i den
 *               allerede eksisterende datastrukturen.
 *
 *  @param   lesAlt - Om HELE filens innhold skal leses, eller KUN 'gSisteDag'
 *  @see     ansattLesJobbingFraFil(...)
 */
void lesJobbingFraFil(const bool lesAlt) {
    FILE* innfil = fopen("EX_H19_JOBBING.DTA", "r");
    int ansNr;

    if(innfil){
        fscanf(innfil, "%i", &gSisteDag);
        getc(innfil);
        
        if(lesAlt) {
            fscanf(innfil, "%i", &gSisteDag);
            getc(innfil);
            printf("Dette vil overskrive all data.\n");
            if(lesChar("Trykk 'J' for å fortsette") == 'J'){
                fscanf(innfil, "%i", &ansNr);
                
                while (feof(innfil) && ansNr >= 0 && ansNr < gAntallAnsatte) {
                    fscanf(innfil, "%i", &ansNr);
                    ansattLesJobbingFraFil(innfil, gAnsatte[ansNr]);
                    getc(innfil);
                }
                
                printf("Nye jobbdata lest inn fra filen 'JOBBING.DTA'.\n");
                
            }else{
                printf("Avbrøt overskriving.\n");
            }
        }
    }else{
        printf("Fant ikke filen 'EX_H19_JOBBING.DTA'!");
    }
    
    fclose(innfil);
}


/**
 *  Oppgave 2E - Leser KUN jobbstatus for EN ansatt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  a   - Structen som får innlest sine data
 */
void ansattLesJobbingFraFil(FILE* inn, struct Ansatt* a) {
    
    for(int i = 0; i < gSisteDag; i++){
        fscanf(inn, " %c", &a->jobbing[i]);
    }
    
}


/**
 *  Oppgave 2F - Statistikk over de ansattes jobbing.
 */
void jobbStatistikk() {
    int mott = 0, ikkeMott = 0, arbeidsDager = 0; //Antall dager møtt opp, ikke møtt opp,
    //og antall dager personen skal arbeide ift vaktplanen.
    float oppmoteProsent = 0; //Oppmøteprosent for hver ansatt

    printf("Oppmøtestatistikk\n");

    for(int i = 0; i < gAntallAnsatte; i++) {
        mott = 0;
        arbeidsDager = 0;
        ikkeMott = 0;
        
        for(int j = 0; j < gDagNr; j++){
            if(gAnsatte[i]->jobbing[j] == 'M'){
            mott++;
            arbeidsDager++;
            }else if(gAnsatte[i]->jobbing[j] == 'J'){
            ikkeMott++;
            arbeidsDager++;
            }
        }
    
    oppmoteProsent = (float)mott / arbeidsDager;

    printf("Ansattnr: %i, navn: %s\n", i, gAnsatte[i]->navn);

    printf("Oppmøte: %i/%i dager.\t Ikke møtt: %i dager.\t Oppmøteprosent: %.2f\n",
               mott, arbeidsDager, ikkeMott, oppmoteProsent);
    }
}


/**
 *  Oppgave 2G - Leser ALLE ansatte fra fil.
 *
 *  @see     ansattLesFraFil(...)
 */
void lesAnsatteFraFil() {
    
    FILE* innfil = fopen("EX_H19_ANSATTE.DTA", "r");

    if(innfil) {
        fscanf(innfil, "%i", &gAntallAnsatte);
        getc(innfil);

        for(int i = 0; i < gAntallAnsatte; i++) {
            gAnsatte[i] = (struct Ansatt*) malloc(sizeof(struct Ansatt));
            ansattLesFraFil(innfil, gAnsatte[i]);
        }
            
        printf("\nAlle ansatte er lest inn fra filen 'EX_H19_ANSATTE.DTA'!\n\n");
        fclose(innfil);
    }else{
        printf("Fant ikke filen 'EX_H19_ANSATTE.DTA'!\n");
    }
}

/**
 *  Oppgave 2G - Leser ALT om EN ansatt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  a   - Structen som får innlest sine data
 */
void ansattLesFraFil(FILE* inn, struct Ansatt* a)  {
    char buffer[STRLEN];

    fscanf(inn, "%i %s", &a->mobil, buffer);
    a->mail = (char*) malloc((strlen(buffer)+1) * sizeof(char));
    strcpy(a->mail, buffer);
    fgetc(inn);

    fgets(buffer, STRLEN, inn); buffer[strlen(buffer) -1] = '\0';
    a->navn = (char*) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(a->navn, buffer);

    for(int i = 0; i < MAXDAG; i++)
        fscanf(inn, " %c", &a->jobbing[i]);
    getc(inn)
    
}
