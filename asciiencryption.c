//
//  asciiencryption.c
//  Basics
//
//  Created by Eirik Hanasand on 27/09/2022.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int ASCIINRFORST = 33;
const int ASCIINRSIST = 126;
const int MOD = (ASCIINRSIST-ASCIINRFORST)+1;
const int CIPHER = 42;

int main(){
    char encryptedSign;
    int value;
    int newvalue;
    char array[20] = {0};
    char newarray[20] = {0};

    printf("Enter letter:\n");
    scanf("%s", &array);
    printf("%d", array);

    for (int i = 0; i < strlen(array); i++) {
        value = ((int)array[i] - ASCIINRFORST + CIPHER) % MOD;
        printf("Value is %i\n", value);
        int encryptedSign = value + ASCIINRFORST;
        printf("Encrypted sign: %c\n", encryptedSign);
        newarray[i]=(char)encryptedSign;
        printf("%s", newarray);
    }
}
