Cosa ho fatto il 19/12/25:

1- Defito un paio di costanti al posto di numeri per le lunghezze degli array
2- Abbozzato array dei prezzi senza una logica precisa
3- Migliorato la funzione "TiraDado" e creato le funzioni "pulisci", "PassaDalVia", "Stato". 
4- Swicth case per impostare la difficoltà | TESTATA E FUNZIONANTE
5- abbozzata la logica del movimento | TESTATA E FUNZIONANTE


void loading(){
    char R[10][2] = {" "," "," "," "," "," "," "," "," "," "};
    int loadval = 0;
    for(int i = 0; i!=10; i++){
        R[i][0] = '#';
        loadval+=10;
        printf("[");
        for(int c = 0; c!=10; c++){
            printf("%c", R[c][0], loadval);
        }
        printf("] %d%%", loadval);
        fflush(stdout);
        usleep((rand()%(850000-200000))+200000);
        printf("\r");
    }
    printf("\n");
}
