//
//  readWriteEmployees.h
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#ifndef readWriteEmployees_h
#define readWriteEmployees_h

#include <stdio.h>

const int STRLEN = 80;

typedef struct{
    int employeeNUM;
    char name[STRLEN];
    float hourlyRate;
} EMPLOYEE;

#endif /* readWriteEmployees_h */
