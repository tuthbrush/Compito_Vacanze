#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "lib.h" 
void loading() {
    const int TOTAL = 80;  // Total width of the progress bar
    char R[TOTAL][2];      // Array to hold characters and potentially spaces
    
    // Initialize the array with spaces
    for(int i = 0; i < TOTAL; i++) {
        R[i][0] = ' ';
        R[i][1] = '\0';  // Null terminator if needed as string
    }
    
    int loadval = 0;
    
    // Seed random number generator if not already seeded
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }
    
    for(int i = 0; i < TOTAL; i++) {
        R[i][0] = '#';
        loadval = ((i + 1) * 100) / TOTAL;  // Calculate percentage
        
        printf("[");
        for(int c = 0; c < TOTAL; c++) {
            printf("%c", R[c][0]);
        }
        printf("] %d%%", loadval);
        
        fflush(stdout);
        
        // Adjust sleep time for smoother animation
        usleep((rand() % (150000 - 50000)) + 50000);  // 50-150ms
        
        printf("\r");
    }
    printf("\n");
}

int main()
{
    loading();
    return 0;
}