//
//  Oppgave 30.h
//  Basics
//
//  Created by Eirik Hanasand on 05/10/2022.
//

#ifndef Oppgave_30_h
#define Oppgave_30_h

#include <stdio.h>      //Inkludert for printf etc.
#include <stdbool.h>    //Inkludert for bool i struct
#include <stdbool.h>    //Inkludert for bool
#include <ctype.h>      //Inkludert for toupper etc.
#include <string.h>     //Inkludert for strcmp etc.

/**
    Struct tralle som inneholder utlånt status, navn på evt utleier og tlfnr for evt utleier
 */
struct Tralle  {
    bool utlaant;
    char navn[80];
    int tlfNr;
};

#endif /* Oppgave_30_h */
