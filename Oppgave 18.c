//
//  Oppgave 18.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

int main(){
    
    for (int i = 1; i <= 100; i++){
        printf("%i", i);
        if (i % 2) {
            printf(" - Oddetall\n");
        }else{
            printf(" - Partall\n");
        }
    }
    
    for (int i = 1; i <= 100; i++){
        printf("%i", i);
        i++;
        printf("\t%i", i);
        i++;
        printf("\t%i\n", i);
    }
    
    for (int i = 1; i <= 100; i++){
        printf("%-0i", i);
        i++;
        printf("\t%i", i);
        i++;
        printf("\t%i", i);
        i++;
        printf("\t%i", i);
        i++;
        printf("\t%i\n", i);
    }
    return 0;
}
