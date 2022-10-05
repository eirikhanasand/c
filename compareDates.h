//
//  compareDates.h
//  Basic
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#ifndef compareDates_h
#define compareDates_h

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
#endif /* compareDates_h */
