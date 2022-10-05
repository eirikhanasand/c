//
//  Oppgave 26.h
//  Basic
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#ifndef Oppgave_26_h
#define Oppgave_26_h

struct time {
    int hour;
    int minute;
    int second;
};

struct time2 {
    int hour;
    int minute;
    int second;
};

struct date {
    int day;
    int month;
    int year;
    struct time t;
};

struct date2 {
    int day;
    int month;
    int year;
    struct time2 t2;
};
#endif /* Oppgave_26_h */
