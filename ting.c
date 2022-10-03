//
//  ting.c
//  Basics
//
//  Created by Eirik Hanasand on 27/09/2022.
//

#include <stdio.h>

int main(){
    int tall1 = 0;
    char valg;
    do{
        printf("Skriv inn verdi\n");
        scanf("%c", &valg);
        
        switch (valg) {
            case 'A':
                printf("Dette er A\n");
                tall1++;
                break;
                
            case 'L':
                if(tall1 == 0) {
                    printf("Lag bruker først!\n");
                }else{
                    printf("Det finnes brukere!\n");
                    }
                
                
                scanf("%c", &valg);
                break;
        }
    }while(tall1 != 1000);
    printf("Tall1 er nå %i\n", tall1);
    return 0;
}
