#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "lib.h"
// Variabili 
// Obbiettivo di proprietà e non di soldi 

#define PROPN 24 // Numero proprietà 
#define STBONUS 1000
int target;
int scelta;
float contoBancario = 1000;
char word[22];
char proprieties[PROPN][22] = {"Start\0","Societa Elettrica'\0","Piazza Universita'\0","Viale Monterosa\0","Corso Magellano\0","Viale Traiano\0",
                            "Via Roma\0","Stazione Nord\0","Piazza Giulio Cesare\0","Via Verdi\0","Viale dei Giardini\0","Viale Liberta'\0",
                            "Via Onomatopea\0","Stazione Ovest\0","Palazzo della regione\0",
                            "Via Rossini\0","Corso San Maurizio\0","Via Tarino","Gobetti\0","Mole\0","Stazione Est\0","Giardini reali\0",
"Parco della Vittoria\0","Avogadro\0"}; // Matrice per definire le proprietà

int prices[PROPN] = {0,350,150,600,50,800,1000,1200,700,850,5400,2200,40,1200,4500,1400,6000,400,2300,8000,1200,4600,7200,10000}; // Da definire

int numCase[PROPN] = {1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,2,1,0,2,0,0,0,0,}; //to modify

int BoolComprata[PROPN] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int cellaAttuale = 0; // cella attuale del player

int numeroProprieta = 0;

// Funzioni 


// Funzione per mostrare il titolo (Chiamata volta ad inizio programma)
void title()
{
    printf("           ___  ___                              _ _   _____                      \n");  // La scritta viene bene, non modificare nulla
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
void show_difficolta()
{
    printf("\nA che difficoltà vorresti giocare?\n");
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
// Pulire lo schermo se necessario. Funziona su tutti gli os
void pulisci()
{
    printf("\033[H\033[J");
}
void PassaDalVia()
{
    contoBancario += STBONUS;
    printf("Sei passato dal Via! Hai guadagnato %d$\n",STBONUS);

}

void stato(int posAttuale, int soldi, char citta[], int prezzo, int BoolComprata, int numeroPro)
{
    printf("--------------------------\n");
    printf("                          \n");
    printf("Situazione attuale:\n");
    printf("Sei nella casella numero %d\n",posAttuale);
    printf("Il tuo saldo ammonta a %d$\n",soldi);
    printf("Proprieta:  %s\n",citta);
    printf("Costo: %d\n",prezzo);
    if(BoolComprata == 1)
    {
        printf("Stato: Comprata\n");
    }else{
        printf("Stato: Non comprata\n");
    }
    printf("Attualmente possiedi %d proprietà.",numeroPro);
    printf("                          \n");
    printf("--------------------------\n");
}
void acquista(int posAttuale, int soldi, char citta[],int prezzo)
{
    if(soldi<prezzo)
    {
        printf("Non hai abbastanza soldi.\n");
    }
    else{
        contoBancario-= prezzo;
        BoolComprata[posAttuale] = 1;
        numeroProprieta++;
        printf("Hai comprato %s e ti sono stati sottratti %d$\n", citta,prezzo);
    }
}

int main()
{
    strcpy(word, proprieties[cellaAttuale]);
    int wordLen = strlen(word);
    srand(time(NULL));
    title();
    sleep(3);
    show_difficolta();
    sleep(2);
    scanf("%d",&scelta);
    switch (scelta)
    {
    case 1:
        target = 10000;
        printf("--------------------------\n");
        printf("                          \n");
        printf("Obbiettivo settato a %d\n",target);
        printf("                          \n");
        printf("--------------------------\n");
        break;
    case 2:
        target = 25000;
        printf("--------------------------\n");
        printf("                          \n");
        printf("Obbiettivo settato a %d\n",target);
        printf("                          \n");
        printf("--------------------------\n");
        break;
    case 3:
        target = 50000;
        printf("--------------------------\n");
        printf("                          \n");
        printf("Obbiettivo settato a %d\n",target);
        printf("                          \n");
        printf("--------------------------\n");
        break;
    
    default:
        printf("Scelta non valida.\n");
        break;
    }

    //makeCell(word, wordLen, numCase, cellaAttuale);  // fuori dal main loop rn
    // Main loop di gioco 
    do
    {
        int mosse = 1;
        while (mosse>0)
        {
            stato(cellaAttuale,contoBancario,proprieties[cellaAttuale],prices[cellaAttuale],BoolComprata[cellaAttuale],numeroProprieta);  
            printf("Digitare 1 per tirare il dado!\n");
            printf("Digitare 2 per comprare la proprietà!\n");
            int BoolTiro;
            scanf("%d",&BoolTiro);
            if (BoolTiro==1)   // Sezione di movimento 
            {
                int dado = TiraDado();
                int temp = (cellaAttuale + dado);
                if(temp >= PROPN){
                    PassaDalVia();
                }
                cellaAttuale = temp % PROPN;
                mosse--;
            }
            else if (BoolTiro == 2 && BoolComprata[cellaAttuale] == 0)   // Sezione di acquisto
            {
                acquista(cellaAttuale,contoBancario,proprieties[cellaAttuale],prices[cellaAttuale]);
                mosse--;
                continue;
            }
            else if (BoolTiro == 2 && BoolComprata[cellaAttuale] == 1)
            {
                printf("Hai già comprato questa proprietà.\n");
            }
        }
        
    } while (contoBancario<target);
    
    



    return 0;
}