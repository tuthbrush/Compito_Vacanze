#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void makeBoard(char array[24][22], int numCase[], int cellaAttuale){
    int i = 0;
    int arrayLen = 0;
    int c = 0;
    int layer = 0;
    int word = 0;
    int contatore = 0;

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
        c = 22 - arrayLen;
        
        for(i = 0; i <= 6; i++){
            printf("|"); //printa il nome della casella
            arrayLen = strlen(array[word]);
            for(contatore = 0; contatore != arrayLen; contatore++){
                printf("%c", array[word][contatore]);
            }
            for(c = 21   - arrayLen; c>=0; c--){
                printf(" ");
            }
            printf("|");
            word++;
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
        else{

            printf("|––––––––––––––––––––––|");
            for(i = 0; i<=4; i++){
                printf("                        ");
            }
            printf("|––––––––––––––––––––––|");

            printf("\n");

            printf("|                      |");
            for(i = 0; i<=4; i++){
                printf("                        ");
            }
            printf("|                      |");

            printf("\n");
            
            arrayLen = strlen(array[word]);
            c = 22 - arrayLen;
            
            for(i = 0; i <= 6; i++){
                    if(i == 0 || i == 6){
                    printf("|"); //printa il nome della casella
                    arrayLen = strlen(array[word]);
                    for(contatore = 0; contatore != arrayLen; contatore++){
                        printf("%c", array[word][contatore]);
                    }
                    for(c = 21   - arrayLen; c>=0; c--){
                        printf(" ");
                    }
                    printf("|");
                    word++;
                }
                else{
                    printf("                        ");
                }
            }

            printf("\n");
                
            printf("|                      |");
            for(i = 0; i<=4; i++){
                printf("                        ");
            }
            printf("|                      |");
            
            printf("\n");

            switch(numCase[cellaAttuale]){
                case 0:
                    printf("|                      |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|                      |");
                    printf("\n");
                    printf("|                      |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|                      |");
                    printf("\n");
                    printf("|                      |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|                      |");
                    printf("\n");
                    printf("|                      |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|                      |");

                    break;
                case 1:
                    printf("|   _____              |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|   _____              |");
                    printf("\n");
                    printf("|  /  #  \\             |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|  /  #  \\             |");
                    printf("\n");
                    printf("| /| # # |\\            |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("| /| # # |\\            |");
                    printf("\n");
                    printf("||  |[]___|             |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("||  |[]___|             |");

                    break;

                case 2:
                    printf("|   _____      _____   |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|   _____      _____   |");
                    printf("\n");
                    printf("|  /  #  \\    /  #  \\  |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|  /  #  \\    /  #  \\  |");
                    printf("\n");
                    printf("| /| # # |\\  /| # # |\\ |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("| /| # # |\\  /| # # |\\ |");
                    printf("\n");
                    printf("|  |[]___|    |[]___|  |");
                    for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                    printf("|  |[]___|    |[]___|  |");

                    break;
                }

                printf("\n");

                printf("|––––––––––––––––––––––|");
                for(i = 0; i<=4; i++){
                        printf("                        ");
                    }
                printf("|––––––––––––––––––––––|");
            }
    }
/*
  _____
 /  #  \
/| # # |\
 |[]___|
    
*/