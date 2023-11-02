#include <stdio.h>  // printf()
#include <stdlib.h> // rand()
#include <time.h>   // time()

#include "params.h" // Spielparameter
#include "snake_hilfsfunktionen.h"

// main.c -> Präprozessor -> Compiler -> Linker -> Ausführbares Programm

char spielfeld[HOEHE][BREITE];

// Schlange startet an Bildschirmmitte
int sx = BREITE/2;
int sy = HOEHE/2;

// Schlange läuft initial nach rechts
int slx = 1;
int sly = 0;



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
        int x = rand() % (BREITE-2) + 1;
        int y = rand() % (HOEHE-2)  + 1;
        spielfeld[y][x] = FELD_FUTTER;
    }
}


void spielfeld_hindernisswaende_einfuegen(int anz_waende, int lx, int ly)
{
    for (int wand_nr=0; wand_nr<anz_waende; wand_nr++)
    {
        // Zufällige Anfangsposition der Wand
        int x = rand() % (BREITE-2) + 1;
        int y = rand() % (HOEHE-2)  + 1;

        for (int wand_stueck=0; wand_stueck<WAND_LAENGE; wand_stueck++)
        {
            int zx = x + wand_stueck*lx;
            int zy = y + wand_stueck*ly;

            if ((zx>=0) && (zx<=BREITE-1) && (zy>=0) && (zy<=HOEHE-1))
                spielfeld[zy][zx] = FELD_WAND;            
        }
    }
}


void spielfeld_initialisieren() {
    
    spielfeld_waende_einfuegen();  
    spielfeld_hindernisswaende_einfuegen(ANZ_VERTIKALE_WAENDE,   0,1);
    spielfeld_hindernisswaende_einfuegen(ANZ_HORIZONTALE_WAENDE, 1,0);
    spielfeld_hindernisswaende_einfuegen(ANZ_DIAGONALE_WAENDE, -1,1);
    //spielfeld_hindernisswaende_einfuegen(ANZ_DIAGONALE_WAENDE,  1,1);
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

        // Schlange von alter Position löschen
        spielfeld[sy][sx] = FELD_LEER;

        // Hat der Benutzer eine Taste gedrückt?
        if (kbhit()) {

            char taste = getchar();

            // Laufrichtung ändern?
            if (taste=='i') {
                slx = 0;
                sly = -1;
            }
            if (taste=='k') {
                slx = 0;
                sly = 1;
            }
            if (taste=='j') {
                slx = -1;
                sly = 0;
            }                
            if (taste=='l') {
                slx = 1;
                sly = 0;
            }           
        }
        // Schlange läuft automatisch in aktuelle Laufrichtung weiter
        sx += slx;
        sy += sly;

        // Schlange kann nicht aus dem Spielfeld laufen!
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

        mssleep(100);
    }

    return 0;
}