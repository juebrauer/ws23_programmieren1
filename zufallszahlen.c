#include <stdio.h>  // printf(), scanf()
#include <stdlib.h> // rand()
#include <time.h>   // time()

int main() {

    srand(time(NULL));

    int zufallszahl;
    int i=1;
    for (;i<=5;)
    {  
        zufallszahl = (rand() % 6) + 1;
        printf("Zufallszahl: %d\n", zufallszahl);

        i=i+1;
    }
  
 
}