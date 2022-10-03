//
//  randomnumber.c
//  Basics
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int diceRoll = 0;
    
        for(int i = 0; i <= 20; i++){
            diceRoll = (rand()%6);
            printf("%d\n", diceRoll+1);
        }
    
    return 0;
}
