//
//  todolist.c
//  Basics
//
//  Created by Eirik Hanasand on 06/09/2022.
//
//  To-do list where you can add or remove items,
//  or view specific elements or the entire list.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void add(void);                 //Add to list
void menu(void);                //Prints menu
void notAllowed(void);          //Prints not allowed
void quit(void);                //Prints program terminated
void rem(void);                 //Removes from element
void remSpace(void);            //Removes from buffer
void view(void);                //View entire list
void viewThis(int listNUM);     //View one element in list

char activityList[3][50][100];  //List used to store name, description and time
int listElements = 0;           //Defines length of activityList
char choice;                    //Determines what the user would like to do
bool moveElement = false;       //Checks if remove element exists
int listNUM;                    //View specific element

/**
    Main function that includes every functionality mentioned in the top of the file
 */
int main(){
    do{
        menu();                                 //Prints menu
        switch (choice) {                       //All options in the program
            case 'A': add();             break; //Add to list function
            case 'V': view();            break; //View list function
            case 'R': rem();             break; //Remove from list function
            case 'S': viewThis(listNUM); break; //View all elements
            case 'Q': quit();            break; //Print quit message
            default : notAllowed();      break; //Print not allowed message
        }
        remSpace();                             //Removes \n from buffer
    }while(choice != 'Q');                      //Quits the program
}

//Gets input from the user
void add(){
    printf("\nWhat would you like to add?\n");
    getchar();
    gets(activityList[0][listElements]);
    printf("Do you have any additional info for \"%s\"?\n", activityList[0]
           [listElements]);
    gets(activityList[1][listElements]);
    printf("What time would you like to %s?\n", activityList[0][listElements]);
    gets(activityList[2][listElements]);
    listElements++;
    printf("Added to list!\n\n");
}

//When input is not allowed
void notAllowed(){
    printf("%c is not an option.\n", choice);
}

//Prints menu
void menu(){
    printf("What would you like to do? (A, R, V, S, Q)\n");
    printf("A - Add to list\n");
    printf("R - Remove from list\n");
    printf("V - View list\n");
    printf("S - View Specific Element\n");
    printf("Q - Quit program\n");

    choice = getchar();
    choice = toupper(choice);
}

//Quits the program
void quit(){
    printf("You quit the program!\n");
}

//Remove from the list
void rem(){
    char removeName[50];            //What the user would like to remove

    if (listElements > 0) {
        printf("Type the name of the activity you would like to remove?\n");
        getchar();
        gets(removeName);
        for(int i = 0; i < listElements; i++){
            if (strcmp(removeName, activityList[0][i]) == 0) {
                moveElement = true;
                listElements--;
                printf("Removed activity %s. Your list now has %i elements.\n",
                       activityList[0][i], listElements);
            }
            
            if (moveElement == true) {
                strcpy(activityList[0][i], activityList[0][i+1]);
                strcpy(activityList[1][i], activityList[0][i+1]);
                strcpy(activityList[2][i], activityList[0][i+1]);
            }
        }
        
        if(moveElement == true){
            moveElement = false;
        }else{
            printf("Activity \"%s\" does not exist.\n", removeName);
        }
    }else{
        printf("The list is already empty.\n");
    }
    
}

//Removes \n from buffer
void remSpace(){
    if (choice != 'A' && choice != 'R') {
        getchar();
    }
}

//Prints entire list
void view(){
    if (listElements > 0) {
        printf("\nThis is the list:\n");
        int j = 0;
        for(int i = 0; i < listElements; i++){
            printf("Activity Number: %i\n", i+1);
            printf("Activity:    %s\n", activityList[0][j]);
            printf("Description: %s\n", activityList[1][j]);
            printf("Time:        %s\n", activityList[2][j]);
            j++;
        }
    }else{
        printf("Add something to the list before viewing it.\n");
    }
}

//View specific element
void viewThis(int listNUM){
    if (listElements > 0) {
        printf("What element would you like to view?\n");
        scanf("%i", &listNUM);
        listNUM -=1;
        
        printf("Displaying Activity Number: %i\n", listNUM+1);
        printf("Activity:    %s\n", activityList[0][listNUM]);
        printf("Description: %s\n", activityList[1][listNUM]);
        printf("Time:        %s\n", activityList[2][listNUM]);
    }else{
        printf("Add something to the list before viewing it.\n");
    }
}
