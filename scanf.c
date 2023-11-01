#include <stdio.h>

int main() {

    char buffer[10];

    // Traditionelle scanf-Funktion - potenziell unsicher
    //scanf("%s", buffer);
    scanf("%9c", buffer);

    printf("Deine Eingabe: %s\n", buffer);

    // Sicherere scanf_s-Funktion
    //scanf_s("%s", buffer, sizeof(buffer));

}