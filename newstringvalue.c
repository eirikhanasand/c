//
//  newstringvalue.c
//  Basics
//
//  Created by Eirik Hanasand on 05/09/2022.
//
//  Setting new string values using pointers. 
//

#include <stdio.h>

int main(){
//      Setting new string values
        char test1[20];
        char * ptest1 = test1;
    
        puts("Enter text below\n");
        fgets(ptest1, 20, stdin);
        puts(test1);
}
