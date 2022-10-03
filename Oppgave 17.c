//
//  Oppgave 17.c
//  Basics
//
//  Created by Eirik Hanasand on 29/09/2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int MAXSKATERS = 10;
const int DISTANSER = 5;

int main(){
    
    int distance[DISTANSER] = {500, 1000, 1500, 5000, 10000};
    int enteredDistance = 0;
    int amt500 = 0;
    int skaterCount = 0;
    int legal = 0;
    int illegal = 0;
    int minutes = 0;
    int seconds = 0;
    float points = 0;
    int milliseconds = 0;
    int i = 0;
    char again;
    
    do {
        
        do{
            printf("Input iceskating distance: (500,1000,1500,5000,10000)\n");
            scanf("%i", &enteredDistance);
            
            for (int i = 0; i < DISTANSER; i++) {
                if(enteredDistance == distance[i]){
                    legal++;
                }
            }
        }while(legal == 0);
        legal = 0;
        
        for (i = 0; i < enteredDistance; i+=500) {
            amt500++;
        }
        printf("%i\n", amt500);
        do{
            printf("How many iceskaters? (max %i)\n", MAXSKATERS);
            scanf("%i", &skaterCount);
            //printf("Du skrev: %i\n", antLopere);
            
            for (i = 0; i < DISTANSER; i++) {
                if(0 < skaterCount && MAXSKATERS >= skaterCount){
                    legal++;
                }
            }
            
        }while(legal == 0);
        legal = 0;
        
        for (i = 0; i < skaterCount; i++) {
            printf("Enter time for skater: %i\n", i+1);
            do {
                printf("Minutes:");
                scanf("%i", &minutes);
                
                printf("Seconds:");
                scanf("%i", &seconds);
                
                printf("Milliseconds:");
                scanf("%i", &milliseconds);
                
                illegal = 0;
                if (minutes < 0 || minutes > 60) {
                    illegal++;
                }else if (seconds < 0 || seconds > 60) {
                    illegal++;
                }else if (milliseconds < 0 || milliseconds > 60) {
                    illegal++;
                }
                
            } while (illegal > 0);
            
            points = (float)((minutes * 60 + seconds + (float)(milliseconds / 100.0) ) / amt500);
            printf("%i\n", minutes);
            printf("%i\n", seconds);
            printf("%i\n", milliseconds);
            printf("%i\n", amt500);
            printf("This skater got %.3f points\n", points);
        }
        
        printf("Again? (Y/n)\n");
        scanf(" %c", &again);
        
    } while (again != 'n');
    
    
    
    
    return 0;
}
