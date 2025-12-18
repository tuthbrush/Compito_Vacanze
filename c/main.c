#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Variabili 
int difficoltà;
float contoBancario;
char properties[28][40] = {}; // Matrice per definire le proprietà
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
    printf("palline sudatine");
}
int TiraDado()
{
    return (rand() % 6);
}

int main()
{
    srand(time(NULL));
    title();
    show_difficolta();
    scanf("%d",difficoltà);
    return 0;
}
