#include <stdio.h>

void makeCell(char array[], int arrayLen, int numCase){
    int i = 0;
    int c = 22 - arrayLen;
    printf("|––––––––––––––––––––––|");

    printf("|                      |");

    printf("|"); //printa il nome della casella
    for(; i!=22; i++){ 
        printf("%c", array[i]);
    }
    for(; c!=0; c--){
        printf(" ");
    }
    printf("|");
    
    printf("|                      |");
    printf("|                      |");

    printf("|                      |");
    printf("|                      |");
    printf("|                      |");
    printf("|                      |");
    printf("|                      |");
    printf("|______________________|");
}
  _____
 /  #  \
/| # # |\
 |[]___|
    
