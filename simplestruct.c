//
//  simplestruct.c
//  Basic
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#include <stdio.h>

const int STRLEN = 20;

typedef struct {
    int length;
    int width;
    int height;
} cube;

typedef struct {
    int x;
    int y;
} position;

typedef struct{
    char owner[STRLEN];
    cube cube;
    position position;
} buildingPlan;
int main(){
    
    cube myCube = {5, 10, 15};
    printf("Enter length, width, height:\n");
    scanf("%i %i %i", &myCube.length, &myCube.width, &myCube.height);
    printf("Length: %i. Width: %i. Height: %i.\n", myCube.length, myCube.width, myCube.height);
    return 0;
}

// AS SIMPLE AS IT GETS
//
//struct cube {
//    int length;
//    int width;
//    int height;
//};
//
//int main(){
//
//    struct cube myCube = {5, 10, 15};
//    printf("Enter length, width, height:\n");
//    scanf("%i %i %i", &myCube.length, &myCube.width, &myCube.height);
//    printf("Length: %i. Width: %i. Height: %i.\n", myCube.length, myCube.width, myCube.height);
//    return 0;
//}
