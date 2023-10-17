#include <stdio.h>

int main() {
    double startkapital, zielkapital, zinssatz;
    int jahre = 0;

    printf("Geben Sie das Startkapital ein: ");
    scanf("%lf", &startkapital);

    printf("Geben Sie das Zielkapital ein: ");
    scanf("%lf", &zielkapital);

    printf("Geben Sie den Zinssatz ein: ");
    scanf("%lf", &zinssatz);

    while (startkapital < zielkapital) {
        jahre++;
        double zinsen = startkapital * zinssatz / 100;
        startkapital += zinsen;

        printf("Nach %d Jahren haben Sie %.2lf Kapital.\n", jahre, startkapital);
    }

    printf("Es dauert %d Jahre, um das Startkapital von %.2lf auf %.2lf zu vermehren.\n", jahre, startkapital, zielkapital);

    return 0;
}
