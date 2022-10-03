//
//  todolist.c
//  Basics
//
//  Created by Eirik Hanasand on 06/09/2022.
//
//  This program makes a to-do list where you can add or remove items, or view the entire list
//
//  WIP
//
//  Things that need to be done:
//  Way to view a specific activity in the list
//  Store in file
//  Make a better interface
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char add[] = "add";           //Const add used when adding something to the list.
const char view[] = "view";         //Const view used when viewing the entire list.
const char rem[] = "remove";        //Const remove used when removing elements.
const char quit[] = "quit";         //Const quit used for closing the program.

int main(){
    int i = 0;                      //Used by for loops
    int j = 0;                      //Used by for loops inside i loops
    int jlistend = 0;               //Used to check when the activityList ends so it doesnt loop forever
    char choice[10];                //Determines what the user would like to do
    char removeName[50];            //Name of the activity the user would like to remove
    char activityList[3][50][100];  //List used to store name, description and time of activity
    bool move = false;
//    char yes[] = "yes";

    do{

//      Asks the user what they want to do (view, add, remove, quit)
        printf("What would you like to do? (view, add, remove, quit)\n");
        gets(choice);

//      Add section
        if(strcmp(choice, add) == 0){
            
            //Gets input from the user
            printf("\nWhat would you like to add?\n");
            gets(activityList[0][jlistend]);
            printf("Do you have any additional info for \"%s\"?\n", activityList[0][jlistend]);
            gets(activityList[1][jlistend]);
            printf("What time would you like to %s?\n", activityList[0][jlistend]);
            gets(activityList[2][jlistend]);
            
            jlistend++;
//      Remove section
        }else if(strcmp(choice, rem) == 0){
            if (jlistend > 0) {
                printf("Type the name of the activity you would like to remove?\n");
                gets(removeName);
                for(int i = 0; i < jlistend; i++){
                    if (strcmp(removeName, activityList[0][i]) == 0) {
                        move = true;
                        jlistend--;
                        printf("Removed activity %s. Your list now has %i elements.\n", activityList[0][i], jlistend);
                    }
                    
                    if (move == true) {
                        strcpy(activityList[0][i], activityList[0][i+1]);
                        strcpy(activityList[1][i], activityList[0][i+1]);
                        strcpy(activityList[2][i], activityList[0][i+1]);
                    }
                    
                }
                
                if(move == true){
                    move = false;
                }else{
                    printf("Activity \"%s\" does not exist.\n", removeName);
                }
            }else{
                printf("The list is already empty.\n");
            }
            
//      View section
        }else if(strcmp(choice, view) == 0){
            if (jlistend > 0) {
                printf("\nThis is the list:\n");
                j=0;
                for(i=0; i < jlistend; i++){
                    printf("Activity Number: %i\n", i+1);
                    printf("Activity:    %s\n", activityList[0][j]);
                    printf("Description: %s\n", activityList[1][j]);
                    printf("Time:        %s\n", activityList[2][j]);
                    j++;
                }
            }else{
                printf("Add something to the list before viewing it.\n");
            }
        }else if(strcmp(choice, quit) == 0){
            return 1;
        }else{
            printf("%s is not an allowed choice\n", choice);

        }
        
    //Going to be used as a exit program function later on
    }while(choice != 'X');
    return 0;
}
