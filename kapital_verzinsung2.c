#include <stdio.h>

int main() {
    double startkapital, zielkapital, zinssatz;
    int jahre = 0;

    // Benutzereingabe
    printf("Bitte geben Sie das Startkapital ein: ");
    scanf("%lf", &startkapital);

    printf("Bitte geben Sie das Zielkapital ein: ");
    scanf("%lf", &zielkapital);

    printf("Bitte geben Sie den Zinssatz in Prozent ein: ");
    scanf("%lf", &zinssatz);
    //zinssatz /= 100;  // Convert percentage to a decimal
    zinssatz = zinssatz / 100;

    // Berechnung
    while (startkapital < zielkapital) {
        startkapital += startkapital * zinssatz;
        jahre++;
        printf("Nach %d Jahr(en): %.2lf\n", jahre, startkapital);
    }

    // Ergebnisausgabe
    printf("\nEs dauert %d Jahre, um das Kapital von %.2lf auf %.2lf bei einem Zinssatz von %.2lf%% zu vermehren.\n",
           jahre, startkapital/(1+zinssatz*jahre), zielkapital, zinssatz*100);

    return 0;
}
