//
//  timetoseconds.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

void writeTime(int hours, int minutes, int seconds);
int hours = 0;
int minutes = 0;
int seconds = 0;

int main(){
    
    //User input
    printf("Enter hours, minutes and seconds.\n");
    printf("Hours: ");
    scanf("%i", &hours);
    
    printf("Minutes: ");
    scanf("%i", &minutes);
    
    printf("Seconds: ");
    scanf("%i", &seconds);
    
    //Calling writetime function
    writeTime(hours, minutes, seconds);
    
    return 0;
}

/**
 This function takes hours minutes and seconds and prints it out (as 01) if its just one minute for example.
 It also converts to seconds and prints how many seconds everything would be in total
 */
void writeTime(int hours, int minutes, int seconds){
    int hoursOK = 0;
    int minutesOK = 0;
    int secondsOK = 0;
    int h10 = 0;
    int m10 = 0;
    int s10 = 0;

    do {
        if (hours < 0 || hours > 60) {
        printf("Hours: ");
        scanf("%i", &hours);
        }else{
            hoursOK = 1;
            if (hours < 10) {
                h10 = 1;
            }
        }
    } while (hoursOK != 1);

    do {
        if (minutes < 0 || minutes > 60) {
        printf("Minutes: ");
        scanf("%i", &minutes);
        }else{
            minutesOK = 1;
            if (minutes < 10) {
                m10 = 1;
            }
        }
    } while (minutesOK != 1);
    
    do {
        if (seconds < 0 || seconds > 60) {
        printf("Seconds: ");
        scanf("%i", &seconds);
        }else{
            secondsOK = 1;
            if (seconds < 10) {
                s10 = 1;
            }
        }
    } while (secondsOK != 1);
     
    if (h10 == 1) {
        printf("0%i:", hours);
    }else{
        printf("%i:", hours);
    }
    
    if (m10 == 1) {
        printf("0%i:", minutes);
    }else{
        printf("%i:", minutes);
    }
    
    if (s10 == 1) {
        printf("0%i\n", seconds);
    }else{
        printf("%i\n", seconds);
    }
    
    printf("This is equal to: %i seconds!\n", hours*3600 + minutes*60 + seconds);
}
