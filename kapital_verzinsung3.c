#include <stdio.h>
#include <math.h>

int main() {
  // Variablen deklarieren
  float startkapital, zielkapital, zinssatz;
  int jahre = 0;

  // Startkapital vom Benutzer einlesen
  printf("Startkapital: ");
  scanf("%f", &startkapital);

  // Zielkapital vom Benutzer einlesen
  printf("Zielkapital: ");
  scanf("%f", &zielkapital);

  // Zinssatz vom Benutzer einlesen
  printf("Zinssatz in %%: ");
  scanf("%f", &zinssatz);

  // Zinssatz in Dezimalzahl umrechnen
  zinssatz /= 100;

  // Kapital nach jedem Jahr berechnen
  float kapital = startkapital;
  while (kapital < zielkapital) {
    //jahre++;
    jahre = jahre + 1;
    //kapital = kapital * (1 + zinssatz);
    kapital = kapital + kapital * zinssatz;
  }
  printf("Zielkapital erreicht nach %d Jahren.\n", jahre); 

  // Ausgabe
  kapital = startkapital;
  for (int i = 0; i <= jahre; i++) {
    printf("Kapital nach %d Jahren: %.2f\n", i, kapital * pow(1 + zinssatz, i));
  }

  // Start: startkapital
  // Nach 1 Jahr  : startkapital * (1+0.05)
  // Nach 2 Jahren: startkapital * (1+0.05) * (1+0.05)
  // Nach 3 Jahren: startkapital * (1+0.05) * (1+0.05) * (1+0.05)

  return 0;
}
