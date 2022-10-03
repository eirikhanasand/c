//
//  asciitegn.c
//  Basics
//
//  Created by Eirik Hanasand on 27/09/2022.
//

#include <stdio.h>
#include <string.h>

const int ASCIINRFORST = 33;
const int ASCIINRSIST = 126;

int main(){
    char input[60];
    int lovlig = 0;
    int ulovlig = 0;
    printf("Skriv inn verdier:\n");
    scanf("%s", input);
    
    for (int i = 0; i <= strlen(input); i++) {
        printf("\"%c\"", input[i]);
            if(ASCIINRFORST > input[i] || input[i] < ASCIINRSIST){
                lovlig++;
            }else{
                ulovlig++;
            }
    }
    printf("Du skrev inn %i lovlige\n", lovlig);
    printf("Du skrev inn %i ulovlige\n", ulovlig);

}
