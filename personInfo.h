//
//  personInfo.h
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#ifndef personInfo_h
#define personInfo_h

#include <stdio.h>
const int STRLEN = 80;

typedef struct{
    char name[STRLEN];
    int age;
    float weight;
} Person;

#endif /* personInfo_h */
