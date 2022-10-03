//
//  structures.c
//  Basics
//
//  Created by Eirik Hanasand on 05/09/2022.
//
//  How to use struct
//

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main(){
    
    struct users ola;
    struct users kari;

    ola.userID = 1;
    kari.userID = 2;
    
    puts("Enter the first name of user 1\n");
    gets(ola.firstName);
    puts("Enter the first name of user 2\n");
    gets(kari.firstName);
    
    printf("User 1 is %d\n", ola.userID);
    printf("User 2 is %s\n", kari.firstName);

    return 0;
}
