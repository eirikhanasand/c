//
//  Oppgave 25.c
//  Basics
//
//  Created by Eirik Hanasand on 02/10/2022.
//

#include <stdio.h>

const int STRLEN = 80;
char s[STRLEN];
char t[STRLEN];
int sLengde = 0;
int tLengde = 0;

int  mstrlen(const char s[]);
void mstrcpy(char s[], char t[]);
void mstrcat(char s[], char t[]);
int  mstrcmp(char s[], char t[]);

int main(){
    //Henter input
    printf("Enter text s:\n");
    gets(s);
    printf("s er %s\n", s);
    
    printf("Enter text t:\n");
    gets(t);
    printf("t er %s\n", t);
    
    //Find length
    printf("Du skrev inn %s. Lengden er %i\n", s, mstrlen(s));
    
    //Check equality
    printf("Likhet: %i\n", mstrcmp(s, t));
    
    //Copy strings
//    mstrcpy(s, t);
//    printf("Her er s %s\n", s);
//    printf("Her er t %s\n", t);
//    printf("Kopierer s til t. t er nå %s\n", t);
    
    //Add to strings
//    printf("Her er s %s\n", s);
//    printf("Her er t %s\n", t);
//    mstrcat(s, t);
//    printf("Legger til s i t. t er nå %s\n", t);
    

}

int  mstrlen(const char s[]){
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void mstrcpy(char s[], char t[]){
    int i = 0;
    while (s[i] != '\0') {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}

void mstrcat(char s[], char t[]){
    sLengde = mstrlen(s);
    tLengde = mstrlen(t);
    
    if (sLengde+tLengde >= STRLEN) {
        printf("Strings are too long to be copied!\n");
    } else {
        int i = 0;
        tLengde = mstrlen(t);
        while (s[i] != '\0') {
            t[tLengde+i] = s[i];
            i++;
        }
        t[tLengde+i] = '\0';
    }
}

int mstrcmp(char s[], char t[]){
    sLengde = mstrlen(s);
    tLengde = mstrlen(t);
    int equal = 0;
    printf("s sin lengde %i\n", sLengde);
    printf("t sin lengde %i\n", tLengde);
    
    if (sLengde == tLengde) {
        for (int i = 0; i < sLengde; i++) {
            if (s[i] == t[i]) {
                equal++;
            }
        }
        if (equal == sLengde) {
            return 0;
        }else{
            for (int i = 0; i < sLengde; i++) {
                if(s[i] == t[i]){
                    continue;
                }else if(s[i] < t[i]) {
                    return 1;
                }else{
                    return 2;
                }
            }
        }
    }else if (sLengde < tLengde){
        for (int i = 0; i < tLengde; i++) {
            if(s[i] == t[i]){
                continue;
            }else if(s[i] < t[i]) {
                return 1;
            }else{
                return 2;
            }
        }
    }else{
        for (int i = 0; i < sLengde; i++) {
            if(s[i] == t[i]){
                continue;
            }else if(s[i] < t[i]) {
                return 1;
            }else{
                return 2;
            }
        }
    }
    return 3;
}
