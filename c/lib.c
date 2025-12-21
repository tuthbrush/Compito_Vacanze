#include <stdio.h>

void makeCell(char array[], int arrayLen, int numCase[], int cellaAttuale){
    int i = 0;
    int c = 22 - arrayLen;
    printf("\n|––––––––––––––––––––––|\n");
    printf("|                      |\n");

    printf("|"); //printa il nome della casella
    for(; i!=22; i++){ 
        printf("%c", array[i]);
    }
    for(; c!=0; c--){
        printf(" ");
    }
    printf("|\n");
    
    switch(numCase[cellaAttuale]){
        case 0:
            printf("|                      |\n");
            printf("|                      |\n");
            printf("|                      |\n");
            printf("|                      |\n");
            printf("|                      |\n");
            printf("|––––––––––––––––––––––|\n");
            break;
        case 1:
            printf("|                      |\n");
            printf("|   _____              |\n");
            printf("|  /  #  \\             |\n");
            printf("| /| # # |\\            |\n");
            printf("|  |[]___|             |\n");
            printf("|––––––––––––––––––––––|\n");
            break;
        case 2:
            printf("|                      |\n");
            printf("|   _____      _____   |\n");
            printf("|  /  #  \\    /  #  \\  |\n");
            printf("| /| # # |\\  /| # # |\\ |\n");
            printf("|  |[]___|    |[]___|  |\n");
            printf("|––––––––––––––––––––––|\n");
            break;
    }
}
/*
  _____
 /  #  \
/| # # |\
 |[]___|
    
*/