//
//  topsecret.c
//  Basics
//
//  Created by Eirik Hanasand on 19/09/2022.
//
//  Loops inside of loops to print different parts of strings to make a new string
//

#include <stdio.h>

int main(){
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    const char look[7] = "Okwonr";
    const char at[7] = "2sp-aa";
    const char this[7] = "C--eo}";
    const char weird[7] = "{psio";
    const char program[6] = "sdwle";
    for (n; n<6; n++) {
        for (i; i<7; i++) {
            printf("%c", look[i]);
            i++;
            break;
        }
        for (j; j<28; j++) {
            printf("%c", at[j]);
            j++;
            break;
        }
        for (k; k<28; k++) {
            printf("%c", this[k]);
            k++;
            break;
        }
        for (l; l<28; l++) {
            printf("%c", weird[l]);
            l++;
            break;
        }
        for (m; m<28; m++) {
            printf("%c", program[m]);
            m++;
            break;
        }
    }
    printf("\n");
    return 0;
}
