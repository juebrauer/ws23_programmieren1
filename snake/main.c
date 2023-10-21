#include <stdio.h>  // printf()
#include <stdlib.h> // rand()
#include <time.h>   // time()

#include "params.h" // Spielparameter
#include "snake_hilfsfunktionen.h"

// main.c -> Präprozessor -> Compiler -> Linker -> Ausführbares Programm

char spielfeld[HOEHE][BREITE];

int sx = BREITE/2;
int sy = HOEHE/2;



void spielfeld_waende_einfuegen() {
    
    for (int y=0; y<HOEHE; y++)
    {
        // Erste Zeile oder letzte Zeile?
        if (y==0 || y==HOEHE-1)        
            for (int x=0; x<BREITE; x++)        
                spielfeld[y][x] = FELD_WAND;
        else
        {            
            // Linke Wand ins Spielfeld setzen
            spielfeld[y][0] = FELD_WAND;
            // Rechte Wand ins Spielfeld setzen
            spielfeld[y][BREITE-1] = FELD_WAND;
            // Alle andere Felder sind frei!
            for (int x=1; x<BREITE-1; x++)
                spielfeld[y][x] = FELD_LEER;
        }
    }
}


void spielfeld_futter_einfuegen() {
    
    for (int i=0; i<ANZ_FUTTERSTUECKE; i++)
    {
        int x;
        int y;
        x = rand() % (BREITE-2) + 1;
        y = rand() % (HOEHE-2)  + 1;
        spielfeld[y][x] = FELD_FUTTER;
    }
}


void spielfeld_initialisieren() {
    
    spielfeld_waende_einfuegen();
    spielfeld_futter_einfuegen();    
}


void spielfeld_ausgeben() {
    for (int y=0; y<HOEHE; y++)
    {
        for (int x=0; x<BREITE; x++)
        {
            printf("%c", spielfeld[y][x]);
        }    
        printf("\n");
    }
}

int main() {

    srand(time(NULL));

    spielfeld_initialisieren();

    // Setze Schlange an Startposition im Spielfeld
    spielfeld[sy][sx] = FELD_SCHLANGE;

    // Spielschleife
    int counter = 0;
    while (1) {
        clear();
        spielfeld_ausgeben();
        counter++;
        printf("%d\n", counter);

        // Hat der Benutzer eine Taste gedrückt?
        if (kbhit()) {

            // Schlange von alter Position löschen
            spielfeld[sy][sx] = FELD_LEER;

            char taste = getchar();
            if (taste=='i')
                sy = sy - 1;            
            if (taste=='k')
                sy = sy + 1;            
            if (taste=='j')
                sx = sx - 1;            
            if (taste=='l')
                sx = sx + 1;
            if (sx==0)
                sx = 1;
            if (sx==BREITE-1)
                sx = BREITE-2;
            if (sy==0)
                sy = 1;
            if (sy==HOEHE-1)
                sy = HOEHE-2;
            
            // Setze Schlange an neue Stelle im Spielfeld
            spielfeld[sy][sx] = FELD_SCHLANGE;
        }
        mssleep(100);
    }

    return 0;
}