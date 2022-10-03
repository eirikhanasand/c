//
//  makeuser.c
//  Basics
//
//  Created by Eirik Hanasand on 29/09/2022.
//

#include <stdio.h>                          //Brukes til bl.a. print
#include <ctype.h>                          //Brukes til bl.a. toupper
#include <stdbool.h>                        //Brukes til bl.a. utsagn
#include <string.h>                         //Brukes til bl.a. strcmp

const int STRLEN = 80;                      //Maks lengde input
const int MAXBRUKERE = 20;                  //Maks antall brukere

int main(){
    char brukerNavn[MAXBRUKERE][STRLEN]; //Array for brukere
    char brukerPass[MAXBRUKERE][STRLEN]; //Array for passord
    char valg;                           //Hva brukeren ønsker å gjøre
    int antBrukere = 0;                  //Antall brukere i systemet
    
    //Brukes for å sjekke brukernavnet
    bool harMellomrom = false;
    
    //Sjekker om det er plass til flere brukere
    if (antBrukere < MAXBRUKERE) {
        do{
            harMellomrom = 0;
            printf("Velg brukernavn:\n");       //Asking for username
            gets(brukerNavn[antBrukere]);        //Getting username
                if (strchr(brukerNavn[antBrukere], ' ') != 0){
                    printf("Brukeravn kan ikke inneholde mellomrom!\n");
                    harMellomrom++;
                }
            }while(harMellomrom > 0);
        
        do{
            do{
                harMellomrom = 0;
                printf("Enter Password:\n");       //Asking for username
                gets(brukerPass[antBrukere]);        //Getting username

                    if (strchr(brukerPass[antBrukere], ' ') != 0){
                        printf("Password contains spaces\n");
                        harMellomrom++;
                    }
            }while(harMellomrom > 0);
            
            printf("Everything worked!\n");
            
            //Looper gjennom alle tegn i passordet
            for (int i = 0; i <= strlen(brukerPass[antBrukere]); i++) {
                
                //Sjekker at alle tegn er lovlig ift ASCII
                if(isascii(brukerPass[antBrukere][i])){
                    
                    //Sjekker for stor bokstav
                    if(isupper(brukerPass[antBrukere][i])){
                        //Øker harStor (sjekkes senere)
                        harStor++;
                        
                    //Sjekker for liten bokstav
                    }else if(islower(brukerPass[antBrukere][i])){
                        harLiten++;
                        
                    //Sjekker for tall (teller som spesialtegn)
                    }else if(isdigit(brukerPass[antBrukere][i])){
                        harTegn++;
                        
                    //Sjekker for spesialtegn
                    }else if(ispunct(brukerPass[antBrukere][i])){
                        harTegn++;
                    }
                
                //Feilmelding hvis ulovlig tegn
                }else{printf("Ulovlig tegn:\"%c\"\n",
                             brukerPass[antBrukere][i]);}
            }

            //Hvis stor bokstav mangler må nytt passord lages
            if(harStor == 0){
                printf("Passordet mangler stor bokstav.\n");
                harStor = 0;
                harLiten = 0;
                harTegn = 0;
                //goto pass; //Går tilbake til skriv inn passord
                
            //Hvis liten bokstav mangler må nytt passord lages
            }else if (harLiten == 0){
                printf("Passordet mangler liten bokstav.\n");
                harStor = 0;
                harLiten = 0;
                harTegn = 0;
                //goto pass; //Går tilbake til skriv inn passord
            
            //Hvis tegn mangler må nytt passord lages
            }else if (harTegn == 0){
                printf("Passordet mangler et spesialtegn.\n");
                harStor = 0;
                harLiten = 0;
                harTegn = 0;
                //goto pass; //Går tilbake til skriv inn passord
            }
            
            //Hvis alle krav blir møtt
            if(harStor != 0 && harLiten != 0 && harTegn != 0){
                
                //Looper gjennom hvert tegn i passordet
                for (int i = 0; i < strlen(brukerPass[antBrukere]); i++) {
                    
                    //Trekker fra første ascii og modder med cipher
                    verdi = ((int)brukerPass[antBrukere][i]
                             - ASCIINRFORST + CIPHER) % MOD;
                    
                    //Plusser på første ascii igjen
                    int kryptertTegn = verdi + ASCIINRFORST;
                    
                    //Skriver kryptert passord til array brukerPass
                    brukerPass[antBrukere][i] = (char)kryptertTegn;
                    godkjent = true;
                }
            }
        }while(godkjent == false);
        
        godkjent = false;
        antBrukere++;  //Øker antall brukere
        
        //Nr på bruker som ble lagd
        printf("Du lagde bruker %i\n", antBrukere);
        
        //Navn på bruker som ble lagd
        printf("Brukernavn:     %s\n", brukerNavn[antBrukere-1]);
        
        //Passord til bruker som ble lagd
        printf("Passord:        %s\n", brukerPass[antBrukere-1]);
        
    }else{
        //Feilmelding hvis det ikke er plass til flere brukere
        printf("Det er ikke plass til flere brukere\n");
    }
    
    //Brukes for å unngå at "\n" fra buffer kommer som valg
    //scanf("%c", &valg);
    
    break;  //Ferdig med lag bruker
    
    return 0;
}
