#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define PROPN 24 // Numero proprietà
#define STBONUS 1000
#define CASA 25 // Percentuale applica al costo delle case
#define CASADUE 40
#define NOCASE 0
#define LOSSGAIN 3500 // Massima perdita / vincita imprevisti e probabilità

// Funzione per mostrare il tabellone
void makeBoard(char array[24][22], int numCase[], int posAttuale, int posReale[], int posArray[])
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
    int positioncheck = 0;
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
                printf("|      "); // printa se c'è il player
                if(posArray[positioncheck]==1){
                    printf("player qui");
                }
                else{
                    printf("          ");
                }
                printf("      |");
                positioncheck++;
            }
           
        /*  for (i = 0; i <= 6; i++)
            {
                printf("|                      |");
            }*/
        

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

            
            
            printf("|      "); // printa se c'è il player
            if(posArray[positioncheck]==1){
                printf("player qui");
            }
            else{
                printf("          ");
            }
            printf("      |");
            positioncheck++;
            for (i = 0; i <= 4; i++)
            {
                printf("                        ");
            }
            printf("|      "); // printa se c'è il player
            if(posArray[positioncheck]==1){
                printf("player qui");
            }
            else{
                printf("          ");
            }
            printf("      |");
            positioncheck++;

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

// Funzione per mostrare il titolo (Chiamata volta ad inizio programma)
void title()
{
    printf("                                  ___  ___                              _ _   _____                      \n"); // La scritta viene bene, non modificare nulla
    printf("                                  |  \\/  |                             | (_) |  __ \\                     \n");
    printf("                                  | .  . | ___  _ __   ___  _ __   ___ | |_  | |  \\/ __ _ _ __ ___   ___ \n");
    printf("                                  | |\\/| |/ _ \\| '_ \\ / _ \\| '_ \\ / _ \\| | | | | __ / _` | '_ ` _ \\ / _ \"\n");
    printf("                                  | |  | | (_) | | | | (_) | |_) | (_) | | | | |_\\ \\ (_| | | | | | |  __/\n");
    printf("                                  \\_|  |_/\\___/|_| |_|\\___/| .__/ \\___/|_|_|  \\____/\\__,_|_| |_| |_|\\___|\n");
    printf("                                                           | |                                           \n");
    printf("                                                           |_|                                           \n");
    printf("                       --------------------------------------------------------------------------------------------------------\n");
    printf("                                               Made by Golisano Leonardo and Luchetta Fabio\n");
    printf("                       --------------------------------------------------------------------------------------------------------\n");
    printf("                       OBBIETTIVO: Il tuo obbiettivo sarà raggiungere una somma di denaro, in base alla difficoltà selezionata\n");
}

void loading()
{
    const int TOTAL = 80; // Total width of the progress bar
    char R[TOTAL][2];
    for (int i = 0; i < TOTAL; i++)
    {
        R[i][0] = ' ';
        R[i][1] = '\0';
    }
    int loadval = 0;
    static int seeded = 0;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = 1;
    }
    for (int i = 0; i < TOTAL; i++)
    {
        R[i][0] = '#';
        loadval = ((i + 1) * 100) / TOTAL;

        printf("[");
        for (int c = 0; c < TOTAL; c++)
        {
            printf("%c", R[c][0]);
        }
        printf("] %d%%", loadval);
        fflush(stdout);
        usleep((rand() % (150000 - 50000)) + 50000); // 50-150ms
        printf("\r");
    }
    printf("\n");
}

void show_difficolta()
{
    printf("\nA che difficoltà vorresti giocare?\n");
    printf("1) Facile: 10 000 $\n");
    printf("2) Media: 25 000 $\n");
    printf("3) Alta: 50 000 $\n");
    printf("Cosa scegli ? (Inserisci il numero): ");
}

int TiraDado()
{
    printf("Tirando il dado");
    usleep(100000);
    for (int i = 0; i < 3; i++)
    {
        usleep(800000);
        printf(".");
        fflush(stdout);
    }

    int risultato = (rand() % 6) + 1;
    printf("\nÈ uscito: %d\n", risultato);

    return risultato;
}

// Pulire lo schermo se necessario. Funziona su tutti gli os
void pulisci() {

    #ifdef _WIN32
        // Windows usa il comando DOS
        system("cls");
    #elif __APPLE__
        // macOS (Unix-based)
        system("clear");
    #elif __linux__
        // Linux
        system("clear");
    #else
        printf("Impossibile riconosere il sistema operativo.\n");
    #endif
}

void PassaDalVia(int contoBancario)
{
    contoBancario += STBONUS;
    printf("Sei passato dal Via! Hai guadagnato %d$\n", STBONUS);
}

