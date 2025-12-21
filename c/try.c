#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"

void makeBoard(char array[24][22], int numCase[], int cellaAttuale){
    int i = 0;
    int arrayLen = 0;
    int c = 0;
    int layer = 1;
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
                    for(i = 0; i<=6; i++){
                        printf("|                      |");
                    }
                    printf("|                      |");
                    printf("\n");
                    printf("|                      |");
                    for(i = 0; i<=6; i++){
                        printf("                        ");
                    }
                    printf("|                      |");
                    printf("\n");
                    printf("|                      |");
                    for(i = 0; i<=6; i++){
                        printf("                        ");
                    }
                    printf("|                      |");
                    printf("\n");
                    printf("|                      |");
                    for(i = 0; i<=6; i++){
                        printf("                        ");
                    }
                    printf("|                      |");

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

int main()
{
    char proprieties[24][22] = {"Start\0","Societa Elettrica'\0","Piazza Universita'\0","Imprevisto\0","Corso Magellano\0","Viale Traiano\0",
                                    "Via Roma\0","Probabilita\0","Piazza Giulio Cesare\0","Via Verdi\0","Viale dei Giardini\0","Viale Liberta'\0",
                                    "Imprevisto\0","Stazione Ovest\0","Palazzo della regione\0",
                                    "Via Rossini\0","Corso San Maurizio\0","Probabilita","Gobetti\0","Mole\0","Stazione Est\0","Giardini reali\0",
                                    "Parco della Vittoria\0","Avogadro\0"}; // Matrice per definire le proprietà;
    int numcase[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int cell = 1;

    makeBoard(proprieties, numcase, cell);

    return 0;
}