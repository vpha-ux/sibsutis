#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int n;
    printf("������� ���������� ��������� � ������� b ");
    scanf("%d", &n);
    
    int *b = (int*)malloc(n * sizeof(int));
    
    int k = 0, m = 0;
    
    printf("�������� ������ ");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 101 - 50;
        printf("%d ", b[i]);
        
        if (b[i] < 0)
        {
            k++;
        }
        if (b[i] > 0)
        {
            m++;
        }
    }
    
    int *c = (int*)malloc(m * sizeof(int));
    int *d = (int*)malloc(k * sizeof(int));
    
    //if (m != k)
    //{
    //  printf("������ \n");
    //}
    //else 
    //{
        k = 0; m = 0;
        for(int i = 0; i < n; i++)
        {
            if (b[i] < 0)
            {
                d[k] = b[i];
                k++;
            }
            if (b[i] > 0)
            {
                c[m] = b[i];
                m++;
            }
        }
        
        printf("������ ������������� ");
        for (int i = 0; i < m; i++)
        {
            printf("%d ", c[i]);
        }
    
        printf("������ ������������� ");
        for (int i = 0; i < k; i++)
        {
            printf("%d ", d[i]);
        }
    
        free(b);
        free(c);
        free(d);
    //}
    
}
