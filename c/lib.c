#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void makeBoard(char array[24][22], int numCase[])
{
    int i = 0;
    int arrayLen = 0;
    int c = 0;
    int layer = 0;
    int word = 0;
    int contatore = 0;
    int cellaAttuale = 0;
    int contaCella = 0;
    int cycleMaker = 0;
    int cellCounter = 0;

    if (layer == 0 || layer == 6)
    {

        for (i = 0; i <= 6; i++)
        {
            printf("|––––––––––––––––––––––|");
        }

        printf("\n");

        for (i = 0; i <= 6; i++)
        {
            printf("|                      |");
        }

        printf("\n");

        arrayLen = strlen(array[word]);
        c = 22 - arrayLen;

        for (i = 0; i <= 6; i++)
        {
            printf("|"); // printa il nome della casella
            arrayLen = strlen(array[word]);
            for (contatore = 0; contatore != arrayLen; contatore++)
            {
                printf("%c", array[word][contatore]);
            }
            for (c = 21 - arrayLen; c >= 0; c--)
            {
                printf(" ");
            }
            printf("|");
            word++;
        }

        printf("\n");

        for (i = 0; i <= 6; i++)
        {
            printf("|                      |");
        }

        printf("\n");
        contaCella = cellaAttuale;
        for (i = 0; i <= 6; i++)
        {
            switch (numCase[cellaAttuale])
            {
            case 0:
                printf("|                      |");
                break;
            case 1:
                printf("|   _____              |");
                break;
            case 2:
                printf("|   _____      _____   |");
                break;
            }
            cellaAttuale++;
        }
        cellaAttuale = contaCella;
        for (i = 0; i <= 6; i++)
        {
            switch (numCase[cellaAttuale])
            {
            case 0:
                printf("|                      |");
                break;
            case 1:
                printf("|  /  #  \\             |");
                break;
            case 2:
                printf("|  /  #  \\    /  #  \\  |");
                break;
            }
            cellaAttuale++;
        }
        cellaAttuale = contaCella;
        for (i = 0; i <= 6; i++)
        {
            switch (numCase[cellaAttuale])
            {
            case 0:
                printf("|                      |");
                break;
            case 1:
                printf("| /| # # |\\            |");
                break;
            case 2:
                printf("| /| # # |\\  /| # # |\\ |");
                break;
            }
            cellaAttuale++;
        }
        cellaAttuale = contaCella;
        for (i = 0; i <= 6; i++)
        {
            switch (numCase[cellaAttuale])
            {
            case 0:
                printf("|                      |");
                break;
            case 1:
                printf("|  |[]___|             |");
                break;
            case 2:
                printf("|  |[]___|    |[]___|  |");
                break;
            }
            cellaAttuale++;
        }
        printf("\n");

        for (i = 0; i <= 6; i++)
        {
            printf("|––––––––––––––––––––––|");
        }
    }
    else
    {
        printf("|––––––––––––––––––––––|");
        for (i = 0; i <= 4; i++)
        {
            printf("                        ");
        }
        printf("|––––––––––––––––––––––|");

        printf("\n");

        printf("|                      |");
        for (i = 0; i <= 4; i++)
        {
            printf("                        ");
        }
        printf("|                      |");

        printf("\n");

        arrayLen = strlen(array[word]);
        c = 22 - arrayLen;

        for (i = 0; i <= 6; i++)
        {
            if (i == 0 || i == 6)
            {
                printf("|"); // printa il nome della casella
                arrayLen = strlen(array[word]);
                for (contatore = 0; contatore != arrayLen; contatore++)
                {
                    printf("%c", array[word][contatore]);
                }
                for (c = 21 - arrayLen; c >= 0; c--)
                {
                    printf(" ");
                }
                printf("|");
                word++;
            }
            else
            {
                printf("                        ");
            }
        }

        printf("\n");

        printf("|                      |");
        for (i = 0; i <= 4; i++)
        {
            printf("                        ");
        }
        printf("|                      |");

        printf("\n");

        
    }
}

/*
  _____
 /  #  \
/| # # |\
 |[]___|

*/