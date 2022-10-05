#include <stdlib.h>    // exit
#include <stdio.h>    // scanf, printf
#include <ctype.h>    // toupper
#include <string.h>    // strcmp(), strlen()

const int STRLEN = 40;                       ///< Max string length
const int MAXUSERS = 20;                     ///< Max number of users
const int ASCIINRFIRST = 33;                 ///< First ascii value allowed
const int ASCIINRLAST = 126;                 ///< Last ascii value allowed
const int MOD = (ASCIINRLAST-ASCIINRFIRST)+1;///< Length of interval
const int CIPHER = 42;                       ///< Number of right-shifts when encrypting

char* encode(char string[STRLEN]);

int main() {
   char username[MAXUSERS][STRLEN];
   char password[MAXUSERS][STRLEN];
   int userCount = 0;
   
    printf("Enter username: ");
    fgets(username[userCount],STRLEN,stdin);
    printf("Enter password: ");
    fgets(password[userCount],STRLEN,stdin);
    password[userCount][strlen(password[userCount])-1] = '\0';
    encode(password[userCount]);
}

char* encode(char string[STRLEN]){
    for(int i=0; i<strlen(string); i++){
        int pChar = string[i];
        pChar += CIPHER;
        if(pChar>126){pChar-=MOD;}
        string[i] = (char)pChar;
    }
   return string;
}

