//
//  isprime.c
//  Basics
//
//  Created by Eirik Hanasand on 26/09/2022.
//
//  Checks if a number is a prime
//

#include <stdio.h>
#include <stdbool.h>

int main(void){
    int p, d;

    bool isPrime;

        for (p = 2; p <= 50; ++p) {
        isPrime = true;
            printf("%i", isPrime);

            for (d = 2; d < p; ++d)
                if (p % d == 0)
                    isPrime = false;

                if (isPrime != false)
                    printf("%i ", p);

        }

    printf("\n");


    return 0;
}
