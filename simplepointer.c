//
//  simplepointer.c
//  Basics
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#include <stdio.h>

//  PART OF THE ADVANCED PART
void test(int * x){
    *x += *x/2;
}

// EASY PART
int main(){
    
    int arr[5] = {1,2,3,4,5};
    int* ptr = arr;
    ptr+=3;
    printf("%d\n", *ptr);
    
//  MAKING IT MORE ADVANCED
    int v = 8;
    test(&v);
    printf("%d\n", v);
    return 0;
}