void stato(int posAttuale, int soldi, int prezzo, int numeroPro, int numCase, int proprieties[])
{
    int costoCasa = (prezzo * CASA) / 100;
    int costoCasaDue = (prezzo * CASADUE) / 100;

    printf("--------------------------\n");
    printf("                          \n");
    printf("Situazione attuale:\n");
    printf("Il tuo saldo ammonta a %d$\n", soldi);
    printf("Ti trovi su : %s\n", proprieties[posAttuale]);
    printf("Costo di una casa: %d$\n", costoCasa);
    printf("Costo della seconda casa: %d$\n", costoCasaDue);
    printf("Attualmente possiedi %d proprietà.\n", numeroPro);
    printf("Attualmente possiedi %d case su questa proprietà.\n", numCase);
    printf("                          \n");
    printf("--------------------------\n");
}

void acquista(int posAttuale, int soldi, char citta[], int prezzo, int BoolComprata[], int numeroProprieta)
{
    if (posAttuale == 0 || posAttuale == 3 || posAttuale == 7 || posAttuale == 12 || posAttuale == 19)
    {
        printf("Non puoi comprare questa proprietà\n");
    }
    else if (soldi < prezzo)
    {
        printf("Non hai abbastanza soldi.\n");
    }
    else
    {
        soldi -= prezzo;
        BoolComprata[posAttuale] = 1;
        numeroProprieta++;
        printf("Hai comprato %s e ti sono stati sottratti %d$\n", citta, prezzo);
    }
}

void imprevisti(int contoBancario)
{
    printf("--------------------------\n");
    printf("                          \n");
    float loss = (rand() % LOSSGAIN) + 1;
    printf("Sei capitato su un imprevisto!\n");
    printf("Ti vengono sottratti %.2f$", loss);
    contoBancario -= loss;
    printf("                          \n");
    printf("--------------------------\n");
}

void probabilita(int contoBancario)
{
    printf("--------------------------\n");
    printf("                          \n");
    float up = (rand() % LOSSGAIN) + 1;
    printf("Sei capitato su una probabilià!\n");
    printf("Ti vengono regalati %.2f$", up);
    contoBancario += up;
    printf("                          \n");
    printf("--------------------------\n");
}

void acquistoCasa(int posAttuale, int soldi, int prezzo, char citta[], int quantCase, int numCase[])
{
    if (posAttuale == 1 || posAttuale == 13 || posAttuale == 20)
    {
        printf("Non puoi acquistare case su questa proprietà.\n");
    }

    if (numCase[posAttuale] >= 2)
    {
        printf("Non puoi acquistare altre case.\n");
    }
    else if (numCase[posAttuale] == 0)
    {
        int costoCasa = (prezzo * CASA) / 100;
        printf("Hai acquistato una casa su %s al costo di %d$\n", citta, costoCasa);
        soldi -= costoCasa;
        numCase[posAttuale]++;
        quantCase++;
    }
    else
    {
        int costoCasa = (prezzo * CASADUE) / 100;
        printf("Hai acquistato una casa su %s al costo di %d$\n", citta, costoCasa);
        soldi -= costoCasa;
        numCase[posAttuale]++;
        quantCase++;
    }
}

void vittoria(int conto, int proprieta, int c)
{
    printf(" _   _       _         _       _        _ \n");
    printf("| | | |     (_)       (_)     | |      | |\n");
    printf("| |_| | __ _ _  __   ___ _ __ | |_ ___ | |\n");
    printf("|  _  |/ _` | | \\ \\ / / | '_ \\| __/ _ \\| |\n");
    printf("| | | | (_| | |  \\ V /| | | | | || (_) |_|\n");
    printf("\\_| |_/\\__,_|_|   \\_/ |_|_| |_|\\__\\___/(_)\n");
    printf("                                                  \n");
    printf("Hai concluso il gioco raggiungendo i %d$, possedendo %d proprietà e %d case!\n", conto, proprieta, c);
}

void sconfitta()
{
    printf(" _   _       _                             _ \n");
    printf("| | | |     (_)                           | |\n");
    printf("| |_| | __ _ _   _ __   ___ _ __ ___  ___ | |\n");
    printf("|  _  |/ _` | | | '_ \\ / _ \\ '__/ __|/ _ \\| |\n");
    printf("| | | | (_| | | | |_) |  __/ |  \\__ \\ (_) |_|\n");
    printf("\\_| |_/\\__,_|_| | .__/ \\___|_|  |___/\\___/(_)\n");
    printf("                | |                          \n");
    printf("                |_|                          \n");
    printf("Un imprevisto ti ha fatto andare in bancarotta.\n");
}

void changeArr(int vecchiaPos,int posAttuale, int posizioneArray[])
{
    posizioneArray[vecchiaPos] = 0;
    posizioneArray[posAttuale] = 1;
    vecchiaPos = posAttuale;
}