/*
    Nome progetto: Monopoli Game
    Autori: Golisano Leonardo e Luchetta Fabio
    Classe: 3 C INF IIS "A.Avogadro" di Torino 
    Data di completamento: 06/01/26
    Versione Attuale  2.0.0
    Dipendeze: lib.c lib.h - Assicurarsi che siano nella stessa cartella di lavoro e incluse nella complilazione dell'eseguibile 
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
#define LOSSGAIN 3500 // Massima perdita / vincita imprevisti e probabilità
float contoBancario = 1000;
char proprieties[PROPN][22] = {"Start\0", "Enel\0", "Palazzo Nuovo\0", "Imprevisto\0", "Corso Magellano\0", "Viale Traiano\0",
                               "Via Roma\0", "Probabilita\0", "Piazza Giulio Cesare\0", "Via Verdi\0", "Parco del Valentino\0", "Viale Liberta'\0",
                               "Imprevisto\0", "Porta Nuova\0", "Palazzo della regione\0",
                               "Via Rossini\0", "Corso San Maurizio\0", "Probabilita", "Gobetti\0", "Mole\0", "Porta Susa\0", "Giardini reali\0",
                               "Parco della Vittoria\0", "Avogadro\0"}; // Matrice per definire le proprietà

int prices[PROPN] = {0, 350, 150, 600, 50, 800, 1000, 1200, 700, 850, 2400, 2200, 400, 1200, 1500, 1400, 3000, 400, 2300, 4000, 1200, 4600, 7200, 10000}; // Da definire

int numCase[PROPN] = {0, NOCASE, 2, NOCASE, 0, 0, 0, NOCASE, 0, 0, 0, 0, NOCASE, NOCASE, 0, 0, 0, NOCASE, 0, 0, NOCASE, 0, 0};

int BoolComprata[PROPN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int posReale[PROPN] = {0, 1, 2, 3, 4, 5, 6, 23, 7, 22, 8, 21, 9, 20, 10, 19, 11, 18, 12, 17, 13, 16, 14, 15};

int posArray[PROPN] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int cellaAttuale = 0; // cella attuale del player

int numeroProprieta = 0;

int quantCase = 0;

int decisione;

int tabellone;

int dado;

int temp;

int posvecchia = 0;

int mosse = 1;

int target;

int scelta;


int main()
{
    srand(time(NULL));
    loading();
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
        printf("\n--------------------------\n");
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
    

    do
    {
        mosse = 1;
        while (mosse > 0)
        {
            makeBoard(proprieties, numCase, cellaAttuale, posReale, posArray);
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
                changeArr(posvecchia, cellaAttuale, posArray);
                posvecchia = cellaAttuale;
                printf("                                                   \n");
                printf("                                                   \n");
                printf("Digitare qualunque numero per tornare al tabellone\n");
                scanf("%d", &tabellone);
            }
            else if (decisione == 2 && BoolComprata[cellaAttuale] == 0) // Sezione di acquisto
            {
                pulisci();
                acquista(cellaAttuale, contoBancario, proprieties[cellaAttuale], prices[cellaAttuale]);
                mosse--;
                printf("                                                   \n");
                printf("                                                   \n");
                printf("Digitare qualunque numero per tornare al tabellone\n");
                scanf("%d", &tabellone);
                continue;
            }
            else if (decisione == 2 && BoolComprata[cellaAttuale] == 1)
            {
                pulisci();
                printf("                                                   \n");
                printf("                                                   \n");
                printf("Hai già comprato questa proprietà.\n");
                printf("Digitare qualunque numero per tornare al tabellone\n");
                scanf("%d", &tabellone);
            }
            else if (decisione == 3 && BoolComprata[cellaAttuale] == 1) // Sezione acquisto case
            {
                pulisci();
                printf("                                                   \n");
                printf("                                                   \n");
                acquistoCasa(cellaAttuale, contoBancario, prices[cellaAttuale], proprieties[cellaAttuale]);
                printf("Digitare qualunque numero per tornare al tabellone\n");
                scanf("%d", &tabellone);
            }
            else if (decisione == 3 && BoolComprata[cellaAttuale] == 0)
            {
                pulisci();
                printf("                                                   \n");
                printf("                                                   \n");
                printf("Non puoi comprare case se non possiedi la proprietà.\n");
                printf("Digitare qualunque numero per tornare al tabellone\n");
                scanf("%d", &tabellone);
            }
            else if (decisione == 4)
            {
                pulisci();
                printf("                                                   \n");
                printf("                                                   \n");
                stato(cellaAttuale, contoBancario, prices[cellaAttuale], numeroProprieta, numCase[cellaAttuale]);
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
