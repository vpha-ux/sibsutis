#include <stdio.h>
#include <stdlib.h>

void f (int n) 
{
    int *array = (int *)malloc(sizeof(int) * (n + 1));

    for (int i = 2; i <= n; i++)
    {
        array[i] = 1;
    }

    for (int p = 2; p * p <= n; p++) 
    {
        if (array[p] == 1) 
        {
            for (int i = p * p; i <= n; i += p)
            {
                array[i] = 0;
            }

        }
    }

    printf("Простые числа от 2 до %d:\n", n);
    
    for (int i = 2; i <= n; i++)
    {
        if (array[i] == 1)
        {
            printf("%d ", i);
        }
    }
    
    free(array);
}

int main() 
{
    int n;

    printf("Ввидите n: ");
    scanf("%d", &n);

    if (n < 2) 
    {
        printf("Простых чисел нет \n");
    } 
    else 
    {
        f(n);
    }
}
