#include <stdio.h>

int main()
{

   printf("ergebnis=%f\n", 10.0/0);


   return 0;
   
   
   printf("\nPlease enter number 1: ");
   int n1;
   scanf("%d", &n1);
   printf("\nPlease enter number 2: ");
   int n2;
   scanf("%d", &n2);

   printf("\nPress ...");
   printf("\n1 - to add the numbers");
   printf("\n2 - to subtract the numbers");
   printf("\n3 - to multiply the numbers");
   printf("\n4 - to divide the numbers");

   int op;
   printf("\nWhat do you want to do? ");
   scanf("%d", &op);

   int res;
   switch (op)
   {
    case 1 : res=n1+n2;
             printf("%d + %d = %d\n", n1, n2, res); 
             
    case 2 : res=n1-n2;
             printf("%d - %d = %d\n", n1, n2, res); 
           
    case 3 : res=n1*n2;
             printf("%d * %d = %d\n", n1, n2, res);
             
    case 4 : res=n1/n2;
             printf("%d / %d = %d\n", n1, n2, res);
             
    default: printf("Das Menü verlangt, dass du 1-4 eingibst!\n");

   }
   


   return 0;
}