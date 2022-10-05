//
//  stringfunctions.c
//  Basics
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#include <stdio.h>

const int STRLEN = 80;
char s[STRLEN];
char t[STRLEN];
int sLength = 0;
int tLength = 0;

int  mstrlen(const char s[]);
void mstrcpy(char s[], char t[]);
void mstrcat(char s[], char t[]);
int  mstrcmp(char s[], char t[]);

int main(){
    
    //Getting input
    printf("Enter text 1:\n");
    gets(s);
    printf("1 is %s\n", s);
    
    printf("Enter text 2:\n");
    gets(t);
    printf("2 is %s\n", t);
    
    //Find length
    printf("You entered %s. The length is %i\n", s, mstrlen(s));
    
    //Check equality
    printf("Equality: %i\n", mstrcmp(s, t));
    
    //COPIED OUT BECAUSE THE LAST ONE WILL CHANGE DEPENDING ON THE RESULT FROM THE FIRST ONE
    //Copy strings
//    mstrcpy(s, t);
//    printf("Here 1 is %s\n", s);
//    printf("Here 2 is %s\n", t);
//    printf("Copying 1 to 2. 2 is %s\n", t);
    
    //Add to strings
//    printf("Here 1 is %s\n", s);
//    printf("Here 2 is %s\n", t);
//    mstrcat(s, t);
//    printf("Adding 1 to 2. 2 is now %s\n", t);
    

}

/**
  Looks for the first backslash 0. Length will be every character before \0 is found.
 */
int  mstrlen(const char s[]){
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

/**
  Copies string s into t one char at a time in a loop.
 */
void mstrcpy(char s[], char t[]){
    int i = 0;
    while (s[i] != '\0') {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}

/**
  Puts strings together by looking for \0 in the first string then adding every char
  from the other string one char at a time
 */
void mstrcat(char s[], char t[]){
    sLength = mstrlen(s);
    tLength = mstrlen(t);
    
    if (sLength+tLength >= STRLEN) {
        printf("Strings are too long to be copied!\n");
    } else {
        int i = 0;
        tLength = mstrlen(t);
        while (s[i] != '\0') {
            t[tLength+i] = s[i];
            i++;
        }
        t[tLength+i] = '\0';
    }
}

/**
  Compares two strings by checking one character at a time and returning different values depending on the result.
  Result will be 0 if equal, 1 if the first string is first in the alphabet and 2 if the second string is first in the alphabet.
 */
int mstrcmp(char s[], char t[]){
    sLength = mstrlen(s);
    tLength = mstrlen(t);
    int equal = 0;
    
    //Checks for equality here
    if (sLength == tLength) {
        for (int i = 0; i < sLength; i++) {
            if (s[i] == t[i]) {
                equal++;
            }
        }
        if (equal == sLength) {
            return 0;
        }else{
            for (int i = 0; i < sLength; i++) {
                if(s[i] == t[i]){
                    continue;
                }else if(s[i] < t[i]) {
                    return 1;
                }else{
                    return 2;
                }
            }
        }
    // If s is shortest it will begin comparing with t
    }else if (sLength < tLength){
        for (int i = 0; i < tLength; i++) {
            if(s[i] == t[i]){
                continue;
            }else if(s[i] < t[i]) {
                return 1;
            }else{
                return 2;
            }
        }
    
    //If t is shortest it will begin comparing with s
    }else{
        for (int i = 0; i < sLength; i++) {
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
