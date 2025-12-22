#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"

void makeBoard(char array[24][22], int numCase[])
{
    int i = 0;
    int arrayLen = 0;
    int c = 0;
    int layer = 0;
    int contatore = 0;
    int cellaAttuale = 0;
    int contaCella = 0;
    int cycleMaker = 0;
    int cellCounter = 0;
    int word = 0;
    for (layer = 0; layer <= 6; layer++)
    {
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
            printf("\n");
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
            printf("\n");
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
            printf("\n");
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

            printf("\n");
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

            for (i = 0; i <= 4; i++)
            {
                printf("                        ");
            }

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
            cellaAttuale--;

            printf("\n");

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

            for (i = 0; i <= 4; i++)
            {
                printf("                        ");
            }

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
            cellaAttuale--;

            printf("\n");

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

            for (i = 0; i <= 4; i++)
            {
                printf("                        ");
            }

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
            cellaAttuale--;

            printf("\n");

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

            for (i = 0; i <= 4; i++)
            {
                printf("                        ");
            }

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

            printf("\n");

            printf("|––––––––––––––––––––––|");
            for (i = 0; i <= 4; i++)
            {
                printf("                        ");
            }
            printf("|––––––––––––––––––––––|");

            printf("\n");
        }
    }
}

int main()
{
    char proprieties[24][22] = {"Start\0", "Societa Elettrica'\0", "Piazza Universita'\0", "Imprevisto\0", "Corso Magellano\0", "Viale Traiano\0",
                                "Via Roma\0", "Probabilita\0", "Piazza Giulio Cesare\0", "Via Verdi\0", "Viale dei Giardini\0", "Viale Liberta'\0",
                                "Imprevisto\0", "Stazione Ovest\0", "Palazzo della regione\0",
                                "Via Rossini\0", "Corso San Maurizio\0", "Probabilita", "Gobetti\0", "Mole\0", "Stazione Est\0", "Giardini reali\0",
                                "Parco della Vittoria\0", "Avogadro\0"}; // Matrice per definire le proprietà;
    int numcase[24] = {0, 1, 0, 0, 1, 2, 0, 2, 0, 1, 0, 0, 1, 0, 2, 1, 0, 0, 0, 0, 1, 0, 0, 1};
    int cell = 1;

    makeBoard(proprieties, numcase);

    return 0;
}
