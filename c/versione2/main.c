/*
    Nome progetto: Monopoli Game
    Autori: Golisano Leonardo e Luchetta Fabio
    Data di completamento: 21/12/25
    Versione 1.0
    Repo GitHub: https://github.com/tuthbrush/Compito_Vacanze.git
*/
// Librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "lib.h"

// Schema colori
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define NORMAL "\x1b[m"

// Variabili

#define PROPN 24 // Numero proprietà
#define STBONUS 1000
#define CASA 25 // Percentuale applica al costo delle case
#define CASADUE 40
#define NOCASE 0
int target;
int scelta;
float contoBancario = 1000;
char proprieties[PROPN][22] = {"Start\0", "Enel\0", "Piazza Universita'\0", "Imprevisto\0", "Corso Magellano\0", "Viale Traiano\0",
                               "Via Roma\0", "Probabilita\0", "Piazza Giulio Cesare\0", "Via Verdi\0", "Parco del Valentino\0", "Viale Liberta'\0",
                               "Imprevisto\0", "Porta Nuova\0", "Palazzo della regione\0",
                               "Via Rossini\0", "Corso San Maurizio\0", "Probabilita", "Gobetti\0", "Mole\0", "Porta Susa\0", "Giardini reali\0",
                               "Parco della Vittoria\0", "Avogadro\0"}; // Matrice per definire le proprietà

int prices[PROPN] = {0, 350, 150, 600, 50, 800, 1000, 1200, 700, 850, 2400, 2200, 400, 1200, 1500, 1400, 3000, 400, 2300, 4000, 1200, 4600, 7200, 10000}; // Da definire

int numCase[PROPN] = {0, NOCASE, 0, NOCASE, 0, 0, 0, NOCASE, 0, 0, 0, 0, NOCASE, NOCASE, 0, 0, 0, NOCASE, 0, 0, NOCASE, 0, 0};

