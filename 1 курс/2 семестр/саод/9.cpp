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

int BuildHeap(int A[], int L, int R)
{
    int x = A[L];
    int i = L;
    
    while (1)
    {
        int j = 2 * (i + 1) - 1;
        
        if (j >= R)
        {
            break;
        }
        if (j < (R - 1) && (C++, A[j + 1] <= A[j]))
        {
            j = j + 1;
        }

        if (C++, x <= A[j])
        {
            break;
        }

        A[i] = A[j];
        i = j;
        M++;
    }
    A[i] = x;
    M++;
}

int HeapSort(int A[], int n)
{
    int L = n / 2;

    while (L >= 0)
    {
        BuildHeap(A, L , n );
        L = L - 1;
    }

    int R = n;
    while (R > 0)
    {
        int temp;
        temp = A[0];
        A[0] = A[R - 1];
        A[R - 1] = temp;
        
        M += 3;

        R = R - 1;
        BuildHeap(A, 0, R);
    }
    return M + C;
}

int CM(int n)
{
    int M, C;
    int R = n, L = n / 2;
    
    C = 2 * log2(n);
    M = log2(n) + 2;
    
    return M + C;
}
void Table(int N1, int N2, int N3, int N4, int N5, int D1, int D2, int D3, int D4, int D5, int R1, int R2, int R3, int R4, int R5, int IR1, int IR2, int IR3, int IR4, int IR5, int S1, int S2, int S3, int S4, int S5, int RS1, int RS2, int RS3, int RS4, int RS5, int IS1, int IS2, int IS3, int IS4, int IS5)
{
    printf("\n");    
    printf("N   |  M+C T  |        M+C F                |\n");
    printf("    |         |  Desc   |  Rand   |   Inc   |\n");    
    printf("100 | %.7d | %.7d | %.7d | %.7d |\n", N1, D1, IR1, IS1);
    printf("200 | %.7d | %.7d | %.7d | %.7d |\n", N2, D2, IR2, IS2);    
    printf("300 | %.7d | %.7d | %.7d | %.7d |\n", N3, D3, IR3, IS3);
    printf("400 | %.7d | %.7d | %.7d | %.7d |\n", N4, D4, IR4, IS4);    
    printf("500 | %.7d | %.7d | %.7d | %.7d |\n ", N5, D5, IR5, IS5); 
    
    
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
    FILLInc(A1, N);
    FILLInc(A2, NN);
    FILLInc(A3, NNN);
    FILLInc(A4, NNNN);
    FILLInc(A5, NNNNN);
    int IS1 = BuildHeap(A1, 0, N);
    M = 0, C = 0;
    int IS2 = BuildHeap(A2, 0, NN);
    M = 0, C = 0;
    int IS3 = BuildHeap(A3, 0, NNN);
    M = 0, C = 0;
    int IS4 = BuildHeap(A4, 0, NNNN);
    M = 0, C = 0;
    int IS5 = BuildHeap(A5, 0, NNNNN);
    M = 0, C = 0;
    
    FILLDec(A1, N);
    FILLDec(A2, NN);
    FILLDec(A3, NNN);
    FILLDec(A4, NNNN);
    FILLDec(A5, NNNNN);
    int D1 = BuildHeap(A1, 0, N);
    M = 0, C = 0;
    int D2 = BuildHeap(A2, 0, NN);
    M = 0, C = 0;
    int D3 = BuildHeap(A3, 0, NNN);
    M = 0, C = 0;
    int D4 = BuildHeap(A4, 0, NNNN);
    M = 0, C = 0;
    int D5 = BuildHeap(A5, 0, NNNNN);
    M = 0, C = 0;
    
    FILLRand(A1, N);
    FILLRand(A2, NN);
    FILLRand(A3, NNN);
    FILLRand(A4, NNNN);
    FILLRand(A5, NNNNN);
    int IR1 = BuildHeap(A1, 0, N);
    M = 0, C = 0;
    int IR2 = BuildHeap(A2, 0, NN);
    M = 0, C = 0;
    int IR3 = BuildHeap(A3, 0, NNN);
    M = 0, C = 0;
    int IR4 = BuildHeap(A4, 0, NNNN);
    M = 0, C = 0;
    int IR5 = BuildHeap(A5, 0, NNNNN);
    M = 0, C = 0;
    
    FILLDec(A1, N);

    FILLDec(A2, NN);
    FILLDec(A3, NNN);
    FILLDec(A4, NNNN);
    FILLDec(A5, NNNNN);
    int S1 = HeapSort(A1, N);
    M = 0, C = 0;
    int S2 = HeapSort(A2, NN);
    M = 0, C = 0;
    int S3 = HeapSort(A3, NNN);
    M = 0, C = 0;
    int S4 = HeapSort(A4, NNNN);
    M = 0, C = 0;
    int S5 = HeapSort(A5, NNNNN);
    M = 0, C = 0;

    FILLRand(A1, N);
    FILLRand(A2, NN);
    FILLRand(A3, NNN);
    FILLRand(A4, NNNN);
    FILLRand(A5, NNNNN);
    int R1 = HeapSort(A1, N);
    M = 0, C = 0;
    int R2 = HeapSort(A2, NN);
    M = 0, C = 0;
    int R3 = HeapSort(A3, NNN);
    M = 0, C = 0;
    int R4 = HeapSort(A4, NNNN);
    M = 0, C = 0;
    int R5 = HeapSort(A5, NNNNN);
    M = 0, C = 0;
    
    FILLInc(A1, N);
    FILLInc(A2, NN);
    FILLInc(A3, NNN);
    FILLInc(A4, NNNN);
    FILLInc(A5, NNNNN);
    M = 0, C = 0;
    int RS1 = HeapSort(A1, N);
    M = 0, C = 0;
    int RS2 = HeapSort(A2, NN);
    M = 0, C = 0;
    int RS3 = HeapSort(A3, NNN);
    M = 0, C = 0;
    int RS4 = HeapSort(A4, NNNN);
    M = 0, C = 0;
    int RS5 = HeapSort(A5, NNNNN);
    M = 0, C = 0;
    
    int N1 = CM(N), N2 = CM(NN), N3 = CM(NNN), N4 = CM(NNNN), N5 = CM(NNNNN);
    
    Table(N1, N2, N3, N4, N5, D1, D2, D3, D4, D5, R1, R2, R3, R4, R5, IR1, IR2, IR3, IR4, IR5, S1, S2, S3, S4, S5, RS1, RS2, RS3, RS4, RS5, IS1, IS2, IS3, IS4, IS5);

    return 0;
}
