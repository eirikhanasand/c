//
//  employeeStruct.c
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#include "employeeStruct.h"
#include <string.h>

helpStruct help;
firstEMP employee;
secondEMP employee2;
const int MAXEMP = 10;

void all(void);
void mywrite(int structNUM);
void otherWay(void);

int main(){
    int structNUM = 0;
    employee.employeeNUM = 1;
    strcpy(employee.name, "bob");
    employee.hourlyRate = 180;
    
    employee2.employeeNUM = 2;
    printf("Name: "); scanf("%s", employee2.name);
    printf("Hourly rate: "); scanf("%f", &employee2.hourlyRate);
    
    mywrite(structNUM);
    all();
    
    otherWay();
    all();
    return 0;
}

void mywrite(int structNUM){
    printf("Which struct would you like to print?\n");
    scanf("%i", &structNUM);
    
    if (structNUM == 1) {
        printf("Employee: %i, ", employee.employeeNUM);
        printf("Name: %s, ", employee.name);
        printf("Hourly rate: %.2f\n", employee.hourlyRate);
    }else{
        printf("Employee: %i, ", employee2.employeeNUM);
        printf("Name: %s, ", employee2.name);
        printf("Hourly rate: %.2f\n", employee2.hourlyRate);
    }

}

void all(void){
    printf("\nPrinting all structs:\n");
    printf("Employee: %i, ", employee.employeeNUM);
    printf("Name: %s, ", employee.name);
    printf("Hourly rate: %.2f\n", employee.hourlyRate);
    printf("Employee: %i, ", employee2.employeeNUM);
    printf("Name: %s, ", employee2.name);
    printf("Hourly rate: %.2f\n", employee2.hourlyRate);
}

void otherWay(void){
    //help.employeeNUM = employee.employeeNUM;
    strcpy(help.name, employee.name);
    help.hourlyRate = employee.hourlyRate;
    
    //employee.employeeNUM = employee2.employeeNUM;
    strcpy(employee.name, employee2.name);
    employee.hourlyRate = employee2.hourlyRate;
    
    //employee2.employeeNUM = help.employeeNUM;
    strcpy(employee2.name, help.name);
    employee2.hourlyRate = help.hourlyRate;
    
}
