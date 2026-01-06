#include <stdio.h>

void makeBoard(char array[24][22], int numCase[], int posAttuale, int posReale[], int posArray[]);

void title();

void loading();

void show_difficolta();

int TiraDado();

void pulisci();

void PassaDalVia(int contoBancario);

void stato(int posAttuale, int soldi, int prezzo, int numeroPro, int numCase, int proprieties[]);

void acquista(int posAttuale, int soldi, char citta[], int prezzo, int BoolComprata[], int numeroProprieta);

void imprevisti(int contoBancario);

void probabilita(int contoBancario);

void acquistoCasa(int posAttuale, int soldi, int prezzo, char citta[], int quantCase, int numCase[]);

void vittoria(int conto, int proprieta, int c);

void sconfitta();

void changeArr(int vecchiaPos,int posAttuale, int posizioneArray[]);