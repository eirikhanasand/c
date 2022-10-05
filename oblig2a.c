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
 * 	    @author     Oliver Tangen, NTNU
 */

#include <stdlib.h>	// exit
#include <stdio.h>	// scanf, printf	
#include <ctype.h>	// toupper	
#include <string.h>	// strcmp(), strlen()
//#include <stdbool.h>	
#include <unistd.h> // sleep()

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
	

	while(1) {
		printf("\nNew user: N | Log in: L | Print users: S | Quit: Q\n");
		printf("Enter command: ");
        scanf(" %c", &command);
        getchar();
		command = toupper(command);
		switch(command){

			case 'N': {

				if(userCount==MAXUSERS){
					printf("\nMaximum number of users is registered\n");
					break;
				}

				printf("Enter username: ");
                fgets(username[userCount],STRLEN,stdin);
				printf("Enter password: ");
                fgets(password[userCount],STRLEN,stdin);
                password[userCount][strlen(password[userCount])-1] = '\0';
                //Loops through string: password["Current User Index"]
                for(int i=0; i<strlen(password[userCount])-1; i++){
                    int pChar = password[userCount][i]; //shorthand variable
                        
                    //check if character is allowed
                    if(pChar<33 || pChar>126){
                        printf("Password can't contain '%c'\n",pChar);
                        break;
                    }

                }
                
                strcpy(password[userCount], encode(password[userCount]));
                
                printf("EncryptedPass: %s",password[userCount]);     
                
                userCount++; //increases userCount with one
				break;
			}		

			case 'L': {
                char emptyString[STRLEN];
				strcpy(enteredUser, emptyString);
                strcpy(enteredPass, emptyString);
                          
                printf("Enter username: ");
				scanf(" %s", enteredUser); //ignore space before
				printf("Enter password: ");
                scanf("%s", enteredPass);
               
                int i = 0;
                for(int i=0;i<MAXUSERS;i++){
                    if(!strcmp(enteredUser,username[i])){
                        break;
                    }
                }
                if(i==MAXUSERS){
                    printf("User \"%s\" does not Exist.", enteredUser);
                    break;
                }
                
                char user[STRLEN];
                strcpy(user,username[i]);
                char passToCmp[STRLEN];
                strcpy(passToCmp, password[i]);
                
                for(i=0;i<strlen(enteredPass);i++){
                    int passChar = enteredPass[i];
                    if((int)passChar<33 || (int)passChar>126){
                        //Password is wrong
                    }
                    int encryptedChar = (int)passChar + CIPHER;
                    if(encryptedChar>126){
                        encryptedChar -= MOD;
                    }
                    enteredPass[i]=(char)encryptedChar;
                }
                
                if(!strcmp(enteredPass,passToCmp)){
                    printf("Login successful!");
                }
                printf("enteredPass: %s, passToCmp: %s",enteredPass,passToCmp);
                
                //encrypting enteredPass (duplicate algorithm)
            }

			case 'S': {

				if(userCount==0) {
					printf("No users to print\n");
					break;
				}
				for(int i=0; i<userCount; i++){
				    printf("%i: User: %s Pass: %s\n",
                           i+1, username[i], password[i]
                    );
				}
				break;
			}

			case 'Q': exit(0);
            
            default: printf("Invalid command!\n");

		}
	}
}


char* encode(char string[STRLEN]){
    string[strlen(string)+1] = 'h';
//    printf("Nå er du her '%s'\n", string);
//    for(int i=0; i<strlen(string); i++){
//        printf("String: %s, char: %c, number: %i\n", string, string[i], string[i]);
//        int pChar = string[i];          //shorthand variable
//        printf("Går inn i loop\n");
//        pChar += CIPHER;                // Caesar encryption algorithm
//        if(pChar>126){pChar-=MOD;}    // wraps if ascii value too big
//        string[i] = pChar;
//    }
    return string;
}
