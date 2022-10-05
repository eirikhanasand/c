//
//  readWriteEmployees.c
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#include "readWriteEmployees.h"

EMPLOYEE employee[3];
const int MAXEMP = 10;

int main(){
    
    int howMany = 0;
    
    printf("How many emmployees would you like to enter information for?\n");
    scanf("%d", &howMany);
    
    if (howMany > MAXEMP) {
        howMany = MAXEMP;
        printf("Too many people, automatically set to max (%i)\n\n", MAXEMP);
    } else if (howMany <= 0) {
        howMany = 1;
        printf("Too few people, automatically set to 1\n\n");
    }
    for (int i = 0; i < howMany; i++) {
        printf("Enter information for employee number %i:\n", i+1);
        printf("Name      : "); scanf("%s", employee[i].name);
        printf("Horly rate: "); scanf("%f", &employee[i].hourlyRate);
        employee[i].employeeNUM = i+1;
    }
    
    printf("The current employees are: \n");
    for (int i = 0; i < howMany; i++) {
        printf("Name: %s, ", employee[i].name);
        printf("Hourly rate: %f\n", employee[i].hourlyRate);
        employee[i].employeeNUM = i+1;
    }
    return 0;
}
