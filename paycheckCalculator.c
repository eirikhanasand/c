/**
 * This file gets name, hourly rate and amount of holiday weeks from 2 persons.
 *
 * Then weekly pay, monthly pay and annual income is calculated for both people.
 * It also checks if the names or hourly rate match. This info is then output to the user.
 *
 * @file      payCheckCalculator.c
 * @date      Oct 3. 2022
 * @version   1
 * @author    Eirik Hanasand
 */

#include <stdio.h>          //Included for printf etc.
#include <string.h>         //Included for strcmp etc.

int main(){
    char name1[20];         //Name person 1
    float hourly1;          //Hourly rate person 1
    float holidayWeeks1;    //Holiday weeks person 1
    float weekly1;          //Weekly pay person 1
    float monthly1;         //Monthly pay person 1
    float annual1;          //Annual rate person 1
    
    char name2[20];         //Name person 2
    float hourly2;          //Hourly rate person 2
    float holidayWeeks2;    //Holiday weeks person 2
    float weekly2;          //Weekly pay person 2
    float monthly2;         //Monthly pay person 2
    float annual2;          //Annual rate person 2
    
    int nameMatch = 0;      //Checks if names match
    int payMatch = 0;       //Checks if hourly pay matches
    
//  Collects name, hourly rate and holiday weeks from person 1
    printf("Name person 1:\n");
    scanf("%s", name1);
    printf("Hourly rate person 1:\n");
    scanf("%f", &hourly1);
    printf("Holiday weeks person 1:\n");
    scanf("%f", &holidayWeeks1);
    
//  Collects name, hourly rate and holiday weeks from person 2
    printf("Name person 2:\n");
    scanf("%s", name2);
    printf("Hourly rate person 2:\n");
    scanf("%f", &hourly2);
    printf("Holiday weeks person 2:\n");
    scanf("%f", &holidayWeeks2);
    
    weekly1 = hourly1*8*5;                  //Calculating weekly pay 1
    monthly1 = weekly1*4.33;                //Calculating monthly pay 1
    annual1 = (52-holidayWeeks1)*weekly1;   //Calculating annual pay 1
    
    weekly2 = hourly2*8*5;                  //Calculating weekly pay 2
    monthly2 = weekly2*4.33;                //Calculating monthly pay 2
    annual2 = (52-holidayWeeks2)*weekly2;   //Calculating annual pay 2
     
//  Printing all information on person 1
    printf("Name 1: %s (length: %lu)\n", name1, strlen(name1));
    printf("Hourly rate:   %.2f\n", hourly1);
    printf("Holiday weeks: %.1f\n", holidayWeeks1);
    printf("Weekly pay:    %.2f\n", weekly1);
    printf("Monthly pay:   %.2f\n", monthly1);
    printf("Annual pay:    %.2f\n\n", annual1);
    
//  Printing all information on person 2
    printf("Name 2: %s (length: %lu)\n", name2, strlen(name2));
    printf("Hourly rate:   %.2f\n", hourly2);
    printf("Holiday weeks: %.1f\n", holidayWeeks2);
    printf("Weekly pay:    %.2f\n", weekly2);
    printf("Monthly pay:   %.2f\n", monthly2);
    printf("Annual pay:    %.2f\n\n", annual2);
    
    nameMatch = !strcmp(name1, name2);        //If names match
    payMatch = (hourly1 == hourly2);          //If hourly pay match
    
    printf("Equal name = %d\n", nameMatch);   //Prints if names match
    printf("Equal pay  = %d\n", payMatch);    //Prints if hourly match
    
    return 0;
}
