//
//  Oppgave 24.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

const int MAXTALL = 20;
int antallTall = 0;
int minsteTall = 0;
int storsteTall = 0;
int tall[MAXTALL];

void hentMinsteVerdi(int tall[antallTall]);
void hentStorsteVerdi(int tall[antallTall]);
void hentVerdi(char valg, int tall[antallTall]);
char valg;

int main(){
    printf("Hvor mange tall vil du skrive inn? (max 20)\n");
    scanf("%i", &antallTall);
    
    for (int i = 0; i < antallTall; i++) {
        printf("Skriv inn tall %i:", i+1);
        scanf("%i", &tall[i]);
    }
    
    printf("Vil du finne minste eller storste verdi? (m/s)\n");
    valg = getchar();
    valg = getchar();
    hentMinsteVerdi(tall);
    hentStorsteVerdi(tall);
    hentVerdi(valg, tall);
}

void hentMinsteVerdi(int tall[antallTall]){
    minsteTall = tall[0];
    for (int i = 0; i < antallTall; i++) {
        if (minsteTall > tall[i]) {
            minsteTall = tall[i];
        }
    }
    printf("Det minste tallet var: %i\n", minsteTall);
}

void hentStorsteVerdi(int tall[antallTall]){
    storsteTall = tall[0];
    for (int i = 0; i < antallTall; i++) {
        if (storsteTall < tall[i]) {
            storsteTall = tall[i];
        }
    }
    printf("Det storste tallet var: %i\n", storsteTall);
}

void hentVerdi(char valg, int tall[antallTall]){
    if(valg == 'm'){
        minsteTall = tall[0];
        for (int i = 0; i < antallTall; i++) {
            if (minsteTall > tall[i]) {
                minsteTall = tall[i];
            }
        }
        printf("Det minste tallet var: %i\n", minsteTall);
    }else{
        storsteTall = tall[0];
        for (int i = 0; i < antallTall; i++) {
            if (storsteTall < tall[i]) {
                storsteTall = tall[i];
            }
        }
        printf("Det storste tallet var: %i\n", storsteTall);
    }
}
