/**
 *  This file contains a system to make, see, remove users, login and quit.
 *
 *  Every user is numbered, contains a username and encrypted password. Stored in arrays.
 *
 *  @file       usermanagement.c
 *  @date       Oct 2. 2022
 *  @version    1
 *  @author     Eirik Hanasand
 */

#include <stdio.h>                          //Used for print etc
#include <ctype.h>                          //Used for toupper etc
#include <stdbool.h>                        //Used for statements etc
#include <string.h>                         //Used for strcmp etc

const int STRLEN = 80;                      //Max input length
const int MAXUSERS = 20;                    //Max number of users
const int ASCIIFIRST = 33;                  //First legal ASCII value
const int ASCIINRSIST = 126;                //Last legal ASCII value.
const int MOD = (ASCIINRSIST-ASCIIFIRST);   //Modding with ASCII interval
const int CIPHER = 42;                      //Rotating 42 positions

/**
 * Main program:
 * Contains a switch statement where the user can pick between 5 functions (N, L, S, R, Q
 *  Functions (explained in detail below)
 *      N - New user
 *      L - Login
 *      S - See all users
 *      R - Remove account
 *      Q - Quit program
 *
 * Detailed explanations:
 *
 * N (New user):
 *  Used to create new accounts, takes a username and password. The password is encrypted then
 *  username is stored in userName and password is stored in userPass
 *
 * L (Login):
 *  Used to login. First checks if there are exisitng users, and if there are the user is free to login
 *  using their username and password.
 *
 * S (See all users):
 *  Shows all users currently in the system, error message if none exist.
 *
 * R (Remove user)
 *  Allows a user to remove their account using username and password.
 *
 * Q (Quit program):
 *  Quits the program by breaking the switch, then going to the end of the while loop. This
 *  terminates the program using return 0;
 */

