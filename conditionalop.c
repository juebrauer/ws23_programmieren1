#include <stdio.h>


int main()
{
   int a = -33;
   int b = -33;

   int maximum = a > b ? a : b;

   printf("The larger number of %d and %d is %d\n", a, b, maximum);

   a < b ? printf("a is smaller than b") : printf("a is not smaller than b");

   return 42;
}