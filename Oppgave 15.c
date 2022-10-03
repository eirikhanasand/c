//
//  Oppgave 15.c
//  Basics
//
//  Created by Eirik Hanasand on 29/09/2022.
//

#include <stdio.h>

int main(){
    int number;
    int number2;
    char choice;

    do{
        printf("Enter two numbers:\n");
        scanf("%i %i", &number, &number2);

        printf("%i + %i = %i\n", number, number2, number + number2);
        printf("%i - %i = %i\n", number, number2, number - number2);
        printf("%i * %i = %i\n", number, number2, number * number2);

        printf("Again? (Y/n)\n");
        scanf(" %c", &choice);

    }while(choice != 'n');
    
    printf("Du avsluttet programmet med \"n\".\n");
    return 0;
}
