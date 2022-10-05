//
//  Oppgave 28.h
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#ifndef Oppgave_28_h
#define Oppgave_28_h

#include <stdio.h>

const int STRLEN = 80;

typedef struct{
    int employeeNUM;
    char name[STRLEN];
    float hourlyRate;
} firstEMP;

typedef struct{
    int employeeNUM;
    char name[STRLEN];
    float hourlyRate;
} secondEMP;

typedef struct{
    int employeeNUM;
    char name[STRLEN];
    float hourlyRate;
} helpStruct;

#endif /* Oppgave_28_h */
