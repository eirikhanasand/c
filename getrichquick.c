//
//  getrichquick.c
//  Basics
//
//  Created by Eirik Hanasand on 21/09/2022.
//
//  Game project, text based story where different actions have different consequences. 
//
#include <stdio.h>      //Used for printf, gets etc
#include <unistd.h>     //Used for sleep
#include <string.h>     //Used for strcmp
#include <ctype.h>      //Used for toupper
#include <stdbool.h>    //Used for bools
#include <time.h>       //Used to make a timer

int main(){
    int i = 0;          //Used in loops
    int money = 0;      //The amount of money the user has
    char choice[20];    //What the user would like to do
    
//============================ EVERY ITEM IN THE GAME ==============================
    
    //Things obtainable in the pet store
    bool cat        = false;
    bool fish       = false;
    bool dog        = false;
    bool squirrel   = false;
    bool sheep      = false;
    bool penguin    = false;
    bool panda      = false;
    bool tiger      = false;
    
    //Things obtainable in the food store
    bool banana     = false;
    bool apple      = false;
    bool grapes     = false;
    bool pineapple  = false;
    bool watermelon = false;
    bool cucumber   = false;
    bool carrot     = false;
    bool salad      = false;
    
    //Things obtainable in the neigbour section
    bool unused1    = false;
    bool unused2    = false;
    bool unused3    = false;
    
    //Things obtainable in the skill section
    bool unused4    = false;
    bool unused5    = false;
    bool unused6    = false;
    
    //Things obtainable in the casino section
    bool unused7    = false;
    bool unused8    = false;
    bool unused9    = false;
    
    //Things obtainable in the secret section
    bool unused10   = false;
    bool unused11   = false;
    bool unused12   = false;
    
    //Things obtainable in the test section
    bool unused13   = false;
    bool unused14   = false;
    bool unused15   = false;
    
//================================= INITIATE GAME ==================================

    printf("Get Rich Quick! The game where money is everything\n\n");
    sleep(1.5);
    printf("\"Man walks over\"\n");
    sleep(1);
    printf("Wow I see you are so poor...\n");
    sleep(1);
    printf("Here take 50 dollars, but spend them well!\n\n");
    money+=50;
    sleep(2);
    
//============================= ALL OPTIONS IN THE GAME =============================
    do{
        //If you have obtained something in the pet section
        if(cat == true){
            
        }
        if(fish == true){
            
        }
        if(dog == true){
            
        }
        if(squirrel == true){
            
        }
        if(sheep == true){
            
        }
        if(penguin == true){
            
        }
        if(panda == true){
            
        }
        if(tiger == true){
            
        }
       
        //If you have obtained something in the food store
        if(banana == true){
            
        }
        if(apple == true){
            
        }
        if(grapes == true){
            
        }
        if(pineapple == true){
            
        }
        if(watermelon == true){
            
        }
        if(cucumber == true){
            
        }
        if(carrot == true){
            
        }
        if(salad == true){
            
        }
        
        //Things obtainable in the neigbour section
        bool unused1    = false;
        bool unused2    = false;
        bool unused3    = false;
        
        //Things obtainable in the skill section
        bool unused4    = false;
        bool unused5    = false;
        bool unused6    = false;
        
        //Things obtainable in the casino section
        bool unused7    = false;
        bool unused8    = false;
        bool unused9    = false;
        
        //Things obtainable in the secret section
        bool unused10   = false;
        bool unused11   = false;
        bool unused12   = false;
        
        //Things obtainable in the test section
        bool unused13   = false;
        bool unused14   = false;
        bool unused15   = false;
        
        printf("\nSelect what you would like to do:\n");
        printf("1. Visit pet store\n");
        printf("2. Visit food store\n");
        printf("3. Walk to neighbour\n");
        printf("4. Learn a new skill\n");
        printf("5. Go to the casino\n");
        
        gets(choice);
        
//================================= CLOSE PROGRAM ===================================
        if(!strcmp(choice, "0")){
            printf("You closed the program with $%i. Have a nice day!\n", money);
            return 1;
            
            
            
//=================================== PET STORE =====================================
        
        }else if (!strcmp(choice, "1")){
            printf("Visiting pet store...\n");
            //What can you do in a pet store?
            printf("We have the following animals:\n");
            printf("$20    Cat\n");
            printf("$50    Fish\n");
            printf("$100   Dog\n");
            printf("$200   Squirrel\n");
            printf("$500   Sheep\n");
            printf("$1000  Penguin\n");
            printf("$5000  Panda (warning: big and dangerous)\n");
            printf("$10000 Tiger (warning: he bites)\n");
            
            printf("Would you like to buy anything?\n");
            gets(choice);
            
            if(!strcmp(choice, "yes") || !strcmp(choice, "y") || !strcmp(choice, "YES")){
                printf("What would you like to buy?\n");
            
                gets(choice);
                tolower(choice);
                
                if (!strcmp(choice, "1") || !strcmp(choice, "cat")){
                    printf("You purchased the cat.\n");
                    cat = true;
                }
                if (!strcmp(choice, "2") || !strcmp(choice, "fish")){
                    printf("You purchased the fish.\n");
                    fish = true;
                }
                
                
            }
        
//==================================== FOOD STORE =================================
        
        }else if(!strcmp(choice, "2")){
            printf("Visiting food store...\n");
            //What can you do in a food store?
            printf("What would you like to eat?\n");
        
        
        
//================================ NEIGHBOUR SECTION ===============================
        
        }else if(!strcmp(choice, "3")){
            printf("Walking to neighbour\n");
            //What does the neighbour have to offer?
        

        
//=================================== SKILL SECTION =================================
        
        }else if(!strcmp(choice, "4")){
            printf("What skill would you like to learn?\n");
            //Give a list of skills with different abilities

            
            
//=================================== CASINO SECTION =================================
        }else if(!strcmp(choice, "5")){
            printf("Welcome to the casino!\n");
            //Give a list of skills with different abilities
        
        
//================================== SECRET SECTION ==================================
        
        }else if(!strcmp(choice, "6")){
            printf("Wow! You found a secret path.. wonder where it leads?\n");
        
            //Follow / dont follow path
            
            printf("Wow a big pile of gold!\n");
            
            printf("You sold the gold and made $50000\n");
            money+=50000;
            
            
            
//================================== TEST SECTION ====================================
        }else if(!strcmp(choice, "7")){
            printf("You got robbed!\n");
            
            money = 0;
            
        }else{
            printf("Your choice is not allowed (1-7)");
        }
        
        
    //Ends the do loop
    }while(money!=0);
        
        
    
//============================== END OF PROGRAM SECTION ==============================

    if(money >= 1000){
        printf("Well done, $%i is impressive!\n", money);
    }else if(money >= 10000){
        printf("Over $10000? $%i is very impressive!\n", money);
    }else if(money >= 100000){
        printf("Damn, $%i is a lot of money!\n", money);
    }else if(money >= 1000000){
        printf("Look at the billionaire! If you only had $%i in real life as well...\n", money);
    }else if(money >= 10000000){
        printf("Youre so rich im lost for words! Well done on your $%i fortune!\n", money);
    }else{
        printf("$%i cant buy you much... Better luck next time!\n", money);
    }
    
    return 0;
}
