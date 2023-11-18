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

// Schlangenlänge (:= Länge der Schlange bis auf den Kopf)
int slen = START_SCHLANGEN_LAENGE;

int sstueckx[MAX_SCHLAENGE_LAENGE];
int sstuecky[MAX_SCHLAENGE_LAENGE];



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

void spielfeld_startbereich_freimachen()
{
    int S = START_BEREICH_SEITENLAENGE;
    for (int oy=-S/2; oy<=S/2; oy++)
        for (int ox=-S/2; ox<=S/2; ox++)
            spielfeld[sy+oy][sx+ox] = FELD_LEER;
}


void spielfeld_initialisieren() {
    
    spielfeld_waende_einfuegen();  
    spielfeld_hindernisswaende_einfuegen(ANZ_VERTIKALE_WAENDE,   0,1);
    spielfeld_hindernisswaende_einfuegen(ANZ_HORIZONTALE_WAENDE, 1,0);
    spielfeld_hindernisswaende_einfuegen(ANZ_DIAGONALE_WAENDE, -1,1);
    //spielfeld_hindernisswaende_einfuegen(ANZ_DIAGONALE_WAENDE,  1,1);
    spielfeld_startbereich_freimachen();
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


void setze_schlange_ins_spielfeld()
{
    // Setze Schlangenkopf ins Spielfeld
    spielfeld[sy][sx] = FELD_SCHLANGE_KOPF;

    for (int stueck=0; stueck<slen; stueck++)
    {
        int kx = sstueckx[stueck];
        int ky = sstuecky[stueck];
        spielfeld[ky][kx] = FELD_SCHLANGEN_STUECK;
    }
}

void bewege_schlange_im_spielfeld(int old_sx, int old_sy)
{
    // Lösche aus dem Spielfeld das letzte Schlangenstückchen
    int kx = sstueckx[slen-1];
    int ky = sstuecky[slen-1];
    spielfeld[ky][kx] = ' ';
        

    // Alle weiteren Schlangenstücke rücken eins auf
    for (int stueck=slen-1; stueck>=1; stueck--)
    {
        sstueckx[stueck] = sstueckx[stueck-1];
        sstuecky[stueck] = sstuecky[stueck-1];
    }

    // Setze das 1. Stück auf die alte Schlangenkopfposition
    sstueckx[0] = old_sx;
    sstuecky[0] = old_sy;

    // Trage die Schlange ins Spielfeld ein
    setze_schlange_ins_spielfeld();
}


int main() {

    //srand(time(NULL));
    srand(42);

    // Die Startposition der Schlange ist über (sx,sy)
    // bereits vorbereitet und die Laufrichtung über (slx, sly).
    // Setze nun die Anfangsschlangenstücke entsprechend:
    for (int stueck=0; stueck<START_SCHLANGEN_LAENGE; stueck++)
    {
        sstueckx[stueck] = sx-stueck-1;
        sstuecky[stueck] = sy;
    }

    spielfeld_initialisieren();

    setze_schlange_ins_spielfeld();
    

    // Spielschleife
    int counter = 0;
    while (1) {
        clear();
        spielfeld_ausgeben();

        counter++;
        printf("Länge: %d, Update: %d\n", slen, counter);      

        printf("sx=%d, sy=%d\n", sx,sy);
        for (int stueck=0; stueck<slen; stueck++)
        {
            printf("stueck #%d: x=%d, y=%d\n", stueck, sstueckx[stueck], sstuecky[stueck]);
        }

        
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
            if (taste=='q')
                break;
        }

        // Schlange läuft automatisch in aktuelle Laufrichtung weiter
        int old_sx = sx;
        int old_sy = sy;
        sx += slx;
        sy += sly;
        
        // Ist die Schlange in eine Wand gelaufen?
        if (spielfeld[sy][sx] == FELD_WAND)
        {
            printf("Ups! Du hast die Schlange in die Wand gefahren!\n");
            break;
        }

        // Ist die Schlange in ein Futterstück gelaufen?
        if (spielfeld[sy][sx] == FELD_FUTTER)
        {
            slen++;
        }

        // Bewege die Schlange im Spielfeld
        bewege_schlange_im_spielfeld(old_sx, old_sy);
        
        mssleep(100);
    }

    printf("Spiel beendet!\n");

    return 0;
}