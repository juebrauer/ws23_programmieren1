#include <stdio.h>

int main()
{
    printf("Startkapital: ");
    float startkapital;
    scanf("%f", &startkapital);

    printf("Zielkapital: ");
    float zielkapital;
    scanf("%f", &zielkapital);

    printf("Zinssatz: ");
    float zinssatz;
    scanf("%f", &zinssatz);

    printf("OK. Ich berechne jetzt wie lange es dauert dein\n"
       "Startkapital in Höhe von %f EUR so lange mit dem\n"
       "Zinssatz von %f Prozent zu verzinsen, bis das\n"
       "Zielkapital in Höhe von %f EUR erreicht ist.\n",
       startkapital, zinssatz, zielkapital);

    float kapital = startkapital;
    int jahr = 0;
    while (kapital < zielkapital)
    {
        jahr = jahr + 1;
        kapital = kapital + kapital*(zinssatz/100.0);
        printf("Jahr: %d --> %f\n", jahr, kapital);
    }
    

    return 0;
}