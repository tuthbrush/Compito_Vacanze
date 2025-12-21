#include <stdio.h>
#include <string.h>

int main(){
    char proprieties[24][22] = {"Start\0","Societa Elettrica'\0","Piazza Universita'\0","Imprevisto\0","Corso Magellano\0","Viale Traiano\0",
                                    "Via Roma\0","Probabilita\0","Piazza Giulio Cesare\0","Via Verdi\0","Viale dei Giardini\0","Viale Liberta'\0",
                                    "Imprevisto\0","Stazione Ovest\0","Palazzo della regione\0",
                                    "Via Rossini\0","Corso San Maurizio\0","Probabilita","Gobetti\0","Mole\0","Stazione Est\0","Giardini reali\0",
                                    "Parco della Vittoria\0","Avogadro\0"}; // Matrice per definire le proprietà;
    int numcase[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int cell = 1;

    printf("%c", proprieties[3][1]);

}