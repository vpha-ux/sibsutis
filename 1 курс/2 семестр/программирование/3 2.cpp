#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int n;
   printf("Введите размер массива а: ");
   scanf("%d", &n);
   
   double *a = (double*)malloc(n * sizeof(double));
   double **b = (double**)malloc(n * sizeof(double*));
   
   printf("Исходный массив а: \n");
   srand(time(NULL));
   for (int i = 0; i < n; i++)
   {
       a[i] = (float)rand()*(1-0)/RAND_MAX + 0;
       printf("%.2f  ", a[i]);
       b[i] = &a[i];
   }
   
    for(int i = 0; i < n - 1; i++) 
  {
      for (int j = i + 1; j < n; j++)
      {
          if (*b[j-1] > *b[j]) 
          {
                double* temp = b[j-1];
                b[j-1] = b[j];
                b[j] = temp;
            }
      }
      printf("%.2f ", *b[i]);
  }
   
   printf("Отсортированный массив: ");
   for (int i = 0; i < n; i++)
   {
       printf("%.2f ", *b[i]);
   }
}
