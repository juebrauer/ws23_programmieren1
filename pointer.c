#include <stdio.h>

int main()
{
    double v;
    v = 123;

    double* pv;
    pv = &v;

    double** pv2;
    pv2 = &pv;

    printf("v=%f\n", v);
    printf("pv=%p\n", pv);
    
    printf("Wert der Variablen, auf den der Pointer pv zeigt:\n");
    printf("%f\n", *pv);

    printf("Um ein int zu speichern, brauchst du %ld Bytes\n", sizeof(int));
    printf("Der Pointer pv benötigt %ld Bytes\n", sizeof(int*));

    // "Pointer-Arithmetik"
    double* p2;
    p2 = pv + 2;
    printf("p2=%p\n", p2);
    printf("Wert der Variablen, auf den der Pointer p2 zeigt:\n");
    printf("%f\n", *p2);
}