int BoolComprata[PROPN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int posizionereale[24] = {0, 1, 2, 3, 4, 5, 6, 23, 7, 22, 8, 21, 9, 20, 10, 19, 11, 18, 12, 17, 13, 16, 14, 15};

int cellaAttuale = 0; // cella attuale del player

int numeroProprieta = 0;

int quantCase = 0;

// Funzioni

// Funzione per mostrare il titolo (Chiamata volta ad inizio programma)
void title()
{
    printf("           ___  ___                              _ _   _____                      \n"); // La scritta viene bene, non modificare nulla
    printf("           |  \\/  |                             | (_) |  __ \\                     \n");
    printf("           | .  . | ___  _ __   ___  _ __   ___ | |_  | |  \\/ __ _ _ __ ___   ___ \n");
    printf("           | |\\/| |/ _ \\| '_ \\ / _ \\| '_ \\ / _ \\| | | | | __ / _` | '_ ` _ \\ / _ \"\n");
    printf("           | |  | | (_) | | | | (_) | |_) | (_) | | | | |_\\ \\ (_| | | | | | |  __/\n");
    printf("           \\_|  |_/\\___/|_| |_|\\___/| .__/ \\___/|_|_|  \\____/\\__,_|_| |_| |_|\\___|\n");
    printf("                                    | |                                           \n");
    printf("                                    |_|                                           \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("                        Made by Golisano Leonardo and Luchetta Fabio\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("OBBIETTIVO: Il tuo obbiettivo sarà raggiungere una somma di denaro, in base alla difficoltà selezionata\n");
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
    
void PassaDalVia()
{
    contoBancario += STBONUS;
    printf("Sei passato dal Via! Hai guadagnato %d$\n", STBONUS);
}

void stato(int soldi, int prezzo, int numeroPro)
{
    int costoCasa = (prezzo * CASA) / 100;
    int costoCasaDue = (prezzo * CASADUE) / 100;

    printf("--------------------------\n");
    printf("                          \n");
    printf("Situazione attuale:\n");
    printf("Il tuo saldo ammonta a %d$\n", soldi);
    printf("Costo di una casa: %d$\n", costoCasa);
    printf("Costo della seconda casa: %d$\n", costoCasaDue);
    printf("Attualmente possiedi %d proprietà.\n", numeroPro);
    printf("                          \n");
    printf("--------------------------\n");
}

void acquista(int posAttuale, int soldi, char citta[], int prezzo)
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
        contoBancario -= prezzo;
        BoolComprata[posAttuale] = 1;
        numeroProprieta++;
        printf("Hai comprato %s e ti sono stati sottratti %d$\n", citta, prezzo);
    }
}

void imprevisti()
{
    printf("--------------------------\n");
    printf("                          \n");
    float loss = (rand() % 3500) + 1;
    printf("Sei capitato su un imprevisto!\n");
    printf("Ti vengono sottratti %.2f$", loss);
    contoBancario -= loss;
    printf("                          \n");
    printf("--------------------------\n");
}

void probabilita()
{
    printf("--------------------------\n");
    printf("                          \n");
    float up = (rand() % 3500) + 1;
    printf("Sei capitato su una probabilià!\n");
    printf("Ti vengono regalati %.2f$", up);
    contoBancario += up;
    printf("                          \n");
    printf("--------------------------\n");
}

void acquistoCasa(int posAttuale, int soldi, int prezzo, char citta[])
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
        contoBancario -= costoCasa;
        numCase[posAttuale]++;
        quantCase++;
    }
    else
    {
        int costoCasa = (prezzo * CASADUE) / 100;
        printf("Hai acquistato una casa su %s al costo di %d$\n", citta, costoCasa);
        contoBancario -= costoCasa;
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

int main()
{
    srand(time(NULL));
    // loading();
    sleep(2);
    pulisci();
    title();
    sleep(3);
    show_difficolta();
    sleep(2);
    scanf("%d", &scelta);
    switch (scelta)
    {
    case 1:
        target = 10000;
        printf("--------------------------\n");
        printf("                          \n");
        printf("Obbiettivo settato a %d\n", target);
        printf("                          \n");
        printf("--------------------------\n");
        break;
    case 2:
        target = 25000;
        printf("--------------------------\n");
        printf("                          \n");
        printf("Obbiettivo settato a %d\n", target);
        printf("                          \n");
        printf("--------------------------\n");
        break;
    case 3:
        target = 50000;
        printf("--------------------------\n");
        printf("                          \n");
        printf("Obbiettivo settato a %d\n", target);
        printf("                          \n");
        printf("--------------------------\n");
        break;

    default:
        printf("Scelta non valida.\n");
        break;
    }

    // Main loop di gioco
    
    int decisione;
    int tabellone;
    int dado;
    int temp;
    int mosse = 1;
    do
    {
        mosse = 1;
        while (mosse > 0)
        {
            makeBoard(proprieties, numCase);
            printf("Digitare 1 per tirare il dado!\n");
            printf("Digitare 2 per comprare la proprietà!\n");
            printf("Digita 3 per acquistare una casa! (Disponibile solo se la proprietà tua)\n");
            printf("Digita 4 per vedere le statistiche!\n");
            scanf("%d", &decisione);
            if (decisione == 1) // Sezione di movimento
            {
                pulisci();
                dado = TiraDado();
                temp = (cellaAttuale + dado);
                if (temp >= PROPN)
                {
                    PassaDalVia();
                }
                if (temp == 3 || temp == 12)
                {
                    imprevisti();
                }
                if (temp == 7 || temp == 19)
                {
                    probabilita();
                }
                cellaAttuale = temp % PROPN; // Dare ciclicità al tabellone
                mosse--;
                printf("Digitare qualunque numero per tornare al tabellone\n");
                scanf("%d", &tabellone);
            }
            else if (decisione == 2 && BoolComprata[cellaAttuale] == 0) // Sezione di acquisto
            {
                acquista(cellaAttuale, contoBancario, proprieties[cellaAttuale], prices[cellaAttuale]);
                mosse--;
                continue;
            }
            else if (decisione == 2 && BoolComprata[cellaAttuale] == 1)
            {
                printf("Hai già comprato questa proprietà.\n");
            }
            else if (decisione == 3 && BoolComprata[cellaAttuale] == 1) // Sezione acquisto case
            {
                acquistoCasa(cellaAttuale, contoBancario, prices[cellaAttuale], proprieties[cellaAttuale]);
            }
            else if (decisione == 3 && BoolComprata[cellaAttuale] == 0)
            {
                printf("Non puoi comprare case se non possiedi la proprietà.\n");
            }
            else if (decisione == 4)
            {
                pulisci();
                stato(contoBancario, prices[cellaAttuale], numeroProprieta);
                printf("Digitare qualunque numero per tornare al tabellone\n");
                scanf("%d", &tabellone);
            }
            else
            {
                printf("scusa puoi ripetere perfavore? non credo di aver sentito bene.\n");
            }
        }
    } while (contoBancario < target && contoBancario > 0);
    pulisci();
    if (contoBancario >= target)
    {
        vittoria(contoBancario, numeroProprieta, quantCase);
    }
    if (contoBancario < 0)
    {
        sconfitta();
    }
    return 0;
}