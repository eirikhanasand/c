#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int POS = 9;

//void emptyboard(void);
void board(void);

int main(){
    
    board();
    
    return 0;
}

void board(void){
    char pos[10] ={48, 49 , 50, 51, 52, 53, 54, 55, 56, 57};
    char x = 'x';
    char o = 'o';
    int desiredPosition = 0;
    int turn = 0;
    int logicArray[POS][POS];
    int available = 0;
    
    for (int i = 0; i < POS; i++) {
        for (int j = 0; j < POS; j++) {
            logicArray[i][j] = 0;
        }
    }
    
    do {
//      ================================ PLAYER O ================================
        if (turn % 2) {
            printf("\n\n\t\t\t\tPlayer O!\n");
            printf("\n\n");
            
            for (int i = 0; i < POS-2; i++) {
                printf("%17c %3c %3c\n\n", pos[i+1], pos[i+2], pos[i+3]);
                i+=2;
            }
            
            scanf("%i", &desiredPosition);
            
            for (int i = 0; i <= POS; i++) {
                if(desiredPosition+48 == pos[i]){
                    printf("You chose %i\n", i);
                    pos[i] = o;
                }
            }
            available = 0;
        
//      ============================== PLAYER X ===============================
               
        }else{
            printf("\n\n\t\t\t\tPlayer X!\n");
            printf("\n\n");
            
            for (int i = 0; i < POS-2; i++) {
                printf("%17c %3c %3c\n\n", pos[i+1], pos[i+2], pos[i+3]);
                i+=2;
            }
            
            scanf("%i", &desiredPosition);
            for (int i = 0; i <= POS; i++) {
                if(desiredPosition+48 == pos[i]){
                    printf("You chose %i\n", i);
                    pos[i] = x;
                }
            }
        }
    
//      =============================== WINNER LOGIC ================================
        
        //Logic for X
        for (int i = 0; i <= POS; i++) {
            if (pos[1] == x && pos[2] == x && pos[3] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }else if (pos[4] == x && pos[5] == x && pos[6] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }else if (pos[7] == x && pos[8] == x && pos[9] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }else if (pos[1] == x && pos[4] == x && pos[7] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }else if (pos[2] == x && pos[5] == x && pos[8] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }else if (pos[3] == x && pos[6] == x && pos[9] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }else if (pos[1] == x && pos[5] == x && pos[9] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }else if (pos[3] == x && pos[5] == x && pos[7] == x) {
                printf(" %17c won!", x);
                desiredPosition = 0;
                break;
            }
        }
        
        //Logic for O
        for (int i = 0; i <= POS; i++) {
            if (pos[1] == o && pos[2] == o && pos[3] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
            }else if (pos[4] == o && pos[5] == o && pos[6] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
            }else if (pos[7] == o && pos[8] == o && pos[9] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
            }else if (pos[1] == o && pos[4] == o && pos[7] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
            }else if (pos[2] == o && pos[5] == o && pos[8] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
            }else if (pos[3] == o && pos[6] == o && pos[9] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
            }else if (pos[1] == o && pos[5] == o && pos[9] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
            }else if (pos[3] == o && pos[5] == o && pos[7] == o) {
                printf(" %17c won!", o);
                desiredPosition = 0;
                break;
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
            break;
        }
        
        turn++;
        
    } while (desiredPosition != 0);
    
    printf("\n\n");
    for (int i = 0; i < POS-2; i++) {
        printf("%17c %3c %3c\n\n", pos[i+1], pos[i+2], pos[i+3]);
        i+=2;
    }
}
