//
//  personInfo.c
//  Basics
//
//  Created by Eirik Hanasand on 04/10/2022.
//

#include "personInfo.h"

const int MAXPEOPLE = 10;
Person person[10];

int main(){
    int howMany = 0;
    int totalAge = 0;
    int totalWeight = 0;
    int oldest = 0;
    int oldestID = 0;

    printf("How many people would you like to input data for?\n");
    scanf("%d", &howMany);
    
    if (howMany > MAXPEOPLE) {
        howMany = MAXPEOPLE;
    }else if (howMany < 0){
        howMany = 1;
    }
    
    for (int i = 0; i < howMany; i++) {
        printf("Enter name, age and weight (person %i):\n", i+1);
        scanf("%s %d %f", person[i].name, &person[i].age, &person[i].weight);
    }
    
    
    for (int i = 0; i < howMany; i++) {
        totalAge += person[i].age;
        totalWeight += person[i].weight;
        
        if (person[i].age > oldest) {
            oldest = person[i].age;
            oldestID = i;
        }
    }

    printf("These are the people:\n");
    for (int i = 0; i < howMany; i++) {
        printf("Person: %i, Name: %s, Age: %d, Weight: %.1f\n", i+1, person[i].name, person[i].age, person[i].weight);
    }

    printf("\nTotal age:     %d\n", totalAge);
    printf("\nAvg weight:    %d\n", totalWeight / howMany);
    printf("\nOldest person: %d\n", person[oldestID].age);
    printf("Person: %i, Name: %s, Age: %d, Weight: %.1f\n", oldestID+1, person[oldestID].name, person[oldestID].age, person[oldestID].weight);
    
    return 0;
}
