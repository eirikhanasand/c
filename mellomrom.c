//
//  mellomrom.c
//  Basics
//
//  Created by Eirik Hanasand on 03/10/2022.
//
//  Lite program som fanger opp mellomrom
//

#include <stdio.h>
#include <string.h>

int main(){
    char brukernavn[20][20];
    int mellomrom = 0;
    do {
        mellomrom = 0;
        printf("Skriv inn brukernavn: \n");
        gets(brukernavn[1]);
        
        if(strchr(brukernavn[1], ' ')){
            printf("Det finnes mellomrom\n");
            mellomrom++;
        }
    
    } while (mellomrom != 0);
    
    
}
