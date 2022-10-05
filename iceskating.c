//
//  iceskating.c
//  Basics
//
//  Created by Eirik Hanasand on 29/09/2022.
//

#include <stdio.h>          //Included for printf etc

const int MAXSKATERS = 10;  //Const max skaters
const int DISTANCES = 5;    //Const amount of distances

int main(){
    
    //Distance array
    int distance[DISTANCES] = {500, 1000, 1500, 5000, 10000};
    
    float points = 0;           //How many points the user get
    int enteredDistance = 0;    //Entered by users
    int amt500 = 0;             //How many 500 meters in input
    int skaterCount = 0;        //How many iceskaters
    int legal = 0;              //If distance input is legal
    int illegal = 0;            //if distance input is not legal
    int minutes = 0;            //Minutes input
    int seconds = 0;            //Seconds input
    int milliseconds = 0;       //Milliseconds input
    int i = 0;                  //Used by loops
    char again;                 //Asks to rerun program
    
    do {
        
        do{ //Runs till input is legal
            //User input distance
            printf("Input iceskating distance: (500,1000,1500,5000,10000)\n");
            scanf("%i", &enteredDistance);
            
            //Checks if distance is legal
            for (int i = 0; i < DISTANCES; i++) {
                if(enteredDistance == distance[i]){
                    legal++;
                }
            }
            
        }while(legal == 0); //Runs till input is legal
        legal = 0;          //Resets legal count
        
        //Calculates amount of 500 meters in input
        for (i = 0; i < enteredDistance; i+=500) {
            amt500++;
        }
        
        
        do{ //Runs till input is legal
            printf("How many iceskaters? (max %i)\n", MAXSKATERS);
            scanf("%i", &skaterCount);
            //printf("Du skrev: %i\n", antLopere);
            
            //Runs till skatercount is legal
            for (i = 0; i < skaterCount; i++) {
                if(0 < skaterCount && MAXSKATERS >= skaterCount){
                    legal++;
                }
            }
            
            //Runs till input is legal
        }while(legal == 0);
        legal = 0;
        
//      Input time for iceskaters
        for (i = 0; i < skaterCount; i++) {
            printf("Enter time for skater: %i\n", i+1);
            
            //Runs till minutes seconds and milliseconds are legal values
            do {
                //Gets minutes
                printf("Minutes:");
                scanf("%i", &minutes);
                
                //Gets seconds
                printf("Seconds:");
                scanf("%i", &seconds);
                
                //Gets milliseconds
                printf("Milliseconds:");
                scanf("%i", &milliseconds);
                
                //Checks if minutes seconds or milliseconds are illegal
                illegal = 0;
                if (minutes < 0 || minutes > 60) {
                    illegal++;
                }else if (seconds < 0 || seconds > 60) {
                    illegal++;
                }else if (milliseconds < 0 || milliseconds > 60) {
                    illegal++;
                }
                
            //Runs till minutes seconds and milliseconds are legal values
            } while (illegal > 0);
            
            //Calculates points
            points = (float)((minutes * 60 + seconds + (float)(milliseconds / 100.0) ) / amt500);
            
            //Prints the points
            printf("This skater got %.3f points\n", points);
        }
        
        //Asks the user if they would like tor un the program again
        printf("Again? (Y/n)\n");
        scanf(" %c", &again);
        
//  Runs again if the user did not input n
    } while (again != 'n');
    
//  Terminates the program
    return 0;
}
