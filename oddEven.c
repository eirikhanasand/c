//
//  oddEven.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

int main(){
    
    /**
        Checks if a number is odd or even then prints it
     */
    for (int i = 1; i <= 100; i++){
        printf("%i", i);
        if (i % 2) {
            printf(" - odd\n");
        }else{
            printf(" - even\n");
        }
    }
    
    /**
        Prints 3 numbers per line
     */
    for (int i = 1; i <= 100; i++){
        printf("%i", i);
        i++;
        printf("\t%i", i);
        i++;
        printf("\t%i\n", i);
    }
    
    /**
        Prints 5 numbers per line
     */
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
