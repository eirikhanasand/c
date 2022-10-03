//
//  arrays.c
//  Basics
//
//  Created by Eirik Hanasand on 30/08/2022.
//
//  Basic example of arrays
//
    
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    int i;
    int players[5] = {2, 4, 15, 36, 42};
    int goals[5] = {58, 67, 34, 86, 92};
    int matchesPlayed[5] = {40, 43, 36, 40, 42};
    float gpg[5];
    float bestGPG = 0.0;
    int bestPlayer;
    
//  Printing the stats for each player
    for(i; i<5; i++){
        gpg[i] = (float)goals[i] / (float)matchesPlayed[i];
        printf("%d \t %d \t %d \t %.2f\n", players[i], goals[i], matchesPlayed[i], gpg[i]);
        
//      Checking who is the best player and setting their values in int bestPlayer and bestGPG
        if(gpg[i] > bestGPG){
            bestPlayer = players[i];
            bestGPG = gpg[i];
        }
    }
//  Printing the best player
    printf("\nThe best player is player %d with %f goals per game.\n\n", bestPlayer, bestGPG);
    
    return 0;
}
