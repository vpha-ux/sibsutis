#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define NN 200
#define NNN 300
#define NNNN 400
#define NNNNN 500

int A1[N];
int A2[NN];
int A3[NNN];
int A4[NNNN];
int A5[NNNNN];

int M = 0, C = 0;

void FILLInc(int A[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        A[i] += i;  
    } 
} 
 
void FILLDec(int A[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        A[i] = n - i; 
    } 
} 
 
void FILLRand(int A[], int n) 
{ 
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
    { 
        A[i] = rand() % n; 
    } 
}

int QuickSort(int* A, int L, int R)
{
    M++;
    int x = A[(L+R)/2], i = L, j = R;

    while(i<=j)
    {

        while(C++, A[i] < x) i++;

        while(C++, A[j] > x) j--;

        int tmp = 0;

        if (i <= j)
        {

            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            M += 3;

            i++;
            j--;
        }

    }

    if (L < j) QuickSort(A, L, j);

    if (i < R) QuickSort(A, i, R);

    return M+C;
}

void Table(int R1, int R2, int R3, int R4, int R5, int S1, int S2, int S3, int S4, int S5, int RS1, int RS2, int RS3, int RS4, int RS5)
{
    printf("\n");    
    printf("N   |             M+C             |\n");
    printf("-----------------------------------\n");
    printf("    |  Desc   |  Rand   |   Inc   |\n");
    printf("-----------------------------------\n");
    printf("100 | %.7d | %.7d | %.7d |\n", S1, R1, RS1);
    printf("200 | %.7d | %.7d | %.7d |\n", S2, R2, RS2);    
    printf("300 | %.7d | %.7d | %.7d |\n", S3, R3, RS3);
    printf("400 | %.7d | %.7d | %.7d |\n", S4, R4, RS4);    
    printf("500 | %.7d | %.7d | %.7d |\n", S5, R5, RS5);
}

int main()
{
    FILLDec(A1, N);
    FILLDec(A2, NN);
    FILLDec(A3, NNN);
    FILLDec(A4, NNNN);
    FILLDec(A5, NNNNN);
    
    int S1 = QuickSort(A1, 0, N - 1);
    M = 0; C = 0;
    int S2 = QuickSort(A2, 0, NN - 1);
    M = 0; C = 0;
    int S3 = QuickSort(A3, 0, NNN - 1);
    M = 0; C = 0;
    int S4 = QuickSort(A4, 0, NNNN - 1);
    M = 0; C = 0;
    int S5 = QuickSort(A5, 0, NNNNN - 1);
    M = 0; C = 0;

    FILLRand(A1, N);
    FILLRand(A2, NN);
    FILLRand(A3, NNN);
    FILLRand(A4, NNNN);
    FILLRand(A5, NNNNN);
    
    int R1 = QuickSort(A1, 0, N - 1);
    M = 0; C = 0;
    int R2 = QuickSort(A2, 0, NN - 1);
    M = 0; C = 0;
    int R3 = QuickSort(A3, 0, NNN - 1);
    M = 0; C = 0;
    int R4 = QuickSort(A4, 0, NNNN - 1);
    M = 0; C = 0;
    int R5 = QuickSort(A5, 0, NNNNN - 1);
    M = 0; C = 0;
    
    FILLInc(A1, N);
    FILLInc(A2, NN);
    FILLInc(A3, NNN);
    FILLInc(A4, NNNN);
    FILLInc(A5, NNNNN);
    
    M = 0; C = 0;
    int RS1 = QuickSort(A1, 0, N - 1);
    M = 0; C = 0;
    int RS2 = QuickSort(A2, 0, NN - 1);
    M = 0; C = 0;
    int RS3 = QuickSort(A3, 0, NNN - 1);
    M = 0; C = 0;
    int RS4 = QuickSort(A4, 0, NNNN - 1);
    M = 0; C = 0;
    int RS5 = QuickSort(A5, 0, NNNNN - 1);
    M = 0; C = 0;
    
    Table(R1, R2, R3, R4, R5, S1, S2, S3, S4, S5, RS1, RS2, RS3, RS4, RS5);

    return 0;
}
