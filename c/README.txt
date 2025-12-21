Cosa ho fatto il 21/12/25:



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
