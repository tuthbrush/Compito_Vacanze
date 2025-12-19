#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "lib.h"
// Variabili 
#define PROPN 24 // Numero proprietà 
int target;
float contoBancario = 0;
char word[22];
char proprieties[PROPN][22] = {"Start\0","Societa Elettrica'\0","Piazza Universita'\0","Viale Monterosa\0","Corso Magellano\0","Viale Traiano\0",
                            "Via Roma\0","Stazione Nord\0","Piazza Giulio Cesare\0","Via Verdi\0","Viale dei Giardini\0","Viale Liberta'\0",
                            "Via Onomatopea\0","Stazione Ovest\0","Palazzo della regione\0",
                            "Via Rossini\0","Corso San Maurizio\0","Via Tarino","Gobetti\0","Mole\0","Stazione Est\0","Giardini reali\0",
"Parco della Vittoria\0","Avogadro\0"}; // Matrice per definire le proprietà

int prices[] = {0,350,150,600,50,800,1000,1200,700,850,5400,2200,40,1200,4500,1400,6000,400,2300,8000,1200,4600,7200,10000}; // Da definire

int numCase[PROPN] = {1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,2,1,0,2,0,0,0,0,}; //to modify

int cellaAttuale = 0; // cella attuale del player

// Funzione per mostrare il titolo (Chiamata volta ad inizio programma)
void title()
{
    printf("___  ___                              _ _   _____                      \n");  // La scritta viene bene, non modificare nulla
    printf("|  \\/  |                             | (_) |  __ \\                     \n");
    printf("| .  . | ___  _ __   ___  _ __   ___ | |_  | |  \\/ __ _ _ __ ___   ___ \n");
    printf("| |\\/| |/ _ \\| '_ \\ / _ \\| '_ \\ / _ \\| | | | | __ / _` | '_ ` _ \\ / _ \"\n");
    printf("| |  | | (_) | | | | (_) | |_) | (_) | | | | |_\\ \\ (_| | | | | | |  __/\n");
    printf("\\_|  |_/\\___/|_| |_|\\___/| .__/ \\___/|_|_|  \\____/\\__,_|_| |_| |_|\\___|\n");
    printf("                         | |                                           \n");
    printf("                         |_|                                           \n");
    printf("-------------------------------------------------------------------------\n");
    printf("Made by Golisano Leonardo and Luchetta Fabio\n");
    printf("-------------------------------------------------------------------------\n");
    printf("OBBIETTIVO: Il tuo obbiettivo sarà raggiungere una somma di denaro, in base alla difficoltà selezionata\n");
    
}
void show_difficolta()
{
    printf("\nA che difficoltà vorresti giocare?");
    printf("1) Facile: 10 000 $\n");
    printf("2) Media: 25 000 $\n");
    printf("3) Alta: 50 000 $\n");
    printf("Cosa scegli ? (Inserisci il numero): ");
}
int TiraDado(){
    printf("Tirando il dado");
    usleep(100000);
    for (int i = 0; i < 3; i++) {
        usleep(800000);
        printf(".");
        fflush(stdout); 
    }

    int risultato = (rand() % 6) + 1; 
    printf("\nÈ uscito: %d\n", risultato);
    
    return risultato;
}

int main()
{
    strcpy(word, proprieties[cellaAttuale]);
    int wordLen = strlen(word);
    srand(time(NULL));
    title();
    show_difficolta();
    //scanf("%d",target);
    
    makeCell(word, wordLen, numCase, cellaAttuale);
    
    return 0;
}