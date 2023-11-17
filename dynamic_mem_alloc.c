#include <stdio.h>
#include <stdlib.h> // malloc

int main() {
   unsigned long long int N;
   int number;

   printf("How many numbers do you want to enter? ");
   scanf("%llu", &N);

   printf("Du hast eingegeben N=%llu\n", N);
   
   int* A = malloc(N * sizeof(int));
   if (A == NULL) {
      printf("Out of memory error!\n");
      exit(1);
   }
      
   for (unsigned int i = 0; i < N; i++) {
      printf("Enter number #%d: ", i);
      scanf("%d", &number);
      //A[i] = number;
      *(A+i) = number;
   }

   for (unsigned int i = 0; i < N; i++)
      printf("\nnumber #%d: %d", i, A[i]);

   free(A);

}