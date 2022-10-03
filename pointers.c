//
//  pointers.c
//  Basics
//
//  Created by Eirik Hanasand on 31/08/2022.
//
//  This program is a guide on pointers.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(){
    int * points;
    points = (int *) malloc(5 * sizeof(int));
    
    puts(points);
    free(points);
    
//    char hello[20];
//
//    char * pHello = hello;
//    puts("Enter text below\n");
//    fgets(pHello, 20, stdin);
//    puts(hello);
//
    return 0;
}
//int main(){
//    char thatchar[] = "This char is hard to work with";
//    char * thischar = "This is a cool char";
//
//    puts(thischar);
//
//    thischar = "hello";
//    puts(thischar);
//
//    return 0;
//
//}

//int main(){
//    int i;
//    int harvestedPD[5] = {403, 349, 568, 546, 453};
//    int potato = 2002;
//    int * pPotato = &potato;
//
//    //Printing the element, address and value for 5 different array elements.
//    printf("Element:   Address:   Value:\n");
//    for(i=0; i < 5; i++){
//        printf("harvestedPD[%d]   %p   %d\n",i, &harvestedPD[i], harvestedPD[i]);
//    }
//
//    //Use %p to find the address of the integer
//    printf("potato\n");
//    printf("Address: %p    Name:%s    Value: %d\n", pPotato, "Potato", potato);
//
//    //Use %p to find the address of the pointer
//    printf("\npPotato\n");
//    printf("Address: %p    Name:%s    Value: %p\n\n", &pPotato, "Potato", pPotato);
//
//    //Dereferencing a pointer to find the storage location of the first pointer
//    printf("Dereferenced:\n");
//    printf("*pPotato: %d\n", *pPotato);
//
//    //Changing the dereferenced value of a pointer also changes the original value of the pointer itself
//    *pPotato = 1983;
//    printf("potato: %d\n", potato);
//    printf("*pPotato: %d\n", *pPotato);
//
//    //harvestedPD is already a pointer therefore we dont need to use the & sign
//    printf("ayooo!\n");
//    printf("%p\n", harvestedPD);
//    printf("%d\n", *harvestedPD);
//
//    //You can use +n to see the pointer for element n in the array
//    printf("%d\n", *(harvestedPD+2));
//
//    return 0;
//}
