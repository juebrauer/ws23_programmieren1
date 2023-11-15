#include <stdio.h>


void swap(int* px, int* py) {
   int tmp;
   tmp = *px;
   *px = *py;
   *py = tmp;

   printf("Hello from swap function!\n");
   printf("Value of variable that px points to=%d\n", *px);
   printf("Value of variable that py points to=%d\n", *py);  
   printf("Finished with swap function!\n");
}

int main()
{

   int a, b;
   a = 3;
   b = 17;

   swap(&a,&b);

   printf("a=%d\n", a);
   printf("b=%d\n", b);   

} // end main