int main(){
    //Arrays
    char userName[MAXUSERS][STRLEN];     //Array for username
    char userPass[MAXUSERS][STRLEN];     //Array for password
    char nameLogin[STRLEN];              //Username when login
    char passLogin[STRLEN];              //Password when login

    //Overview
    char choice;                         //Users choice
    int userCount = 0;                   //Number of users existing
    int userNumber = 0;                  //Username logged in
    bool hasSpace = false;               //Checking for space

    //Used for password
    int hasUpper = 0;                    //Amount of uppercase letters
    int hasLower = 0;                    //Amount of lowercase letters
    int hasOther = 0;                    //Amount of other characters
    int illegalChar = 0;                 //Amount of illegal characters
    bool approved = false;               //Password validity
    int value;                           //ASCII value when encryption
    int encryptedChar;                   //Value of encrypted character

    //Used at login
    bool brukerMatch = false;            //Checks if username exists
    bool passMatch = false;              //Checks if password exists
    
    do{
        //Asks the user what they would like to do
        printf("What would you like to do? (N, L, S, R, Q)\n");
        gets(&choice);                                //Gets the users choice
        choice = toupper(choice);                     //Sets it to uppercase

        //Switch containing all options the user has
        switch (choice) {
                
            case 'N':   //Create account
                
                //Checks if there is space for more users
                if (userCount < MAXUSERS) {
                    
                    do{ //Loops until username is legal
                        
                        hasSpace = 0;                 //Amount of spaces
                        printf("Choose username:\n"); //Asking for username
                        gets(userName[userCount]);    //Getting username
                        
                        //Checking for empty username
                        if (strlen(userName[userCount]) == 0) {
                            printf("Username cannot be empty.\n");
                            
                            //Increasing hasSpace (checked later)
                            hasSpace++;
                        }
                        
                        //Checking for spaces in username
                        if (strchr(userName[userCount], ' ') != 0){
                            printf("Spaces are not allowed!\n");
                            
                            //Increasing hasSpaces (checked later)
                            hasSpace++;
                        }
                        
                        //Looper till username is legal
                        }while(hasSpace > 0);
                        
                    do{     //Until password satisfies all requirements
                        
                        //In case of multiple rounds
                        hasSpace = 0;       //Amount of spaces
                        hasUpper = 0;       //Amount of uppercase
                        hasLower = 0;       //Amount of lowercase
                        hasOther = 0;       //Amount of other chars
                        illegalChar = 0;    //Amount of illegal chars
                        
                        do{ //Loops till passord exists without spaces
                            
                            hasSpace = 0;               //Amount of spaces
                            printf("Choose password:\n");  //Asking for username
                            gets(userPass[userCount]);  //Getting username
                            
                            //Checking for empty password
                            if (strlen(userPass[userCount]) == 0) {
                                printf("Password may not be empty.\n");
                                
                                //Increasing hasSpaces (checked later)
                                hasSpace++;
                            }
                            //Checking for spaces in password
                            if (strchr(userPass[userCount], ' ') != 0){
                                printf("Spaces not allowed!\n");
                                
                                //Increasing hasSpaces (checked later)
                                hasSpace++;
                            }
                            
                            //Loops till passord exists without spaces
                            }while(hasSpace > 0);
                                                
                        //Checking every character in the password
                        for (int i = 0; i <= strlen(userPass[userCount]
                                                    )-1; i++) {
                            
                            //Checking if they are legal ASCII chars
                            if(ASCIIFIRST <= (userPass[userCount][i]) &&
                               ASCIINRSIST >= (userPass[userCount][i])){
                                
                                //Checking for uppercase
                                if(isupper(userPass[userCount][i])){
                                    //Increasing hasUpper (later checked)
                                    hasUpper++;
                                    
                                //Checking for lowercase
                                }else if(islower(userPass[userCount][i])){
                                    //Increasing hasLower (later checked)
                                    hasLower++;
                                    
                                //If they are not upper nor lower
                                }else{
                                    //Increasing hasOther (later checked)
                                    hasOther++;
                                }
                            
                            //If sign is outside ASCII interval
                            }else{
                                //Increasing illegalChar (later checked)
                                illegalChar++;
                            }
                        }
                        
                        //Error if illegal characters
                        if(illegalChar-1 == 0){
                            printf("Password contains illegal characters.\n");
                            approved = false;
                        
                        //Error if uppercase is missing
                        }else if (hasUpper == 0){
                            printf("Password must contain uppercase letter.\n");
                            approved = false;
                        
                        //Error if lowercase is missing
                        }else if (hasLower == 0){
                            printf("Password must contain lowercase letter.\n");
                            approved = false;
                        
                        //Error if other character is missing
                        }else if (hasOther == 0){
                            printf("Password must contain a special char or number.\n");
                            approved = false;
                        
                        //Bool is true if password is approved
                        }else{
                            approved = true;
                        }
                
                    //Loops till password satisifies all requirements
                    }while(approved == false);
                            
                    //Encrypting every sign in the password
                    for (int i = 0; i < strlen(userPass[userCount]); i++) {

                        //Subtracting first ascii and modding by cipher
                        value = ((int)userPass[userCount][i]
                                        - ASCIIFIRST + CIPHER) % MOD;
                                
                        //Adding first ascii again
                        int kryptertTegn = value + ASCIIFIRST;
                                
                        //Writing encrypted password to array userPass
                        userPass[userCount][i] = (char)kryptertTegn;
                        approved = true;
                    }
                    
                    approved = false;
                    userCount++;  //Increasing amount of users
                    
                    //Nr and name for the user made
                    printf("You made user: %i, Username: %s\n",
                           userCount, userName[userCount-1]);
                    
                }else{
                    //If there is not room for more users
                    printf("There is no room for more users!\n");
                }
                
                break;  //Creating user completed
                
            case 'L':   //Login
                
                //Checking if there are users
                if(userCount == 0) {
                    
                    //Error message if there are no users
                    printf("Make an account first!\n");
                    
                }else{                      //If there are users
                    printf("Username:\n");  //Asking for username
                    gets(nameLogin);        //Getting username
                    
                    printf("Password:\n");  //Asking for password
                    gets(passLogin);        //Getting password
                    
                    //Loops through every character
                    for (int i = 0; i < strlen(passLogin); i++) {
                        
                        //Subtracting first ASCII value and modding by CIPHER
                        value = ((int)passLogin[i] - ASCIIFIRST + CIPHER) % MOD;
                        
                        //Adding first ASCII value back on
                        encryptedChar = value + ASCIIFIRST;
                        
                        //Writing encrypted password to passLogin
                        passLogin[i] = (char)encryptedChar;
                    }
                    
                    //Loops through all users
                    for (int i = 0; i < userCount; i++) {
                        
                        //Searching for matching user
                        brukerMatch = strcmp(nameLogin, userName[i]);
                        
                        //Searching for matching password
                        passMatch = strcmp(passLogin, userPass[i]);
                        
                        //If there is a match
                        if (brukerMatch == 0 && passMatch == 0) {
                            userNumber = i+1;
                        }
                    }
                    
                    //Logging in if login information is correct
                    if (userNumber > 0) {
                        
                        //Which account was logged in
                        printf("Logged in as user: %i, Username: %s\n",
                               userNumber, userName[userNumber-1]);
                        
                    //Error message if username or password is wrong
                    }else{
                        printf("This is not correct.\n");
                    }
                }

                break;  //Login Complete
             
            case 'R':   //Remove user
                
                //Checking if there are users
                if(userCount == 0) {
                    
                    //Error message if there are no users
                    printf("There are no users to remove!\n");
                    
                }else{                      //If there are users
                    printf("Username:\n");  //Asking for username
                    gets(nameLogin);        //Getting username
                    
                    printf("Password:\n");  //Asking for password
                    gets(passLogin);        //Getting password
                    
                    //Loops through every character
                    for (int i = 0; i < strlen(passLogin); i++) {
                        
                        //Subtracting first ASCII value and modding by CIPHER
                        value = ((int)passLogin[i] - ASCIIFIRST + CIPHER) % MOD;
                        
                        //Adding first ASCII value back on
                        encryptedChar = value + ASCIIFIRST;
                        
                        //Writing encrypted password to passLogin
                        passLogin[i] = (char)encryptedChar;
                    }
                    
                    //Loops through all users
                    for (int i = 0; i < userCount; i++) {
                        
                        //Searching for matching user
                        brukerMatch = strcmp(nameLogin, userName[i]);
                        
                        //Searching for matching password
                        passMatch = strcmp(passLogin, userPass[i]);
                        
                        //If there is a match
                        if (brukerMatch == 0 && passMatch == 0) {
                            userNumber = i+1;
                        }
                    }
                    
                    //Removing user if user details are correct
                    if (userNumber > 0) {
                        
                        //Which account is going to be removed
                        printf("Are you sure you want to remove user: %i, Username: %s \t(y/N)\n",
                               userNumber, userName[userNumber-1]);
                        gets(&choice);
                        if (choice == 'y') {
                            for (int i = userNumber-1; i < userCount; i++) {
                                strcpy(userName[i], userName[i+1]);
                                strcpy(userPass[i], userPass[i+1]);
                            }
                            userCount--;
                            printf("User removed.\n");
                            
                        } else {
                            printf("Cancelled user removal.\n");
                        }
                        
                    //Error message if username or password is wrong
                    }else{
                        printf("This is not correct.\n");
                    }
                }

                break;  //Login Complete
                
            case 'S':   //See all users
                
                //Checking if there are users
                if(userCount == 0) {
                    
                    //Error message if there aare no users
                    printf("There are no users!\n");
                    
                }else{  //If there are users
                    printf("Showing users:\n");
                    
                    //Looping through the arrays and showing all users
                    for (int i = 0; i < userCount; i++) {
                        
                        //Writing userNumber, username and password
                        printf("User: %i, Username: %s, Password: %s\n",
                               i+1, userName[i], userPass[i]);
                    }
                }
                
                break;              //Done showing users
                
            case 'Q':               //Quitting the program
                break;              //Going to while statement
                
          //Error message if choice was not a choice
            default:
                printf("You entered \"%c\". Try again.\n", choice);
                break;
        }
        
    }while(choice != 'Q');    //Exiting the do while loop if Q was entered
    
    //Informing the user that the program is terminated
    printf("You terminated the program using %c.\n", choice);
    
    return 0;   //Terminating the program
}
