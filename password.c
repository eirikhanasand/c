#include <stdlib.h>    // exit
#include <stdio.h>    // scanf, printf
#include <ctype.h>    // toupper
#include <string.h>    // strcmp(), strlen()

const int STRLEN = 40;                             ///< Max string length
const int MAXUSERS = 20;                         ///< Max number of users
const int ASCIINRFIRST = 33;                     ///< First ascii value allowed
const int ASCIINRLAST = 126;                    ///< Last ascii value allowed
   
int main() {
   char username[MAXUSERS][STRLEN]; // array of user strings
   char password[MAXUSERS][STRLEN]; // array of password strings
   char enteredUser[STRLEN];        // variable for entered user
   char enteredPass[STRLEN];        // variable for entered password
   char command;                    // variable for entered command
   int userCount = 0;  // keeps track of how many users are registered
   int uLetter = 0;
   int lLetter = 0;
   int sign = 0;
   int legal =  0;
   int illegal = 0;
   int pChar = 0;
   int matchingUser = 0;
   int loggedin = 0;

   do {
       printf("Enter command: (N / L)");
       command = getchar(); //clears buffer
       command = toupper(command);
       getchar();
       switch(command){

           case 'N': {
               printf("Enter username: ");
               fgets(username[userCount],STRLEN,stdin);
               do {
                   legal = illegal = uLetter = lLetter = sign = 0;
                   printf("Enter password: ");
                   fgets(password[userCount],STRLEN,stdin);
                
                   //removes unwanted newline char from password
                   username[userCount][strlen(username[userCount])-1] = '\0';
                   password[userCount][strlen(password[userCount])-1] = '\0';
                   
                   printf("Username: '%s'\n", username[userCount]);
                   printf("Passwrd: '%s'\n", password[userCount]);
                   //Loops through string: password["Current User Index"]
                   for(int i=0; i<strlen(password[userCount]); i++){
                       pChar = password[userCount][i]; //shorthand variable
                           
                       //check if ascii value is in allowed range
                       if(pChar<ASCIINRFIRST || pChar>ASCIINRLAST)illegal++;
                       else if(isupper(pChar)) uLetter++;
                       else if(islower(pChar)) lLetter++;
                       else                    sign++;
                   }
                   
                   if (uLetter && lLetter && sign > 0 && illegal == 0) {
                   legal = 1;
                   }else{
                       if(uLetter == 0) printf("Missing capital letter!\n");
                       if (lLetter == 0) printf("Missing lower case letter!\n");
                       if (sign == 0) printf("Missing sign!\n");
                   }
               } while (legal != 1);
               
               printf("Password set!\n");
               userCount++;
               break;
           }

           case 'L':
               printf("Enter username: ");
               fgets(enteredUser,STRLEN,stdin);
               printf("Enter password: ");
               fgets(enteredPass,STRLEN,stdin);
               enteredUser[strlen(enteredUser)-1] = '\0';
               enteredPass[strlen(enteredPass)-1] = '\0';
               
                   for (int i = 0; i < userCount; i++) {
                        legal = 1;
                        matchingUser = 1;
                        loggedin = 0;
                       matchingUser = strcmp(enteredUser, username[i]);
                       legal = strcmp(enteredPass, password[i]);
                       if (matchingUser == 0 && legal == 0) {
                           loggedin = i+1;
                       }
                   }
                   if (loggedin > 0) {
                       printf("Logged in as: %i, username: %s\n",
                              loggedin, username[loggedin-1]);
                   }else{
                       printf("Invalid.\n");
                   }
               break;
       }

   }while(command != 'Q');
}
