//
//  tictactoe.c
//  Basics
//
//  Created by Eirik Hanasand on 03/10/2022.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int POS = 9;

void emptyboard(void);
void board(void);

int main(){
    emptyboard();
    
    board();
    
    return 0;
}

void emptyboard(void){
    printf("Welcome to tictactoe. You will be player X!\n");
    printf("You pick a spot using the numbers 1-9.\n");
    sleep(3);
    printf("\n\n\t\t\tThe board is yours!\n");
    printf("\n\n");
    
    for (int i = 0; i < POS-2; i++) {
        printf("%17i %3i %3i\n\n", i+1, i+2, i+3);
        i+=2;
    }
}

void board(void){
    char pos[10] ={48, 49 , 50, 51, 52, 53, 54, 55, 56, 57};
    char x = 'x';
    char o = 'o';
    int desiredPosition = 0;
    int Xcheck[POS];
    int Ocheck[POS];
    int logicArray[POS][POS];
    int hasdecided = 0;
    int available = 0;
    
    for (int i = 0; i < POS; i++) {
        for (int j = 0; j < POS; j++) {
            logicArray[i][j] = 0;
        }
    }
    
    do {
//      ================================ USER INPUT ================================
        
        scanf("%i", &desiredPosition);
        
        for (int i = 0; i < 10; i++) {
            Xcheck[i] = i;
            Ocheck[i] = i;
        }
        
        for (int i = 0; i <= POS; i++) {
            if(desiredPosition+48 == pos[i]){
                printf("You chose %i\n", i);
                pos[i] = x;
            }
        }
        hasdecided = 0;
        available = 0;
        
//      ============================== COMPUTER LOGIC ===============================
        
//      ---- CASES TO WIN IN ONE MOVE ----
        //case1.1
        if (pos[1] == o && pos[2] == o && pos[3] != x && pos[3] != o && hasdecided == 0){
            pos[3] = o;
            hasdecided = 1;
        }
        
        //case1.2
        if (pos[2] == o && pos[3] == o && pos[1] != x && pos[1] != o && hasdecided == 0){
            pos[1] = o;
            hasdecided = 1;
        }
        
        //case1.3
        if (pos[1] == o && pos[3] == o && pos[2] != x && pos[2] != o && hasdecided == 0){
            pos[2] = o;
            hasdecided = 1;
        }
        
        //case2.1
        if (pos[4] == o && pos[5] == o && pos[6] != x && pos[6] != o && hasdecided == 0){
            pos[6] = o;
            hasdecided = 1;
        }
        //case2.2
        if (pos[5] == o && pos[6] == o && pos[4] != x && pos[4] != o && hasdecided == 0){
            pos[4] = o;
            hasdecided = 1;
        }
        
        //case2.3
        if (pos[4] == o && pos[6] == o && pos[5] != x && pos[5] != o && hasdecided == 0) {
            pos[5] = o;
            hasdecided = 1;
        }
        
        //case3.1
        if (pos[7] == o && pos[8] == o && pos[9] != x && pos[9] != o && hasdecided == 0) {
            pos[9] = o;
            hasdecided = 1;
        }
        
        //case3.2
        if (pos[8] == o && pos[9] == o && pos[7] != x && pos[7] != o && hasdecided == 0) {
            pos[7] = o;
            hasdecided = 1;
        }
        
        //case3.3
        if (pos[7] == o && pos[9] == o && pos[8] != x && pos[8] != o && hasdecided == 0){
            pos[8] = o;
            hasdecided = 1;
        }
        
        //case4.1
        if (pos[1] == o && pos[4] == o && pos[7] != x && pos[7] != o && hasdecided == 0){
            pos[7] = o;
            hasdecided = 1;
        }
        
        //case4.2
        if (pos[1] == o && pos[7] == o && pos[4] != x && pos[4] != o && hasdecided == 0){
            pos[4] = o;
            hasdecided = 1;
        }
        
        //case4.3
        if (pos[4] == o && pos[7] == o && pos[1] != x && pos[1] != o && hasdecided == 0){
            pos[1] = o;
            hasdecided = 1;
        }
        
        //case5.1
        if (pos[2] == o && pos[5] == o && pos[8] != x && pos[8] != o && hasdecided == 0){
            pos[8] = o;
            hasdecided = 1;
        }
        //case5.2
        if (pos[2] == o && pos[8] == o && pos[5] != x && pos[5] != o && hasdecided == 0){
            pos[5] = o;
            hasdecided = 1;
        }
        
        //case5.3
        if (pos[5] == o && pos[8] == o && pos[2] != x && pos[2] != o && hasdecided == 0){
            pos[2] = o;
            hasdecided = 1;
        }
        
        //case6.1
        if (pos[3] == o && pos[6] == o && pos[9] != x && pos[9] != o && hasdecided == 0){
            pos[9] = o;
            hasdecided = 1;
        }
        
        //case6.2
        if (pos[3] == o && pos[9] == o && pos[6] != x && pos[6] != o && hasdecided == 0){
            pos[6] = o;
            hasdecided = 1;
        }
        
        //case6.3
        if (pos[6] == o && pos[9] == o && pos[3] != x && pos[3] != o && hasdecided == 0){
            pos[3] = o;
            hasdecided = 1;
        }
        
        //case7.1
        if (pos[1] == o && pos[5] == o && pos[9] != x && pos[9] != o && hasdecided == 0){
            pos[9] = o;
            hasdecided = 1;
        }
        
        //case7.2
        if (pos[1] == o && pos[9] == o && pos[5] != x && pos[5] != o && hasdecided == 0){
            pos[5] = o;
            hasdecided = 1;
        }
        //case7.3
        if (pos[5] == o && pos[9] == o && pos[1] != x && pos[1] != o && hasdecided == 0){
            pos[1] = o;
            hasdecided = 1;
        }
        
        //case8.1
        if (pos[3] == o && pos[5] == o && pos[7] != x && pos[7] != o && hasdecided == 0) {
            pos[7] = o;
            hasdecided = 1;
        }
        
        //case8.2
        if (pos[3] == o && pos[7] == o && pos[5] != x && pos[5] != o && hasdecided == 0) {
            pos[5] = o;
            hasdecided = 1;
        }
        //case8.3
        if (pos[5] == o && pos[7] == o && pos[1] != x && pos[3] != o && hasdecided == 0) {
            pos[3] = o;
            hasdecided = 1;
        }
        
        
//      ---- TO PREVENT X FROM WINNING ----
        //case1.1
        if (pos[1] == x && pos[2] == x && pos[3] != x && pos[3] != o && hasdecided == 0 && logicArray[1][1] == 0) {
            pos[3] = o;
            hasdecided = 1;
            logicArray[1][1] = 1;
        }
        
        //case1.2
        if (pos[2] == x && pos[3] == x && pos[1] != x && pos[1] != o && hasdecided == 0 && logicArray[1][2] == 0) {
            pos[1] = o;
            hasdecided = 1;
            logicArray[1][2] = 1;
        }
        
        //case1.3
        if (pos[1] == x && pos[3] == x && pos[2] != x && pos[2] != o && hasdecided == 0 && logicArray[1][3] == 0) {
            pos[2] = o;
            hasdecided = 1;
            logicArray[1][3] = 1;
        }
        
        //case2.1
        if (pos[4] == x && pos[5] == x && pos[6] != x && pos[6] != o && hasdecided == 0 && logicArray[2][1] == 0) {
            pos[6] = o;
            hasdecided = 1;
            logicArray[2][1] = 1;
        }
        //case2.2
        if (pos[5] == x && pos[6] == x && pos[4] != x && pos[4] != o && hasdecided == 0 && logicArray[2][2] == 0) {
            pos[4] = o;
            hasdecided = 1;
            logicArray[2][2] = 1;
        }
        
        //case2.3
        if (pos[4] == x && pos[6] == x && pos[5] != x && pos[5] != o && hasdecided == 0 && logicArray[2][3] == 0) {
            pos[5] = o;
            hasdecided = 1;
            logicArray[2][3] = 1;
        }
        
        //case3.1
        if (pos[7] == x && pos[8] == x && pos[9] != x && pos[9] != o && hasdecided == 0 && logicArray[3][1] == 0) {
            pos[9] = o;
            hasdecided = 1;
            logicArray[3][1] = 1;
        }
        
        //case3.2
        if (pos[8] == x && pos[9] == x && pos[7] != x && pos[7] != o && hasdecided == 0 && logicArray[3][2] == 0) {
            pos[7] = o;
            hasdecided = 1;
            logicArray[3][2] = 1;
        }
        
        //case3.3
        if (pos[7] == x && pos[9] == x && pos[8] != x && pos[8] != o && hasdecided == 0 && logicArray[3][3] == 0) {
            pos[8] = o;
            hasdecided = 1;
            logicArray[3][3] = 1;
        }
        
        //case4.1
        if (pos[1] == x && pos[4] == x && pos[7] != x && pos[7] != o && hasdecided == 0 && logicArray[4][1] == 0) {
            pos[7] = o;
            hasdecided = 1;
            logicArray[4][1] = 1;
        }
        
        //case4.2
        if (pos[1] == x && pos[7] == x && pos[4] != x && pos[4] != o && hasdecided == 0 && logicArray[4][2] == 0) {
            pos[4] = o;
            hasdecided = 1;
            logicArray[4][2] = 1;
        }
        
        //case4.3
            if (pos[4] == x && pos[7] == x && pos[1] != x && pos[1] != o && hasdecided == 0 && logicArray[4][3] == 0) {
            pos[1] = o;
            hasdecided = 1;
            logicArray[4][3] = 1;
        }
        
        //case5.1
        if (pos[2] == x && pos[5] == x && pos[8] != x && pos[8] != o && hasdecided == 0 && logicArray[5][1] == 0) {
            pos[8] = o;
            hasdecided = 1;
            logicArray[5][1] = 1;
        }
        //case5.2
        if (pos[2] == x && pos[8] == x && pos[5] != x && pos[5] != o && hasdecided == 0 && logicArray[5][2] == 0) {
            pos[5] = o;
            hasdecided = 1;
            logicArray[5][2] = 1;
        }
        
        //case5.3
        if (pos[5] == x && pos[8] == x && pos[2] != x && pos[2] != o && hasdecided == 0 && logicArray[5][3] == 0) {
            pos[2] = o;
            hasdecided = 1;
            logicArray[5][3] = 1;
        }
        
        //case6.1
        if (pos[3] == x && pos[6] == x && pos[9] != x && pos[9] != o && hasdecided == 0 && logicArray[6][1] == 0) {
            pos[9] = o;
            hasdecided = 1;
            logicArray[6][1] = 1;
        }
        
        //case6.2
        if (pos[3] == x && pos[9] == x && pos[6] != x && pos[6] != o && hasdecided == 0 && logicArray[6][2] == 0) {
            pos[6] = o;
            hasdecided = 1;
            logicArray[6][2] = 1;
        }
        
        //case6.3
        if (pos[6] == x && pos[9] == x && pos[3] != x && pos[3] != o && hasdecided == 0 && logicArray[6][3] == 0) {
            pos[3] = o;
            hasdecided = 1;
            logicArray[6][3] = 1;
        }
        
        //case7.1
        if (pos[1] == x && pos[5] == x && pos[9] != x && pos[9] != o && hasdecided == 0 && logicArray[7][1] == 0) {
            pos[9] = o;
            hasdecided = 1;
            logicArray[7][1] = 1;
        }
        
        //case7.2
        if (pos[1] == x && pos[9] == x && pos[5] != x && pos[5] != o && hasdecided == 0 && logicArray[7][2] == 0) {
            pos[5] = o;
            hasdecided = 1;
            logicArray[7][2] = 1;
        }
        //case7.3
        if (pos[5] == x && pos[9] == x && pos[1] != x && pos[1] != o && hasdecided == 0 && logicArray[7][3] == 0) {
            pos[1] = o;
            hasdecided = 1;
            logicArray[7][3] = 1;
        }
        
        //case8.1
        if (pos[3] == x && pos[5] == x && pos[7] != x && pos[7] != o && hasdecided == 0 && logicArray[8][1] == 0) {
            pos[7] = o;
            hasdecided = 1;
            logicArray[8][1] = 1;
        }
        
        //case8.2
        if (pos[3] == x && pos[7] == x && pos[5] != x && pos[5] != o && hasdecided == 0 && logicArray[8][2] == 0) {
            pos[5] = o;
            hasdecided = 1;
            logicArray[8][2] = 1;
        }
        //case8.3
        if (pos[5] == x && pos[7] == x && pos[1] != x && pos[3] != o && hasdecided == 0 && logicArray[8][3] == 0) {
            pos[3] = o;
            hasdecided = 1;
            logicArray[8][3] = 1;
        }
        
        //Default cases if no way to lose / win
        if (pos[5] != x && pos[5] != o && hasdecided == 0 && logicArray[5][5] == 0) {
            pos[5] = o;
            hasdecided = 1;
            logicArray[5][5] = 1;
        }
        if (pos[2] != x && pos[2] != o && hasdecided == 0 && logicArray[5][6] == 0) {
            pos[2] = o;
            hasdecided = 1;
            logicArray[5][6] = 1;
        }
        if (pos[4] != x && pos[4] != o && hasdecided == 0 && logicArray[5][7] == 0) {
            pos[4] = o;
            hasdecided = 1;
            logicArray[5][7] = 1;
        }
        if (pos[6] != x && pos[6] != o && hasdecided == 0 && logicArray[5][8] == 0) {
            pos[6] = o;
            hasdecided = 1;
            logicArray[5][8] = 1;
        }
        if (pos[8] != x && pos[8] != o && hasdecided == 0 && logicArray[5][4] == 0) {
            pos[8] = o;
            hasdecided = 1;
            logicArray[5][4] = 1;
        }
        
        
//      =============================== WINNER LOGIC ================================
        
        //Logic for X
        for (int i = 0; i <= POS; i++) {
            if (pos[1] == x && pos[2] == x && pos[3] == x && desiredPosition != 0) {
                printf("%17c won!", x);
                desiredPosition = 0;
            }else if (pos[4] == x && pos[5] == x && pos[6] == x && desiredPosition != 0) {
                printf("%17c won!", x);
                desiredPosition = 0;
            }else if (pos[7] == x && pos[8] == x && pos[9] == x && desiredPosition != 0) {
                printf(" %17c won!", x);
                desiredPosition = 0;
            }else if (pos[1] == x && pos[4] == x && pos[7] == x && desiredPosition != 0) {
                printf(" %17c won!", x);
                desiredPosition = 0;
            }else if (pos[2] == x && pos[5] == x && pos[8] == x && desiredPosition != 0) {
                printf(" %17c won!", x);
                desiredPosition = 0;
            }else if (pos[3] == x && pos[6] == x && pos[9] == x && desiredPosition != 0) {
                printf(" %17c won!", x);
                desiredPosition = 0;
            }else if (pos[1] == x && pos[5] == x && pos[9] == x && desiredPosition != 0) {
                printf(" %17c won!", x);
                desiredPosition = 0;
            }else if (pos[3] == x && pos[5] == x && pos[7] == x && desiredPosition != 0) {
                printf(" %17c won!", x);
                desiredPosition = 0;
            }
        }
        
        //Logic for O
        for (int i = 0; i <= POS; i++) {
            if (pos[1] == o && pos[2] == o && pos[3] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }else if (pos[4] == o && pos[5] == o && pos[6] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }else if (pos[7] == o && pos[8] == o && pos[9] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }else if (pos[1] == o && pos[4] == o && pos[7] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }else if (pos[2] == o && pos[5] == o && pos[8] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }else if (pos[3] == o && pos[6] == o && pos[9] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }else if (pos[1] == o && pos[5] == o && pos[9] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }else if (pos[3] == o && pos[5] == o && pos[7] == o && desiredPosition != 0) {
                printf(" %17c won!", o);
                desiredPosition = 0;
            }
        }
        
        //Logic for draw
        for (int i = 0; i <= POS; i++) {
            if (pos[i] != x && pos[i] != o) {
                available++;
            }
        }
        
        if (available-1 == 0) {
            printf("\t\t\t\t Draw!");
            desiredPosition = 0;
        }
        
//      ============================== PRINTING BOARD ===============================

        printf("\n\n");
        
        for (int i = 0; i < POS-2; i++) {
            printf("%17c %3c %3c\n\n", pos[i+1], pos[i+2], pos[i+3]);
            i+=2;
        }
    } while (desiredPosition != 0);
    
}
