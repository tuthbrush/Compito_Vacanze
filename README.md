# Monopoly Game - Compito vacanze 

Monopoly in C è una versione digitale semplificata del classico gioco da tavolo Monopoly. Il gioco include meccaniche come:
- Movimento del giocatore
- Acquisto di proprietà e case
- Imprevisti e probabilità
- Obiettivi e condizioni di vittoria
- Un’interfaccia grafica di base nel terminale

## Caratteristiche principali
- Gioco a turni (con 1 giocatore)
- Possibilità di acquistare proprietà
- Costruzione di case sulle proprietà
- Imprevisti e probabilità
- Visualizzazione del tabellone con il numero di case per ogni proprietà
- Statistiche del giocatore (saldo, proprietà possedute, ecc.)

## Strumenti utilizzati
- Linguaggio: C
- Ambiente di sviluppo: terminale/console/editor di codice
- Git per il versionamento del codice

## Istruzioni per l'installazione

Se sei un utente casual, [qui](https://github.com/tuthbrush/Compito_Vacanze/releases/tag/V1) c'è già il file compilato

## Istruzioni per la compilazione

Se sei un utente esperto puoi prendere questa via:

1. Clona il repository:
   ```bash
   git clone https://github.com/tuthbrush/Compito_Vacanze.git
   ```
   
2. Entra nella cartella del progetto
    ```bash
   cd Compito_Vacanze/c/versione2
   ```
   
3. Compila il file con le relative dipendenze
    ```bash
   gcc lib.c main.c -o main
   ```
   
4. Esegui il file
    ```bash
   ./main
   ```

## Come giocare 
- **Tira il dado**: Premi un numero per far muovere la pedina e avanzare di un numero di caselle casuale.
- **Acquista proprietà**: Se ti trovi su una casella non posseduta, puoi acquistare la proprietà.
- **Compra case**: Se possiedi una proprietà, puoi acquistare case per migliorarla.
- **Visualizza le statistiche**: Premi per vedere il saldo, le proprietà possedute e il numero di case.
- **Imprevisti e probabilità** ti aiuterranno a raggiungere il tuo obbiettivo o saranno la causa della tua sconfitta