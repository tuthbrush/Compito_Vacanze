#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"

void makeCell(char word[], int wordLen, int numCase){
    int i = 0;
    int c = 22 - wordLen;
    printf("|––––––––––––––––––––––|\n");

    printf("|                      |\n");

    printf("|"); //printa il nome della casella
    for(; i!=22; i++){ 
        printf("%c", word[i]);
    }
    for(; c!=0; c--){
        printf(" ");
    }
    printf("|\n");
    
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|   _____              |\n");
    printf("|  /  #  \\             |\n");
    printf("| /| # # |\\            |\n");
    printf("|  |[]___|             |\n");
    printf("|                      |\n");
    printf("|––––––––––––––––––––––|\n");
}   

int main()
{
    char word[22] = {"palline"};
    int Len = strlen(word);
    int numcase = 0;

    makeCell(word, Len, numcase);

    return 0;
}