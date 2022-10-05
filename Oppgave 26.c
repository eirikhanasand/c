//
//  Oppgave 26.c
//  Basic
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#include <stdio.h>
#include "Oppgave 26.h"

struct date d;
struct date2 d2;

int main(){
    printf("Enter date and time (1): (dd mm yyyy hh mm ss)\n");
    scanf("%d %d %d %d %d %d", &d.day, &d.month, &d.year, &d.t.hour, &d.t.minute, &d.t.second);
    
    printf("Enter date and time (2): (dd mm yyyy hh mm ss)\n");
    scanf("%d %d %d %d %d %d", &d2.day, &d2.month, &d2.year, &d2.t2.hour, &d2.t2.minute, &d2.t2.second);
    
    if (d.year == d2.year) {
        if (d.month == d2.month) {
            if (d.day == d2.day) {
                if (d.t.hour == d2.t2.hour) {
                    if (d.t.minute == d2.t2.minute) {
                        if (d.t.second == d2.t2.second) {
                            printf("The dates are the same!\n");
                        }else if (d.t.second < d2.t2.second) {
                            printf("First date came first, decided by second!\n");
                            printf("Date 1: %i:%i:%i, Time: %i:%i:%i\n", d.day, d.month, d.year, d.t.hour, d.t.minute, d.t.second);
                        }else{
                            printf("Second date came first, decided by second!\n");
                            printf("Date 2: %i:%i:%i, Time: %i:%i:%i\n", d2.day, d2.month, d2.year, d2.t2.hour, d2.t2.minute, d2.t2.second);
                        }
                    }else if (d.t.minute < d2.t2.minute) {
                        printf("First date came first, decided by minute!\n");
                        printf("Date 1: %i:%i:%i, Time: %i:%i:%i\n", d.day, d.month, d.year, d.t.hour, d.t.minute, d.t.second);
                    }else{
                        printf("Second date came first, decided by minute!\n");
                        printf("Date 2: %i:%i:%i, Time: %i:%i:%i\n", d2.day, d2.month, d2.year, d2.t2.hour, d2.t2.minute, d2.t2.second);
                    }
                }else if (d.t.hour < d2.t2.hour) {
                    printf("First date came first, decided by hour!\n");
                    printf("Date 1: %i:%i:%i, Time: %i:%i:%i\n", d.day, d.month, d.year, d.t.hour, d.t.minute, d.t.second);
                }else{
                    printf("Second date came first, decided by hour!\n");
                    printf("Date 2: %i:%i:%i, Time: %i:%i:%i\n", d2.day, d2.month, d2.year, d2.t2.hour, d2.t2.minute, d2.t2.second);
                }
            }else if (d.day < d2.day) {
                printf("First date came first, decided by day!\n");
                printf("Date 1: %i:%i:%i, Time: %i:%i:%i\n", d.day, d.month, d.year, d.t.hour, d.t.minute, d.t.second);
            }else{
                printf("Second date came first, decided by day!\n");
                printf("Date 2: %i:%i:%i, Time: %i:%i:%i\n", d2.day, d2.month, d2.year, d2.t2.hour, d2.t2.minute, d2.t2.second);
            }
        }else if (d.month < d2.month) {
            printf("First date came first, decided by month!\n");
            printf("Date 1: %i:%i:%i, Time: %i:%i:%i\n", d.day, d.month, d.year, d.t.hour, d.t.minute, d.t.second);
        }else{
            printf("Second date came first, decided by month!\n");
            printf("Date 2: %i:%i:%i, Time: %i:%i:%i\n", d2.day, d2.month, d2.year, d2.t2.hour, d2.t2.minute, d2.t2.second);
        }
        
    }else if (d.year < d2.year) {
        printf("First date came first, decided by year!\n");
        printf("Date 1: %i:%i:%i, Time: %i:%i:%i\n", d.day, d.month, d.year, d.t.hour, d.t.minute, d.t.second);
    }else{
        printf("Second date came first, decided by year!\n");
        printf("Date 2: %i:%i:%i, Time: %i:%i:%i\n", d2.day, d2.month, d2.year, d2.t2.hour, d2.t2.minute, d2.t2.second);
    }
    return 0;
}
