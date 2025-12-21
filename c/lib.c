#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void makeBoard(char array[24][22], int numCase[], int cellaAttuale){
    int i = 0;
    int arrayLen = 0;
    int c = 0;
    int layer = 0;
    int word = 0;


    if(layer == 0 || layer == 6){

        for(i = 0; i<=6; i++){
            printf("|––––––––––––––––––––––|");
        }

        printf("\n");

        for(i = 0; i<=6; i++){
            printf("|                      |");
        }

        printf("\n");
        
        arrayLen = strlen(array[word]);
        c = arrayLen - 22;
        
        for(i = 0; i <= 6; i++){
            printf("|"); //printa il nome della casella
            printf("%c", array[word]);
            arrayLen = strlen(array[word]);
            c = arrayLen - 22;
            for(; c!=0; c--){
                printf(" ");
            }
            printf("|");
        }

        printf("\n");
            
        for(i = 0; i<=6; i++){
            printf("|                      |");
        }

        printf("\n");

        switch(numCase[cellaAttuale]){
            case 0:
                for(i = 0; i<=6; i++){
                    printf("|                      |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("|                      |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("|                      |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("|                      |");
                }

                break;
            case 1:
                for(i = 0; i<=6; i++){
                    printf("|   _____              |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("|  /  #  \\             |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("| /| # # |\\            |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("||  |[]___|             |");
                }

                break;
            case 2:
                for(i = 0; i<=6; i++){
                    printf("|   _____      _____   |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("|  /  #  \\    /  #  \\  |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("| /| # # |\\  /| # # |\\ |");
                }
                printf("\n");
                for(i = 0; i<=6; i++){
                    printf("|  |[]___|    |[]___|  |");
                }

                break;
            }

            printf("\n");

            for(i = 0; i<=6; i++){
                    printf("|––––––––––––––––––––––|");
                }
        }
    } 

/*
  _____
 /  #  \
/| # # |\
 |[]___|
    
*/