 /**
 * 	    Oblig 2 -- A Basic Login System.
 *	
 *	    Features:
 *		    - Create users
 *		    - Log in
 *		    - Print users
 *		    - Quit program
 *
 *      @file 	    main.c
 * 	 @author       Oliver Tangen, NTNU
 */

#include <stdlib.h>	// exit
#include <stdio.h>	// scanf, printf	
#include <ctype.h>	// toupper	
#include <string.h>	// strcmp(), strlen()

const int STRLEN = 40; 				            ///< Max string length
const int MAXUSERS = 20; 			            ///< Max number of users
const int ASCIINRFIRST = 33; 			        ///< First ascii value allowed
const int ASCIINRLAST = 126;			        ///< Last ascii value allowed
const int MOD = (ASCIINRLAST-ASCIINRFIRST)+1; 	///< Length of interval
const int CIPHER = 42;		///< Number of right-shifts when encrypting

char* encode(char string[STRLEN]);
    
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
		printf("\nNew user: N | Log in: L | Print users: S | Quit: Q\n");
		printf("Enter command: ");
        command = getchar(); //clears buffer
		command = toupper(command);
        getchar();
		switch(command){

            case 'N': {
				if(userCount==MAXUSERS){
                    printf("\nMaximum number of users is registered\n");
					break;
				}
				printf("Enter username: ");
                fgets(username[userCount],STRLEN,stdin);
                do {
                    legal = illegal = uLetter = lLetter = sign = 0;
                    printf("Enter password: ");
                    fgets(password[userCount],STRLEN,stdin);
                    
                    //removes unwanted newline char from password
                    username[userCount][strlen(username[userCount])-1] = '\0';
                    password[userCount][strlen(password[userCount])-1] = '\0';

                    //Loops through string: password["Current User Index"]
                    for(int i=0; i<strlen(password[userCount]); i++){
                        pChar = password[userCount][i]; //shorthand variable
                            
                        //check if ascii value is in allowed range
                        if(pChar<ASCIINRFIRST || pChar>ASCIINRLAST)illegal++;
                        else if(isupper(pChar)) uLetter++;
                        else if(islower(pChar)) lLetter++;
                        else                    sign++;
                    }
                    
                    if (uLetter + lLetter && sign && illegal == 0) {
                    legal = 1;
                    }
                    if(uLetter == 0) printf("Missing capital letter!\n");
                    if (lLetter == 0) printf("Missing lower case letter!\n");
                    if (sign == 0) printf("Missing sign!\n");
                    
                } while (legal != 1);
                
                printf("Password set!\n");
                encode(password[userCount]);    //Encrypts password
                userCount++;                    //increases userCount with one
				break;
			}		

			case 'L':
                if(userCount==0) {
                    printf("No users exist\n");
                }else{
                    printf("Enter username: ");
                    fgets(enteredUser,STRLEN,stdin);
                    printf("Enter password: ");
                    fgets(enteredPass,STRLEN,stdin);
                    enteredUser[strlen(enteredUser)-1] = '\0';
                    enteredPass[strlen(enteredPass)-1] = '\0';
                    encode(enteredPass);
                        for (int i = 0; i < userCount; i++) {
                             legal = 1;
                             matchingUser = 1;
                             loggedin = 0;
                            matchingUser = strcmp(enteredUser, username[i]);
                            legal = strcmp(enteredPass, password[i]);
                            if (matchingUser == 0 && legal == 0) {
                                loggedin = i+1;
                                printf("Logged in as: %i, username: %s\n",
                                       loggedin, username[loggedin-1]);
                                break;
                            }
                        }
                            if (loggedin == 0) {
                            printf("Invalid.\n");
                        }
                }
                break;
                
			case 'S': {
				if(userCount==0) {
					printf("No users to print\n");
					break;
				}
			    for(int i=0; i<userCount; i++){     // loops through all users
				 printf("%i: User: '%s' Pass: '%s'\n",i+1, username[i], password[i]);
				}
				break;
			}
            case 'Q': printf("Terminated\n"); break;
            default: printf("Invalid command!\n");
		}
    }while(command != 'Q');
}

/**
 *  Function used to encrypt strings. Using caesar method in a loop shifting every sign 42 positions.
 */
char* encode(char string[STRLEN]){
    for(int i=0; i<strlen(string); i++){
        int pChar = string[i];
        pChar += CIPHER;
        if(pChar>126){pChar-=MOD;}
        string[i] = (char)pChar;
    }
   return string;
}

